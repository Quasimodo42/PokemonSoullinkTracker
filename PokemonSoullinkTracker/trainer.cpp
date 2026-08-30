#include "trainer.h"

QString Trainer::getName() const
{
    return name;
}

QVector<std::unique_ptr<Pokemon> > Trainer::getTeamPokemon() const
{
    return teamPokemon;
}

QVector<std::unique_ptr<Pokemon> > Trainer::getBoxPokemon() const
{
    return boxPokemon;
}

QVector<std::unique_ptr<Pokemon> > Trainer::getDeadPokemon() const
{
    return deadPokemon;
}

Trainer::Trainer() {}
