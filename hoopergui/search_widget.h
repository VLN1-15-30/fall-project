#ifndef SEARCH_WIDGET_H
#define SEARCH_WIDGET_H

#include <QWidget>
#include <string>
#include "Services/list.h"


using namespace std;

namespace Ui {
class search_widget;
}

class search_widget : public QWidget
{
    Q_OBJECT

public:
    explicit search_widget(QWidget *parent = 0);
    void setUpUi();
    void populateTableAtIndex(int index, int order, int col);
    ~search_widget();

    void searchPeople(string search);
private slots:
    void on_tab_search_tabBarClicked(int index);

    void on_comboBox_pioneers_currentIndexChanged(int index);

    void on_lineEdit_pioneers_textChanged(const QString &arg1);

    void on_table_pioneers_clicked(const QModelIndex &index);

    void on_table_computers_clicked(const QModelIndex &index);

    void on_table_connections_clicked(const QModelIndex &index);

    void on_lineEdit_computers_textChanged(const QString &arg1);

    void on_lineEdit_connections_textChanged(const QString &arg1);

    void on_comboBox_Order_currentIndexChanged(int index);

private:
    Ui::search_widget *ui;
    List hpList;
    vector<person>dbPersons;
    string searchColumn;
};

#endif // SEARCH_WIDGET_H
