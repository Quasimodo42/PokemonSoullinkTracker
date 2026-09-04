#ifndef TRAINER_H
#define TRAINER_H

#include "pokemon.h"

#include <QString>
#include <QVector>

class Trainer
{
private:
    QString name;
    QVector<std::shared_ptr<Pokemon>> teamPokemon;
    QVector<std::shared_ptr<Pokemon>> boxPokemon;
    QVector<std::shared_ptr<Pokemon>> deadPokemon;
public:
    Trainer(QString name) : name(name) {}

    QString getName() const;
    QVector<std::shared_ptr<Pokemon> > getTeamPokemon() const;
    QVector<std::shared_ptr<Pokemon> > getBoxPokemon() const;
    QVector<std::shared_ptr<Pokemon> > getDeadPokemon() const;

    void addTeamPokemon(std::shared_ptr<Pokemon> p);
    void addBoxPokemon(std::shared_ptr<Pokemon> p);
    void addDeadPokemon(std::shared_ptr<Pokemon> p);

    void clearTeamPokemon();
    void clearBoxPokemon();
    void clearDeadPokemon();

};

#endif // TRAINER_H
