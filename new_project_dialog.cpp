#include "new_project_dialog.h"
#include "ui_new_project_dialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    ui->setupUi(this);
    validate = false;
}

NewProjectDialog::~NewProjectDialog()
{
    delete ui;
}

bool NewProjectDialog::get_validate() {
    return validate;
}

void NewProjectDialog::set_validate(bool action) {
    validate = action;
}

void NewProjectDialog::set_project(Project *p) {
    project = p;
}

void NewProjectDialog::on_path_project_button_clicked()
{
    // Select a folder for the project path
    QString dir = QFileDialog::getExistingDirectory(this, tr("Sélectionnez l'emplacement du projet"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    ui->path_project_field->setText(dir);
}

void NewProjectDialog::on_button_box_accepted()
{
    // Form accepted

    // Check if project name and path project are not empty
    if(ui->project_name_field->text() != "" && ui->path_project_field->text() != "") {
        QString path = ui->path_project_field->text() + "/" + ui->project_name_field->text();
        try {
            project->create_project(path, ui->project_name_field->text());
            QMessageBox::information(this, tr("Informaiton"),
                                     tr("Le projet à bien été créé."),
                                     QMessageBox::Ok);
            set_validate(true);
            this->close();
        }
        catch(...) {
            QMessageBox::critical(this, tr("Erreur"),
                                  tr("Une erreur critique est survenue !\n"
                                     "Veuillez réessayer ultérieurement ou contacter le développeur."),
                                  QMessageBox::Ok);
            QApplication::quit();
        }
    }
    else {
        QMessageBox::information(this, tr("Erreur"),
                                 tr("Veuillez remplir tous les champs correctement."),
                                 QMessageBox::Ok);
    }
}

void NewProjectDialog::on_button_box_rejected()
{
    this->close();
}
