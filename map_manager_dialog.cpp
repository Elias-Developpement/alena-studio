#include "map_manager_dialog.h"
#include "ui_map_manager_dialog.h"
#include <QFile>

MapManagerDialog::MapManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapManagerDialog)
{
    ui->setupUi(this);
}

MapManagerDialog::~MapManagerDialog()
{
    delete ui;
}

void MapManagerDialog::set_project(Project *p) {
    project = p;
    this->map_tree_update();
}

void MapManagerDialog::map_tree_update() {
    QList<QString> map_list = project->get_map_list();

    map_count = map_list.size();

    ui->map_tree->clear();

    for(int i = 1 ; i <= map_list.size() ; i++) {
        QTreeWidgetItem *item = new QTreeWidgetItem;
        // Map ID
        item->setData(0,Qt::DisplayRole, i);
        // Map Name
        item->setData(1,Qt::DisplayRole, map_list.at(i - 1));
        // Add map on tree widget
        ui->map_tree->addTopLevelItem(item);
    }
}

void MapManagerDialog::on_map_add_button_clicked()
{
    QString map_id = QStringLiteral("%1").arg((map_count + 1));
    // Add a new map
    QFile file(project->get_project_path() + "/Maps/map" + map_id + ".map");
    if(file.open(QIODevice::ReadWrite)) {
        file.close();
    }

    this->map_tree_update();

}

void MapManagerDialog::on_map_delete_button_clicked()
{
    // Delete selected map
}

void MapManagerDialog::on_validate_button_clicked()
{
    // Close modal
    this->close();
}
