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
    QHBoxLayout *horizontalLayout;
    QTabWidget *updateTabs;
    QWidget *pioneer;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableView_pioneers_2;
    QComboBox *updateOptionsPioneers;
    QLineEdit *replacePioneersInfo;
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
        update_widget->resize(400, 300);
        horizontalLayout = new QHBoxLayout(update_widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        updateTabs = new QTabWidget(update_widget);
        updateTabs->setObjectName(QStringLiteral("updateTabs"));
        updateTabs->setTabShape(QTabWidget::Triangular);
        pioneer = new QWidget();
        pioneer->setObjectName(QStringLiteral("pioneer"));
        verticalLayout = new QVBoxLayout(pioneer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView_pioneers_2 = new QTableWidget(pioneer);
        tableView_pioneers_2->setObjectName(QStringLiteral("tableView_pioneers_2"));

        verticalLayout->addWidget(tableView_pioneers_2);

        updateOptionsPioneers = new QComboBox(pioneer);
        updateOptionsPioneers->setObjectName(QStringLiteral("updateOptionsPioneers"));

        verticalLayout->addWidget(updateOptionsPioneers);

        replacePioneersInfo = new QLineEdit(pioneer);
        replacePioneersInfo->setObjectName(QStringLiteral("replacePioneersInfo"));

        verticalLayout->addWidget(replacePioneersInfo);

        updatePioneer = new QPushButton(pioneer);
        updatePioneer->setObjectName(QStringLiteral("updatePioneer"));

        verticalLayout->addWidget(updatePioneer);

        updateAnotherPioneer = new QPushButton(pioneer);
        updateAnotherPioneer->setObjectName(QStringLiteral("updateAnotherPioneer"));

        verticalLayout->addWidget(updateAnotherPioneer);

        updateTabs->addTab(pioneer, QString());
        computers = new QWidget();
        computers->setObjectName(QStringLiteral("computers"));
        verticalLayout_3 = new QVBoxLayout(computers);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tableView_computers_2 = new QTableWidget(computers);
        tableView_computers_2->setObjectName(QStringLiteral("tableView_computers_2"));

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
        tableView_connections_2->setObjectName(QStringLiteral("tableView_connections_2"));

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

        horizontalLayout->addWidget(updateTabs);


        retranslateUi(update_widget);

        updateTabs->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(update_widget);
    } // setupUi

    void retranslateUi(QWidget *update_widget)
    {
        update_widget->setWindowTitle(QApplication::translate("update_widget", "Form", 0));
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
