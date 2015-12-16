#include "update_widget.h"
#include "ui_update_widget.h"
#include <QDebug>

update_widget::update_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::update_widget)
{
    ui->setupUi(this);
    //ui->label_update->setStyleSheet("QLabel {color: white;}");
    qDebug()<<"running update widget";
    setUpUi();
    populateTablePioneers(0);
    populateTableComputers(0);
    populateTableConnections();
}

void update_widget::setUpUi(){

    ui->updateTabs->setStyleSheet("QTabWidget::pane { border: 0; }QTabBar::tab { background-color: #34466E; color: #ACADB1 }");
    ui->tableView_pioneers_2->setStyleSheet("QTableView{border : 1px solid white}");
    ui->tableView_computers_2->setStyleSheet("QTableView{border : 1px solid white}");
    ui->tableView_connections_2->setStyleSheet("QTableView{border : 1px solid white}");
    ui->label_info_update_pioneers->setStyleSheet("QLabel{color :white}");
    ui->label_info_update_computers->setStyleSheet("QLabel{color :white}");
    ui->label_info_update_connection->setStyleSheet("QLabel{color :white}");
    ui->label_connection_instr->setStyleSheet("QLabel{color :white}");
    ui->label_connection_c_name->setStyleSheet("QLabel{color :white}");
    ui->label_connection_p_first->setStyleSheet("QLabel{color :white}");
    ui->label_connection_p_last->setStyleSheet("QLabel{color :white}");

    ui->error_computer->setStyleSheet("QLabel{color :red}");
    ui->error_connection->setStyleSheet("QLabel{color :red}");
    ui->error_pioneer->setStyleSheet("QLabel{color :red}");

    ui->comboBox_pioneers->addItem("Last name");
    ui->comboBox_pioneers->addItem("Gender");
    ui->comboBox_pioneers->addItem("Year born");
    ui->comboBox_pioneers->addItem("Year of death");

    ui->comboBox_computers->addItem("Name");
    ui->comboBox_computers->addItem("Type");
    ui->comboBox_computers->addItem("Year Invented");
    ui->comboBox_computers->addItem("Was made");

    ui->updateTabs->setCurrentIndex(0);
}

void update_widget::populateTablePioneers(int i)
{
    loading = true;
    if(i == 0){
        dbPersons = hpList.getPersons();
    } else {
        //do nothing because dbPersons has result of search
    }

    ui->tableView_pioneers_2->clearContents();

    ui->tableView_pioneers_2->setRowCount(dbPersons.size());

    for (unsigned int row = 0; row < dbPersons.size(); row++)
    {
        person currentPioneer = dbPersons[row];

        QString id = QString::number(hpList.getPersonID(currentPioneer.getLastName(),currentPioneer.getFirstName()));
        QString firstName = QString::fromStdString(currentPioneer.getFirstName());
        QString lastName = QString::fromStdString(currentPioneer.getLastName());
        QString sex = QString::fromStdString(currentPioneer.getSex());
        QString born = QString::number(currentPioneer.getBorn());
        QString died = QString::number(currentPioneer.getDied());

        ui->tableView_pioneers_2->setItem(row, 0, new QTableWidgetItem(id));
        ui->tableView_pioneers_2->setItem(row, 1, new QTableWidgetItem(firstName));
        ui->tableView_pioneers_2->setItem(row, 2, new QTableWidgetItem(lastName));
        ui->tableView_pioneers_2->setItem(row, 3, new QTableWidgetItem(sex));
        ui->tableView_pioneers_2->setItem(row, 4, new QTableWidgetItem(born));
        ui->tableView_pioneers_2->setItem(row, 5, new QTableWidgetItem(died));

        ui->tableView_pioneers_2->hideColumn(0);
    }
    loading = false;
}

