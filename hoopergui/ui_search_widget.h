/********************************************************************************
** Form generated from reading UI file 'search_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_WIDGET_H
#define UI_SEARCH_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_search_widget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tab_search;
    QWidget *pioneers;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_pioneers;
    QTableView *tableView_pioneers;
    QWidget *computers;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_computers;
    QTableView *tableView_computers;
    QWidget *connections;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_connections;
    QTableView *tableView_connections;

    void setupUi(QWidget *search_widget)
    {
        if (search_widget->objectName().isEmpty())
            search_widget->setObjectName(QStringLiteral("search_widget"));
        search_widget->resize(427, 300);
        verticalLayout = new QVBoxLayout(search_widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tab_search = new QTabWidget(search_widget);
        tab_search->setObjectName(QStringLiteral("tab_search"));
        tab_search->setFocusPolicy(Qt::TabFocus);
        tab_search->setContextMenuPolicy(Qt::NoContextMenu);
        tab_search->setTabShape(QTabWidget::Triangular);
        pioneers = new QWidget();
        pioneers->setObjectName(QStringLiteral("pioneers"));
        gridLayout = new QGridLayout(pioneers);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_pioneers = new QLineEdit(pioneers);
        lineEdit_pioneers->setObjectName(QStringLiteral("lineEdit_pioneers"));
        lineEdit_pioneers->setFrame(false);

        gridLayout->addWidget(lineEdit_pioneers, 0, 0, 1, 1);

        tableView_pioneers = new QTableView(pioneers);
        tableView_pioneers->setObjectName(QStringLiteral("tableView_pioneers"));
        tableView_pioneers->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(tableView_pioneers, 1, 0, 1, 1);

        tab_search->addTab(pioneers, QString());
        computers = new QWidget();
        computers->setObjectName(QStringLiteral("computers"));
        verticalLayout_4 = new QVBoxLayout(computers);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lineEdit_computers = new QLineEdit(computers);
        lineEdit_computers->setObjectName(QStringLiteral("lineEdit_computers"));
        lineEdit_computers->setFrame(false);

        verticalLayout_4->addWidget(lineEdit_computers);

        tableView_computers = new QTableView(computers);
        tableView_computers->setObjectName(QStringLiteral("tableView_computers"));
        tableView_computers->setFrameShape(QFrame::NoFrame);

        verticalLayout_4->addWidget(tableView_computers);

        tab_search->addTab(computers, QString());
        connections = new QWidget();
        connections->setObjectName(QStringLiteral("connections"));
        gridLayout_2 = new QGridLayout(connections);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lineEdit_connections = new QLineEdit(connections);
        lineEdit_connections->setObjectName(QStringLiteral("lineEdit_connections"));
        lineEdit_connections->setFrame(false);

        gridLayout_2->addWidget(lineEdit_connections, 0, 0, 1, 1);

        tableView_connections = new QTableView(connections);
        tableView_connections->setObjectName(QStringLiteral("tableView_connections"));
        tableView_connections->setFrameShape(QFrame::NoFrame);

        gridLayout_2->addWidget(tableView_connections, 1, 0, 1, 1);

        tab_search->addTab(connections, QString());

        verticalLayout->addWidget(tab_search);


        retranslateUi(search_widget);

        tab_search->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(search_widget);
    } // setupUi

    void retranslateUi(QWidget *search_widget)
    {
        search_widget->setWindowTitle(QApplication::translate("search_widget", "Form", 0));
#ifndef QT_NO_TOOLTIP
        tab_search->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lineEdit_pioneers->setText(QString());
        lineEdit_pioneers->setPlaceholderText(QApplication::translate("search_widget", "Search pioneers...", 0));
        tab_search->setTabText(tab_search->indexOf(pioneers), QApplication::translate("search_widget", "Pioneers", 0));
        lineEdit_computers->setPlaceholderText(QApplication::translate("search_widget", "search computers...", 0));
        tab_search->setTabText(tab_search->indexOf(computers), QApplication::translate("search_widget", "Computers", 0));
        lineEdit_connections->setPlaceholderText(QApplication::translate("search_widget", "Search connections...", 0));
        tab_search->setTabText(tab_search->indexOf(connections), QApplication::translate("search_widget", "Connections", 0));
    } // retranslateUi

};

namespace Ui {
    class search_widget: public Ui_search_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_WIDGET_H
