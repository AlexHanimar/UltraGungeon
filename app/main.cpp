#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <Entities/MovableEntity.h>
#include <Model/EntityWrapper.h>
#include <Model/Model.h>
#include <Interface/MainWindow.h>

using namespace std;

int main(int argc, char** argv)
{
    QApplication::addLibraryPath("C:/Qt/6.5.0/mingw_64/plugins");
    QApplication::addLibraryPath("D:/Qt/6.5.0/mingw_64/plugins");
    QApplication app(argc, argv);
    auto* window = new MainWindow(10, {10000, 10000});
    window->show();
    return app.exec();
}
