#include "soullinkteam.h"

#include <QJsonArray>
#include <QJsonObject>

SoulLinkTeam::SoulLinkTeam() {}

void SoulLinkTeam::writePokeJSON() const
{
    if (team.isEmpty()) {
        throw std::runtime_error("Kein Pokemon Team geladen!");
    }

    QJsonArray jsonArray;

    for (const auto& trainer : team) {
        QJsonObject trainerObj;

        trainerObj.insert("trainer", trainer->getName());

        QJsonArray teamArray;

        for (const auto& poke : trainer->getTeamPokemon()) {
            QJsonObject teamObj;

            teamObj.insert("name", poke->getName());
            teamObj.insert("nickname", poke->getNickname());
        }
        // hier jetzt die Box und die Toten
    }

}
