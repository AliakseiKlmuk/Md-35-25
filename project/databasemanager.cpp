#include "databasemanager.h"

DatabaseManager::DatabaseManager(QObject* parent)
    : QObject(parent) {}

bool DatabaseManager::open(const QString &filePath){

    if (QSqlDatabase::contains(m_connectionName)){
        m_db = QSqlDatabase::database(m_connectionName);
    } else {
        m_db = QSqlDatabase::addDatabase("QSQLITE", m_connectionName);
    }
    m_db.setDatabaseName(filePath);
    bool ok = m_db.open();

    if(!ok){
        qDebug() <<"[open] DB open error:" << m_db.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::initSchema(){
    QSqlQuery q(m_db);

    const QStringList statements = {
        R"SQL(
                CREATE TABLE IF NOT EXISTS components(
                component_id   INTEGER PRIMARY KEY AUTOINCREMENT,
                visible_name   TEXT NOT NULL,
                type_name      TEXT NOT NULL,
                nominal_value  TEXT,
                manufactured   TEXT,
                footprint_id   TEXT NOT NULL,
                symbol_id      TEXT
                );
        )SQL",

        R"SQL(  CREATE TABLE IF NOT EXISTS footprints(
                footprint_id   TEXT PRIMARY KEY,
                footprint_name TEXT
                );
        )SQL",

        R"SQL(   CREATE TABLE IF NOT EXISTS footprint_pins(
                 footprint_id   TEXT NOT NULL,
                 pin_name       TEXT NOT NULL,
                 pin_local_x    REAL NOT NULL,
                 pin_local_y    REAL NOT NULL,
                 pin_local_rot  REAL DEFAULT 0,
                 PRIMARY KEY (footprint_id, pin_name),
                 FOREIGN KEY (footprint_id) REFERENCES footprints(footprint_id)
                );
        )SQL",

        R"SQL(  CREATE TABLE IF NOT EXISTS projects(
                project_id INTEGER PRIMARY KEY AUTOINCREMENT,
                project_name TEXT NOT NULL,
                created_at TEXT
                );
        )SQL",

        R"SQL(  CREATE INDEX IF NOT EXISTS idx_footprint_pins_footprint_id
                ON footprint_pins(footprint_id)
        )SQL",

        R"SQL(  CREATE TABLE IF NOT EXISTS placed_elements(
                placed_element_id INTEGER PRIMARY KEY AUTOINCREMENT,
                project_id INTEGER NOT NULL,
                component_id INTEGER NOT NULL,
                x INTEGER NOT NULL,
                y INTEGER NOT NULL,
                rotation REAL DEFAULT 0,
                FOREIGN KEY (project_id) REFERENCES projects(project_id),
                FOREIGN KEY (component_id) REFERENCES components(component_id)
                );
        )SQL",

        R"SQL(  CREATE INDEX IF NOT EXISTS idx_placed_elements_project_id
                ON placed_elements(project_id)
        )SQL",

        R"SQL(  CREATE TABLE IF NOT EXISTS placed_pins(
                placed_pin_id INTEGER PRIMARY KEY AUTOINCREMENT,
                placed_element_id INTEGER NOT NULL,
                pin_name TEXT NOT NULL,
                x INTEGER NOT NULL,
                y INTEGER NOT NULL,
                rotation DEFAULT 0,
                FOREIGN KEY (placed_element_id) REFERENCES placed_elements(placed_element_id)
                );
        )SQL",

        R"SQL(  CREATE INDEX IF NOT EXISTS idx_placed_pins_placed_element_id
                ON placed_pins(placed_element_id)
        )SQL",

        R"SQL(  CREATE UNIQUE INDEX IF NOT EXISTS idx_placed_pinns_element_pinname
                ON placed_pins(placed_element_id, pin_name)
        )SQL"

   };

    for (const auto& s: statements){
        if(!q.exec(s)){
        qDebug() << "initSchema error: " << q.lastError(). text();
        return false;
        }
    }
    return true;
}

