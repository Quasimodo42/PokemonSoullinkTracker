#ifndef ADMINPOKEMONCHANGE_H
#define ADMINPOKEMONCHANGE_H

#include "soullinkteam.h"

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class AdminPokemonChange;
}

class AdminPokemonChange : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPokemonChange(SoulLinkTeam *slt, QWidget *parent = nullptr);
    ~AdminPokemonChange();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AdminPokemonChange *ui;

    SoulLinkTeam *slt;

    QVector<QVector<QLineEdit*>> teamLineEditGrid;

    void loadLineEdits();
};

#endif // ADMINPOKEMONCHANGE_H