void update_widget::populateTableComputers(int i)
{
    loading = true;
    if(i == 0){
        dbComputers = hpList.getComputers();
    } else {
        //do nothing because dbComputers has result of search
    }

    ui->tableView_computers_2->clearContents();

    ui->tableView_computers_2->setRowCount(dbComputers.size());

    for (unsigned int row = 0; row < dbComputers.size(); row++)
    {
        computer currentComputer = dbComputers[row];

        QString id = QString::number(hpList.getComputerID(currentComputer.getName()));
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

        ui->tableView_computers_2->setItem(row, 0, new QTableWidgetItem(id));
        ui->tableView_computers_2->setItem(row, 1, new QTableWidgetItem(name));
        ui->tableView_computers_2->setItem(row, 2, new QTableWidgetItem(type));
        ui->tableView_computers_2->setItem(row, 3, new QTableWidgetItem(year));
        ui->tableView_computers_2->setItem(row, 4, new QTableWidgetItem(wasMade));

        ui->tableView_computers_2->hideColumn(0);
    }
    loading = false;

}

void update_widget::populateTableConnections()
{
    vector<connection> conn  = hpList.orderbyConnections(0,1);

    ui->tableView_connections_2->clearContents();

    ui->tableView_connections_2->setRowCount(conn.size());

    for (unsigned int row = 0; row < conn.size(); row++)
    {
        connection currentConnection = conn[row];

        QString pid = QString::number(hpList.getPersonID(currentConnection.getLastName(),currentConnection.getFirstName()));
        QString cid = QString::number(hpList.getComputerID(currentConnection.getComputerName()));
        QString comp = QString::fromStdString(currentConnection.getComputerName());
        QString first = QString::fromStdString(currentConnection.getFirstName());
        QString last = QString::fromStdString(currentConnection.getLastName());
        QString year = QString::number(currentConnection.getYearInvented());

        ui->tableView_connections_2->setItem(row, 0, new QTableWidgetItem(pid));
        ui->tableView_connections_2->setItem(row, 1, new QTableWidgetItem(cid));
        ui->tableView_connections_2->setItem(row, 2, new QTableWidgetItem(comp));
        ui->tableView_connections_2->setItem(row, 3, new QTableWidgetItem(first));
        ui->tableView_connections_2->setItem(row, 4, new QTableWidgetItem(last));
        ui->tableView_connections_2->setItem(row, 5, new QTableWidgetItem(year));

        ui->tableView_connections_2->hideColumn(0);
        ui->tableView_connections_2->hideColumn(1);
    }
}

void update_widget::searchPerson(string search)
{
     dbPersons = hpList.getSearchPerson(searchPersonColumn, search);
     populateTablePioneers(1);
}

void update_widget::searchComputer(string search)
{
    dbComputers = hpList.getSearchComputer(searchComputerColumn, search);
    populateTableComputers(1);
}

update_widget::~update_widget()
{
    delete ui;
}

void update_widget::on_tableView_pioneers_2_cellChanged(int row, int column)
{
    if(loading) return;

    int id = ui->tableView_pioneers_2->item(row,0)->text().toInt();
    string value = ui->tableView_pioneers_2->item(row,column)->text().toStdString();

    if(value.length() == 0){
        ui->error_pioneer->setText("You must type something");
        populateTablePioneers(0);
        return;
    }

    if(column == 3){
        if(value == "m"||value == "f"){
            //donothing
        }
        else
        {
            ui->error_pioneer->setText("Please type m/f");
            populateTablePioneers(0);

            return;
        }

    }

    else if (column == 4){
        int born = ui->tableView_pioneers_2->item(row,column)->text().toInt();
        int invalidInput = 0;

        if(born == invalidInput && value != "0"){
            ui->error_pioneer->setText("You must type a valid number for year born");
            populateTablePioneers(0);

            return;
        }
    }
    else if (column == 5){

        int died = ui->tableView_pioneers_2->item(row,column)->text().toInt();
        int born = ui->tableView_pioneers_2->item(row,column-1)->text().toInt();
        int invalidInput = 0;

        if(died < born){
            ui->error_pioneer->setText("Year died can not be less than year of birth");
            populateTablePioneers(0);
        }
        else if(died == invalidInput && value != "0"){
            ui->error_pioneer->setText("You must type a valid number for year died");
            populateTablePioneers(0);

            return;
        }

    }
    switch(column){
    case 1: hpList.update(id, "firstname", value, "persons");
        break;
    case 2: hpList.update(id, "lastname", value, "persons");
        break;
    case 3: hpList.update(id, "sex", value, "persons");
        break;
    case 4: hpList.update(id, "born", value, "persons");
        break;
    case 5: hpList.update(id, "died", value, "persons");
        break;
    default:
        break;
    }
    ui->error_pioneer->setText("");

}

