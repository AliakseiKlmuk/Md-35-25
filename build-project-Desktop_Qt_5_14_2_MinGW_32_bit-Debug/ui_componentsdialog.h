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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ComponentsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *refreshButton;
    QPushButton *removeButton;
    QPushButton *addToSceneButton;
    QPushButton *addButton;

    void setupUi(QDialog *ComponentsDialog)
    {
        if (ComponentsDialog->objectName().isEmpty())
            ComponentsDialog->setObjectName(QString::fromUtf8("ComponentsDialog"));
        ComponentsDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(ComponentsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(ComponentsDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        refreshButton = new QPushButton(ComponentsDialog);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));

        horizontalLayout->addWidget(refreshButton);

        removeButton = new QPushButton(ComponentsDialog);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        horizontalLayout->addWidget(removeButton);

        addToSceneButton = new QPushButton(ComponentsDialog);
        addToSceneButton->setObjectName(QString::fromUtf8("addToSceneButton"));

        horizontalLayout->addWidget(addToSceneButton);

        addButton = new QPushButton(ComponentsDialog);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        horizontalLayout->addWidget(addButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ComponentsDialog);

        QMetaObject::connectSlotsByName(ComponentsDialog);
    } // setupUi

    void retranslateUi(QDialog *ComponentsDialog)
    {
        ComponentsDialog->setWindowTitle(QCoreApplication::translate("ComponentsDialog", "Dialog", nullptr));
        refreshButton->setText(QCoreApplication::translate("ComponentsDialog", "Refresh", nullptr));
        removeButton->setText(QCoreApplication::translate("ComponentsDialog", "Remove", nullptr));
        addToSceneButton->setText(QCoreApplication::translate("ComponentsDialog", "Add to screen", nullptr));
        addButton->setText(QCoreApplication::translate("ComponentsDialog", "Add ot memory", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComponentsDialog: public Ui_ComponentsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPONENTSDIALOG_H
