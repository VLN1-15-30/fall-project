#include "remove_widget.h"
#include "ui_remove_widget.h"

remove_widget::remove_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::remove_widget)
{
    ui->setupUi(this);
    ui->label_remove->setStyleSheet("QLabel {color: white;}");

}

remove_widget::~remove_widget()
{
    delete ui;
}
