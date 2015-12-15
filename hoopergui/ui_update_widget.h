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

class Ui_update_widget
{
public:
    QGridLayout *gridLayout_4;
    QTabWidget *updateTabs;
    QWidget *pioneer;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *tableView_pioneers_2;
    QLabel *label_2;
    QWidget *computers;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_info_update;
    QTableWidget *tableView_computers_2;
    QWidget *connections;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QTableWidget *tableView_connections_2;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *computerName;
    QLineEdit *firstName;
    QLineEdit *lastName;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *updateComputer;
    QPushButton *updateConnection;

    void setupUi(QWidget *update_widget)
    {
        if (update_widget->objectName().isEmpty())
            update_widget->setObjectName(QStringLiteral("update_widget"));
        update_widget->resize(637, 448);
        gridLayout_4 = new QGridLayout(update_widget);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        updateTabs = new QTabWidget(update_widget);
        updateTabs->setObjectName(QStringLiteral("updateTabs"));
        updateTabs->setTabShape(QTabWidget::Triangular);
        pioneer = new QWidget();
        pioneer->setObjectName(QStringLiteral("pioneer"));
        gridLayout_5 = new QGridLayout(pioneer);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));

        gridLayout_5->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        tableView_pioneers_2 = new QTableWidget(pioneer);
        if (tableView_pioneers_2->columnCount() < 6)
            tableView_pioneers_2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableView_pioneers_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableView_pioneers_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableView_pioneers_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableView_pioneers_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableView_pioneers_2->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableView_pioneers_2->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableView_pioneers_2->setObjectName(QStringLiteral("tableView_pioneers_2"));
        tableView_pioneers_2->setSortingEnabled(true);
        tableView_pioneers_2->horizontalHeader()->setStretchLastSection(true);
        tableView_pioneers_2->verticalHeader()->setStretchLastSection(false);

        gridLayout_5->addWidget(tableView_pioneers_2, 1, 0, 1, 1);

        label_2 = new QLabel(pioneer);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_5->addWidget(label_2, 0, 0, 1, 1);

        updateTabs->addTab(pioneer, QString());
        computers = new QWidget();
        computers->setObjectName(QStringLiteral("computers"));
        verticalLayout_3 = new QVBoxLayout(computers);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_info_update = new QLabel(computers);
        label_info_update->setObjectName(QStringLiteral("label_info_update"));

        verticalLayout_3->addWidget(label_info_update);

        tableView_computers_2 = new QTableWidget(computers);
        if (tableView_computers_2->columnCount() < 5)
            tableView_computers_2->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableView_computers_2->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableView_computers_2->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableView_computers_2->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableView_computers_2->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableView_computers_2->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        tableView_computers_2->setObjectName(QStringLiteral("tableView_computers_2"));
        tableView_computers_2->setSortingEnabled(true);
        tableView_computers_2->horizontalHeader()->setStretchLastSection(true);
        tableView_computers_2->verticalHeader()->setStretchLastSection(false);

        verticalLayout_3->addWidget(tableView_computers_2);

        updateTabs->addTab(computers, QString());
        connections = new QWidget();
        connections->setObjectName(QStringLiteral("connections"));
        verticalLayout_2 = new QVBoxLayout(connections);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(connections);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        tableView_connections_2 = new QTableWidget(connections);
        if (tableView_connections_2->columnCount() < 6)
            tableView_connections_2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableView_connections_2->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableView_connections_2->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableView_connections_2->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableView_connections_2->setHorizontalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableView_connections_2->setHorizontalHeaderItem(4, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableView_connections_2->setHorizontalHeaderItem(5, __qtablewidgetitem16);
        tableView_connections_2->setObjectName(QStringLiteral("tableView_connections_2"));
        tableView_connections_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_connections_2->setSortingEnabled(true);
        tableView_connections_2->horizontalHeader()->setStretchLastSection(true);
        tableView_connections_2->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableView_connections_2->verticalHeader()->setStretchLastSection(false);

        verticalLayout_2->addWidget(tableView_connections_2);

        label_7 = new QLabel(connections);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(connections);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        label_5 = new QLabel(connections);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        label_4 = new QLabel(connections);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        computerName = new QLineEdit(connections);
        computerName->setObjectName(QStringLiteral("computerName"));

        horizontalLayout->addWidget(computerName);

        firstName = new QLineEdit(connections);
        firstName->setObjectName(QStringLiteral("firstName"));

        horizontalLayout->addWidget(firstName);

        lastName = new QLineEdit(connections);
        lastName->setObjectName(QStringLiteral("lastName"));

        horizontalLayout->addWidget(lastName);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        updateComputer = new QPushButton(connections);
        updateComputer->setObjectName(QStringLiteral("updateComputer"));

        horizontalLayout_4->addWidget(updateComputer);

        updateConnection = new QPushButton(connections);
        updateConnection->setObjectName(QStringLiteral("updateConnection"));

        horizontalLayout_4->addWidget(updateConnection);


        verticalLayout_2->addLayout(horizontalLayout_4);

        updateTabs->addTab(connections, QString());

        gridLayout_4->addWidget(updateTabs, 0, 0, 1, 1);


        retranslateUi(update_widget);

        updateTabs->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(update_widget);
    } // setupUi

    void retranslateUi(QWidget *update_widget)
    {
        update_widget->setWindowTitle(QApplication::translate("update_widget", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableView_pioneers_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("update_widget", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableView_pioneers_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("update_widget", "First name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableView_pioneers_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("update_widget", "Last name", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableView_pioneers_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("update_widget", "Gender", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableView_pioneers_2->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("update_widget", "Year born", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableView_pioneers_2->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("update_widget", "Year died", 0));
        label_2->setText(QApplication::translate("update_widget", "Double click cell to update", 0));
        updateTabs->setTabText(updateTabs->indexOf(pioneer), QApplication::translate("update_widget", "Pioneers", 0));
        label_info_update->setText(QApplication::translate("update_widget", "Double click cell to update", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableView_computers_2->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("update_widget", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableView_computers_2->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("update_widget", "Computer name", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableView_computers_2->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("update_widget", "Computer type", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableView_computers_2->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("update_widget", "Year invented", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableView_computers_2->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("update_widget", "Was it built?", 0));
        updateTabs->setTabText(updateTabs->indexOf(computers), QApplication::translate("update_widget", "Computers", 0));
        label_3->setText(QApplication::translate("update_widget", "Select row to update", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableView_connections_2->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("update_widget", "PID", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableView_connections_2->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("update_widget", "CID", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableView_connections_2->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QApplication::translate("update_widget", "Computer name", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableView_connections_2->horizontalHeaderItem(3);
        ___qtablewidgetitem14->setText(QApplication::translate("update_widget", "First name", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableView_connections_2->horizontalHeaderItem(4);
        ___qtablewidgetitem15->setText(QApplication::translate("update_widget", "Last name", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableView_connections_2->horizontalHeaderItem(5);
        ___qtablewidgetitem16->setText(QApplication::translate("update_widget", "Year invented", 0));
        label_7->setText(QApplication::translate("update_widget", "Enter either computer name or first and last name of pioneer", 0));
        label_6->setText(QApplication::translate("update_widget", "Computer name", 0));
        label_5->setText(QApplication::translate("update_widget", "Pioneers first name", 0));
        label_4->setText(QApplication::translate("update_widget", "Pioneers last name", 0));
        updateComputer->setText(QApplication::translate("update_widget", "Update computer", 0));
        updateConnection->setText(QApplication::translate("update_widget", "Update pioneer", 0));
        updateTabs->setTabText(updateTabs->indexOf(connections), QApplication::translate("update_widget", "Connections", 0));
    } // retranslateUi

};

namespace Ui {
    class update_widget: public Ui_update_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATE_WIDGET_H
