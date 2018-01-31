#include "project.h"
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QString>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QFileSystemModel>
#include <QFileInfo>

Project::Project()
{

}

// Check if the project exists
bool Project::is_opened() {
    if(project_path != "") {
        return QFileInfo::exists(project_path);
    }

    return false;
}

// Try to open a project
int Project::open_project(QString file_name) {
    if(QFileInfo::exists(file_name)) {
        if(file_name != "") {
            QString file_content;
            QFile file(file_name);
            if(file.open(QIODevice::ReadOnly)) {
                QTextStream stream(&file);
                file_content = stream.readAll();
            }

            file.close();

            // Regular expression to get the name of the project
            QRegularExpression re("^([a-zA-Z_]+): (<?variable>[a-zA-Z/_-]+)");
            QRegularExpressionMatch matchs = re.match(file_content);
            for(int i = 0 ; i <= matchs.lastCapturedIndex() ; i++) {
                if(matchs.captured(i) == "project_name") {
                    project_name = matchs.captured("variable");
                }
            }

            // Project Tree generation
            QFileSystemModel *model = new QFileSystemModel;
            QFileInfo file_info(file_name);
            QMessageBox msg;
            msg.setText(file_info.absolutePath());
            msg.exec();
            model->setRootPath("/" + file_info.absolutePath() + "/");
            project_path = file_info.absolutePath();
            project_name = file_info.baseName();
        }
        return 1;
    }

    return 0;
}

void Project::create_project(QString path_project, QString name_project) {
    if(!QDir(path_project).exists()) {
        QDir().mkdir(path_project);
    }

    QDir().mkdir(path_project + "/Animations");
    QDir().mkdir(path_project + "/Audio");
    QDir().mkdir(path_project + "/Charsets");
    QDir().mkdir(path_project + "/Fonts");
    QDir().mkdir(path_project + "/Maps");
    QDir().mkdir(path_project + "/Sound effects");
    QDir().mkdir(path_project + "/Sprites");
    QDir().mkdir(path_project + "/Tilesets");

    QString file_name = path_project + "/" + name_project + ".asp";

    project_name = name_project;
    project_path = path_project;

    if(this->save_project() == 1) {
        // Success
    }
    else {
        // Erreur
    }
}

// Try to save the project
int Project::save_project() {
    // Insert try catch
    try {
        QFile file(project_path + "/" + project_name + ".asp");

        // If file dosen't exist, it will be created
        if(file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            // Write into file
            stream << "project_name: " << project_name << endl;
            stream << "project_path: " << project_path << endl;
            stream << "--------------------" << endl;
            stream << "characters_data: " << project_path << "/Charsets/characters.data" << endl;
            stream << "tilesets_data: " << project_path << "/Tilesets/tilesets.data" << endl;
            stream << "animations_data: " << project_path << "/Animations/animations.data" << endl;
            stream << "maps_data: " << project_path << "/Maps/maps.data" << endl;
            file.close();
        }

        file.setFileName(project_path + "/Charsets/characters.data");
        if(file.open(QIODevice::ReadWrite)) {
            file.close();
        }

        file.setFileName(project_path + "/Tilesets/tilesets.data");
        if(file.open(QIODevice::ReadWrite)) {
            file.close();
        }

        file.setFileName(project_path + "/Animations/animations.data");
        if(file.open(QIODevice::ReadWrite)) {
            file.close();
        }

        file.setFileName(project_path + "/Maps/maps.data");
        if(file.open(QIODevice::ReadWrite)) {
            file.close();
        }

        // True, success
        return 1;
    }
    catch(...) {
        QMessageBox msg_box;
        msg_box.setText("Une erreur est survenue lors de la sauvegarde du projet !");
        msg_box.exec();
    }

    // False, wrong save
    return 0;
}

void Project::close() {
    project_name = "";
    project_path = "";
}

QString Project::get_project_name() {
    QString file_name = project_path;
    QString project_name;
    QFile file(file_name);

    if(file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        //in >> "project_name:" >> project_name;
    }

    file.close();

    QMessageBox msg_box;
    //msg_box.text("Nom du projet : " + project_name);

    return project_name;
}

QString Project::get_project_path() {
    return project_path;
}
