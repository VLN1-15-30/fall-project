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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QTableWidget *tableView_pioneers_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *updateOptionsPioneers;
    QLineEdit *replacePioneersInfo;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *updatePioneer;
    QPushButton *updateAnotherPioneer;
    QWidget *computers;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableView_computers_2;
    QComboBox *updateOptionsComputers;
    QLineEdit *replaceComputersInfo;
    QPushButton *updateComputer;
    QPushButton *updateAnotherComputer;
    QWidget *connections;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableView_connections_2;
    QComboBox *updateOptionsConnections;
    QLineEdit *replaceConnectionsInfo;
    QPushButton *updateConnection;
    QPushButton *updateAnotherConnection;

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
        tableView_pioneers_2 = new QTableWidget(pioneer);
        if (tableView_pioneers_2->columnCount() < 5)
            tableView_pioneers_2->setColumnCount(5);
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
        tableView_pioneers_2->setObjectName(QStringLiteral("tableView_pioneers_2"));
        tableView_pioneers_2->setSortingEnabled(true);
        tableView_pioneers_2->horizontalHeader()->setStretchLastSection(true);
        tableView_pioneers_2->verticalHeader()->setStretchLastSection(true);

        gridLayout_5->addWidget(tableView_pioneers_2, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        updateOptionsPioneers = new QComboBox(pioneer);
        updateOptionsPioneers->setObjectName(QStringLiteral("updateOptionsPioneers"));

        horizontalLayout_2->addWidget(updateOptionsPioneers);

        replacePioneersInfo = new QLineEdit(pioneer);
        replacePioneersInfo->setObjectName(QStringLiteral("replacePioneersInfo"));

        horizontalLayout_2->addWidget(replacePioneersInfo);


        gridLayout_5->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        updatePioneer = new QPushButton(pioneer);
        updatePioneer->setObjectName(QStringLiteral("updatePioneer"));

        horizontalLayout_3->addWidget(updatePioneer);

        updateAnotherPioneer = new QPushButton(pioneer);
        updateAnotherPioneer->setObjectName(QStringLiteral("updateAnotherPioneer"));

        horizontalLayout_3->addWidget(updateAnotherPioneer);


        gridLayout_5->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        updateTabs->addTab(pioneer, QString());
        computers = new QWidget();
        computers->setObjectName(QStringLiteral("computers"));
        verticalLayout_3 = new QVBoxLayout(computers);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tableView_computers_2 = new QTableWidget(computers);
        if (tableView_computers_2->columnCount() < 4)
            tableView_computers_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableView_computers_2->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableView_computers_2->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableView_computers_2->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableView_computers_2->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        tableView_computers_2->setObjectName(QStringLiteral("tableView_computers_2"));
        tableView_computers_2->setSortingEnabled(true);
        tableView_computers_2->horizontalHeader()->setStretchLastSection(true);
        tableView_computers_2->verticalHeader()->setStretchLastSection(true);

        verticalLayout_3->addWidget(tableView_computers_2);

        updateOptionsComputers = new QComboBox(computers);
        updateOptionsComputers->setObjectName(QStringLiteral("updateOptionsComputers"));

        verticalLayout_3->addWidget(updateOptionsComputers);

        replaceComputersInfo = new QLineEdit(computers);
        replaceComputersInfo->setObjectName(QStringLiteral("replaceComputersInfo"));

        verticalLayout_3->addWidget(replaceComputersInfo);

        updateComputer = new QPushButton(computers);
        updateComputer->setObjectName(QStringLiteral("updateComputer"));

        verticalLayout_3->addWidget(updateComputer);

        updateAnotherComputer = new QPushButton(computers);
        updateAnotherComputer->setObjectName(QStringLiteral("updateAnotherComputer"));

        verticalLayout_3->addWidget(updateAnotherComputer);

        updateTabs->addTab(computers, QString());
        connections = new QWidget();
        connections->setObjectName(QStringLiteral("connections"));
        verticalLayout_2 = new QVBoxLayout(connections);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableView_connections_2 = new QTableWidget(connections);
        if (tableView_connections_2->columnCount() < 3)
            tableView_connections_2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableView_connections_2->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableView_connections_2->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableView_connections_2->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        tableView_connections_2->setObjectName(QStringLiteral("tableView_connections_2"));
        tableView_connections_2->setSortingEnabled(true);
        tableView_connections_2->horizontalHeader()->setStretchLastSection(true);
        tableView_connections_2->verticalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(tableView_connections_2);

        updateOptionsConnections = new QComboBox(connections);
        updateOptionsConnections->setObjectName(QStringLiteral("updateOptionsConnections"));

        verticalLayout_2->addWidget(updateOptionsConnections);

        replaceConnectionsInfo = new QLineEdit(connections);
        replaceConnectionsInfo->setObjectName(QStringLiteral("replaceConnectionsInfo"));

        verticalLayout_2->addWidget(replaceConnectionsInfo);

        updateConnection = new QPushButton(connections);
        updateConnection->setObjectName(QStringLiteral("updateConnection"));

        verticalLayout_2->addWidget(updateConnection);

        updateAnotherConnection = new QPushButton(connections);
        updateAnotherConnection->setObjectName(QStringLiteral("updateAnotherConnection"));

        verticalLayout_2->addWidget(updateAnotherConnection);

        updateTabs->addTab(connections, QString());

        gridLayout_4->addWidget(updateTabs, 0, 0, 1, 1);


        retranslateUi(update_widget);

        updateTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(update_widget);
    } // setupUi

    void retranslateUi(QWidget *update_widget)
    {
        update_widget->setWindowTitle(QApplication::translate("update_widget", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableView_pioneers_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("update_widget", "First name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableView_pioneers_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("update_widget", "Last name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableView_pioneers_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("update_widget", "Gender", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableView_pioneers_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("update_widget", "Year born", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableView_pioneers_2->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("update_widget", "Year died", 0));
        updateOptionsPioneers->clear();
        updateOptionsPioneers->insertItems(0, QStringList()
         << QApplication::translate("update_widget", "Choose what to update", 0)
         << QApplication::translate("update_widget", "First name", 0)
         << QApplication::translate("update_widget", "Last name", 0)
         << QApplication::translate("update_widget", "Gender", 0)
         << QApplication::translate("update_widget", "Year born", 0)
         << QApplication::translate("update_widget", "Year died", 0)
        );
        replacePioneersInfo->setText(QApplication::translate("update_widget", "Replace with...", 0));
        updatePioneer->setText(QApplication::translate("update_widget", "Update", 0));
        updateAnotherPioneer->setText(QApplication::translate("update_widget", "Continue updating", 0));
        updateTabs->setTabText(updateTabs->indexOf(pioneer), QApplication::translate("update_widget", "Pioneers", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableView_computers_2->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("update_widget", "New Column", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableView_computers_2->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("update_widget", "Computer type", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableView_computers_2->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("update_widget", "Year invented", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableView_computers_2->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("update_widget", "Was it built?", 0));
        updateOptionsComputers->clear();
        updateOptionsComputers->insertItems(0, QStringList()
         << QApplication::translate("update_widget", "Choose what to update", 0)
         << QApplication::translate("update_widget", "Computer name", 0)
         << QApplication::translate("update_widget", "Computer type", 0)
         << QApplication::translate("update_widget", "Year invented", 0)
         << QApplication::translate("update_widget", "Was it built?", 0)
        );
        replaceComputersInfo->setText(QApplication::translate("update_widget", "Replace with...", 0));
        updateComputer->setText(QApplication::translate("update_widget", "Update", 0));
        updateAnotherComputer->setText(QApplication::translate("update_widget", "Continu updating", 0));
        updateTabs->setTabText(updateTabs->indexOf(computers), QApplication::translate("update_widget", "Computers", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableView_connections_2->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("update_widget", "First name", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableView_connections_2->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("update_widget", "Last name", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableView_connections_2->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QApplication::translate("update_widget", "Computer", 0));
        updateOptionsConnections->clear();
        updateOptionsConnections->insertItems(0, QStringList()
         << QApplication::translate("update_widget", "Choose what to update", 0)
         << QApplication::translate("update_widget", "Pioneer first name", 0)
         << QApplication::translate("update_widget", "Pioneer last name", 0)
         << QApplication::translate("update_widget", "Computer name", 0)
        );
        replaceConnectionsInfo->setText(QApplication::translate("update_widget", "Replace with...", 0));
        updateConnection->setText(QApplication::translate("update_widget", "Update", 0));
        updateAnotherConnection->setText(QApplication::translate("update_widget", "Continue updating", 0));
        updateTabs->setTabText(updateTabs->indexOf(connections), QApplication::translate("update_widget", "Connections", 0));
    } // retranslateUi

};

namespace Ui {
    class update_widget: public Ui_update_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATE_WIDGET_H
