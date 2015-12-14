#include "add_widget.h"
#include "ui_add_widget.h"



add_widget::add_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_widget)
{
    ui->setupUi(this);
    //ui->->setStyleSheet("QLabel {color: white;}");

}

add_widget::~add_widget()
{
    delete ui;
}

void add_widget::on_pushButton_add_pioneer_clicked()
{
    string firstName = ui->input_firstname->text().toStdString();
    string lastName = ui->input_lastname->text().toStdString();
    string sex = ui->input_gender->text().toStdString();
    int yearBorn = ui->input__yearOfBirth->text().toInt();
    int yearDied = ui->input_yearOfDeath->text().toInt();

    /*
    if(firstName.isEmpty()) {

        return;
    }

    if(lastName.isEmpty()) {
        return;
    }

    if(sex.isEmpty()) {
       return;
    }

    if(yearDied.isEmpty()) {
        return;
    }
    */

    person p;
    p.setFirstName(firstName);
    p.setLastName(lastName);
    p.setSex(sex);
    p.setBorn(yearBorn);
    p.setDied(yearDied);

    bool check = ComputerScientist.addPerson(p);
    if(check) {
        cout << "Successfully added" << endl;
    }
        else{
        cout << "Failed to add" << endl;
    }

}


void add_widget::on_pushButton_add_computer_clicked()
{

    string computerName = ui->input_computer_name->text().toStdString();
    string computerType = ui->input_type->text().toStdString();
    int yearInvented = ui->input_yearBuilt->text().toInt();
    bool wasMade = ui->input_ifMade->text().toInt();

    computer c;
    c.setName(computerName);
    c.setType(computerType);
    c.setYearMade(yearInvented);
    c.setWasMade(wasMade);

    bool check = ComputerScientist.addComp(c);
    if(check) {
        cout << "Successfully added" << endl;
    }
        else {
        cout << "Failed to add" << endl;
    }

}

void add_widget::on_pushButton_add_connection_clicked()
{
     vector<person> p = ComputerScientist.getPersons();
     vector<computer> c = ComputerScientist.getComputers();

     string connectFirstName = ui->input_connect_firstname->text().toStdString();
     string connectLastName = ui->input_connect_lastname->text().toStdString();
     string connectCompName = ui->Input_connect_computer_name->text().toStdString();


    bool check = ComputerScientist.addConnection(connectFirstName, connectLastName, connectCompName);
    if(check) {
        cout << "Successfully added a new connection" << endl;
    }
        else {
        cout << "Failed to add" << endl;
    }
}

