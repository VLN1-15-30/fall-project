#include "discover_widget.h"
#include "ui_discover_widget.h"

discover_widget::discover_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::discover_widget)
{
    ui->setupUi(this);
    ui->label_discover->setStyleSheet("QLabel {color: white;}");

}

discover_widget::~discover_widget()
{
    delete ui;
}
