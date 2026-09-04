#ifndef ADMINEINSTELLUNGEN_H
#define ADMINEINSTELLUNGEN_H

#include "adminpokemonchange.h"
#include "soullinkteam.h"

#include <QDialog>

namespace Ui {
class AdminEinstellungen;
}

class AdminEinstellungen : public QDialog
{
    Q_OBJECT

public:
    explicit AdminEinstellungen(SoulLinkTeam *slt, QWidget *parent = nullptr);
    ~AdminEinstellungen();

private slots:
    void on_pushButton_pressed();

private:
    Ui::AdminEinstellungen *ui;

    SoulLinkTeam *slt;
};

#endif // ADMINEINSTELLUNGEN_H
