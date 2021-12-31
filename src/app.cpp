#include "app.hpp"

App::App(int argc, char ** argv) : QGuiApplication(argc, argv)
{

}

int App::run()
{
    return QGuiApplication::exec();
}
