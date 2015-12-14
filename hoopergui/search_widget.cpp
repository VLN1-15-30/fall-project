#include "search_widget.h"
#include "ui_search_widget.h"
#include <QDebug>

search_widget::search_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search_widget)
{
    ui->setupUi(this);
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


    ui->comboBox_pioneers->setStyleSheet("QComboBox { background: rgb(255, 255, 255); color: black; }");
    ui->comboBox_computers->setStyleSheet("QComboBox { background: rgb(255, 255, 255); color: black; }");
    ui->comboBox_connections->setStyleSheet("QComboBox { background: rgb(255, 255, 255); color: black; }");

    ui ->comboBox_pioneers->addItem("Last name");
    ui ->comboBox_pioneers->addItem("Gender");
    ui ->comboBox_pioneers->addItem("Year born");
    ui ->comboBox_pioneers->addItem("Year of death");

    ui ->comboBox_computers->addItem("Name");
    ui ->comboBox_computers->addItem("Type");
    ui ->comboBox_computers->addItem("Year made");
    ui ->comboBox_computers->addItem("Was made");


}

search_widget::~search_widget()
{
    delete ui;
}

void search_widget::on_tab_search_tabBarClicked(int index)
{

}

void search_widget::on_comboBox_currentIndexChanged(const QString &arg1)
{

}
