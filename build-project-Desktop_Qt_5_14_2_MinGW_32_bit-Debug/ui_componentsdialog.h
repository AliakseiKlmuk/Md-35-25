/********************************************************************************
** Form generated from reading UI file 'componentsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPONENTSDIALOG_H
#define UI_COMPONENTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComponentsDialog
{
public:
    QTableWidget *tableWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *refreshButton;
    QPushButton *removeButton;
    QPushButton *addButton;

    void setupUi(QDialog *ComponentsDialog)
    {
        if (ComponentsDialog->objectName().isEmpty())
            ComponentsDialog->setObjectName(QString::fromUtf8("ComponentsDialog"));
        ComponentsDialog->resize(400, 300);
        tableWidget = new QTableWidget(ComponentsDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(5, 11, 391, 211));
        widget = new QWidget(ComponentsDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 240, 254, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        refreshButton = new QPushButton(widget);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));

        horizontalLayout->addWidget(refreshButton);

        removeButton = new QPushButton(widget);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        horizontalLayout->addWidget(removeButton);

        addButton = new QPushButton(widget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        horizontalLayout->addWidget(addButton);


        retranslateUi(ComponentsDialog);

        QMetaObject::connectSlotsByName(ComponentsDialog);
    } // setupUi

    void retranslateUi(QDialog *ComponentsDialog)
    {
        ComponentsDialog->setWindowTitle(QCoreApplication::translate("ComponentsDialog", "Dialog", nullptr));
        refreshButton->setText(QCoreApplication::translate("ComponentsDialog", "Refresh", nullptr));
        removeButton->setText(QCoreApplication::translate("ComponentsDialog", "Remove", nullptr));
        addButton->setText(QCoreApplication::translate("ComponentsDialog", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComponentsDialog: public Ui_ComponentsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPONENTSDIALOG_H
