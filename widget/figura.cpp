#include <math.h>
#include "figura.h"
void Figura::move(float Alpha,QPainter *Painter) // функция движения фугуры (изменения угла наклона)
{
    dx=halflen*cos(Alpha); // расчет вектора (dx, dy), задающего угол наклона через тригонометрические функции
    dy=halflen*sin(Alpha);
    draw(Painter); // отрисовка фигуры с новыми параметрами
}
void MyLine::draw(QPainter *Painter)// функция отрисовки отрезка
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy); // отрисовывает в объекте линию с центром в (x, y), параллельную вектору (dx, dy)
}
void MyRect::draw(QPainter *Painter) // функция отрисовки прямоугольника
{
    // отрисовка граней прямоугольника с центром в (x, y)
    // диагональ которого параллельна вектору (dx, dy)
    // вторая диагональ, следовательно, перепендикулярна этому вектору

    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
