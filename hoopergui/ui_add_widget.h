/********************************************************************************
** Form generated from reading UI file 'add_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_WIDGET_H
#define UI_ADD_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add_widget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_add;

    void setupUi(QWidget *add_widget)
    {
        if (add_widget->objectName().isEmpty())
            add_widget->setObjectName(QStringLiteral("add_widget"));
        add_widget->resize(400, 300);
        verticalLayout = new QVBoxLayout(add_widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_add = new QLabel(add_widget);
        label_add->setObjectName(QStringLiteral("label_add"));
        label_add->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_add);


        retranslateUi(add_widget);

        QMetaObject::connectSlotsByName(add_widget);
    } // setupUi

    void retranslateUi(QWidget *add_widget)
    {
        add_widget->setWindowTitle(QApplication::translate("add_widget", "Form", 0));
        label_add->setText(QApplication::translate("add_widget", "add", 0));
    } // retranslateUi

};

namespace Ui {
    class add_widget: public Ui_add_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_WIDGET_H
