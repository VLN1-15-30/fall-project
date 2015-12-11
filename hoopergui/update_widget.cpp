#include "update_widget.h"
#include "ui_update_widget.h"

update_widget::update_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::update_widget)
{
    ui->setupUi(this);
    ui->label_update->setStyleSheet("QLabel {color: white;}");

}

update_widget::~update_widget()
{
    delete ui;
}
