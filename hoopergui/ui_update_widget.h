/********************************************************************************
** Form generated from reading UI file 'update_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATE_WIDGET_H
#define UI_UPDATE_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_update_widget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_update;

    void setupUi(QWidget *update_widget)
    {
        if (update_widget->objectName().isEmpty())
            update_widget->setObjectName(QStringLiteral("update_widget"));
        update_widget->resize(400, 300);
        verticalLayout = new QVBoxLayout(update_widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_update = new QLabel(update_widget);
        label_update->setObjectName(QStringLiteral("label_update"));
        label_update->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_update);


        retranslateUi(update_widget);

        QMetaObject::connectSlotsByName(update_widget);
    } // setupUi

    void retranslateUi(QWidget *update_widget)
    {
        update_widget->setWindowTitle(QApplication::translate("update_widget", "Form", 0));
        label_update->setText(QApplication::translate("update_widget", "update", 0));
    } // retranslateUi

};

namespace Ui {
    class update_widget: public Ui_update_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATE_WIDGET_H
