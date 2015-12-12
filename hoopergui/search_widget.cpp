#include "search_widget.h"
#include "ui_search_widget.h"
#include <QDebug>

search_widget::search_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search_widget)
{
    ui->setupUi(this);
    //this->setStyleSheet("background-color: #34466E;");
    qDebug()<<"running search widget";
    setUpUi();

}

void search_widget::setUpUi(){

    ui->lineEdit_computers->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); color: black; }");
    ui->lineEdit_connections->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); color: black; }");
    ui->lineEdit_pioneers->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); color: black; }");
    ui->tab_search->setStyleSheet("QTabWidget::pane { border: 0; }QTabBar::tab { background-color: #34466E; color: #ACADB1 }");
    ui->tableView_pioneers->setStyleSheet("QTableView{border : 1px solid white}");
    ui->tableView_computers->setStyleSheet("QTableView{border : 1px solid white}");
    ui->tableView_connections->setStyleSheet("QTableView{border : 1px solid white}");

}

search_widget::~search_widget()
{
    delete ui;
}

void search_widget::on_tab_search_tabBarClicked(int index)
{

}
