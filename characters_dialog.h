#ifndef CHARACTERSDIALOG_H
#define CHARACTERSDIALOG_H

#include <QDialog>

namespace Ui {
class CharactersDialog;
}

class CharactersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CharactersDialog(QWidget *parent = 0);
    ~CharactersDialog();

private:
    Ui::CharactersDialog *ui;
};

#endif // CHARACTERSDIALOG_H
