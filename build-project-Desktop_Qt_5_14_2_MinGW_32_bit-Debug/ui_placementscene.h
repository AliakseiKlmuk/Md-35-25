/********************************************************************************
** Form generated from reading UI file 'placementscene.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLACEMENTSCENE_H
#define UI_PLACEMENTSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_PlacementScene
{
public:
    QTableWidget *tableWidget;

    void setupUi(QDialog *PlacementScene)
    {
        if (PlacementScene->objectName().isEmpty())
            PlacementScene->setObjectName(QString::fromUtf8("PlacementScene"));
        PlacementScene->resize(400, 300);
        tableWidget = new QTableWidget(PlacementScene);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(50, 30, 256, 192));

        retranslateUi(PlacementScene);

        QMetaObject::connectSlotsByName(PlacementScene);
    } // setupUi

    void retranslateUi(QDialog *PlacementScene)
    {
        PlacementScene->setWindowTitle(QCoreApplication::translate("PlacementScene", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlacementScene: public Ui_PlacementScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLACEMENTSCENE_H
