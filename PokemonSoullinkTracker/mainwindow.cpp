#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include <QLineEdit>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    slt.clearTeam();
    slt.addTrainer(std::make_shared<Trainer>("Jannis"));
    slt.addTrainer(std::make_shared<Trainer>("Jonah"));
    slt.addTrainer(std::make_shared<Trainer>("Luis"));
    slt.addTrainer(std::make_shared<Trainer>("Alex"));

    loadPokeData();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionJSON_lesen_triggered()
{
    slt.writePokeJSON("testJSON.json");
}


void MainWindow::on_pushButtonReLoad_pressed()
{
    QSettings settings;
    QString savedPath = settings.value("jsonFilePath", "").toString();



    try {
        slt.readPokeJSON(savedPath);
        updateUi();
    } catch (std::exception& e) {
        QMessageBox::critical(this, "Fehler", e.what());
    }

}

void MainWindow::changeJsonUrl()
{
    QSettings settings;
    QString filename = QFileDialog::getOpenFileName(this, "Wähle die Soullink JSON aus", "", "JSON Dateien (*.json);;AlleDateien (*)");

    settings.setValue("jsonFilePath", filename);
}

void MainWindow::updateUi()
{

    ui->listWidget_Alex1->clear();
    ui->listWidget_Jannis1->clear();
    ui->listWidget_Jonah1->clear();
    ui->listWidget_Luis1->clear();
    ui->listWidget_Jannis2->clear();

    const auto& trainers = slt.getTeam();

    // 3. Über die Trainer und deren Pokémon iterieren
    for (const auto& trainerPtr : trainers) {
        if (!trainerPtr) continue; // Sicherheitshalber auf Nullpointer prüfen

        // Annahme: Dein Trainer-Objekt hat eine Methode getName()
        QString trainerName = trainerPtr->getName();

        // Annahme: Dein Trainer-Objekt hat eine Methode getTeam(), die den Vector zurückgibt
        for (const auto& pokemon : trainerPtr->getTeamPokemon()) {
            // Annahme: Dein Pokemon-Objekt hat eine Methode getName()
            QString pokeName = pokemon->getName();

            // 4. Die Pokémon dem richtigen Widget zuordnen


        ui->listWidget_Luis2->addItem("gg");
        // daten aus logik holen und dann in die widgets reinladen

        if (trainerName == "Jannis") {
            ui->listWidget_Jannis1->addItem(pokeName);
        } else if (trainerName == "Jonah") {
            ui->listWidget_Jonah1->addItem(pokeName);
        } else if (trainerName == "Luis") {
            ui->listWidget_Luis1->addItem(pokeName);
        } else if (trainerName == "Alex") {
            ui->listWidget_Alex1->addItem(pokeName);
        }

        }

}
}

void MainWindow::loadPokeData()
{
    QSettings settings;

    QString savedPath = settings.value("jsonFilePath", "").toString();

    if (!savedPath.isEmpty()) {
        try {
            slt.readPokeJSON(savedPath);
        } catch (const std::exception& e) {
            QMessageBox::critical(this, "Kritische Fehler!", e.what());
        }
    }
}


void MainWindow::on_action_ndere_den_JSON_Dateipfad_triggered()
{
    changeJsonUrl();
}

void MainWindow::on_action_ffne_Admin_Einstellungen_triggered()
{
    bool ok;
    QString password = QInputDialog::getText(this,
                                             "Admin Login",
                                             "Bitte Admin-Passwort eingeben: ",
                                             QLineEdit::Password,
                                             "",
                                             &ok);

    if (ok && password == "NurLuisDarf") {
        AdminEinstellungen adminWindow(&slt, this);
        adminWindow.exec();
    } else if (ok) {
        QMessageBox::warning(this, "Zugriff verweigert", "Das ist nichts für dich du Hund!");
    }
}

