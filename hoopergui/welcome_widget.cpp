#include "welcome_widget.h"
#include "ui_welcome_widget.h"
#include <QDebug>

welcome_widget::welcome_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::welcome_widget)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #34466E;");
    ui->label_welcome->setStyleSheet("QLabel {color: white;}");
    ui->label_info->setStyleSheet("QLabel {color: white;}");

    qDebug()<<"running welcome widget";

}

welcome_widget::~welcome_widget()
{
    delete ui;
}
