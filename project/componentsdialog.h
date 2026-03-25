#ifndef COMPONENTSDIALOG_H
#define COMPONENTSDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>
#include <QMessageBox>

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

private slots:
    void onRefreshClicked();
    void onRemoveClicked();
    void onAddClicked();

private:
    void loadTable();

private:
    Ui::ComponentsDialog *ui;
    DatabaseManager* m_db;
};

#endif // COMPONENTSDIALOG_H
