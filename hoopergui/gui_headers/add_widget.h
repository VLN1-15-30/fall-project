#ifndef ADD_WIDGET_H
#define ADD_WIDGET_H

#include <QWidget>

namespace Ui {
class add_widget;
}

class add_widget : public QWidget
{
    Q_OBJECT

public:
    explicit add_widget(QWidget *parent = 0);
    ~add_widget();

private:
    Ui::add_widget *ui;
};

#endif // ADD_WIDGET_H
