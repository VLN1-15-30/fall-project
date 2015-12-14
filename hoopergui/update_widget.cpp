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
}

void update_widget::setUpUi(){

    ui->replaceComputersInfo->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); color: black; }");
    ui->replaceConnectionsInfo->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); color: black; }");
    ui->replacePioneersInfo->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); color: black; }");
    ui->updateTabs->setStyleSheet("QTabWidget::pane { border: 0; }QTabBar::tab { background-color: #34466E; color: #ACADB1 }");
    ui->tableView_pioneers_2->setStyleSheet("QTableView{border : 1px solid white}");
    ui->tableView_computers_2->setStyleSheet("QTableView{border : 1px solid white}");
    ui->tableView_connections_2->setStyleSheet("QTableView{border : 1px solid white}");

}

void update_widget::populateTablePioneers()
{
    vector<person> p  = hpList.getPersons();

    ui->tableView_pioneers_2->clearContents();

    ui->tableView_pioneers_2->setRowCount(p.size());

    for (unsigned int row = 0; row < p.size(); row++)
    {
        person currentPioneer = p[row];

        QString firstName = QString::fromStdString(currentPioneer.getFirstName());
        QString lastName = QString::fromStdString(currentPioneer.getLastName());
        QString sex = QString::fromStdString(currentPioneer.getSex());
        QString born = QString::number(currentPioneer.getBorn());
        QString died = QString::number(currentPioneer.getDied());

        ui->tableView_pioneers_2->setItem(row, 0, new QTableWidgetItem(firstName));
        ui->tableView_pioneers_2->setItem(row, 1, new QTableWidgetItem(lastName));
        ui->tableView_pioneers_2->setItem(row, 2, new QTableWidgetItem(sex));
        ui->tableView_pioneers_2->setItem(row, 3, new QTableWidgetItem(born));
        ui->tableView_pioneers_2->setItem(row, 4, new QTableWidgetItem(died));
    }
}

void update_widget::populateTableComputers()
{
    vector<computer> c  = hpList.getComputers();

    ui->tableView_computers_2->clearContents();

    ui->tableView_computers_2->setRowCount(c.size());

    for (unsigned int row = 0; row < c.size(); row++)
    {
        computer currentComputer = c[row];

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

        ui->tableView_computers_2->setItem(row, 0, new QTableWidgetItem(name));
        ui->tableView_computers_2->setItem(row, 1, new QTableWidgetItem(type));
        ui->tableView_computers_2->setItem(row, 2, new QTableWidgetItem(year));
        ui->tableView_computers_2->setItem(row, 3, new QTableWidgetItem(wasMade));
    }
}

update_widget::~update_widget()
{
    delete ui;
}
