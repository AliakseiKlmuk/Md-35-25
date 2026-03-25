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
                symbol_id      TEXT);
        )SQL",

        R"SQL(
                 CREATE TABLE IF NOT EXISTS footprints(
                 footprint_id   TEXT PRIMARY KEY,
                 footprint_name TEXT);
        )SQL",

        R"SQL(
                 CREATE TABLE IF NOT EXISTS footprint_pins(
                 footprint_id   TEXT NOT NULL,
                 pin_name       TEXT NOT NULL,
                 pin_local_x    REAL NOT NULL,
                 pin_local_y    REAL NOT NULL,
                 pin_local_rot  REAL DEFAULT 0,
                 PRIMARY KEY (footprint_id, pin_name),
                 FOREIGN KEY (footprint_id) REFERENCES footprints(footprint_id));
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

