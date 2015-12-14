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
    void setUpUi();
    ~search_widget();

private slots:
    void on_tab_search_tabBarClicked(int index);

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::search_widget *ui;
};

#endif // SEARCH_WIDGET_H
