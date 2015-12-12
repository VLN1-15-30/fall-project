#include "about_widget.h"
#include "ui_about_widget.h"

about_widget::about_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::about_widget)
{
    ui->setupUi(this);
    ui->label_about->setStyleSheet("QLabel {color: white;}");
    ui->label_authors->setStyleSheet("QLabel {color: white;}");

}

about_widget::~about_widget()
{
    delete ui;
}
