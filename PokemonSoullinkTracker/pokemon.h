#ifndef POKEMON_H
#define POKEMON_H

#include <QString>

class Pokemon
{
private:
    QString name;
public:
    Pokemon(QString name) :
        name(name) {}
    QString getName() const;
};

#endif // POKEMON_H
