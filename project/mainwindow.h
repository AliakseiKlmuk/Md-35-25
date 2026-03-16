#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QMessageBox>
#include <QMenuBar>
#include <QWidget>
#include <QToolButton>
#include <QHBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    void setupToolBar();
    void setupButtonPanel();

private:
    Ui::MainWindow *ui;

private:
    QToolBar *toolBar;

private:
    QWidget *buttonPanel;       // Панель с кнопками
    QToolButton *addButton;     // Кнопка добавить
    QToolButton *removeButton;  // Кнопка удалить
    QToolButton *editorButton;  // Кнопка для графического редактора


};
#endif // MAINWINDOW_H
