#ifndef VIEW_WIDGET_H
#define VIEW_WIDGET_H

#include <QWidget>

namespace Ui {
class view_widget;
}

class view_widget : public QWidget
{
    Q_OBJECT

public:
    explicit view_widget(QWidget *parent = 0);
    ~view_widget();

private:
    Ui::view_widget *ui;
};

#endif // VIEW_WIDGET_H
