#include "discover_widget.h"
#include "ui_discover_widget.h"
#include <cstdlib>

discover_widget::discover_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::discover_widget)
{
    ui->setupUi(this);


    setUpUI();
    discover();
}

void discover_widget::discover()
{
    int i = rand() % 3 + 1;
    switch (i) {
    case 1:{

        ui->label_target->setText("Pioneer");
        person p = hpList.discoverPerson();

        QString first = QString::fromStdString(p.getFirstName());
        QString last = QString::fromStdString(p.getLastName());
        QString gender = QString::fromStdString(p.getSex());
        QString born = QString::number(p.getBorn());
        QString died = QString::number(p.getDied());

        if(gender == "m"){
            gender = "Male";
        }
        else if (gender == "f"){
            gender = "Female";
        }

        ui->label_target_1->setText(first);
        ui->label_target_2->setText(last);
        ui->label_target_3->setText(gender);
        ui->label_target_4->setText(born);
        ui->label_target_5->setText(died);

        ui ->label_define_1->setText("First name:");
        ui ->label_define_2->setText("Last name:");
        ui ->label_define_3->setText("Gender:");
        ui ->label_define_4->setText("Year born:");
        ui ->label_define_5->setText("Year died:");

    }
    break;
    case 2:{

        ui->label_target->setText("Computer");
        computer c = hpList.discoverComputer();

        QString name = QString::fromStdString(c.getName());
        QString type = QString::fromStdString(c.getType());
        QString year = QString::number(c.getYearMade());
        QString made;

        bool wasMade = c.getWasMade();
        if(wasMade){
            made = "YES";
        }
        else{
            made = "NO";

        }

        ui->label_target_1->setText(name);
        ui->label_target_2->setText(type);
        ui->label_target_3->setText(year);
        ui->label_target_4->setText(made);
        ui->label_target_5->setText("");

        ui ->label_define_5->setText("");
        ui ->label_define_1->setText("Name:");
        ui ->label_define_2->setText("Type:");
        ui ->label_define_3->setText("Year made:");
        ui ->label_define_4->setText("was made:");
        ui ->label_define_5->setText("");

    }
    break;
    case 3:{

        ui->label_target->setText("Connection");
        connection c = hpList.discoverConnection();

        QString first = QString::fromStdString(c.getFirstName());
        QString last = QString::fromStdString(c.getLastName());
        QString computer = QString::fromStdString(c.getComputerName());
        QString year = QString::number(c.getYearInvented());

        ui->label_target_1->setText(first);
        ui->label_target_2->setText(last);
        ui->label_target_3->setText(computer);
        ui->label_target_4->setText(year);
        ui->label_target_5->setText("");

        ui ->label_define_1->setText("First name:");
        ui ->label_define_2->setText("Last name:");
        ui ->label_define_3->setText("Computer:");
        ui ->label_define_4->setText("Year made:");
        ui ->label_define_5->setText("");

    }
    break;
    default:
        break;
    }
}

void discover_widget::setUpUI()
{
    ui->label_info->setStyleSheet("QLabel {color: white;}");
    ui->label_define_1->setStyleSheet("QLabel {color: white;}");
    ui->label_define_2->setStyleSheet("QLabel {color: white;}");
    ui->label_define_3->setStyleSheet("QLabel {color: white;}");
    ui->label_define_4->setStyleSheet("QLabel {color: white;}");
    ui->label_define_5->setStyleSheet("QLabel {color: white;}");

    ui->label_target->setStyleSheet("QLabel {color: white;}");
    ui->label_target_1->setStyleSheet("QLabel {color: white;}");
    ui->label_target_2->setStyleSheet("QLabel {color: white;}");
    ui->label_target_3->setStyleSheet("QLabel {color: white;}");
    ui->label_target_4->setStyleSheet("QLabel {color: white;}");
    ui->label_target_5->setStyleSheet("QLabel {color: white;}");
}

discover_widget::~discover_widget()
{
    delete ui;
}


void discover_widget::on_pushButton_discover_clicked()
{
  discover();
}
