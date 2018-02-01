#ifndef MAP_MANAGER_DIALOG_H
#define MAP_MANAGER_DIALOG_H

#include "project.h"
#include "main_window.h"
#include <QDialog>

namespace Ui {
class MapManagerDialog;
}

class MapManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MapManagerDialog(QWidget *parent = 0);
    ~MapManagerDialog();
    void set_project(Project *p);
    void map_tree_update();

private slots:
    void on_map_add_button_clicked();

    void on_map_delete_button_clicked();

    void on_validate_button_clicked();

private:
    Ui::MapManagerDialog *ui;
    Project *project;
    int map_count;
};

#endif // MAP_MANAGER_DIALOG_H
