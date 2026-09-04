#ifndef SOULLINKTEAM_H
#define SOULLINKTEAM_H

#include "trainer.h"

#include <QVector>

class SoulLinkTeam
{
private:
    QVector<std::shared_ptr<Trainer>> team;
public:
    SoulLinkTeam();

    void readPokeJSON(const QString& filename);
    void writePokeJSON(const QString& filename) const;

    void showTeam() const; //debug
    const QVector<std::shared_ptr<Trainer>>& getTeam() const;

    void addTrainer(std::shared_ptr<Trainer> trainer);
    void clearTeam();
};

#endif // SOULLINKTEAM_H
