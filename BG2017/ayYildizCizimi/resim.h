#ifndef RESIM_H
#define RESIM_H

#include <QLabel>
#include <QImage>
#include <QMouseEvent>



class resim : public QLabel
{
    Q_OBJECT
public:
    explicit resim(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *);
    QList<QPoint> noktalar;
    void daireCiz(int); // yaricap degeri aliyor.
    void cizDDA(QPoint,QPoint);
    void cemberCiz(int);
    void yildizCiz();





signals:

public slots:


private:
    QRgb deger,deger2;
    QPoint ilknokta;
    QPoint sonnokta;
    QImage res;

};

#endif // RESIM_H
