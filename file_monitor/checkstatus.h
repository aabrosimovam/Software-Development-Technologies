#ifndef CHECKSTATUS_H
#define CHECKSTATUS_H
#include "state_file.h"

class Monitor : public QObject
{
    Q_OBJECT
private:

    Monitor() {}; //конструктор не доступен
    ~Monitor() {}; //как и деструктор
    Monitor(Monitor const&);
    Monitor &operator = (Monitor const&); //запрещаем копирование

    QList<StateFile> objects; // список самих files

public:

    //добавить и удалить файлы из списка QList
    bool AddFile(const QString &filename);
    bool DeleteFile(const QString &filename);

    static Monitor &Instance(); //паттерн singletone

signals:
    void FileAddMon(StateFile file); // файл добавлен под наблюдение -> сигнал
    void FileDeleteMon(StateFile file); // файл удален из под наблюдения -> сигнал
    void fileCreate(const QString &FName, qint64 FSize); // файл создали -> сигнал
    void fileChange(const QString &FName, qint64 FSize); // файл изменили -> сигнал
    void fileDelete(const QString &FName); // файл удалили -> сигнал

public slots:
    void updateState();

};


#endif // CHECKSTATUS_H
