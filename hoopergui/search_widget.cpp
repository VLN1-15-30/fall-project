#include "search_widget.h"
#include "ui_search_widget.h"
#include <QDebug>

search_widget::search_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search_widget)
{
    ui->setupUi(this);
    setUpUi();
    populateTableAtIndex(1);

}

void search_widget::setUpUi(){

    ui->lineEdit_computers->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); color: black; }");
    ui->lineEdit_connections->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); color: black; }");
    ui->lineEdit_pioneers->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); color: black; }");
    ui->tab_search->setStyleSheet("QTabWidget::pane { border: 0; }QTabBar::tab { background-color: #34466E; color: #ACADB1 }");

    ui->comboBox_pioneers->setStyleSheet("QComboBox { border: 0; }}");
    ui->comboBox_computers->setStyleSheet("QComboBox { border: 0; }}");
    ui->comboBox_connections->setStyleSheet("QComboBox { border: 0; }}");

    ui->comboBox_pioneers->addItem("Last name");
    ui->comboBox_pioneers->addItem("Gender");
    ui->comboBox_pioneers->addItem("Year born");
    ui->comboBox_pioneers->addItem("Year of death");

    ui->comboBox_computers->addItem("Name");
    ui->comboBox_computers->addItem("Type");
    ui->comboBox_computers->addItem("Year made");
    ui->comboBox_computers->addItem("Was made");

    ui->tab_search->setCurrentIndex(0);

}

void search_widget::populateTableAtIndex(int index)
{
    switch (index) {
    case 1:  {

        vector<person>dbPersons = hpList.getPersons();

        ui->table_pioneers->clearContents();
        ui->table_pioneers->setRowCount(dbPersons.size());

        cout << "persons: " <<dbPersons.size()<<endl;

        for (unsigned int row = 0; row < dbPersons.size(); row++){

            person currentP = dbPersons[row];

            QString firstName = QString::fromStdString(currentP.getFirstName());
            QString lastname = QString::fromStdString(currentP.getLastName());
            QString gender = QString::fromStdString(currentP.getSex());

            ui->table_pioneers->setItem(row,0,new QTableWidgetItem(firstName));
            ui->table_pioneers->setItem(row,1,new QTableWidgetItem(lastname));
            ui->table_pioneers->setItem(row,2,new QTableWidgetItem(gender));

        }

    }
        break;
    default:
        break;
    }
}

search_widget::~search_widget()
{
    delete ui;
}

void search_widget::on_tab_search_tabBarClicked(int index)
{

}


void search_widget::on_comboBox_pioneers_currentIndexChanged(const QString &arg1)
{
    string currentSelection = ui->comboBox_pioneers->currentText().toStdString();
}

void search_widget::on_lineEdit_pioneers_textChanged(const QString &arg1)
{
    string currentText = ui->lineEdit_pioneers->text().toStdString();

}
