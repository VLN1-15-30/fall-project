#ifndef UPDATE_WIDGET_H
#define UPDATE_WIDGET_H

#include <QWidget>
#include <vector>
#include "Services/list.h"

namespace Ui {
class update_widget;
}

class update_widget : public QWidget
{
    Q_OBJECT

public:
    explicit update_widget(QWidget *parent = 0);
    void setUpUi();
    void populateTablePioneers(int i);
    void populateTableComputers(int i);
    void populateTableConnections();
    void searchPerson(string search);
    void searchComputer(string search);

    ~update_widget();

private slots:
    void on_tableView_pioneers_2_cellChanged(int row, int column);

    void on_tableView_computers_2_cellChanged(int row, int column);

    void on_updateComputer_clicked();

    void on_updateConnection_clicked();

    void on_updateTabs_currentChanged(int index);


    void on_lineEdit_person_textChanged(const QString &arg1);

    void on_comboBox_pioneers_currentIndexChanged(int index);

    void on_lineEdit_computers_textChanged(const QString &arg1);

    void on_comboBox_computers_currentIndexChanged(int index);

private:
    Ui::update_widget *ui;
    List hpList;
    vector<person> dbPersons;
    vector<computer> dbComputers;
    bool loading;
    string searchPersonColumn;
    string searchComputerColumn;
};

#endif // UPDATE_WIDGET_H
