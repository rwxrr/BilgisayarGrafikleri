#include "resim.h"
#include <math.h>
#include <qmath.h>
#include <QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"


resim::resim(QWidget *parent) :
    QLabel(parent)
{
    setFrameShape(QFrame::Box);
    deger = qRgb(255,0,0);
    deger2 = qRgb(0,0,0);
    QImage ortam(600,600,QImage::Format_RGB32);
    setPixmap(QPixmap::fromImage(ortam));
    res = ortam;


}

void resim::mousePressEvent(QMouseEvent *event) // QImage tipindeki resim nesnesinden x ve y eventlerine aliyoruz.
{
    ilknokta.setX(event->x());
    ilknokta.setY(event->y());

}


void resim::daireCiz(int yaricap)
{
    int hesaplabuyukD;

    for(int x=-70; x < 70; ++x)
    {
        QApplication::processEvents();
        hesaplabuyukD= sqrt(pow(70,2) - pow(x,2));
        for(int y=-hesaplabuyukD;y<hesaplabuyukD;++y)
        {
            res.setPixel(200+x,300+y,deger);
            setPixmap(QPixmap::fromImage(res));
        }
    }


    int hesaplakucukD;


    for(int x=-60; x < 60; ++x)
    {
        QApplication::processEvents();
        hesaplakucukD= sqrt(pow(60,2) - pow(x,2));
        for(int y=-hesaplakucukD;y<hesaplakucukD;++y)
        {
            res.setPixel(220+x,300+y,deger2);
            setPixmap(QPixmap::fromImage(res));
        }
    }



}


void resim::cemberCiz(int yaricap)
{

    double aci = 0.0;
    double x,y;
    QPoint yildizNokta; // yildizin kose koordinatlarini tutuyoruz.
       while (aci <= 360) {

           x = yaricap * cos(qDegreesToRadians(aci))+ 300;
           y = yaricap * sin(qDegreesToRadians(aci))+ 300;
           yildizNokta.setX(x); // nokta degerleri koyuldu x ve y ye
           yildizNokta.setY(y);
           res.setPixel(round(x),round(y),deger);
           aci += 72;
           noktalar.push_back(yildizNokta); // noktalar listesine atildi.
           setPixmap(QPixmap::fromImage(res));




       }

  }

 void resim::cizDDA(QPoint ilknokta, QPoint sonnokta)
{
           double dx = sonnokta.x() - ilknokta.x();
           double dy = sonnokta.y() - ilknokta.y();
           double Xartim, Yartim;
           double adim;
           double x, y;
           if (fabs(dx) > fabs(dy)) {
               adim = fabs(dx);
           } else {
               adim = fabs(dy);
           }
           Xartim = dx / adim;
           Yartim = dy / adim;
           x = ilknokta.x();
           y = ilknokta.y();
           for (int i = 0; i < adim; ++i)
           {
               x += Xartim;
               y += Yartim;
               res.setPixel(round(x),round(y),deger);
           }
           setPixmap(QPixmap::fromImage(res));
}





void resim::yildizCiz()
{
    // noktalar dizisindeki ilk noktayi noktalar dizisine ekleidk.[(0,0),(1,0),(2,0),(3,0),(4,0),(0,0)]
    for (int i = 0; i < noktalar.size()-1; ++i) {
            cizDDA(noktalar[(i)%5], noktalar[(i+2)%5]);




    }

}





