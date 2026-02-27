#include "shakkikello.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Shakkikello w;
    w.show();
    return a.exec();
}
