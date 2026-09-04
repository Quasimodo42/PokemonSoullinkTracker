#include "admineinstellungen.h"
#include "adminpokemonchange.h"
#include "ui_admineinstellungen.h"

AdminEinstellungen::AdminEinstellungen(SoulLinkTeam *slt, QWidget *parent)
    : QDialog(parent), ui(new Ui::AdminEinstellungen)
    , slt(slt)
{
    ui->setupUi(this);
}

AdminEinstellungen::~AdminEinstellungen()
{
    delete ui;
}

void AdminEinstellungen::on_pushButton_pressed()
{
    AdminPokemonChange adminPokeChange(slt, this);
    adminPokeChange.exec();
}

