#include "search_widget.h"
#include "ui_search_widget.h"
#include <QDebug>

search_widget::search_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search_widget)
{
    ui->setupUi(this);
    setUpUi();
    populateTableAtIndex(1,-1,0);

}

void search_widget::setUpUi(){

    ui->lineEdit_computers->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); color: black; }");
    ui->lineEdit_connections->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); color: black; }");
    ui->lineEdit_pioneers->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); color: black; }");
    ui->tab_search->setStyleSheet("QTabWidget::pane { border: 0; }QTabBar::tab { background-color: #34466E; color: #ACADB1 }");

    ui->comboBox_Order->addItem("Order by");
    ui->comboBox_Order->addItem("Last name - ASC");
    ui->comboBox_Order->addItem("Last name - DESC");
    ui->comboBox_Order->addItem("Born - ASC");
    ui->comboBox_Order->addItem("Born - DESC");

    ui->comboBox_pioneers->addItem("Last name");
    ui->comboBox_pioneers->addItem("Gender");
    ui->comboBox_pioneers->addItem("Year born");
    ui->comboBox_pioneers->addItem("Year of death");

    ui->comboBox_computers->addItem("Name");
    ui->comboBox_computers->addItem("Type");
    ui->comboBox_computers->addItem("Year made");
    ui->comboBox_computers->addItem("Was made");

    ui->tab_search->setCurrentIndex(0);
    ui->label_removePioneer->setStyleSheet("QLabel { color: white;}");
    ui->label_remove_computer->setStyleSheet("QLabel { color: white;}");
    ui->label_remove_conneciton->setStyleSheet("QLabel { color: white;}");

}

void search_widget::populateTableAtIndex(int index, int order, int col)
{
    switch (index) {
    case 1:  {
        vector<person>dbPersons;

        if( order == -1 ) {
            dbPersons = hpList.getPersons();
        } else {
            dbPersons = hpList.orderbyPersons(order,col);
        }

        ui->table_pioneers->clearContents();
        ui->table_pioneers->setRowCount(dbPersons.size());

        cout << "persons: " <<dbPersons.size()<<endl;

        for (unsigned int row = 0; row < dbPersons.size(); row++){

            person currentP = dbPersons[row];

            QString firstName = QString::fromStdString(currentP.getFirstName());
            QString lastname = QString::fromStdString(currentP.getLastName());
            QString gender = QString::fromStdString(currentP.getSex());
            QString born = QString::number(currentP.getBorn());
            QString died = QString::number(currentP.getDied());

            ui->table_pioneers->setItem(row,0,new QTableWidgetItem(firstName));
            ui->table_pioneers->setItem(row,1,new QTableWidgetItem(lastname));
            ui->table_pioneers->setItem(row,2,new QTableWidgetItem(gender));
            ui->table_pioneers->setItem(row,3,new QTableWidgetItem(born));
            ui->table_pioneers->setItem(row,4,new QTableWidgetItem(died));
        }

    }
        break;
    default:
        break;
    }
}

search_widget::~search_widget()
{
    delete ui;
}

void search_widget::on_tab_search_tabBarClicked(int index)
{
    populateTableAtIndex(index+1,-1,0);
}


void search_widget::on_comboBox_pioneers_currentIndexChanged(const QString &arg1)
{
    string currentSelection = ui->comboBox_pioneers->currentText().toStdString();
}

void search_widget::on_lineEdit_pioneers_textChanged(const QString &arg1)
{
    string currentText = ui->lineEdit_pioneers->text().toStdString();

}

void search_widget::on_lineEdit_computers_textChanged(const QString &arg1)
{
    string currentText = ui->lineEdit_computers->text().toStdString();

}


void search_widget::on_lineEdit_connections_textChanged(const QString &arg1)
{
    string currentText = ui->lineEdit_connections->text().toStdString();

}
void search_widget::on_table_pioneers_clicked(const QModelIndex &index)
{
    ui->pushButton_remove_Pioneer->setEnabled(true);
}

void search_widget::on_table_computers_clicked(const QModelIndex &index)
{
    ui->pushButton_remove_computer->setEnabled(true);

}

void search_widget::on_table_connections_clicked(const QModelIndex &index)
{
    ui->pushButton_remove_connection->setEnabled(true);

}



void search_widget::on_comboBox_Order_currentIndexChanged(int index)
{
    switch(index){
    case 1:
        populateTableAtIndex(1,0,0);
        break;
    case 2:
        populateTableAtIndex(1,1,0);
        break;
    case 3:
        populateTableAtIndex(1,0,1);
        break;
    case 4:
        populateTableAtIndex(1,1,1);
        break;
    default:
        break;

    }
}
