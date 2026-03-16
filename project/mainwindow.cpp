#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    setupToolBar();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setupToolBar(){
    toolBar = new QToolBar("Main Toolbar", this);
    addToolBar(toolBar);

    QAction *fileAction = new QAction("File", this);
    QMenu *fileMenu = new QMenu(this);

    QAction *newAction = new QAction("New", this);
    QAction *openAction = new QAction("Open", this);
    QAction *saveAction = new QAction("Save", this);
    QAction *exitAction = new QAction("Exit", this);

    connect(newAction, &QAction::triggered, [this](){
        QMessageBox::information(this, "Action", "New Action Triggered");
    });

    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);

    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(exitAction);

    fileAction->setMenu(fileMenu);
    toolBar->addAction(fileAction);

    toolBar->addSeparator();

    QMenu *actionsMenu = new QMenu("Actions", this);

    QAction *addButton = new QAction("Add Item", this);
    QAction *removeButton = new QAction("Remove Item", this);
    QAction *editButton = new QAction("Edit Item", this);

        connect(addButton, &QAction::triggered, [this](){
            QMessageBox::information(this, "Action", "Add Item Trigered");
        });
        connect(removeButton, &QAction::triggered, [this](){
            QMessageBox::information(this, "Action", "Remove Item Trigered");
        });
        connect(editButton, &QAction::triggered, [this]() {
            QMessageBox::information(this, "Action", "Edit Item Triggered");
     });

    actionsMenu->addAction(addButton);
    actionsMenu->addAction(removeButton);
    actionsMenu->addAction(editButton);

    toolBar->addAction(actionsMenu->menuAction());
    toolBar->addSeparator();

}