void update_widget::on_tableView_computers_2_cellChanged(int row, int column)
{
    if(loading) return;


    int id = ui->tableView_computers_2->item(row,0)->text().toInt();
    string value = ui->tableView_computers_2->item(row,column)->text().toStdString();

    if(value.length() == 0){
        ui->error_computer->setText("You must type something");
        populateTableComputers(0);
        return;
    }

    if (column == 3){
        int year = ui->tableView_computers_2->item(row,column)->text().toInt();
        int invalidInput = 0;
        if(year == invalidInput){
            ui->error_computer->setText("You must type a valid number for year invented");
            return;
        }
    }
    else if(column == 4){
        if(value == "NO"||value == "Yes"){
            //donothing
        }
        else{
            ui->error_computer->setText("Please specify YES or NO");
            populateTableComputers(0);
        }
    }

    ui->error_computer->setText("");


    switch(column){
    case 1: hpList.update(id, "name", value, "computers");
        break;
    case 2: hpList.update(id, "type", value, "computers");
        break;
    case 3: hpList.update(id, "yearMade", value, "computers");
        break;
    case 4: hpList.update(id, "wasMade", value, "computers");
        break;
    default:
        break;
    }
}

void update_widget::on_updateComputer_clicked()
{
    ui->error_connection->setText("");
    string compName = ui->computerName->text().toStdString();

    if(compName.length() == 0){
        ui->error_connection->setText("You must type computer name");
        populateTableConnections();
        return;
    }
    if (! (ui->tableView_connections_2->selectionModel()->isSelected(ui->tableView_connections_2->currentIndex()))  ) {
        ui->error_connection->setText("You must select a row");
        return;
    }

    int rowNum = ui->tableView_connections_2->currentRow();
    int pid = ui->tableView_connections_2->item(rowNum, 0)->text().toInt();
    int cid = ui->tableView_connections_2->item(rowNum, 1)->text().toInt();
    int newID = hpList.getComputerID(compName);

    if(newID == -1){
        ui->error_connection->setText("Invalid computer selected. Please try again");
        return;
    }

    hpList.updateConnection(pid, cid, "cID", newID);

    ui->computerName->clear();

    populateTableConnections();
}



void update_widget::on_updateConnection_clicked()
{
    ui->error_connection->setText("");

    string firstName = ui->firstName->text().toStdString();
    string lastName = ui->lastName->text().toStdString();

    if(firstName.length() == 0 || lastName.length() == 0){
        ui->error_connection->setText("You must type first name and last name");
        populateTableConnections();
        return;

    }

    if (! (ui->tableView_connections_2->selectionModel()->isSelected(ui->tableView_connections_2->currentIndex()))  ) {
        ui->error_connection->setText("You must select a row");
        return;
    }

    int rowNum = ui->tableView_connections_2->currentRow();
    int pid = ui->tableView_connections_2->item(rowNum, 0)->text().toInt();
    int cid = ui->tableView_connections_2->item(rowNum, 1)->text().toInt();
    int newID = hpList.getPersonID(lastName, firstName);
    if(newID == -1){
        ui->error_connection->setText("Invalid pioneer selected. Please try again");
        return;
    }



    hpList.updateConnection(pid, cid, "pID", newID);

    ui->firstName->clear();
    ui->lastName->clear();

    populateTableConnections();
}

void update_widget::on_updateTabs_currentChanged(int index)
{
    ui->error_connection->setText("");
    ui->error_computer->setText("");
    ui->error_pioneer->setText("");

}

void update_widget::on_lineEdit_person_textChanged(const QString &arg1)
{
    string currentText = ui->lineEdit_person->text().toStdString();
    searchPerson(currentText);
}

void update_widget::on_comboBox_pioneers_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        searchPersonColumn = "lastname";
        break;
    case 1:
        searchPersonColumn = "sex";
        break;
    case 2:
        searchPersonColumn = "born";
        break;
    case 3:
        searchPersonColumn = "died";
        break;
    default:
        break;

    }
}

void update_widget::on_lineEdit_computers_textChanged(const QString &arg1)
{
    string currenttext = ui->lineEdit_computers->text().toStdString();
    searchComputer(currenttext);
}

void update_widget::on_comboBox_computers_currentIndexChanged(int index)
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
