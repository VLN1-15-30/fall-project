#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include "welcome_widget.h"
#include "discover_widget.h"
#include "add_widget.h"
#include "about_widget.h"
#include "search_widget.h"
#include "update_widget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    bool eventFilter(QObject *obj, QEvent *event);
    void setButtonColors();
    void trackHovers();
    void setUpHooper();
    void setButtonClicked(int index);

    ~MainWindow();


private slots:
    void on_button_view_database_clicked();

    void on_button_add_database_clicked();

    void on_button_discover_clicked();

    void on_button_about_clicked();

    void on_button_update_clicked();


private:
    Ui::MainWindow *ui;
    int selectedIndex;
    QButtonGroup * menuButtons;
    welcome_widget *welcome;
    search_widget *view_db;
    add_widget *add_db;
    discover_widget *discover_db;
    about_widget *about_db;
    update_widget *update_db;

};

#endif // MAINWINDOW_H
