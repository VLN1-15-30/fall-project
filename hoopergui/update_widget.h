#ifndef UPDATE_WIDGET_H
#define UPDATE_WIDGET_H

#include <QWidget>

namespace Ui {
class update_widget;
}

class update_widget : public QWidget
{
    Q_OBJECT

public:
    explicit update_widget(QWidget *parent = 0);
    ~update_widget();

private:
    Ui::update_widget *ui;
};

#endif // UPDATE_WIDGET_H
