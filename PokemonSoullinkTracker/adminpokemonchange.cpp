#include "adminpokemonchange.h"
#include "ui_adminpokemonchange.h"

#include <QSettings>
#include <QMessageBox>

AdminPokemonChange::AdminPokemonChange(SoulLinkTeam *slt, QWidget *parent)
    : QDialog(parent), ui(new Ui::AdminPokemonChange)
    , slt(slt)
{
    ui->setupUi(this);

    teamLineEditGrid = {
        {ui->lineEditJannis1, ui->lineEditJannis2, ui->lineEditJannis3, ui->lineEditJannis4, ui->lineEditJannis5, ui->lineEditJannis6},
        {ui->lineEditJonah1, ui->lineEditJonah2, ui->lineEditJonah3, ui->lineEditJonah4, ui->lineEditJonah5, ui->lineEditJonah6},
        {ui->lineEditLuis1, ui->lineEditLuis2, ui->lineEditLuis3, ui->lineEditLuis4, ui->lineEditLuis5, ui->lineEditLuis6},
        {ui->lineEditAlex1, ui->lineEditAlex2, ui->lineEditAlex3, ui->lineEditAlex4, ui->lineEditAlex5, ui->lineEditAlex6},
    };

    loadLineEdits();

}

AdminPokemonChange::~AdminPokemonChange()
{
    delete ui;
}

void AdminPokemonChange::on_buttonBox_accepted()
{
    const auto& team = slt->getTeam();

    for (int row = 0; row < teamLineEditGrid.size(); ++row) {

        if (row >= team.size()) {
            break;
        }
        auto uiSlots = teamLineEditGrid[row];
        std::shared_ptr<Trainer> trainer = team[row];

        trainer->clearTeamPokemon();
        trainer->clearBoxPokemon();
        trainer->clearDeadPokemon();

        for (int column = 0; column < teamLineEditGrid[row].size(); ++column) {
            QString pokemonName = uiSlots[column]->text().trimmed();

            if (!pokemonName.isEmpty()) {
                trainer->addTeamPokemon(std::make_shared<Pokemon>(pokemonName));
            }
        }
    }

    QSettings settings;
    QString savedPath = settings.value("jsonFilePath", "").toString();

    if (!savedPath.isEmpty()) {
        try {
            slt->writePokeJSON(savedPath);
        } catch (const std::exception& e) {
            QMessageBox::critical(this, "Kritischer Fehler!", e.what());
        }
    }

    accept();
}

void AdminPokemonChange::loadLineEdits()
{
    const auto& team = slt->getTeam();

    for (int row = 0; row < teamLineEditGrid.size(); row++) {

        if (row >= team.size()) break;

        auto trainer = team.at(row);
        auto uiSlots = teamLineEditGrid.at(row);
        auto teamPokemon = trainer->getTeamPokemon();

        for (auto lineEdit : uiSlots) {
            lineEdit->setPlaceholderText("---");
            lineEdit->clear();
        }

        for (int col = 0; col < uiSlots.size(); col++) {

            if (col >= teamPokemon.size()) break;

            QString pokeName = teamPokemon.at(col)->getName();
            uiSlots.at(col)->setText(pokeName);
        }
    }
}

