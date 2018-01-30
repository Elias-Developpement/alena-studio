#ifndef NEW_PROJECT_DIALOG_H
#define NEW_PROJECT_DIALOG_H

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

private slots:
    void on_path_project_button_clicked();

    void on_button_box_accepted();

    void on_button_box_rejected();

private:
    Ui::NewProjectDialog *ui;
};

#endif // NEW_PROJECT_DIALOG_H
