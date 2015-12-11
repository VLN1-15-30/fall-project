#include "add_widget.h"
#include "ui_add_widget.h"

add_widget::add_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_widget)
{
    ui->setupUi(this);
    ui->label_add->setStyleSheet("QLabel {color: white;}");

}

add_widget::~add_widget()
{
    delete ui;
}
