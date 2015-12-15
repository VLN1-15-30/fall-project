#include "add_widget.h"
#include "ui_add_widget.h"



add_widget::add_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_widget)
{
    ui->setupUi(this);
    ui->tab_add->setStyleSheet("QTabWidget::pane { border: 0; }QTabBar::tab { background-color: #34466E; color: #ACADB1 }");
    ui->tab_add->setCurrentIndex(0);
    ui->label_pioneer_error->setStyleSheet("QLabel { color: red;}");
    ui->label_computer_error_2->setStyleSheet("QLabel {color: red;}");
    ui->label_connection_error->setStyleSheet("QLabel {color: red;}");
}

bool add_widget::pioneerErrorCheck()
{

    if(ui->input_firstname->text().isEmpty()) {
        currentError = "Missing first name";
        return false;
    }

    if(ui->input_lastname->text().isEmpty()) {
        currentError = "Missing last name";

        return false;
    }

    if(ui->input_gender->text().isEmpty()) {
        currentError = "Missing gender (m/f)";

        return false;
    }

    if((ui->input_gender->text().toStdString() == "m") || (ui->input_gender->text().toStdString() == "f")) {
    }
    else{
        currentError = "Please type only m/f";
        return false;
    }

    if(ui->input__yearOfBirth->text().isEmpty()) {
        currentError = "Missing year of birth";

        return false;
    }



    if(ui->input__yearOfBirth->text().toInt() == 0 && ui->input__yearOfBirth->text() != "0"){
        currentError ="You must type a valid number for year born";

        return false;
    }


    if(ui->input_yearOfDeath->text().isEmpty()) {
        currentError = "Missing year of death (0 if still alive)";

        return false;
    }
    if(ui->input_yearOfDeath->text().toInt() == 0 && ui->input_yearOfDeath->text() != "0"){
        currentError = "You must type a valid number for year died";

        return false;
    }

    if(ui->input_yearOfDeath->text().toInt() < ui->input__yearOfBirth->text().toInt() && !(ui->input_yearOfDeath->text().toInt() == 0)) {
        currentError = "Year of death is smaller than year of birth";

        return false;
    }


    return true;

}

bool add_widget::computerErrorCheck()
{
  if(ui->input_computer_name->text().isEmpty()) {
      currentError = "Missing computer name";
      return false;
  }
  if(ui->input_type->text().isEmpty()) {
      currentError = "Missing computer type";
      return false;
  }
  if(ui->input_yearBuilt->text().isEmpty()) {
      currentError = "Missing year made" ;
      return false;
  }
  if(ui->input_ifMade->text().isEmpty()) {
      currentError = "Missing if made(0 if made, else 1)";
      return false;
  }

  if((ui->input_ifMade->text().toStdString() == "0") || (ui->input_ifMade->text().toStdString() == "1")) {
  }
  else{
      currentError = "Please type 0 if made, else 1";
      return false;
  }
  if(isdigit(ui->input_yearBuilt->text().toInt()) &&ui->input_yearBuilt->text().length() <= 4 ){
      currentError = "Please type only a valid year";
      return false;
  }


  return true;
}

bool add_widget::connectionErrorCheck() {
    if(ui->input_connect_firstname->text().isEmpty()) {
        currentError = "Missing first name";
        return false;
    }
    if(ui->input_connect_lastname->text().isEmpty()) {
        currentError = "Missing last name";
        return false;
    }
    if(ui->Input_connect_computer_name->text().isEmpty()) {
        currentError = "missing computer name";
        return false;
    }
    return true;
}

void add_widget::clearContents(int index)
{
    if(index == 1){
        ui->label_pioneer_error->setText("");
        ui->input_firstname->setText("");
        ui->input_lastname->setText("");
        ui->input_gender->setText("");
        ui->input_yearOfDeath->setText("");
        ui->input__yearOfBirth->setText("");

    }
    if(index == 2){
        ui->label_computer_error_2->setText("");
        ui->input_computer_name->setText("");
        ui->input_type->setText("");
        ui->input_yearBuilt->setText("");
        ui->input_ifMade->setText("");
    }
    if(index == 3) {
        ui->label_connection_error->setText("");
        ui->input_connect_firstname->setText("");
        ui->input_connect_lastname->setText("");
        ui->Input_connect_computer_name->setText("");
    }

}

add_widget::~add_widget()
{
    delete ui;
}

void add_widget::on_pushButton_add_pioneer_clicked()
{

    bool allOk = pioneerErrorCheck();

    if(allOk){

        string firstName = ui->input_firstname->text().toStdString();
        string lastName = ui->input_lastname->text().toStdString();
        string sex = ui->input_gender->text().toStdString();
        int yearBorn = ui->input__yearOfBirth->text().toInt();
        int yearDied = ui->input_yearOfDeath->text().toInt();

        person p;
        p.setFirstName(firstName);
        p.setLastName(lastName);
        p.setSex(sex);
        p.setBorn(yearBorn);
        p.setDied(yearDied);

        bool check = ComputerScientist.addPerson(p);
        if(check) {
            cout << "Successfully added" << endl;
            clearContents(1);
        }
            else{
            cout << "Failed to add" << endl;
        }

    }
    else{

        ui->label_pioneer_error->setText(QString::fromStdString(currentError));
    }


}


void add_widget::on_pushButton_add_computer_clicked()
{
    bool AllOk = computerErrorCheck();

    if(AllOk) {

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
        clearContents(2);
        }
            else {
        cout << "Failed to add" << endl;
            }
    }

    else{

        ui->label_computer_error_2->setText(QString::fromStdString(currentError));
    }

}

void add_widget::on_pushButton_add_connection_clicked()
{
    bool AllOk = connectionErrorCheck();

    if(AllOk) {
     vector<person> p = ComputerScientist.getPersons();
     vector<computer> c = ComputerScientist.getComputers();

     string connectFirstName = ui->input_connect_firstname->text().toStdString();
     string connectLastName = ui->input_connect_lastname->text().toStdString();
     string connectCompName = ui->Input_connect_computer_name->text().toStdString();


    bool check = ComputerScientist.addConnection(connectFirstName, connectLastName, connectCompName);
        if(check) {
        cout << "Successfully added a new connection" << endl;
        clearContents(3);
        }
            else {
        cout << "Failed to add" << endl;
            }
    }
    else {
        ui->label_connection_error->setText(QString::fromStdString(currentError));
    }
}

