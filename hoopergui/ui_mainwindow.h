/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_hooper;
    QVBoxLayout *verticalLayout;
    QPushButton *button_view_database;
    QPushButton *button_add_database;
    QPushButton *button_update;
    QPushButton *button_discover;
    QPushButton *button_about;
    QStackedWidget *stack_widget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1250, 700);
        MainWindow->setMinimumSize(QSize(800, 500));
        MainWindow->setDockNestingEnabled(false);
        MainWindow->setDockOptions(QMainWindow::AnimatedDocks);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_hooper = new QGroupBox(centralWidget);
        groupBox_hooper->setObjectName(QStringLiteral("groupBox_hooper"));
        groupBox_hooper->setMaximumSize(QSize(16777215, 800));
        groupBox_hooper->setAlignment(Qt::AlignCenter);
        groupBox_hooper->setFlat(false);
        verticalLayout = new QVBoxLayout(groupBox_hooper);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        button_view_database = new QPushButton(groupBox_hooper);
        button_view_database->setObjectName(QStringLiteral("button_view_database"));
        QFont font;
        font.setPointSize(16);
        button_view_database->setFont(font);
        button_view_database->setFlat(true);

        verticalLayout->addWidget(button_view_database);

        button_add_database = new QPushButton(groupBox_hooper);
        button_add_database->setObjectName(QStringLiteral("button_add_database"));
        button_add_database->setFont(font);
        button_add_database->setFlat(true);

        verticalLayout->addWidget(button_add_database);

        button_update = new QPushButton(groupBox_hooper);
        button_update->setObjectName(QStringLiteral("button_update"));
        button_update->setFont(font);
        button_update->setFlat(true);

        verticalLayout->addWidget(button_update);

        button_discover = new QPushButton(groupBox_hooper);
        button_discover->setObjectName(QStringLiteral("button_discover"));
        button_discover->setFont(font);
        button_discover->setFlat(true);

        verticalLayout->addWidget(button_discover);

        button_about = new QPushButton(groupBox_hooper);
        button_about->setObjectName(QStringLiteral("button_about"));
        button_about->setFont(font);
        button_about->setFlat(true);

        verticalLayout->addWidget(button_about);


        horizontalLayout->addWidget(groupBox_hooper);

        stack_widget = new QStackedWidget(centralWidget);
        stack_widget->setObjectName(QStringLiteral("stack_widget"));

        horizontalLayout->addWidget(stack_widget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stack_widget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Hooper", 0));
        groupBox_hooper->setTitle(QApplication::translate("MainWindow", "Hooper   ", 0));
        button_view_database->setText(QApplication::translate("MainWindow", "View", 0));
        button_add_database->setText(QApplication::translate("MainWindow", "Add", 0));
        button_update->setText(QApplication::translate("MainWindow", "Update", 0));
        button_discover->setText(QApplication::translate("MainWindow", "Discover", 0));
        button_about->setText(QApplication::translate("MainWindow", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
