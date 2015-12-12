#ifndef WELCOME_WIDGET_H
#define WELCOME_WIDGET_H

#include <QWidget>

namespace Ui {
class welcome_widget;
}

class welcome_widget : public QWidget
{
    Q_OBJECT

public:
    explicit welcome_widget(QWidget *parent = 0);
    ~welcome_widget();

private:
    Ui::welcome_widget *ui;
};

#endif // WELCOME_WIDGET_H
