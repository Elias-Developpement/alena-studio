#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <QSettings>
#include <QMap>
#include <QList>

class Project
{
public:
    Project();

    bool is_opened();
    int open_project(QString path);
    int save_project();
    void close();
    void create_project(QString path_project, QString name_project);
    QString get_project_name();
    QString get_project_path();
    QList<QString> get_map_list();
private:
    QString project_path;
    QString project_name;
    QSettings settings;
    static QMap<QString, QVariant> default_values;
    //QList<QString> map_list;

};

#endif // PROJECT_H
