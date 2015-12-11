#include "view_widget.h"
#include "ui_view_widget.h"
#include <QDebug>

view_widget::view_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::view_widget)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #34466E;");
    ui->label_view->setStyleSheet("QLabel {color: white;}");

    qDebug()<<"running view widget";

}

view_widget::~view_widget()
{
    delete ui;
}
