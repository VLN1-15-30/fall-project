#include "search_widget.h"
#include "ui_search_widget.h"
#include <QDebug>
#include "Utilities/utils.h"

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

    ui->comboBox_OrderConnection->addItem("Order by");
    ui->comboBox_OrderConnection->addItem("Inventor - ASC");
    ui->comboBox_OrderConnection->addItem("Inventor - DESC");
    ui->comboBox_OrderConnection->addItem("Computer - ASC");
    ui->comboBox_OrderConnection->addItem("Computer - DESC");

    ui->comboBox_pioneers->addItem("Last name");
    ui->comboBox_pioneers->addItem("Gender");
    ui->comboBox_pioneers->addItem("Year born");
    ui->comboBox_pioneers->addItem("Year of death");

    ui->comboBox_computers->addItem("Name");
    ui->comboBox_computers->addItem("Type");
    ui->comboBox_computers->addItem("Year Invented");
    ui->comboBox_computers->addItem("Was made");

    ui->comboBox_connections->addItem("Inventor");
    ui->comboBox_connections->addItem("Computer");
    ui->comboBox_connections->addItem("Year Invented");

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

        } else {
            dbPersons = hpList.orderbyPersons(order, col);
        }

        ui->table_pioneers->clearContents();
        ui->table_pioneers->setRowCount(dbPersons.size());

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
    case 3: {

        if(order == -1){
            dbConnection = hpList.getConnections();
        } else if(order == -2) {
            cout << "searching" << endl;
        } else {
            dbConnection = hpList.orderbyConnections(order, col);
        }

        ui->table_connections->clearContents();

        ui->table_connections->setRowCount(dbConnection.size());

        for (unsigned int row = 0; row < dbConnection.size(); row++)
        {
            connection currentConnection = dbConnection[row];

            QString comp = QString::fromStdString(currentConnection.getComputerName());
            QString first = QString::fromStdString(currentConnection.getFirstName());
            QString last = QString::fromStdString(currentConnection.getLastName());
            QString year = QString::number(currentConnection.getYearInvented());

            ui->table_connections->setItem(row, 0, new QTableWidgetItem(first));
            ui->table_connections->setItem(row, 1, new QTableWidgetItem(last));
            ui->table_connections->setItem(row, 2, new QTableWidgetItem(comp));
            ui->table_connections->setItem(row, 3, new QTableWidgetItem(year));
        }
    }
        break;
    default:
        break;
    }
}

void search_widget::disableRemove()
{
    ui->pushButton_remove_connection->setEnabled(false);
    ui->label_remove_conneciton->setText("Select a row to remove a connection from the database");
    ui->pushButton_remove_Pioneer->setEnabled(false);
    ui->label_removePioneer->setText("Select a row to remove a pioneer from the database");
    ui->pushButton_remove_computer->setEnabled(false);
    ui->label_remove_computer->setText("Select a row to remove a computer from the database");
}

search_widget::~search_widget()
{
    delete ui;
}

void search_widget::on_tab_search_tabBarClicked(int index)
{
    disableRemove();
    populateTableAtIndex(index+1,-1,0);
}


void search_widget::on_comboBox_pioneers_currentIndexChanged(int index)
{
    disableRemove();

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

void search_widget::on_comboBox_connections_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        searchConnectionColumn = "P.lastname";
        break;
    case 1:
        searchConnectionColumn = "C.name";
        break;
    case 2:
        searchConnectionColumn = "C.yearMade";
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
    searchConnection(currentText);

}
void search_widget::on_table_pioneers_clicked(const QModelIndex &index)
{
    ui->pushButton_remove_Pioneer->setEnabled(true);
    stringstream ss;
    ss<<"Row selected at index: ";
    ss<<index.row()+1;
    QString ind = QString::fromStdString(ss.str());
    ui->label_removePioneer->setText(ind);

}

void search_widget::on_table_computers_clicked(const QModelIndex &index)
{
    ui->pushButton_remove_computer->setEnabled(true);
    stringstream ss;
    ss<<"Row selected at index: ";
    ss<<index.row()+1;
    QString ind = QString::fromStdString(ss.str());
    ui->label_remove_computer->setText(ind);


}

void search_widget::on_table_connections_clicked(const QModelIndex &index)
{
    ui->pushButton_remove_connection->setEnabled(true);
    stringstream ss;
    ss<<"Row selected at index: ";
    ss<<index.row()+1;
    QString ind = QString::fromStdString(ss.str());
    ui->label_remove_conneciton->setText(ind);

}

void search_widget::searchPeople(string search){

    dbPersons = hpList.getSearchPerson(searchColumn, search);
    populateTableAtIndex(1,-2,0);
}

void search_widget::searchComputer(string search){
    dbComputers = hpList.getSearchComputer(searchComputerColumn, search);
    populateTableAtIndex(2,-2,0);
}

void search_widget::searchConnection(string search)
{
    dbConnection = hpList.getSearchConnection(searchConnectionColumn, search);
    populateTableAtIndex(3,-2,0);
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

void search_widget::on_comboBox_OrderConnection_currentIndexChanged(int index)
{
    switch(index){
    case 1:
        populateTableAtIndex(3,0,0);
        break;
    case 2:
        populateTableAtIndex(3,1,0);
        break;
    case 3:
        populateTableAtIndex(3,0,1);
        break;
    case 4:
        populateTableAtIndex(3,1,1);
        break;
    default:
        break;

    }
}

void search_widget::on_pushButton_remove_Pioneer_clicked()
{
    string lastname = ui->table_pioneers->item(ui->table_pioneers->currentRow(), 1)->text().toStdString();
    hpList.deleteCharacterWithName(lastname,0);
    populateTableAtIndex(1,-1,0);

}

void search_widget::on_pushButton_remove_computer_clicked()
{
    string name = ui->table_computers->item(ui->table_computers->currentRow(), 0)->text().toStdString();
    hpList.deleteCharacterWithName(name,1);
    populateTableAtIndex(2,-1,0);

}

void search_widget::on_pushButton_remove_connection_clicked()
{
    string first = ui->table_connections->item(ui->table_connections->currentRow(), 0)->text().toStdString();
    string last = ui->table_connections->item(ui->table_connections->currentRow(), 1)->text().toStdString();
    string computer = ui->table_connections->item(ui->table_connections->currentRow(), 2)->text().toStdString();

    hpList.removeConnection(first,last,computer);
    populateTableAtIndex(3,-1,0);
}

void search_widget::convertToCSV(int index){

    if(index == 0) {
        utils::writeToFile(dbPersons, numOfPrint++);
    } else if(index == 1) {
        utils::writeToFile(dbComputers, numOfPrint++);
    } else {
        utils::writeToFile(dbConnection, numOfPrint++);
    }


}

void search_widget::on_pushButton_printDbPerson_clicked()
{
    convertToCSV(0);
}

void search_widget::on_pushButton_printDbComputer_clicked()
{
    convertToCSV(1);
}

void search_widget::on_pushButton_printDbConnection_clicked()
{
    convertToCSV(2);
}
