#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QtSql/QSqlDatabase>
#include <QObject>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QVariant>
#include <QVector>

#include "PinInfo.h"

struct ComponentRow {
    int component_id;
    QString visible_name;
    QString type_name;
    QString nominal_value;
    QString manufactured;
    QString footprint_id;
    QString symbol_id;
};


class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit  DatabaseManager(QObject* parent = nullptr);

public:
    bool open(const QString& filePath);
    bool initSchema();

public:
    QVector<ComponentRow> loadAllComponents();
    bool removeComponent(int componentId);

public:
    bool addComponent(const ComponentRow& r);

public:
    bool updatePlacedElementPosition(int placedElementId, int newX, int newY, double newRotation);
    bool recalcPlacedPinsForElement(int placedElementId);

public:
    QVector<PinInfo> loadFootprintPins(const QString& footprintId);
    void insertTestFootprintPins();

private:
    QSqlDatabase m_db;
    const QString m_connectionName = "radio_db_connection";

};

#endif // DATABASEMANAGER_H