QVector<ComponentRow> DatabaseManager::loadAllComponents(){
    QVector<ComponentRow> rows;
    QSqlQuery q(m_db);
    q.exec("RPAGMA foreign_keys = ON;");

    const QString sql = R"SQL(
                        SELECT component_id, visible_name, type_name, nominal_value,
                        manufactured, footprint_id, symbol_id

                        FROM components
                        ORDER BY component_id DESC
                        )SQL";

    if (!q.exec(sql)){
        qDebug() <<"loadAllComponents error:" << q.lastError().text();
        return rows;
    }

    while(q.next()){
        ComponentRow r;
        r.component_id   = q.value(0).toInt();
        r.visible_name   = q.value(1).toString();
        r.type_name      = q.value(2).toString();
        r.nominal_value  = q.value(3).toString();
        r.manufactured   = q.value(4).toString();
        r.footprint_id   = q.value(5).toString();
        r.symbol_id      = q.value(6).toString();
        rows.push_back(r);
    }
    return rows;
}

bool DatabaseManager::removeComponent(int componentId){
    QSqlQuery q(m_db);

    q.prepare("DELETE FROM components WHERE component_id = :id");
    q.bindValue(":id", componentId);

    if (!q.exec()){
        qDebug() << "removeComponent error: " << q.lastError(). text();
        return false;
    }
    return true;
}

bool DatabaseManager::addComponent(const ComponentRow& r){
    QSqlQuery q(m_db);

    q.prepare(R"SQL(
              INSERT INTO components
              (visible_name, type_name, nominal_value, manufactured, footprint_id, symbol_id)
              VALUES(:visible_name, :type_name, :nominal_value, :manufactured, :footprint_id, :symbol_id)
              )SQL");

    q.bindValue(":visible_name", r.visible_name);
    q.bindValue(":type_name", r.type_name);
    q.bindValue(":nominal_value", r.nominal_value);
    q.bindValue(":manufactured", r.manufactured);
    q.bindValue(":footprint_id", r.footprint_id);
    q.bindValue(":symbol_id", r.symbol_id);

    qDebug() << "SQL for addComponent:" <<q.executedQuery();
    qDebug() << "Placeholders bind:"
             <<r.visible_name << r.type_name << r.nominal_value
            << r.manufactured << r.footprint_id << r.symbol_id;

    if (!q.exec()){
        qDebug() <<"addComponent error query:" <<q.lastQuery();
        qDebug() <<"addComponent error:" << q.lastError().text();
        return false;
    }
    return true;

}

