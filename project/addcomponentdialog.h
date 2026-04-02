#ifndef ADDCOMPONENTDIALOG_H
#define ADDCOMPONENTDIALOG_H

#include "databasemanager.h"

#include <QDialog>

namespace Ui {
class AddComponentDialog;
}

class AddComponentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddComponentDialog(DatabaseManager* db, QWidget *parent = nullptr);
    ~AddComponentDialog();

public:
    bool isOk() const {return m_ok;}

private slots:
    void onAccepted();

private:
    Ui::AddComponentDialog *ui;
    DatabaseManager* m_db = nullptr;
    bool m_ok = false;
};

#endif // ADDCOMPONENTDIALOG_H
