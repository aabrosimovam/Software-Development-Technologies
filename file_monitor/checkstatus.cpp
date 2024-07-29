#include "checkstatus.h"
#include <QTimer>

Monitor &Monitor::Instance()
{
    static Monitor object;
    return object;
}

bool Monitor::AddFile(const QString & filename) //добавление файла в монитор
{
    StateFile temp(filename); // новый файл для проверки на наличие нужного файла
    if (objects.contains(temp))
    {
        return false;
    }
    objects.append(temp); //если файла нет в списке, то добавляем
    emit FileAddMon(temp); //имит. сигнал о добавлении файла
}

bool Monitor::DeleteFile(const QString & filename) //удаление файла из монитора
{
    StateFile temp(filename); // новый файл для проверки
    if (objects.contains(temp))
    {
        objects.removeOne(temp); //если файл есть в списке, то удаляем
        emit FileDeleteMon(temp); //имит. сигнал об удалении файла
        return true;
    }
    return false;
}

void Monitor::updateState() //функция на обновление данных о файле
{
    for (int i=0; i<objects.size(); i++) //для каждого файла проверяем данные о нем
    {
        switch (objects[i].udFile())
        {
        case 0:
            emit fileCreate(objects[i].getFName(),objects[i].getFSize());
            //сигнал о создании файла
            break;
        case 1:
            emit fileChange(objects[i].getFName(),objects[i].getFSize());
            //сигнал об изменение файла
            break;
        case 2:
            emit fileDelete(objects[i].getFName());
            //сигнал об удалении файла
            break;
        case 3:
            break; //ничего не поменялось
        };

    }
}
