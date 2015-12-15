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
    populateTablePioneers();
    populateTableComputers();
    populateTableConnections();
}

void update_widget::setUpUi(){

    ui->updateTabs->setStyleSheet("QTabWidget::pane { border: 0; }QTabBar::tab { background-color: #34466E; color: #ACADB1 }");
    ui->tableView_pioneers_2->setStyleSheet("QTableView{border : 1px solid white}");
    ui->tableView_computers_2->setStyleSheet("QTableView{border : 1px solid white}");
    ui->tableView_connections_2->setStyleSheet("QTableView{border : 1px solid white}");

}

void update_widget::populateTablePioneers()
{
    loading = true;
    vector<person> p  = hpList.getPersons();

    ui->tableView_pioneers_2->clearContents();

    ui->tableView_pioneers_2->setRowCount(p.size());

    for (unsigned int row = 0; row < p.size(); row++)
    {
        person currentPioneer = p[row];

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

void update_widget::populateTableComputers()
{
    vector<computer> c  = hpList.getComputers();

    ui->tableView_computers_2->clearContents();

    ui->tableView_computers_2->setRowCount(c.size());

    for (unsigned int row = 0; row < c.size(); row++)
    {
        computer currentComputer = c[row];

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
}

void update_widget::populateTableConnections()
{
    vector<connection> conn  = hpList.getConnections();

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

update_widget::~update_widget()
{
    delete ui;
}

void update_widget::on_tableView_pioneers_2_cellChanged(int row, int column)
{
    if(loading) return;
    int id = ui->tableView_pioneers_2->item(row,0)->text().toInt();
    string value = ui->tableView_pioneers_2->item(row,column)->text().toStdString();
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
}

void update_widget::on_tableView_computers_2_cellChanged(int row, int column)
{
    if(loading) return;
    int id = ui->tableView_computers_2->item(row,0)->text().toInt();
    string value = ui->tableView_computers_2->item(row,column)->text().toStdString();
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
    string compName = ui->computerName->text().toStdString();
    int rowNum;
    for(int s=0; s < ui->tableView_connections_2->rowCount(); s++)
    {
       if(ui->tableView_connections_2->item(s,0)->isSelected())
          {
             rowNum = s;
          }
    }
    int pid = ui->tableView_connections_2->item(rowNum, 0)->text().toInt();
    int cid = ui->tableView_connections_2->item(rowNum, 1)->text().toInt();
    int newID = hpList.getComputerID(compName);

    hpList.updateConnection(pid, cid, "cID", newID);

    populateTableConnections();
}



void update_widget::on_updateConnection_clicked()
{
    string firstName = ui->firstName->text().toStdString();
    string lastName = ui->lastName->text().toStdString();
    int rowNum;
    for(int s=0; s < ui->tableView_connections_2->rowCount(); s++)
    {
       if(ui->tableView_connections_2->item(s,0)->isSelected())
          {
             rowNum = s;
          }
    }
    int pid = ui->tableView_connections_2->item(rowNum, 0)->text().toInt();
    int cid = ui->tableView_connections_2->item(rowNum, 1)->text().toInt();
    int newID = hpList.getPersonID(lastName, firstName);

    hpList.updateConnection(pid, cid, "pID", newID);

    populateTableConnections();
}
