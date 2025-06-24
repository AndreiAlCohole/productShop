#include <QApplication>
#include "MainWindow.h"
#include "AppController.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppController controller;
    controller.loadData();  // Załaduj dane (plik lub pre-created)

    MainWindow w(&controller);
    w.show();

    return a.exec();
}
