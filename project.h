#ifndef PROJECT_H
#define PROJECT_H

#include <QString>

class Project
{
public:
    Project();

    bool exist();
    int open_project(QString path);
    QString get_project_name();
private:
    QString project_path;

};

#endif // PROJECT_H
