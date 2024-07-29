#include "file_printer.h"

// добавление файла в монитор(!)
void FilePrinter :: FP_FileAddMon(StateFile file)
{
    cout<<"File [ "<<file.getFName().toStdString()<< " ] was added to MONITOR. Size = "<<file.getFSize()<<endl;
    if (file.getExistStatus())
    {
        cout<<"File exist"<<endl;
    }
    else cout<<"File dosn't exist"<<endl;
}

//удаление файла из монитора(!)
void FilePrinter :: FP_FileDeleteMon(StateFile file)
{
    cout<<"File [ "<<file.getFName().toStdString()<<" ] was deleted from MONITOR"<<endl;
}

//изменение размера файла
void FilePrinter :: FP_fileChange(const QString &FName, qint64 FSize)
{
    cout<<"Size of file [ "<<FName.toStdString()<<" ] was change. New size = "<<FSize<<endl;
}

//при создании файла
void FilePrinter :: FP_fileCreate(const QString &FName, qint64 FSize)
{
    cout<<"File [ "<<FName.toStdString()<<" ] was created. Size = "<<FSize<<endl;
}

//при удалении файла
void FilePrinter :: FP_fileDelete(const QString &FName)
{
    cout<<"File [ "<<FName.toStdString()<<" ] was deleted"<<endl;
}
