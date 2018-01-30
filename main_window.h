#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "new_project_dialog.h"
#include "project.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_menu_new_project_triggered();

    void on_menu_open_project_triggered();

    void on_menu_save_project_triggered();

    void on_menu_close_project_triggered();

    void on_menu_exit_triggered();

private:
    Ui::MainWindow *ui;
    NewProjectDialog new_project_dialog;
};

#endif // MAIN_WINDOW_H
