#include <iostream>
#include "area.h"
Area::Area(QWidget *parent):QWidget(parent) //конструктор виджета
{
    setFixedSize(QSize(300,200)); //установка фиксированного размера виджета
    myline=new MyLine(80,100,50); //создание фигуры линии
    myrect=new MyRect(220,100,50); //создание фигуры прямоугольника

    alpha=0;//угол поворота
}
void Area::showEvent(QShowEvent *) //обработчик события, когда виджет стал виден
{
    myTimer=startTimer(50); // создать таймер
}
void Area::paintEvent(QPaintEvent *) //обработчик события отрисовки виджета
{
    QPainter painter(this); //создание объекта рисования
    painter.setPen(Qt::red); //цвет красный
    if (myline!=nullptr && myrect!=nullptr) //проверка на существование myline и myrect, чтобы не вызвать исключени
    {
        myline->move(alpha,&painter); //движение линии и отрисовка
        myrect->move(alpha*(-0.5),&painter); // -\\- прямоугольника
    }


}
void Area::timerEvent(QTimerEvent *event) //обработчик события сбрасывания таймера
{
    if (event->timerId() == myTimer) // если наш таймер
    {
        alpha=alpha+0.2; //меняем угот
        update(); // обновить внешний вид
    }
    else
        QWidget::timerEvent(event); // иначе передать для стандартной обработки
}
void Area::hideEvent(QHideEvent *) //обработчик события, когда виджет стал скрыт
{
    killTimer(myTimer); // уничтожить таймер
}
Area::~Area()//деструктор
{
    delete myline;
    delete myrect;
}
