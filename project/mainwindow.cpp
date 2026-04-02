#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drawwidget.h"
#include "databasemanager.h"
#include "componentsdialog.h"
#include "placementscene.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
      ui->setupUi(this);
      setupToolBar();

      // --- База данных ---
      m_db = new DatabaseManager(this);
      m_db -> open("radio.db");
      m_db->initSchema();
      m_db->insertTestFootprintPins();

      // --- DrawWidget (верхний слой, только рисует) ---
      _draw = new DrawWidget(ui->centralwidget);
      _draw->setFixedSize(800, 600);
      _draw->setAttribute(Qt::WA_TranslucentBackground, true);
      _draw->setAttribute(Qt::WA_TransparentForMouseEvents, true);

      // --- QGraphicsView (нижний слой, перемещение) ---
      auto* view = new QGraphicsView(ui->centralwidget);
      view->setFixedSize(800,600);
      view->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

      m_scene = new PlacementScene(this);

      // --- Соединяем рисование ---
      connect(m_scene, &PlacementScene::drawLine,
              _draw, &DrawWidget::addLine);

      connect(m_scene, &PlacementScene::strokeFinished,
              _draw, &DrawWidget::finishStroke);

      // --- Переключение режима рисования ---
      connect(m_scene, &PlacementScene::footprintHover,
              this, [this](bool inside){
             _draw->setDrawingEnabled(!inside);});

      // --- Настройки view ---
      view->setScene(m_scene);
      view->setFrameShape(QFrame::NoFrame);
      view->setFrameShadow(QFrame::Plain);
      view->setDragMode(QGraphicsView::NoDrag);

      view->setStyleSheet("background: transparent;");    // прозрачность для view
      view->setAttribute(Qt::WA_TranslucentBackground, true);
      view->viewport()->setAutoFillBackground(false);

      view->setAlignment(Qt::AlignLeft | Qt::AlignTop);     // не было отступов за layout
      view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      view->setSceneRect(0, 0, 800, 600);

      view->setContentsMargins(0, 0, 0, 0);                    // масштабирование
      view->setResizeAnchor(QGraphicsView::AnchorViewCenter);
      view->setTransformationAnchor(QGraphicsView::AnchorViewCenter);

      // --- Расположение ---
      view->setGeometry(0, 0, 800, 600);
      view->raise();

      _draw->setGeometry(0, 0, 800, 600);
      _draw->raise();

      // --- Обновление ---
      view->viewport()->update();
      view->update();
      _draw->update();
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
        connect(&dlg, &ComponentsDialog::componentSelected,
                this, [this](const ComponentRow& comp){
            auto pins = m_db->loadFootprintPins(comp.footprint_id);

            for (auto& p : pins){
                qDebug() << p.x << p.y;
            }
            m_scene->addFootprint(pins);
        });

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


