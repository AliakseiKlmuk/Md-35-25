#ifndef COMPONENTSDIALOG_H
#define COMPONENTSDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>
#include <QMessageBox>

#include "databasemanager.h"
#include "addcomponentdialog.h"

class DatabaseManager;

namespace Ui {
class ComponentsDialog;
}

class ComponentsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ComponentsDialog(DatabaseManager* db, QWidget *parent = nullptr);
    ~ComponentsDialog();

public:
    ComponentRow selectedComponent() const;

signals:
    void componentSelected(const ComponentRow& row);

private slots:
    void onRefreshClicked();
    void onRemoveClicked();
    void onAddClicked();
    void onAddToSceneClicked();

private:
    void loadTable();

private:
    Ui::ComponentsDialog *ui;
    DatabaseManager* m_db;
};

#endif // COMPONENTSDIALOG_H
