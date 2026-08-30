#ifndef SOULLINKTEAM_H
#define SOULLINKTEAM_H

#include "trainer.h"

#include <QVector>

class SoulLinkTeam
{
private:
    QVector<std::unique_ptr<Trainer>> team;
public:
    SoulLinkTeam();

    void readPokeJSON();
    void writePokeJSON() const;

    void showTeam() const; //debug
};

#endif // SOULLINKTEAM_H
