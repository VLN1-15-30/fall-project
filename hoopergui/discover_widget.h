#ifndef DISCOVER_WIDGET_H
#define DISCOVER_WIDGET_H

#include <QWidget>

namespace Ui {
class discover_widget;
}

class discover_widget : public QWidget
{
    Q_OBJECT

public:
    explicit discover_widget(QWidget *parent = 0);
    ~discover_widget();

private:
    Ui::discover_widget *ui;
};

#endif // DISCOVER_WIDGET_H
