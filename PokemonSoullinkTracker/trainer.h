#ifndef TRAINER_H
#define TRAINER_H

#include "pokemon.h"

#include <QString>
#include <QVector>

class Trainer
{
private:
    QString name;
    QVector<std::unique_ptr<Pokemon>> teamPokemon;
    QVector<std::unique_ptr<Pokemon>> boxPokemon;
    QVector<std::unique_ptr<Pokemon>> deadPokemon;
public:
    Trainer();
    QString getName() const;
    QVector<std::unique_ptr<Pokemon> > getTeamPokemon() const;
    QVector<std::unique_ptr<Pokemon> > getBoxPokemon() const;
    QVector<std::unique_ptr<Pokemon> > getDeadPokemon() const;
};

#endif // TRAINER_H
