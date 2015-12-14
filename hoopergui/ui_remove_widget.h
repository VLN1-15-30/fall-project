/********************************************************************************
** Form generated from reading UI file 'remove_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVE_WIDGET_H
#define UI_REMOVE_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_remove_widget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_remove;

    void setupUi(QWidget *remove_widget)
    {
        if (remove_widget->objectName().isEmpty())
            remove_widget->setObjectName(QStringLiteral("remove_widget"));
        remove_widget->resize(400, 300);
        verticalLayout = new QVBoxLayout(remove_widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_remove = new QLabel(remove_widget);
        label_remove->setObjectName(QStringLiteral("label_remove"));
        label_remove->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_remove);


        retranslateUi(remove_widget);

        QMetaObject::connectSlotsByName(remove_widget);
    } // setupUi

    void retranslateUi(QWidget *remove_widget)
    {
        remove_widget->setWindowTitle(QApplication::translate("remove_widget", "Form", 0));
        label_remove->setText(QApplication::translate("remove_widget", "remove", 0));
    } // retranslateUi

};

namespace Ui {
    class remove_widget: public Ui_remove_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVE_WIDGET_H
