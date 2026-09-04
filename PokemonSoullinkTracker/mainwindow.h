#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "soullinkteam.h"
#include "admineinstellungen.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_actionJSON_lesen_triggered();

    void on_pushButtonReLoad_pressed();

    void on_action_ndere_den_JSON_Dateipfad_triggered();

    void on_action_ffne_Admin_Einstellungen_triggered();

private:
    Ui::MainWindow *ui;

    SoulLinkTeam slt;

    void changeJsonUrl();

    void updateUi();

    void loadPokeData();
};
#endif // MAINWINDOW_H
