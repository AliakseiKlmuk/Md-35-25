#include "componentsdialog.h"
#include "ui_componentsdialog.h"
#include "databasemanager.h"
#include "addcomponentdialog.h"

ComponentsDialog::ComponentsDialog(DatabaseManager* db, QWidget *parent) :
    QDialog(parent), ui(new Ui::ComponentsDialog), m_db(db)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(7);;
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "Visible name", "Type", "Nominal Value", "Manufactured", "Footprint", "Symbol"});
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    loadTable();

    connect(ui->refreshButton, &QPushButton::clicked,
            this, &ComponentsDialog::onRefreshClicked);
    connect(ui->removeButton, &QPushButton::clicked,
            this, &ComponentsDialog::onRemoveClicked);
    connect(ui->addButton, &QPushButton::clicked,
            this, &ComponentsDialog::onAddClicked);
}

ComponentsDialog::~ComponentsDialog()
{
    delete ui;
}

void ComponentsDialog::onRefreshClicked(){
    loadTable();
}
void ComponentsDialog::onRemoveClicked(){
    auto sel = ui->tableWidget->selectedItems();
    if(sel.isEmpty()){
        QMessageBox::information(this, "Remove", "Select a row first.");
        return;
    }
    int row = sel.first()->row();
    int componentId = ui->tableWidget->item(row, 0)->text().toInt();

    if(!m_db->removeComponent(componentId)){
        QMessageBox::warning(this, "Remove", "Filed to remove component.");
        return;
    }
    loadTable();
}

void ComponentsDialog::loadTable(){
    ui->tableWidget->clearContents();
    auto rows = m_db->loadAllComponents();
    ui->tableWidget->setRowCount(rows.size());

    for(int i = 0; i < rows.size(); ++i){
        const auto& r = rows[i];

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(r.component_id)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(r.visible_name));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(r.type_name));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(r.nominal_value));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(r.manufactured));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(r.footprint_id));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(r.symbol_id));
     }

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}

void ComponentsDialog::onAddClicked(){
    AddComponentDialog dlg(m_db, this);

    if(dlg.exec() == QDialog::Accepted){
        loadTable();
    }
}
