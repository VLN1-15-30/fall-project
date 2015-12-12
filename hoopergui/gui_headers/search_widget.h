#ifndef SEARCH_WIDGET_H
#define SEARCH_WIDGET_H

#include <QWidget>

namespace Ui {
class search_widget;
}

class search_widget : public QWidget
{
    Q_OBJECT

public:
    explicit search_widget(QWidget *parent = 0);
    ~search_widget();

private:
    Ui::search_widget *ui;
};

#endif // SEARCH_WIDGET_H
