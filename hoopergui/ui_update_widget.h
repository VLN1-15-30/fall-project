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
    QTableWidget *tableView_pioneers_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_person;
    QComboBox *comboBox_pioneers;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_info_update_pioneers;
    QLabel *error_pioneer;
    QWidget *computers;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_info_update_computers;
    QLabel *error_computer;
    QTableWidget *tableView_computers_2;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *lineEdit_computers;
    QHBoxLayout *horizontalLayout_12;
    QComboBox *comboBox_computers;
    QWidget *connections;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_info_update_connection;
    QLabel *error_connection;
    QTableWidget *tableView_connections_2;
    QLabel *label_connection_instr;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_connection_c_name;
    QLabel *label_connection_p_first;
    QLabel *label_connection_p_last;
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
        tableView_pioneers_2->setSortingEnabled(false);
        tableView_pioneers_2->horizontalHeader()->setStretchLastSection(true);
        tableView_pioneers_2->verticalHeader()->setStretchLastSection(false);

        gridLayout_5->addWidget(tableView_pioneers_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit_person = new QLineEdit(pioneer);
        lineEdit_person->setObjectName(QStringLiteral("lineEdit_person"));
        lineEdit_person->setInputMethodHints(Qt::ImhNone);
        lineEdit_person->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_person->setDragEnabled(true);
        lineEdit_person->setReadOnly(false);

        horizontalLayout_3->addWidget(lineEdit_person);

        comboBox_pioneers = new QComboBox(pioneer);
        comboBox_pioneers->setObjectName(QStringLiteral("comboBox_pioneers"));

        horizontalLayout_3->addWidget(comboBox_pioneers, 0, Qt::AlignRight);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));

        horizontalLayout_3->addLayout(horizontalLayout_9);


        gridLayout_5->addLayout(horizontalLayout_3, 5, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_info_update_pioneers = new QLabel(pioneer);
        label_info_update_pioneers->setObjectName(QStringLiteral("label_info_update_pioneers"));

        horizontalLayout_6->addWidget(label_info_update_pioneers);

        error_pioneer = new QLabel(pioneer);
        error_pioneer->setObjectName(QStringLiteral("error_pioneer"));

        horizontalLayout_6->addWidget(error_pioneer);


        gridLayout_5->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        updateTabs->addTab(pioneer, QString());
        computers = new QWidget();
        computers->setObjectName(QStringLiteral("computers"));
        verticalLayout_3 = new QVBoxLayout(computers);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_info_update_computers = new QLabel(computers);
        label_info_update_computers->setObjectName(QStringLiteral("label_info_update_computers"));

        horizontalLayout_5->addWidget(label_info_update_computers);

        error_computer = new QLabel(computers);
        error_computer->setObjectName(QStringLiteral("error_computer"));

        horizontalLayout_5->addWidget(error_computer);


        verticalLayout_3->addLayout(horizontalLayout_5);

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
        tableView_computers_2->setSortingEnabled(false);
        tableView_computers_2->horizontalHeader()->setStretchLastSection(true);
        tableView_computers_2->verticalHeader()->setStretchLastSection(false);

        verticalLayout_3->addWidget(tableView_computers_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        lineEdit_computers = new QLineEdit(computers);
        lineEdit_computers->setObjectName(QStringLiteral("lineEdit_computers"));

        horizontalLayout_10->addWidget(lineEdit_computers);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        comboBox_computers = new QComboBox(computers);
        comboBox_computers->setObjectName(QStringLiteral("comboBox_computers"));

        horizontalLayout_12->addWidget(comboBox_computers);


        horizontalLayout_10->addLayout(horizontalLayout_12);


        verticalLayout_3->addLayout(horizontalLayout_10);

        updateTabs->addTab(computers, QString());
        connections = new QWidget();
        connections->setObjectName(QStringLiteral("connections"));
        verticalLayout_2 = new QVBoxLayout(connections);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_info_update_connection = new QLabel(connections);
        label_info_update_connection->setObjectName(QStringLiteral("label_info_update_connection"));

        horizontalLayout_7->addWidget(label_info_update_connection);

        error_connection = new QLabel(connections);
        error_connection->setObjectName(QStringLiteral("error_connection"));

        horizontalLayout_7->addWidget(error_connection);


        verticalLayout_2->addLayout(horizontalLayout_7);

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
        tableView_connections_2->setSortingEnabled(false);
        tableView_connections_2->horizontalHeader()->setStretchLastSection(true);
        tableView_connections_2->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableView_connections_2->verticalHeader()->setStretchLastSection(false);

        verticalLayout_2->addWidget(tableView_connections_2);

        label_connection_instr = new QLabel(connections);
        label_connection_instr->setObjectName(QStringLiteral("label_connection_instr"));

        verticalLayout_2->addWidget(label_connection_instr);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_connection_c_name = new QLabel(connections);
        label_connection_c_name->setObjectName(QStringLiteral("label_connection_c_name"));

        horizontalLayout_2->addWidget(label_connection_c_name);

        label_connection_p_first = new QLabel(connections);
        label_connection_p_first->setObjectName(QStringLiteral("label_connection_p_first"));

        horizontalLayout_2->addWidget(label_connection_p_first);

        label_connection_p_last = new QLabel(connections);
        label_connection_p_last->setObjectName(QStringLiteral("label_connection_p_last"));

        horizontalLayout_2->addWidget(label_connection_p_last);


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
        lineEdit_person->setText(QString());
        lineEdit_person->setPlaceholderText(QApplication::translate("update_widget", "Search for pioneer...", 0));
        label_info_update_pioneers->setText(QApplication::translate("update_widget", "Double click cell to update", 0));
        error_pioneer->setText(QString());
        updateTabs->setTabText(updateTabs->indexOf(pioneer), QApplication::translate("update_widget", "Pioneers", 0));
        label_info_update_computers->setText(QApplication::translate("update_widget", "Double click cell to update", 0));
        error_computer->setText(QString());
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
        lineEdit_computers->setPlaceholderText(QApplication::translate("update_widget", "Search for computer...", 0));
        updateTabs->setTabText(updateTabs->indexOf(computers), QApplication::translate("update_widget", "Computers", 0));
        label_info_update_connection->setText(QApplication::translate("update_widget", "Select row to update", 0));
        error_connection->setText(QString());
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
        label_connection_instr->setText(QApplication::translate("update_widget", "Enter either computer name or first and last name of pioneer", 0));
        label_connection_c_name->setText(QApplication::translate("update_widget", "Computer name", 0));
        label_connection_p_first->setText(QApplication::translate("update_widget", "Pioneer first name", 0));
        label_connection_p_last->setText(QApplication::translate("update_widget", "Pioneer last name", 0));
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
