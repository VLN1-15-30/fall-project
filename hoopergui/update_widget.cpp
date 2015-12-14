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

update_widget::~update_widget()
{
    delete ui;
}
