#include "characters_dialog.h"
#include "ui_characters_dialog.h"

CharactersDialog::CharactersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CharactersDialog)
{
    ui->setupUi(this);
}

CharactersDialog::~CharactersDialog()
{
    delete ui;
}
