#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include "Utilities/utils.h"
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

    void on_button_search_database_clicked();

    void on_button_removefrom_database_clicked();

    void on_button_discover_clicked();

    void on_button_about_clicked();

    void on_button_update_clicked();


private:
    Ui::MainWindow *ui;
    int selectedIndex;
    QButtonGroup * menuButtons;

};

#endif // MAINWINDOW_H
