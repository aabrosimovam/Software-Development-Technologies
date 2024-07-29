#include <QTimer>
#include <QThread>
#include <iostream>
#include <QCoreApplication>
#include "checkstatus.h"
#include "file_printer.h"
#include "state_file.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Monitor &monitor = Monitor::Instance();
    //Monitor monitor;
    FilePrinter testprinter(monitor);

    monitor.AddFile("A.txt");
    monitor.AddFile("AA.txt");
    monitor.AddFile("AAA.txt");

    while(true)
    {
       //бесконечный цикл с проверкой состояния файла каждую секунду
       QThread::msleep(1000);
       monitor.updateState();
    }

    return a.exec();

}
