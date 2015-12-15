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

    ui->comboBox_OrderPerson->addItem("Order by");
    ui->comboBox_OrderPerson->addItem("Last name - ASC");
    ui->comboBox_OrderPerson->addItem("Last name - DESC");
    ui->comboBox_OrderPerson->addItem("Born - ASC");
    ui->comboBox_OrderPerson->addItem("Born - DESC");

    ui->comboBox_OrderComputers->addItem("Order by");
    ui->comboBox_OrderComputers->addItem("Name - ASC");
    ui->comboBox_OrderComputers->addItem("Name - DESC");
    ui->comboBox_OrderComputers->addItem("Type - ASC");
    ui->comboBox_OrderComputers->addItem("Type - DESC");

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

        if( order == -1 ) {
            dbPersons = hpList.getPersons();
        } else if(order == -2) {
            cout << "seearc" << endl;
        } else {
            dbPersons = hpList.orderbyPersons(order, col);
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
    case 2: {

        if(order == -1){
            dbComputers = hpList.getComputers();
        } else if(order == -2) {
            cout << "searching" << endl;
        } else {
            dbComputers = hpList.orderbyComputers(order, col);
        }

        ui->table_computers->clearContents();

        ui->table_computers->setRowCount(dbComputers.size());

        for (unsigned int row = 0; row < dbComputers.size(); row++)
        {
            computer currentComputer = dbComputers[row];

            QString name = QString::fromStdString(currentComputer.getName());
            QString type = QString::fromStdString(currentComputer.getType());
            QString year = QString::number(currentComputer.getYearMade());
            QString made = QString::number(currentComputer.getWasMade());
            QString wasMade;
            if(made == 0){
                wasMade = "No";
            }
            else{
                wasMade = "Yes";
            }

            ui->table_computers->setItem(row, 0, new QTableWidgetItem(name));
            ui->table_computers->setItem(row, 1, new QTableWidgetItem(type));
            ui->table_computers->setItem(row, 2, new QTableWidgetItem(year));
            ui->table_computers->setItem(row, 3, new QTableWidgetItem(wasMade));
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


void search_widget::on_comboBox_pioneers_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        searchColumn = "lastname";
        break;
    case 1:
        searchColumn = "sex";
        break;
    case 2:
        searchColumn = "born";
        break;
    case 3:
        searchColumn = "died";
        break;
    default:
        break;

    }
}
void search_widget::on_comboBox_computers_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        searchComputerColumn = "name";
        break;
    case 1:
        searchComputerColumn = "type";
        break;
    case 2:
        searchComputerColumn = "yearMade";
        break;
    case 3:
        searchComputerColumn = "wasMade";
        break;
    default:
        break;

    }
}

void search_widget::on_lineEdit_pioneers_textChanged(const QString &arg1)
{
    string currentText = ui->lineEdit_pioneers->text().toStdString();
    searchPeople(currentText);
}

void search_widget::on_lineEdit_computers_textChanged(const QString &arg1)
{
    string currentText = ui->lineEdit_computers->text().toStdString();
    searchComputer(currentText);
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

void search_widget::searchPeople(string search){

    dbPersons = hpList.getSearchPerson(searchColumn, search);
    populateTableAtIndex(1,-2,0);
}

void search_widget::searchComputer(string search){
    dbComputers = hpList.getSearchComputer(searchComputerColumn, search);
    populateTableAtIndex(2,-2,0);
}

void search_widget::on_comboBox_OrderPerson_currentIndexChanged(int index)
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

void search_widget::on_comboBox_OrderComputers_currentIndexChanged(int index)
{
    switch(index){
    case 1:
        populateTableAtIndex(2,0,0);
        break;
    case 2:
        populateTableAtIndex(2,1,0);
        break;
    case 3:
        populateTableAtIndex(2,0,1);
        break;
    case 4:
        populateTableAtIndex(2,1,1);
        break;
    default:
        break;

    }
}


