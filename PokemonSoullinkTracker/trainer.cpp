#include "trainer.h"

QString Trainer::getName() const
{
    return name;
}

QVector<std::shared_ptr<Pokemon> > Trainer::getTeamPokemon() const
{
    return teamPokemon;
}

QVector<std::shared_ptr<Pokemon> > Trainer::getBoxPokemon() const
{
    return boxPokemon;
}

QVector<std::shared_ptr<Pokemon> > Trainer::getDeadPokemon() const
{
    return deadPokemon;
}

void Trainer::addTeamPokemon(std::shared_ptr<Pokemon> p)
{
    teamPokemon.append(p);
}

void Trainer::addBoxPokemon(std::shared_ptr<Pokemon> p)
{
    boxPokemon.append(p);
}

void Trainer::addDeadPokemon(std::shared_ptr<Pokemon> p)
{
    deadPokemon.append(p);
}

void Trainer::clearTeamPokemon()
{
    teamPokemon.clear();
}

void Trainer::clearBoxPokemon()
{
    boxPokemon.clear();
}

void Trainer::clearDeadPokemon()
{
    deadPokemon.clear();
}

