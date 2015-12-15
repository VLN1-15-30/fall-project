#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QPropertyAnimation>
#include <QStackedWidget>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    utils::getDatabaseConnection();
    ui->setupUi(this);

    setUpHooper();
    setButtonColors();
    trackHovers();

}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == (QObject*)ui->button_add_database) {
           if (event->type() == QEvent::Enter)
           {
               ui->button_add_database->setStyleSheet("QPushButton { color: white;}");


           }
           else if (event->type() == QEvent::Leave){

               if(selectedIndex != 2)
               ui->button_add_database->setStyleSheet("QPushButton { color: #ACADB1;}");


           }
           return QWidget::eventFilter(obj, event);;
       }


    else if (obj == (QObject*)ui->button_view_database) {
           if (event->type() == QEvent::Enter)
           {
               ui->button_view_database->setStyleSheet("QPushButton { color: white;}");


           }
           else if (event->type() == QEvent::Leave){

               if(selectedIndex != 1)
               ui->button_view_database->setStyleSheet("QPushButton { color: #ACADB1;}");


           }
           return QWidget::eventFilter(obj, event);;
       }


    else if (obj == (QObject*)ui->button_discover) {
           if (event->type() == QEvent::Enter)
           {
               ui->button_discover->setStyleSheet("QPushButton { color: white;}");

           }
           else if (event->type() == QEvent::Leave){

               if(selectedIndex != 3)
               ui->button_discover->setStyleSheet("QPushButton { color: #ACADB1;}");

           }
           return QWidget::eventFilter(obj, event);;
       }



    else if (obj == (QObject*)ui->button_about) {
           if (event->type() == QEvent::Enter)
           {
               ui->button_about->setStyleSheet("QPushButton { color: white;}");

           }
           else if (event->type() == QEvent::Leave){

               if(selectedIndex != 5)
               ui->button_about->setStyleSheet("QPushButton { color: #ACADB1;}");

           }
           return QWidget::eventFilter(obj, event);;
       }

    else if (obj == (QObject*)ui->button_update) {
           if (event->type() == QEvent::Enter)
           {
               ui->button_update->setStyleSheet("QPushButton {color: white;}");


           }
           else if (event->type() == QEvent::Leave){

               if(selectedIndex != 4)
               ui->button_update->setStyleSheet("QPushButton { color: #ACADB1;}");

           }
           return QWidget::eventFilter(obj, event);;
       }


    else {
           // pass the event on to the parent class

           return QWidget::eventFilter(obj, event);
    }
}

void MainWindow::setButtonColors()
{
    ui->button_view_database->setStyleSheet("QPushButton { color: #ACADB1;}");
    ui->button_add_database->setStyleSheet("QPushButton { color: #ACADB1;}");
    ui->button_about->setStyleSheet("QPushButton { color: #ACADB1;}");
    ui->button_discover->setStyleSheet("QPushButton { color: #ACADB1;}");
    ui->button_update->setStyleSheet("QPushButton {color: #ACADB1;}");

}

void MainWindow::trackHovers()
{
    this->setMouseTracking(true);

    ui->button_add_database->installEventFilter(this);
    ui->button_view_database->installEventFilter(this);
    ui->button_discover->installEventFilter(this);
    ui->button_about->installEventFilter(this);
    ui->button_update->installEventFilter(this);

}

void MainWindow::setUpHooper()
{

    setAutoFillBackground(true);
    QPalette p = this->palette();
    QColor linkColor("#34466E");
    p.setColor(this->backgroundRole(),linkColor);
    this->setPalette(p);

    ui->groupBox_hooper->setStyleSheet("QGroupBox { color: white;border: 0px;background-color:#414870}");

    welcome = new welcome_widget;
    view_db = new search_widget;
    add_db = new add_widget;
    discover_db = new discover_widget;
    about_db = new about_widget;
    update_db = new update_widget;

    ui->stack_widget->addWidget(welcome);
    ui->stack_widget->addWidget(view_db);
    ui->stack_widget->addWidget(add_db);
    ui->stack_widget->addWidget(discover_db);
    ui->stack_widget->addWidget(update_db);
    ui->stack_widget->addWidget(about_db);

    ui->stack_widget->setCurrentIndex(0);
    ui->stack_widget->show();

    menuButtons = new QButtonGroup;
    menuButtons->addButton(ui->button_view_database,0);
    menuButtons->addButton(ui->button_add_database,1);
    menuButtons->addButton(ui->button_discover,2);
    menuButtons->addButton(ui->button_update,3);
    menuButtons->addButton(ui->button_about,4);




}

void MainWindow::setButtonClicked(int index)
{

    for(int i = 0; i <= 4; i++)
    {
        if(i != index-1){
            menuButtons->button(i)->setStyleSheet("QPushButton { color: #ACADB1;}");
        }

    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_view_database_clicked()
{
    qDebug()<<"should change";
    ui->stack_widget->setCurrentIndex(1);
    ui->button_view_database->setStyleSheet("QPushButton { color: white;}");
    selectedIndex = 1;
    setButtonClicked(selectedIndex);

    view_db->populateTableAtIndex(1,-1,0);
    view_db->populateTableAtIndex(2,-1,0);
    view_db->populateTableAtIndex(3,-1,0);

}

void MainWindow::on_button_add_database_clicked()
{
    ui->stack_widget->setCurrentIndex(2);
    ui->button_add_database->setStyleSheet("QPushButton { color: white;}");
    selectedIndex = 2;
    setButtonClicked(selectedIndex);

}



void MainWindow::on_button_discover_clicked()
{
    ui->stack_widget->setCurrentIndex(3);
    ui->button_discover->setStyleSheet("QPushButton { color: white;}");
    selectedIndex = 3;
    setButtonClicked(selectedIndex);

}

void MainWindow::on_button_about_clicked()
{
    ui->stack_widget->setCurrentIndex(5);
    ui->button_about->setStyleSheet("QPushButton { color: white;}");
    selectedIndex = 5;
    setButtonClicked(selectedIndex);

}

void MainWindow::on_button_update_clicked()
{
    ui->stack_widget->setCurrentIndex(4);
    ui->button_update->setStyleSheet("QPushButton { color: white;}");
    selectedIndex = 4;
    setButtonClicked(selectedIndex);

    update_db->populateTablePioneers();
    update_db->populateTableConnections();
    update_db->populateTableComputers();


}
