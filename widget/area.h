#ifndef AREA_H
#define AREA_H

#include "figura.h"
#include <QWidget>

class Area : public QWidget //виджет, содержащий вращающиеся фигуры
{
    int myTimer; // идентификатор таймера
    float alpha; // угол поворота
public:
    Area(QWidget *parent = 0);
    ~Area();
    MyLine *myline;
    MyRect *myrect;
protected:
//обработчики событий
    void paintEvent(QPaintEvent *event); //обр. соб. отрисовки виджета
    void timerEvent(QTimerEvent *event); //обр. соб. срабатывания таймера
    void showEvent(QShowEvent *event); //обр. соб. появления видимости виджета
    void hideEvent(QHideEvent *event); //обр. соб., когда виджет стал скрыт
};

#endif // AREA_H
