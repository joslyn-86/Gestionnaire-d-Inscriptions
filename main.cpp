#include "inscription.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    inscription w;
    w.show();
    return a.exec();
}
