#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drawwidget.h"
#include "databasemanager.h"
#include "componentsdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
      ui->setupUi(this);
      setupToolBar();

      _draw = new DrawWidget(ui->centralwidget);
      auto* layout = ui->centralwidget->layout();
      if(!layout){
          layout = new QVBoxLayout(ui->centralwidget);
      }
      layout->addWidget(_draw);

      m_db = new DatabaseManager(this);
      m_db -> open("radio.db");
      m_db -> initSchema();
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

    QAction *connectAction = new QAction("Connect", this);
    QAction *addAction = new QAction("Add element", this);
    QAction *undoAction = new QAction("Clear last", this);
    QAction *clearAction = new QAction("Clear all", this);

    connect(connectAction, &QAction::triggered, [this](){
        QMessageBox::information(this, "Action", "Connect");
        });
    connect(addAction, &QAction::triggered, this, [this](){
        if (!m_db) return;
        ComponentsDialog dlg(m_db, this);
            dlg.exec();
        });
    connect(undoAction, &QAction::triggered, [this]() {
            if(_draw) {_draw->undoLast();}
        });
    connect(clearAction, &QAction::triggered, [this]() {
            if(_draw) {_draw->clearAll();}
        });

    actionsMenu->addAction(connectAction);
    actionsMenu->addAction(addAction);
    actionsMenu->addAction(undoAction);
    actionsMenu->addAction(clearAction);

    toolBar->addAction(actionsMenu->menuAction());
    toolBar->addSeparator();

}


