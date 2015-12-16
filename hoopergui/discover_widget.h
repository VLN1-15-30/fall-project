#ifndef DISCOVER_WIDGET_H
#define DISCOVER_WIDGET_H

#include <QWidget>
#include "Services/list.h"

namespace Ui {
class discover_widget;
}

class discover_widget : public QWidget
{
    Q_OBJECT

public:
    explicit discover_widget(QWidget *parent = 0);
    void discover();
    void setUpUI();
    ~discover_widget();

private slots:
    void on_pushButton_discover_clicked();

private:
    Ui::discover_widget *ui;
    List hpList;
};

#endif // DISCOVER_WIDGET_H
