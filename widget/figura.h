#ifndef FIGURA_H
#define FIGURA_H

#include <QtGui>

class Figura
{
protected:
    int x,y,halflen,dx,dy;
    //x,y координаты расположения центра фигуры
    //halflen половина от длины фигуры
    //dx,dy координаты вектора, указывающего наклон фигуры
    virtual void draw(QPainter *Painter)=0; //вирт. функция для отрисовки фигуры
public:
    Figura(int X,int Y,int Halflen): // конструктор определяет положение фигуры (X, Y) и размер (halfLen - половина длины)
    x(X),y(Y),halflen(Halflen){}
    void move(float Alpha,QPainter *Painter); // функция движения фигуры (изменения угла наклона)
    virtual ~Figura(){}
};

class MyLine:public Figura // класс линии, наследуется от класса Figura
{
protected:
    void draw(QPainter *Painter);
public:
    MyLine(int x,int y,int halflen): // конструктор, использующий родительский конструктор
        Figura(x,y,halflen){}

};

class MyRect:public Figura // класс прямоугольника, наследуется от класса Figura
{
protected:
    void draw(QPainter *Painter);
public:
    MyRect(int x,int y,int halflen):
        Figura(x,y,halflen){}

};
#endif // FIGURA_H
