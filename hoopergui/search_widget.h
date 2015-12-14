#ifndef SEARCH_WIDGET_H
#define SEARCH_WIDGET_H

#include <QWidget>
#include <string>
#include "Services/list.h"


using namespace std;

namespace Ui {
class search_widget;
}

class search_widget : public QWidget
{
    Q_OBJECT

public:
    explicit search_widget(QWidget *parent = 0);
    void setUpUi();
    void populateTableAtIndex(int index);
    ~search_widget();

private slots:
    void on_tab_search_tabBarClicked(int index);

    void on_comboBox_pioneers_currentIndexChanged(const QString &arg1);

    void on_lineEdit_pioneers_textChanged(const QString &arg1);

private:
    Ui::search_widget *ui;
    List hpList;
};

#endif // SEARCH_WIDGET_H
