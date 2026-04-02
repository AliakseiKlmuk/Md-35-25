#include "addcomponentdialog.h"
#include "ui_addcomponentdialog.h"
#include "databasemanager.h"

AddComponentDialog::AddComponentDialog(DatabaseManager* db, QWidget *parent) :
    QDialog(parent), ui(new Ui::AddComponentDialog), m_db(db)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted,
            this, &AddComponentDialog::onAccepted);

    connect(ui->buttonBox, &QDialogButtonBox::rejected,
            this, &QDialog::reject);
}

AddComponentDialog::~AddComponentDialog()
{
    delete ui;
}

void AddComponentDialog::onAccepted(){
    if (!m_db){
        m_ok = false;
        return;
    }

    ComponentRow r;
    r.visible_name = ui->visible_name->text().trimmed();
    r.type_name = ui->type_name->text().trimmed();
    r.nominal_value = ui->nominal_value->text().trimmed();
    r.manufactured = ui->manufactured->text().trimmed();
    r.footprint_id = ui->footprint_id->text().trimmed();
    r.symbol_id = ui->symbol_id->text().trimmed();

    if(r.visible_name.isEmpty() || r.type_name.isEmpty() ||r.footprint_id.isEmpty()){
        m_ok = false;
        QDialog::reject();
        return;
    }

    m_ok = m_db->addComponent(r);
    if (m_ok){
        QDialog::accept();
    } else{
        QDialog::reject();
    }
}
