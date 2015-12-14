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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_hooper;
    QPushButton *button_view_database;
    QPushButton *button_search_database;
    QPushButton *button_add_database;
    QPushButton *button_discover;
    QPushButton *button_update;
    QPushButton *button_removefrom_database;
    QPushButton *button_about;
    QStackedWidget *stack_widget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 550);
        MainWindow->setMinimumSize(QSize(0, 0));
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
        groupBox_hooper->setAlignment(Qt::AlignCenter);
        groupBox_hooper->setFlat(false);
        button_view_database = new QPushButton(groupBox_hooper);
        button_view_database->setObjectName(QStringLiteral("button_view_database"));
        button_view_database->setGeometry(QRect(-8, 50, 91, 35));
        QFont font;
        font.setPointSize(16);
        button_view_database->setFont(font);
        button_view_database->setFlat(true);
        button_search_database = new QPushButton(groupBox_hooper);
        button_search_database->setObjectName(QStringLiteral("button_search_database"));
        button_search_database->setGeometry(QRect(-8, 170, 91, 35));
        button_search_database->setFont(font);
        button_search_database->setFlat(true);
        button_add_database = new QPushButton(groupBox_hooper);
        button_add_database->setObjectName(QStringLiteral("button_add_database"));
        button_add_database->setGeometry(QRect(-8, 110, 91, 35));
        button_add_database->setFont(font);
        button_add_database->setFlat(true);
        button_discover = new QPushButton(groupBox_hooper);
        button_discover->setObjectName(QStringLiteral("button_discover"));
        button_discover->setGeometry(QRect(-10, 290, 91, 35));
        button_discover->setFont(font);
        button_discover->setFlat(true);
        button_update = new QPushButton(groupBox_hooper);
        button_update->setObjectName(QStringLiteral("button_update"));
        button_update->setGeometry(QRect(-10, 350, 86, 35));
        button_update->setFont(font);
        button_update->setFlat(true);
        button_removefrom_database = new QPushButton(groupBox_hooper);
        button_removefrom_database->setObjectName(QStringLiteral("button_removefrom_database"));
        button_removefrom_database->setGeometry(QRect(-8, 230, 91, 35));
        button_removefrom_database->setFont(font);
        button_removefrom_database->setFlat(true);
        button_about = new QPushButton(groupBox_hooper);
        button_about->setObjectName(QStringLiteral("button_about"));
        button_about->setGeometry(QRect(-10, 410, 86, 35));
        button_about->setFont(font);
        button_about->setFlat(true);

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
        button_search_database->setText(QApplication::translate("MainWindow", "Search", 0));
        button_add_database->setText(QApplication::translate("MainWindow", "Add", 0));
        button_discover->setText(QApplication::translate("MainWindow", "Discover", 0));
        button_update->setText(QApplication::translate("MainWindow", "Update", 0));
        button_removefrom_database->setText(QApplication::translate("MainWindow", "Remove", 0));
        button_about->setText(QApplication::translate("MainWindow", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
