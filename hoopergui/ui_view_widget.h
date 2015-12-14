/********************************************************************************
** Form generated from reading UI file 'view_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_WIDGET_H
#define UI_VIEW_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_view_widget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_view;

    void setupUi(QWidget *view_widget)
    {
        if (view_widget->objectName().isEmpty())
            view_widget->setObjectName(QStringLiteral("view_widget"));
        view_widget->resize(400, 300);
        verticalLayout = new QVBoxLayout(view_widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_view = new QLabel(view_widget);
        label_view->setObjectName(QStringLiteral("label_view"));
        label_view->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_view);


        retranslateUi(view_widget);

        QMetaObject::connectSlotsByName(view_widget);
    } // setupUi

    void retranslateUi(QWidget *view_widget)
    {
        view_widget->setWindowTitle(QApplication::translate("view_widget", "Form", 0));
        label_view->setText(QApplication::translate("view_widget", "View", 0));
    } // retranslateUi

};

namespace Ui {
    class view_widget: public Ui_view_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_WIDGET_H
