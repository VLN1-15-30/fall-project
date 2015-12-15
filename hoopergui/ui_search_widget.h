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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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
    QTableWidget *table_pioneers;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_pioneers;
    QComboBox *comboBox_pioneers;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_remove_Pioneer;
    QLabel *label_removePioneer;
    QComboBox *comboBox_OrderPerson;
    QWidget *computers;
    QVBoxLayout *verticalLayout_4;
    QComboBox *comboBox_OrderComputers;
    QTableWidget *table_computers;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_computers;
    QComboBox *comboBox_computers;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_remove_computer;
    QLabel *label_remove_computer;
    QWidget *connections;
    QGridLayout *gridLayout_2;
    QTableWidget *table_connections;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_remove_connection;
    QLabel *label_remove_conneciton;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_connections;
    QComboBox *comboBox_connections;
    QComboBox *comboBox_OrderConnection;

    void setupUi(QWidget *search_widget)
    {
        if (search_widget->objectName().isEmpty())
            search_widget->setObjectName(QStringLiteral("search_widget"));
        search_widget->resize(671, 325);
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
        table_pioneers = new QTableWidget(pioneers);
        if (table_pioneers->columnCount() < 5)
            table_pioneers->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_pioneers->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_pioneers->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_pioneers->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_pioneers->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_pioneers->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        table_pioneers->setObjectName(QStringLiteral("table_pioneers"));
        table_pioneers->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::EditKeyPressed);
        table_pioneers->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_pioneers->setSortingEnabled(false);
        table_pioneers->horizontalHeader()->setStretchLastSection(true);
        table_pioneers->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(table_pioneers, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_pioneers = new QLineEdit(pioneers);
        lineEdit_pioneers->setObjectName(QStringLiteral("lineEdit_pioneers"));
        lineEdit_pioneers->setFrame(false);

        horizontalLayout->addWidget(lineEdit_pioneers);

        comboBox_pioneers = new QComboBox(pioneers);
        comboBox_pioneers->setObjectName(QStringLiteral("comboBox_pioneers"));

        horizontalLayout->addWidget(comboBox_pioneers);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_remove_Pioneer = new QPushButton(pioneers);
        pushButton_remove_Pioneer->setObjectName(QStringLiteral("pushButton_remove_Pioneer"));
        pushButton_remove_Pioneer->setEnabled(false);

        horizontalLayout_4->addWidget(pushButton_remove_Pioneer);

        label_removePioneer = new QLabel(pioneers);
        label_removePioneer->setObjectName(QStringLiteral("label_removePioneer"));

        horizontalLayout_4->addWidget(label_removePioneer);


        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 1);

        comboBox_OrderPerson = new QComboBox(pioneers);
        comboBox_OrderPerson->setObjectName(QStringLiteral("comboBox_OrderPerson"));

        gridLayout->addWidget(comboBox_OrderPerson, 0, 0, 1, 1, Qt::AlignRight);

        tab_search->addTab(pioneers, QString());
        computers = new QWidget();
        computers->setObjectName(QStringLiteral("computers"));
        verticalLayout_4 = new QVBoxLayout(computers);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        comboBox_OrderComputers = new QComboBox(computers);
        comboBox_OrderComputers->setObjectName(QStringLiteral("comboBox_OrderComputers"));

        verticalLayout_4->addWidget(comboBox_OrderComputers, 0, Qt::AlignRight);

        table_computers = new QTableWidget(computers);
        if (table_computers->columnCount() < 4)
            table_computers->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_computers->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_computers->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_computers->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table_computers->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        table_computers->setObjectName(QStringLiteral("table_computers"));
        table_computers->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_computers->horizontalHeader()->setStretchLastSection(true);
        table_computers->verticalHeader()->setStretchLastSection(false);

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

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_remove_computer = new QPushButton(computers);
        pushButton_remove_computer->setObjectName(QStringLiteral("pushButton_remove_computer"));
        pushButton_remove_computer->setEnabled(false);

        horizontalLayout_5->addWidget(pushButton_remove_computer);

        label_remove_computer = new QLabel(computers);
        label_remove_computer->setObjectName(QStringLiteral("label_remove_computer"));

        horizontalLayout_5->addWidget(label_remove_computer);


        verticalLayout_4->addLayout(horizontalLayout_5);

        tab_search->addTab(computers, QString());
        connections = new QWidget();
        connections->setObjectName(QStringLiteral("connections"));
        gridLayout_2 = new QGridLayout(connections);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        table_connections = new QTableWidget(connections);
        if (table_connections->columnCount() < 4)
            table_connections->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table_connections->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table_connections->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table_connections->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table_connections->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        table_connections->setObjectName(QStringLiteral("table_connections"));

        table_connections->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::EditKeyPressed);
        table_connections->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_connections->horizontalHeader()->setStretchLastSection(true);
        table_connections->verticalHeader()->setStretchLastSection(false);

        gridLayout_2->addWidget(table_connections, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButton_remove_connection = new QPushButton(connections);
        pushButton_remove_connection->setObjectName(QStringLiteral("pushButton_remove_connection"));
        pushButton_remove_connection->setEnabled(false);

        horizontalLayout_6->addWidget(pushButton_remove_connection);

        label_remove_conneciton = new QLabel(connections);
        label_remove_conneciton->setObjectName(QStringLiteral("label_remove_conneciton"));

        horizontalLayout_6->addWidget(label_remove_conneciton);


        gridLayout_2->addLayout(horizontalLayout_6, 5, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit_connections = new QLineEdit(connections);
        lineEdit_connections->setObjectName(QStringLiteral("lineEdit_connections"));
        lineEdit_connections->setFrame(false);

        horizontalLayout_3->addWidget(lineEdit_connections);

        comboBox_connections = new QComboBox(connections);
        comboBox_connections->setObjectName(QStringLiteral("comboBox_connections"));

        horizontalLayout_3->addWidget(comboBox_connections);


        gridLayout_2->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        comboBox_OrderConnection = new QComboBox(connections);
        comboBox_OrderConnection->setObjectName(QStringLiteral("comboBox_OrderConnection"));

        gridLayout_2->addWidget(comboBox_OrderConnection, 0, 0, 1, 1, Qt::AlignRight);

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
        QTableWidgetItem *___qtablewidgetitem = table_pioneers->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("search_widget", "First name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_pioneers->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("search_widget", "Last name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_pioneers->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("search_widget", "Gender", 0));
        QTableWidgetItem *___qtablewidgetitem3 = table_pioneers->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("search_widget", "Year born", 0));
        QTableWidgetItem *___qtablewidgetitem4 = table_pioneers->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("search_widget", "Year died", 0));
        lineEdit_pioneers->setText(QString());
        lineEdit_pioneers->setPlaceholderText(QApplication::translate("search_widget", "Search pioneers...", 0));
        pushButton_remove_Pioneer->setText(QApplication::translate("search_widget", "Remove", 0));
        label_removePioneer->setText(QApplication::translate("search_widget", "Select a row to remove a pionner from the database", 0));
        tab_search->setTabText(tab_search->indexOf(pioneers), QApplication::translate("search_widget", "Pioneers", 0));
        QTableWidgetItem *___qtablewidgetitem5 = table_computers->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("search_widget", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem6 = table_computers->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("search_widget", "Type", 0));
        QTableWidgetItem *___qtablewidgetitem7 = table_computers->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("search_widget", "Year made", 0));
        QTableWidgetItem *___qtablewidgetitem8 = table_computers->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("search_widget", "Was made", 0));
        lineEdit_computers->setPlaceholderText(QApplication::translate("search_widget", "search computers...", 0));
        pushButton_remove_computer->setText(QApplication::translate("search_widget", "Remove", 0));
        label_remove_computer->setText(QApplication::translate("search_widget", "Select a row to remove a computer from the database", 0));
        tab_search->setTabText(tab_search->indexOf(computers), QApplication::translate("search_widget", "Computers", 0));
        QTableWidgetItem *___qtablewidgetitem9 = table_connections->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("search_widget", "First name", 0));
        QTableWidgetItem *___qtablewidgetitem10 = table_connections->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("search_widget", "Last name", 0));
        QTableWidgetItem *___qtablewidgetitem11 = table_connections->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QApplication::translate("search_widget", "Computer", 0));
        QTableWidgetItem *___qtablewidgetitem12 = table_connections->horizontalHeaderItem(3);
        ___qtablewidgetitem12->setText(QApplication::translate("search_widget", "Year Invented", 0));
        pushButton_remove_connection->setText(QApplication::translate("search_widget", "PushButton", 0));
        label_remove_conneciton->setText(QApplication::translate("search_widget", "Select a row to remove a connection from the database", 0));
        lineEdit_connections->setPlaceholderText(QApplication::translate("search_widget", "Search connections...", 0));
        tab_search->setTabText(tab_search->indexOf(connections), QApplication::translate("search_widget", "Connections", 0));
    } // retranslateUi

};

namespace Ui {
    class search_widget: public Ui_search_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_WIDGET_H
