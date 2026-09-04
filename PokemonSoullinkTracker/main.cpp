#include "mainwindow.h"
#include "soullinkteam.h"

#include <QApplication>

#ifdef Q_OS_WIN
#include "winsparkle.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("SoulLinkTeam");
    QCoreApplication::setApplicationName("TrackerApp");

#ifdef Q_OS_WIN
    win_sparkle_set_appcast_url("https://quasimodo42.github.io/PokemonSoullinkTracker/appcast.xml");

    win_sparkle_set_app_details(L"Quasimodo42", L"PokemonSoullinkTracker", L"0.1");

    win_sparkle_init();

    // Debug: Öffne sofort winsparkle PopUp
    //win_sparkle_check_update_with_ui();
#endif


    MainWindow w;
    w.show();

#ifdef Q_OS_WIN
    win_sparkle_cleanup();
#endif

    // AB HIER MAIN CODE:


    //return 0;
    return QApplication::exec();
}

//TODO NOTES:
/*
 * In Mainwindow: Widgets müssen verschwinden wenn leer!
 *
 *
 *
 */

