#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
#include <QVector>
#include <qcustomplot.h>
#include "photo.h"
#include "moveitem.h"
#include "math.h"
#include "info01.h"
#include "info11.h"
#include "info21.h"
#include "moveitem1.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int var;
    bool check=false;//суммарно-дальномерный
    bool check1=false;//разностно дальномерный
    bool check2=false;//угломерный

    int count=0;
    int count1=0;

    double A=2;
    double B=1;

    //среднеквадратичная ошибка
    double D=2;//разностно дальномерный
    double U=1;//угломерный
    double S=1;//суммарно-дальномерный

    const int pointCount = 500;
    MoveItem1 *item1;

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_spinBox_5_valueChanged(int arg1);


    void changeGraph();//угломерный

    void changeGraph1();//разностно дальномерный

    void changeGraph2();//суммарно угломерно дальномерный


    void on_spinBox_74_valueChanged(int arg1);

    void on_spinBox_76_valueChanged(int arg1);

    void on_spinBox_75_valueChanged(int arg1);

    void on_spinBox_77_valueChanged(int arg1);

    void on_spinBox_121_valueChanged(int arg1);

    void on_spinBox_125_valueChanged(int arg1);

    void on_spinBox_122_valueChanged(int arg1);

    void on_spinBox_126_valueChanged(int arg1);

    void on_spinBox_123_valueChanged(int arg1);

    void on_spinBox_127_valueChanged(int arg1);

    void on_spinBox_124_valueChanged(int arg1);

    void on_spinBox_128_valueChanged(int arg1);


    void change();

    void change1();

    void change2();

    void change3();

    void change4();

    void change5();


    void on_spinBox_6_valueChanged(int arg1);

    void on_doubleSpinBox_valueChanged(double arg1);

private:
     void configureSpinBox(QSpinBox *spinBox, int min, int max);
     void onMouseEvent(const QString &eventName, const QPoint &pos);
    Ui::MainWindow *ui;


    photo *window;
    info01 *window1;
    info11 *window2;
    info21 *window3;


//    QTimer *animationTimer;

    QCPCurve *fermatSpiral1 ;
    QCPCurve *deltoidRadial ;

    QGraphicsScene *scene;





};

#endif // MAINWINDOW_H
