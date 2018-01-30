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
}

NewProjectDialog::~NewProjectDialog()
{
    delete ui;
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
            if(!QDir(path).exists()) {
                QDir().mkdir(path);
            }

            QDir().mkdir(path + "/Animations");
            QDir().mkdir(path + "/Audio");
            QDir().mkdir(path + "/Charsets");
            QDir().mkdir(path + "/Fonts");
            QDir().mkdir(path + "/Maps");
            QDir().mkdir(path + "/Sound effects");
            QDir().mkdir(path + "/Sprites");
            QDir().mkdir(path + "/Tileset");

            QString file_name = path + "/" + ui->project_name_field->text() + ".asp";
            QFile file(file_name);

            if(file.open(QIODevice::ReadWrite)) {
                QTextStream stream(&file);
                stream << "project_name:" + ui->project_name_field->text() << endl;
            }

            file.close();

            QMessageBox::information(this, tr("Information"),
                                     tr("Le projet à bien été créé !"),
                                     QMessageBox::Ok);
            this->close();
        }
        catch(...) {
            QMessageBox::critical(this, tr("Erreur"),
                                  tr("Une erreur critique est survenue !\n"
                                     "Veuillez réessayer ultérieurement ou contacter le développeur."),
                                  QMessageBox::Ok);
        }
    }
}

void NewProjectDialog::on_button_box_rejected()
{
    this->close();
}
