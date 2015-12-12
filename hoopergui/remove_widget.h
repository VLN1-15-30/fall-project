#ifndef REMOVE_WIDGET_H
#define REMOVE_WIDGET_H

#include <QWidget>

namespace Ui {
class remove_widget;
}

class remove_widget : public QWidget
{
    Q_OBJECT

public:
    explicit remove_widget(QWidget *parent = 0);
    ~remove_widget();

private:
    Ui::remove_widget *ui;
};

#endif // REMOVE_WIDGET_H
