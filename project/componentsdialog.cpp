#include "componentsdialog.h"
#include "ui_componentsdialog.h"

#include "databasemanager.h"

ComponentsDialog::ComponentsDialog(DatabaseManager* db, QWidget *parent) :
    QDialog(parent), ui(new Ui::ComponentsDialog), m_db(db)
{
    ui->setupUi(this);

    resize(800, 600);         // утснаовка размера окна
    setMinimumSize(800, 600);
    setMaximumSize(800,600);

    ui->tableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "Visible name", "Type", "Nominal Value", "Manufactured", "Footprint", "Symbol"});
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //выделение строки
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    loadTable();

    connect(ui->refreshButton, &QPushButton::clicked,
            this, &ComponentsDialog::onRefreshClicked);
    connect(ui->removeButton, &QPushButton::clicked,
            this, &ComponentsDialog::onRemoveClicked);
    connect(ui->addButton, &QPushButton::clicked,
            this, &ComponentsDialog::onAddClicked);
    connect(ui->addToSceneButton, &QPushButton::clicked,
            this, &ComponentsDialog::onAddToSceneClicked);
}

ComponentsDialog::~ComponentsDialog()
{
    delete ui;
}

void ComponentsDialog::onRefreshClicked(){
    loadTable();
}
void ComponentsDialog::onRemoveClicked(){
    int row = ui->tableWidget->currentRow();
    if(row < 0){
        QMessageBox::warning(this, "Remove", "No ID found for selected row.");
        return;
    }

    auto *idItem = ui->tableWidget->item(row, 0);
    if(!idItem){
        QMessageBox::warning(this, "Remove", "No ID found for selected row.");
        return;
    }

    int componentId = idItem->text().toInt();
    if(!m_db->removeComponent(componentId)){
        QMessageBox::warning(this, "Remove", "Failed to remove component.");
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
}

void ComponentsDialog::onAddClicked(){
    AddComponentDialog dlg(m_db, this);

    if(dlg.exec() == QDialog::Accepted){
        loadTable();
    }
}

void ComponentsDialog::onAddToSceneClicked(){
 int row = ui->tableWidget->currentRow();
 if (row < 0){
     QMessageBox::warning(this, "Select", "Please select a component.");
     return;
 }
 ComponentRow r = selectedComponent();

 emit componentSelected(r);
 accept();
}

ComponentRow ComponentsDialog::selectedComponent() const{
    ComponentRow r;
    int row = ui->tableWidget->currentRow();
    if(row < 0) return r;

    r.component_id = ui->tableWidget->item(row, 0)->text().toInt();
    r.visible_name = ui->tableWidget->item(row, 1)->text();
    r.type_name = ui->tableWidget->item(row, 2)->text();
    r.nominal_value = ui->tableWidget->item(row, 3)->text();
    r.manufactured = ui->tableWidget->item(row, 4)->text();
    r.footprint_id = ui->tableWidget->item(row, 5)->text();
    r.symbol_id = ui->tableWidget->item(row, 6)->text();

return r;
}

