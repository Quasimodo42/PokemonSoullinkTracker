#include "soullinkteam.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

const QVector<std::shared_ptr<Trainer>>& SoulLinkTeam::getTeam() const
{
    return team;
}

void SoulLinkTeam::addTrainer(std::shared_ptr<Trainer> trainer)
{
    team.append(trainer);
}

void SoulLinkTeam::clearTeam()
{
    team.clear();
}

SoulLinkTeam::SoulLinkTeam() {}

void SoulLinkTeam::readPokeJSON(const QString &filename)
{

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        throw std::runtime_error("Pokedaten konnten nicht gelesen werden: " +
                                 file.errorString().toStdString());
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &parseError);

    if (jsonDoc.isNull() || parseError.error != QJsonParseError::NoError) {
        throw std::runtime_error("JSON Parsing Fehler: " +
                                 parseError.errorString().toStdString());
    }

    if (!jsonDoc.isArray()) {
        throw std::runtime_error("Ungueltige JSON Struktur: Array erwartet.");
    }

    QJsonArray trainerArray = jsonDoc.array();

    int index = 0;
    for (const QJsonValue& trainerVal : trainerArray) {

        if (index >= team.size()) break;

        QJsonObject trainerObj = trainerVal.toObject();

        auto trainer = team[index];
        trainer->clearTeamPokemon();
        trainer->clearBoxPokemon();
        trainer->clearDeadPokemon();

        if (!trainerObj.contains("trainer")) {
            throw std::runtime_error("Ungueltige Struktur: trainer erwartet");
        }
        if (!trainerObj.contains("team")) {
            throw std::runtime_error("Ungueötige Struktur: team erwartet");
        }
        if (!trainerObj.contains("box")) {
            throw std::runtime_error("Ungueötige Struktur: box erwartet");
        }
        if (!trainerObj.contains("dead")) {
            throw std::runtime_error("Ungueötige Struktur: dead erwartet");
        }

        QJsonArray teamArray = trainerObj.value("team").toArray();

        for (const auto& teamPoke : teamArray) {
            QJsonObject pokeObj = teamPoke.toObject();

            if (!pokeObj.contains("name")) {
                throw std::runtime_error("Ungültige Struktur: name erwartet");
            }

            QString pokeName = pokeObj.value("name").toString("Unbekannt");

            std::shared_ptr<Pokemon> p = std::make_shared<Pokemon>(pokeName);

            trainer->addTeamPokemon(p);
        }

        QJsonArray boxArray = trainerObj.value("box").toArray();

        for (const auto& boxPoke : boxArray) {
            QJsonObject pokeObj = boxPoke.toObject();

            if (!pokeObj.contains("name")) {
                throw std::runtime_error("Ungültige Struktur: name erwartet");
            }

            QString pokeName = pokeObj.value("name").toString("Unbekannt");

            std::shared_ptr<Pokemon> p = std::make_shared<Pokemon>(pokeName);

            trainer->addBoxPokemon(p);
        }

        QJsonArray deadArray = trainerObj.value("dead").toArray();

        for (const auto& deadPoke : deadArray) {
            QJsonObject pokeObj = deadPoke.toObject();

            if (!pokeObj.contains("name")) {
                throw std::runtime_error("Ungültige Struktur: name erwartet");
            }

            QString pokeName = pokeObj.value("name").toString("Unbekannt");

            std::shared_ptr<Pokemon> p = std::make_shared<Pokemon>(pokeName);

            trainer->addDeadPokemon(p);
        }

        index++;
    }
}

void SoulLinkTeam::writePokeJSON(const QString& filename) const
{
    if (team.isEmpty()) {
        throw std::runtime_error("Kein Pokemon Team geladen!");
    }

    QJsonArray trainerArray;

    for (const auto& trainer : team) {

        if (!trainer) continue;

        QJsonObject trainerObj;

        trainerObj.insert("trainer", trainer->getName());

        QJsonArray teamArray;
        for (const auto& teamPoke : trainer->getTeamPokemon()) {

            if (!teamPoke) continue;
            QJsonObject teamObj;

            teamObj.insert("name", teamPoke->getName());

            teamArray.append(teamObj);
        }

        trainerObj.insert("team", teamArray);

        QJsonArray boxArray;
        for (const auto& boxPoke : trainer->getBoxPokemon()) {

            if (!boxPoke) continue;
            QJsonObject boxObj;

            boxObj.insert("name", boxPoke->getName());

            boxArray.append(boxObj);
        }

        trainerObj.insert("box", boxArray);

        QJsonArray deadArray;
        for (const auto& deadPoke : trainer->getDeadPokemon()) {

            if (!deadPoke) continue;

            QJsonObject deadObj;

            deadObj.insert("name", deadPoke->getName());

            deadArray.append(deadObj);
        }

        trainerObj.insert("dead", deadArray);

        trainerArray.append(trainerObj);
    }

    QJsonDocument jsonDoc(trainerArray);

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        throw std::runtime_error("Datei konnte nicht zum Schreiben geoffnet werden: " +
                                 file.errorString().toStdString());
    }

    file.write(jsonDoc.toJson());
    file.close();
}