bool DatabaseManager::updatePlacedElementPosition(int placedElementId, int newX, int newY, double newRotation){
    QSqlQuery q(m_db);

    if(!q.prepare(R"SQL(
                  UPDATE placed_elements
                  SET x = :x, y = :y, rotation = :rot
                  WHERE placed_element_id = :placedElementId
                  )SQL"))
        return false;

    q.bindValue(":x", newX);
    q.bindValue(":y", newY);
    q.bindValue(":rot", newRotation);
    q.bindValue(":placedElementId", placedElementId);

    if(!q.exec()){
        qDebug() << "updatePlacedElementPosition: update failed" <<q.lastError().text();
        return false;
    }
    return recalcPlacedPinsForElement(placedElementId);
}

bool DatabaseManager::recalcPlacedPinsForElement(int placedElementId){
    QSqlQuery q(m_db);

    if (!q.prepare(R"SQL(
                   SELECT pe.x, pe.y, pe.rotation, c.footprint_id
                   FROM placed_elements pe
                   JOIN components c ON c.component_id = pe.component_id
                   WHERE pe.placed_element_id = :placedElementId
                   )SQL"))
        return false;

    q.bindValue(":placedElementId", placedElementId);

    if(!q.exec()){
        qDebug() <<"recalcPlacedPinsForElement: selecte filed" << q.lastError().text();
        return false;
    }

    if (!q.next()){
        qDebug() << "recalcPlacedPinsForElement: placed element not found" << placedElementId;
        return false;
    }

    const int elemX = q.value(0).toInt();
    const int elemY =q.value(1).toInt();
    const double elemRot = q.value(2).toDouble();
    const QString footprintId = q.value(3).toString();

    QSqlQuery qp(m_db);
    if(!qp.prepare(R"SQL(
                   SELECT pin_name, pin_local_x, pinLocal_y, pin_local_rot
                   FROM footprint_pins
                   WHERE footprint_id = :footprintId
                   )SQL"))
        return false;

    qp.bindValue(":footprintId", footprintId);

    if (!qp.exec()){
        qDebug() << "recalcPlacedPinsElemet: footprint_pins select failed" << qp.lastError().text();
        return false;
    }

    QSqlQuery qu(m_db);
    if(!qu.prepare(R"SQL(
                   UPDATE placed_pins
                   SET x = :x, y = :y, rotation = :rot
                   WHERE placed_element_id = :placedElementId AND pin_name = :pin_name
                   )SQL"))
        return false;

    while(qp.next()){
        const QString pinName = qp.value(0).toString();
        const double pinLocalX = qp.value(1).toDouble();
        const double pinLocalY = qp.value(2).toDouble();
        const double pinLocalRot = qp.value(3).toDouble();

        const double newPinX = elemX + pinLocalX;
        const double newPinY = elemY + pinLocalY;

        const double newPinRot = pinLocalRot + elemRot;

        qu.bindValue(":x", newPinX);
        qu.bindValue(":y", newPinY);
        qu.bindValue(":rot", newPinRot);
        qu.bindValue(":placedElementId", placedElementId);
        qu.bindValue(":pin_name", pinName);

        if(!qu.exec()){
            qDebug()<< "recalcPlacedPinsForElement: placed_pins update filed" << qu.lastError().text();
            return false;
        }
      }
   return true;
}

QVector<PinInfo> DatabaseManager::loadFootprintPins(const QString& footprintId){
    QVector<PinInfo> pins;
    QSqlQuery q(m_db);

    q.prepare(R"SQL(
              SELECT pin_name, pin_local_x, pin_local_y
              FROM footprint_pins
              WHERE footprint_id = :id
              )SQL");
    q.bindValue(":id", footprintId);

    if (!q.exec()){
        qDebug() <<"loadFootprintPins error:" << q.lastError().text();
        return pins;
    }

    while(q.next()){
        PinInfo p;
        p.name = q.value(0).toString();
        p.x = q.value(1).toInt();
        p.y = q.value(2).toInt();
        pins.push_back(p);
    }
    return pins;
}

void DatabaseManager::insertTestFootprintPins(){
    QSqlQuery q(m_db);

    q.exec("DELETE FROM footprint_pins");

    QSqlQuery q2(m_db);
    q2.exec("INSERT OR IGNORE INTO footprints(footprint_id, footprint_name) VALUES('TO220', 'TO-220')");
    q2.exec("INSERT OR IGNORE INTO footprints(footprint_id, footprint_name) VALUES('DIP4', 'DIP-4')");
    q2.exec("INSERT OR IGNORE INTO footprints(footprint_id, footprint_name) VALUES('DIP8', 'DIP-8')");

    if (!q.prepare("INSERT OR IGNORE INTO footprint_pins "
              "(footprint_id, pin_name, pin_local_x, pin_local_y)"
              "VALUES (:id, :name, :x, :y)"))
    {
        qDebug() <<"Prepare error:" <<q.lastError().text();
        return;}

    struct Pin{QString name; double x, y;};

    const double mm = 10.0;

    QVector<Pin> to220 = {
        {"1", 0 * mm, 0 * mm},
        {"2", 3 * mm, 0 * mm},
        {"3", 6 * mm, 0 * mm}
    };

    for (auto& p : to220){
        q.bindValue(":id", "TO220");
        q.bindValue(":name", p.name);
        q.bindValue(":x", p.x);
        q.bindValue(":y", p.y);

        if (!q.exec()){
            qDebug() << "Isert TO220 error:" << q.lastError().text();
        }
    }

    QVector<Pin> dip4 = {
        {"1", 0 * mm, 0 * mm},
        {"2", 0 * mm, 9 * mm},
        {"3", 3 * mm, 9 * mm},
        {"4", 3 * mm, 0 * mm}
    };

    for (auto& p : dip4){
        q.bindValue(":id", "DIP4");
        q.bindValue(":name", p.name);
        q.bindValue(":x", p.x);
        q.bindValue(":y", p.y);

        if (!q.exec()){
            qDebug() << "Isert DIP4 error:" << q.lastError().text();
        }
    }

        QVector<Pin> dip8 = {
            {"1", 0 * mm, 3 * mm},
            {"2", 0 * mm, 6 * mm},
            {"3", 0 * mm, 9 * mm},
            {"4", 0 * mm, 12 * mm},
            {"5", 3 * mm, 12 * mm},
            {"6", 3 * mm, 9 * mm},
            {"7", 3 * mm, 6 * mm},
            {"8", 3 * mm, 3 * mm},
        };

        for (auto& p : dip8){
            q.bindValue(":id", "DIP8");
            q.bindValue(":name", p.name);
            q.bindValue(":x", p.x);
            q.bindValue(":y", p.y);

            if (!q.exec()){
                qDebug() << "Isert DIP8 error:" << q.lastError().text();
            }
    }

    qDebug() << "Test footprint pins inserted.";
}
