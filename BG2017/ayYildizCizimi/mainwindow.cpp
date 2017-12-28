#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showMaximized();
    img = new resim(this);
    img->setGeometry(50,50,600,600);

    img->show();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() // press the start button
{
    img->daireCiz(70); // büyük ve kücük daire ciziliyor.
    img->cemberCiz(40); // yildizin kose koordinatlari belirleniyor
    img->yildizCiz(); // kose koordinatlari birleştiriliyor.





}
