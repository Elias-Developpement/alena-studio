#include "main_window.h"
#include "ui_main_window.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QRegularExpression>
#include <QFileSystemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage(tr("Prêt"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_menu_new_project_triggered()
{
    // Create a new projet
    new_project_dialog.exec();

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

    if(dir != "") {
        QFile file(dir);
        if(file.open(QIODevice::ReadOnly)) {
            QTextStream stream(&file);
            file_content = stream.readAll();
        }

        file.close();

        // Regular expression to get the name of the project
        QRegularExpression re("^project_name:(?<project_name>[a-zA-Z]+)");
        QRegularExpressionMatch match = re.match(file_content);
        if(match.hasMatch()) {
            project_name = match.captured("project_name");
        }

        QWidget::setWindowTitle("Alena Studio - " + project_name);

        // Project Tree generation
        QFileSystemModel *model = new QFileSystemModel;
        QFileInfo file_info(dir);
        QMessageBox msg;
        msg.setText(file_info.absolutePath());
        msg.exec();
        model->setRootPath("/" + file_info.absolutePath() + "/");
        ui->project_tree->setModel(model);
        ui->project_tree->setEnabled(true);
        ui->statusBar->showMessage(file_info.absolutePath());
    }

    ui->statusBar->showMessage(tr("Prêt"));
}

void MainWindow::on_menu_save_project_triggered()
{
    // Save the current project
}

void MainWindow::on_menu_close_project_triggered()
{
    // Close the current project
}

void MainWindow::on_menu_exit_triggered()
{
    // Quit Alena Studio
    QApplication::exit(0);
}
