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
    void populateTableAtIndex(int index);
    ~update_widget();

private:
    Ui::update_widget *ui;
    List hpList;
};

#endif // UPDATE_WIDGET_H
