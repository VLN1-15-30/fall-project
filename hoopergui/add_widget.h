#ifndef ADD_WIDGET_H
#define ADD_WIDGET_H

#include <QWidget>
#include <person.h>
#include <string>
#include <iostream>
#include <vector>
#include <computer.h>
#include <fstream>
#include <algorithm>
#include <QtSql>
#include <Services/list.h>

namespace Ui {
class add_widget;
}

class add_widget : public QWidget
{
    Q_OBJECT

public:
    explicit add_widget(QWidget *parent = 0);
    bool errorCheck();
    void clearContents(int index);
    ~add_widget();

private slots:
    void on_pushButton_add_pioneer_clicked();

    void on_pushButton_add_computer_clicked();

    void on_pushButton_add_connection_clicked();

private:
    List ComputerScientist;
    Ui::add_widget *ui;
    string currentError;
};

#endif // ADD_WIDGET_H
