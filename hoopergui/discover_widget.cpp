#include "discover_widget.h"
#include "ui_discover_widget.h"

discover_widget::discover_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::discover_widget)
{
    ui->setupUi(this);
    ui->label_info->setStyleSheet("QLabel {color: white;}");
    ui->label_result->setStyleSheet("QLabel {color: white;}");
    ui->pushButton_discover->setStyleSheet("QPushButton { color: purple;}");

}

discover_widget::~discover_widget()
{
    delete ui;
}
