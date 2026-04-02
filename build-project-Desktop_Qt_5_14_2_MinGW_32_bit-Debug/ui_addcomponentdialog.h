/********************************************************************************
** Form generated from reading UI file 'addcomponentdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOMPONENTDIALOG_H
#define UI_ADDCOMPONENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddComponentDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *visible_name;
    QLineEdit *type_name;
    QLineEdit *nominal_value;
    QLineEdit *manufactured;
    QLineEdit *footprint_id;
    QLineEdit *symbol_id;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *visible_name_2;
    QLabel *type_name_2;
    QLabel *nominal_value_2;
    QLabel *manufactured_2;
    QLabel *footprint_id_2;
    QLabel *symbol_id_2;

    void setupUi(QDialog *AddComponentDialog)
    {
        if (AddComponentDialog->objectName().isEmpty())
            AddComponentDialog->setObjectName(QString::fromUtf8("AddComponentDialog"));
        AddComponentDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddComponentDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(80, 210, 171, 22));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(AddComponentDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 20, 93, 164));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        visible_name = new QLineEdit(widget);
        visible_name->setObjectName(QString::fromUtf8("visible_name"));

        verticalLayout->addWidget(visible_name);

        type_name = new QLineEdit(widget);
        type_name->setObjectName(QString::fromUtf8("type_name"));

        verticalLayout->addWidget(type_name);

        nominal_value = new QLineEdit(widget);
        nominal_value->setObjectName(QString::fromUtf8("nominal_value"));

        verticalLayout->addWidget(nominal_value);

        manufactured = new QLineEdit(widget);
        manufactured->setObjectName(QString::fromUtf8("manufactured"));

        verticalLayout->addWidget(manufactured);

        footprint_id = new QLineEdit(widget);
        footprint_id->setObjectName(QString::fromUtf8("footprint_id"));

        verticalLayout->addWidget(footprint_id);

        symbol_id = new QLineEdit(widget);
        symbol_id->setObjectName(QString::fromUtf8("symbol_id"));

        verticalLayout->addWidget(symbol_id);

        widget1 = new QWidget(AddComponentDialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(190, 20, 81, 161));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        visible_name_2 = new QLabel(widget1);
        visible_name_2->setObjectName(QString::fromUtf8("visible_name_2"));

        verticalLayout_2->addWidget(visible_name_2);

        type_name_2 = new QLabel(widget1);
        type_name_2->setObjectName(QString::fromUtf8("type_name_2"));

        verticalLayout_2->addWidget(type_name_2);

        nominal_value_2 = new QLabel(widget1);
        nominal_value_2->setObjectName(QString::fromUtf8("nominal_value_2"));

        verticalLayout_2->addWidget(nominal_value_2);

        manufactured_2 = new QLabel(widget1);
        manufactured_2->setObjectName(QString::fromUtf8("manufactured_2"));

        verticalLayout_2->addWidget(manufactured_2);

        footprint_id_2 = new QLabel(widget1);
        footprint_id_2->setObjectName(QString::fromUtf8("footprint_id_2"));

        verticalLayout_2->addWidget(footprint_id_2);

        symbol_id_2 = new QLabel(widget1);
        symbol_id_2->setObjectName(QString::fromUtf8("symbol_id_2"));

        verticalLayout_2->addWidget(symbol_id_2);


        retranslateUi(AddComponentDialog);

        QMetaObject::connectSlotsByName(AddComponentDialog);
    } // setupUi

    void retranslateUi(QDialog *AddComponentDialog)
    {
        AddComponentDialog->setWindowTitle(QCoreApplication::translate("AddComponentDialog", "Dialog", nullptr));
        visible_name_2->setText(QCoreApplication::translate("AddComponentDialog", "Name", nullptr));
        type_name_2->setText(QCoreApplication::translate("AddComponentDialog", "Type", nullptr));
        nominal_value_2->setText(QCoreApplication::translate("AddComponentDialog", "Nominal", nullptr));
        manufactured_2->setText(QCoreApplication::translate("AddComponentDialog", "Manufactured", nullptr));
        footprint_id_2->setText(QCoreApplication::translate("AddComponentDialog", "Footprint", nullptr));
        symbol_id_2->setText(QCoreApplication::translate("AddComponentDialog", "Symbol", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddComponentDialog: public Ui_AddComponentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMPONENTDIALOG_H
