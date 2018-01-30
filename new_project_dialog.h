#ifndef NEW_PROJECT_DIALOG_H
#define NEW_PROJECT_DIALOG_H

#include "project.h"
#include <QDialog>

namespace Ui {
class NewProjectDialog;
}

class NewProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewProjectDialog(QWidget *parent = 0);
    ~NewProjectDialog();

    void set_project(Project *project);
    bool get_validate();

private slots:
    void on_path_project_button_clicked();

    void on_button_box_accepted();

    void on_button_box_rejected();

private:
    void set_validate(bool action);
    Ui::NewProjectDialog *ui;
    Project *project;
    bool validate;
};

#endif // NEW_PROJECT_DIALOG_H
