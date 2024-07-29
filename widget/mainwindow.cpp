#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow()
{
    codec = QTextCodec::codecForName("UTF-8");// смена кодировки для русского языка
    // установка заголовка окна
    this->setWindowTitle(codec->toUnicode("Обработка событий"));

    area = new Area(this); // создание виджета area на текущем виджете
    btn = new QPushButton(codec->toUnicode("Завершить"),this ); // создание кнопки на текущем виджете

    QVBoxLayout *layout = new QVBoxLayout(this); // создание вертикальной разметки на текущем виджете
    layout->addWidget(area); // добавление виджета area с фигурами на нее
    layout->addWidget(btn); // и кнопки

    connect(btn, &QPushButton::clicked,this,&MainWindow::close); // подключение сигнала нажатия кнопки к слоту закрытия окна
}
