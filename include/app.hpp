#ifndef APP_HPP
#define APP_HPP

#include <QGuiApplication>

class App : QGuiApplication
{
public:
    App(int, char **);
    int run();
private:
};

#endif // APP_HPP
