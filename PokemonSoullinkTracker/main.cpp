#include "mainwindow.h"

#include <QApplication>

#ifdef Q_OS_WIN
#include "winsparkle.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef Q_OS_WIN
    win_sparkle_set_appcast_url("https://quasimodo42.github.io/PokemonSoullinkTracker/appcast.xml");

    win_sparkle_set_app_details(L"Quasimodo42", L"PokemonSoullinkTracker", L"0.1");

    win_sparkle_init();
#endif


    MainWindow w;
    w.show();

#ifdef Q_OS_WIN
    win_sparkle_cleanup();
#endif

    return QApplication::exec();
}
