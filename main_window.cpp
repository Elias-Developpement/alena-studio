#include "main_window.h"
#include "ui_main_window.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QRegularExpression>
#include <QFileSystemModel>
#include <QMenu>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage(tr("Prêt"));

    /*QMenu menu;
    new_map_action = new QAction(
                     tr("Edit"), this);
    addAction(new_map_action);*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_menu_new_project_triggered()
{
    // Create a new projet
    NewProjectDialog new_project_dialog;
    new_project_dialog.set_project(&project);
    if(new_project_dialog.exec()) {

    }
    if(new_project_dialog.get_validate()) {
        // Update the main window
        context_menu_update();
    }

}

void MainWindow::on_menu_open_project_triggered()
{
    // Open an existing project
    QString project_name;
    QString file_content;

    ui->statusBar->showMessage(tr("Ouverture d'un projet..."));

    QString dir = QFileDialog::getOpenFileName(this, tr("Ouvrir un projet"),
                                                    "/home",
                                                    tr("Alena Studio Project (*.asp)"));

    if(project.open_project(dir) == 1) {
        // Project opened
        context_menu_update();
    }
    else {

    }

    ui->statusBar->showMessage(tr("Prêt"));
}

void MainWindow::context_menu_update() {
    // There is an opened project
    ui->menu_save_project->setEnabled(project.is_opened());
    ui->menu_close_project->setEnabled(project.is_opened());
    ui->menu_characters->setEnabled(project.is_opened());
    ui->menu_ennemies->setEnabled(project.is_opened());
    ui->menu_common_events->setEnabled(project.is_opened());
    ui->menu_tilesets->setEnabled(project.is_opened());
    ui->menu_animations->setEnabled(project.is_opened());
}

void MainWindow::on_menu_save_project_triggered()
{
    // Save the current project
    try {
        project.save_project();
    }
    catch(...) {
        QMessageBox msg;
        msg.setText("Une erreur est survenue lors de la sauvegarde du projet");
        msg.exec();
    }
}

void MainWindow::on_menu_close_project_triggered()
{
    // Close the current project
    project.close();
    context_menu_update();
}

void MainWindow::on_menu_exit_triggered()
{
    // Quit Alena Studio
    QApplication::exit(0);
}
