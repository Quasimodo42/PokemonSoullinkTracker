#ifndef POKEMON_H
#define POKEMON_H

#include <QString>

class Pokemon
{
private:
    QString name;
    QString nickname;
public:
    Pokemon();
    QString getName() const;
    QString getNickname() const;
};

#endif // POKEMON_H
