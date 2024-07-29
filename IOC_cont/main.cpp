#include <QCoreApplication>
#include "ioc.h"
#include "computer.h"
#include "iprocessor.h"
#include <iostream>
using namespace std;

// инициализируем ненулевым числом
int IOC::s_nextTypeId = 1;

int main()
{
    IOC injector; // создаем объект контейнер

//------Example #1----------------
    // Регистрируем IProcessor с классом Intel, т.о. каждый раз запрашивая Iprocessor получаем объект Intel.
    injector.RegisterInstance<IProcessor, IntelProcessor>();
    injector.GetObject<IProcessor>()->SetterProcessor("Intel",x64,2.1); // получили процессор через иок контейнер установили в него параметры
    Computer computerIntel(injector.GetObject<IProcessor>().get()); // создали объект компьютер и установили в него процессор интел
    cout<<computerIntel.GetProcessor()<<endl; // вывели информацию о процессоре

//------Example #2----------------
    // Регистрируем IProcessor с классом AMD, т.о. каждый раз запрашивая Iprocessor получаем объект Amd;
    //то же самое для AMD
    injector.RegisterInstance<IProcessor, AMDProcessor>();
    injector.GetObject<IProcessor>()->SetterProcessor("AMD",x86,4.2);
    Computer computerAMD(injector.GetObject<IProcessor>().get());
    cout<<computerAMD.GetProcessor()<<endl;

        return 0;

}
