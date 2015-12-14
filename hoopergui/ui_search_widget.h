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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
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
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_pioneers;
    QComboBox *comboBox_pioneers;
    QTableWidget *table_pioneers;
    QWidget *computers;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *table_computers;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_computers;
    QComboBox *comboBox_computers;
    QWidget *connections;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_connections;
    QComboBox *comboBox_connections;
    QTableWidget *table_connections;

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
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_pioneers = new QLineEdit(pioneers);
        lineEdit_pioneers->setObjectName(QStringLiteral("lineEdit_pioneers"));
        lineEdit_pioneers->setFrame(false);

        horizontalLayout->addWidget(lineEdit_pioneers);

        comboBox_pioneers = new QComboBox(pioneers);
        comboBox_pioneers->setObjectName(QStringLiteral("comboBox_pioneers"));

        horizontalLayout->addWidget(comboBox_pioneers);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        table_pioneers = new QTableWidget(pioneers);
        if (table_pioneers->columnCount() < 3)
            table_pioneers->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_pioneers->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_pioneers->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_pioneers->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        table_pioneers->setObjectName(QStringLiteral("table_pioneers"));
        table_pioneers->horizontalHeader()->setStretchLastSection(true);
        table_pioneers->verticalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(table_pioneers, 0, 0, 1, 1);

        tab_search->addTab(pioneers, QString());
        computers = new QWidget();
        computers->setObjectName(QStringLiteral("computers"));
        verticalLayout_4 = new QVBoxLayout(computers);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        table_computers = new QTableWidget(computers);
        table_computers->setObjectName(QStringLiteral("table_computers"));

        verticalLayout_4->addWidget(table_computers);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit_computers = new QLineEdit(computers);
        lineEdit_computers->setObjectName(QStringLiteral("lineEdit_computers"));
        lineEdit_computers->setFrame(false);

        horizontalLayout_2->addWidget(lineEdit_computers);

        comboBox_computers = new QComboBox(computers);
        comboBox_computers->setObjectName(QStringLiteral("comboBox_computers"));

        horizontalLayout_2->addWidget(comboBox_computers);


        verticalLayout_4->addLayout(horizontalLayout_2);

        tab_search->addTab(computers, QString());
        connections = new QWidget();
        connections->setObjectName(QStringLiteral("connections"));
        gridLayout_2 = new QGridLayout(connections);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit_connections = new QLineEdit(connections);
        lineEdit_connections->setObjectName(QStringLiteral("lineEdit_connections"));
        lineEdit_connections->setFrame(false);

        horizontalLayout_3->addWidget(lineEdit_connections);

        comboBox_connections = new QComboBox(connections);
        comboBox_connections->setObjectName(QStringLiteral("comboBox_connections"));

        horizontalLayout_3->addWidget(comboBox_connections);


        gridLayout_2->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        table_connections = new QTableWidget(connections);
        table_connections->setObjectName(QStringLiteral("table_connections"));

        gridLayout_2->addWidget(table_connections, 0, 0, 1, 1);

        tab_search->addTab(connections, QString());

        verticalLayout->addWidget(tab_search);


        retranslateUi(search_widget);

        tab_search->setCurrentIndex(0);


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
        QTableWidgetItem *___qtablewidgetitem = table_pioneers->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("search_widget", "First name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_pioneers->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("search_widget", "Last name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_pioneers->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("search_widget", "Gender", 0));
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
