#include "search_widget.h"
#include "ui_search_widget.h"

search_widget::search_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search_widget)
{
    ui->setupUi(this);
    ui->label_search->setStyleSheet("QLabel {color: white;}");

}

search_widget::~search_widget()
{
    delete ui;
}
