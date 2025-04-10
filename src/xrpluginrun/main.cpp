#include <QApplication>
#include <QWidget>

#include "liblog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LibLog::Instance()->init("./testaaaas.log");
    LOG_DEBUG("xrplubingrun init");
    QWidget w;
    w.show();
    LOG_DEBUG("xrplubingrun exit");
    return a.exec();
}