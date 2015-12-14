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
    void displayPioneers();
    ~update_widget();

private slots:
    void on_updatePioneer_clicked();

private:
    Ui::update_widget *ui;
    List hpList;
};

#endif // UPDATE_WIDGET_H
