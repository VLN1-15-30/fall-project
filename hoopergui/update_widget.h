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
    void populateTablePioneers();
    void populateTableComputers();
    void populateTableConnections();
    ~update_widget();

private slots:
    void on_tableView_pioneers_2_cellChanged(int row, int column);

    void on_tableView_computers_2_cellChanged(int row, int column);

private:
    Ui::update_widget *ui;
    List hpList;
    bool loading;
};

#endif // UPDATE_WIDGET_H
