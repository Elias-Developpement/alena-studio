#include "project.h"
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QString>

Project::Project()
{
}

// Check if the project exists
bool Project::exist() {
    if(project_path != "") {
        return QFileInfo::exists(project_path);
    }

    return false;
}

// Try to open a project
int Project::open_project(QString path) {
    if(QFileInfo::exists(path)) {
        project_path = path;
        return 1;
    }

    return 0;
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
