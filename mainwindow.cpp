#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "photo.h"
#include "moveitem.h"
#include "moveitem1.h"
#include <QMouseEvent>
#include "math.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QVector>

QVector <MoveItem*> item(4);

static int randomBetween(int low, int high){
  return (qrand()%((high+1)-low)+low);}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{




    ui->setupUi(this);
    ui->pushButton->setStyleSheet("* {background-color:red}");
    ui->pushButton_2->setStyleSheet("* {background-color:green}");
    ui->pushButton_3->setStyleSheet("* {background-color:#0077D6}");
    setStyleSheet("*{background-color: #F5F5CF;}");

    ui->stackedWidget_2->setCurrentIndex(2);
    ui->stackedWidget->setCurrentIndex(2);

    configureSpinBox(ui->spinBox_74, -INT_MAX, +INT_MAX);
    configureSpinBox(ui->spinBox_76, -INT_MAX, +INT_MAX);
    configureSpinBox(ui->spinBox_75, -INT_MAX, +INT_MAX);
    configureSpinBox(ui->spinBox_77, -INT_MAX, +INT_MAX);
    configureSpinBox(ui->spinBox_121, -INT_MAX, +INT_MAX);
    configureSpinBox(ui->spinBox_125, -INT_MAX, +INT_MAX);
    configureSpinBox(ui->spinBox_122, -INT_MAX, +INT_MAX);
    configureSpinBox(ui->spinBox_126, -INT_MAX, +INT_MAX);
    configureSpinBox(ui->spinBox_123, -INT_MAX, +INT_MAX);
    configureSpinBox(ui->spinBox_127, -INT_MAX, +INT_MAX);
    configureSpinBox(ui->spinBox_124, -INT_MAX, +INT_MAX);
    configureSpinBox(ui->spinBox_128, -INT_MAX, +INT_MAX);


    ui->lineEdit->setText(QString::number(A));
    ui->lineEdit_2->setText(QString::number(A*A*M_PI));




    fermatSpiral1 = new QCPCurve(ui->widget->xAxis, ui->widget->yAxis);
    deltoidRadial = new QCPCurve(ui->widget->xAxis, ui->widget->yAxis);


         QVector<QCPCurveData> dataSpiral(pointCount), dataSpiral1(pointCount);
         for (int i=0; i<pointCount; ++i)
         {
            double phi = i/(double)(pointCount-1)*2*M_PI;

           dataSpiral[i] = QCPCurveData(i, A*qCos(phi), qSin(phi));
//           dataSpiral1[i]=QCPCurveData(i, B*qCos(phi), qSin(phi));

         }
         // pass the data to the curves; we know t (i in loop above) is ascending, so set alreadySorted=true (saves an extra internal sort):
//         fermatSpiral1->data()->set(dataSpiral1, true);
         deltoidRadial->data()->set(dataSpiral, true);

//         fermatSpiral1->setPen(QPen(Qt::blue));


        deltoidRadial->setPen(QPen(QColor(Qt::red)));

        ui->widget->axisRect()->setupFullAxesBox();
        ui->widget->xAxis->setRange(-40,40);
        ui->widget->yAxis->setRange(-40,40);
        ui->widget->replot();


/////////////////////////////////////////////



         scene = new QGraphicsScene(0,0,471,491,this);
         ui->graphicsView->setScene(scene);

              QPixmap pixmap;
                 pixmap.load("V:/Progects_Qt/Analitics/D.jpg");

                 scene->setBackgroundBrush(QBrush(pixmap.scaled(471, 491)));




              ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // РЈСЃС‚Р°РЅР°РІР»РёРІР°РµРј СЃРіР»Р°Р¶РёРІР°РЅРёРµ
              ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // РћС‚РєР»СЋС‡Р°РµРј СЃРєСЂРѕР»Р»Р±Р°СЂ РїРѕ РІРµСЂС‚РёРєР°Р»Рё
              ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // РћС‚РєР»СЋС‡Р°РµРј СЃРєСЂРѕР»Р»Р±Р°СЂ РїРѕ РіРѕСЂРёР·РѕРЅС‚Р°Р»Рё

              item1 = new MoveItem1();
              item1->setPos(200, randomBetween(30,470));
              scene->addItem(item1);
              ui->spinBox_74->setValue(item1->scenePos().x());
              ui->spinBox_76->setValue(item1->scenePos().y());




              connect(item1,SIGNAL(n()), this, SLOT(change()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    window = new photo;
    window->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    window1 = new info01;
    window1->show();
}

void MainWindow::on_pushButton_clicked()
{
    check=true;
    check1=false;
    check2=false;

    if (((ui->spinBox_5->value())<3)) {ui->stackedWidget_2->setCurrentIndex(1);}
     else ui->stackedWidget_2->setCurrentIndex(0);
    ui->label_5->setGeometry(310,120,55,16);
    ui->label_5->setStyleSheet("font-family: Arial;font-style: normal;font-size: 9pt");

     ui->stackedWidget->setCurrentIndex(0);
    setStyleSheet("background-color:#FF808C;");
}

void MainWindow::on_pushButton_2_clicked()//разостно дальномерный
{
    check=false;
    check1=true;
    check2=false;
    ui->spinBox_6->setValue(15);

    if (((ui->spinBox_5->value())<3)) {ui->stackedWidget_2->setCurrentIndex(1);}
     else ui->stackedWidget_2->setCurrentIndex(0);

     ui->doubleSpinBox->hide();
     ui->label_2->hide();
     ui->label->show();
     ui->spinBox_6->show();
     ui->label_3->show();
     ui->label->setGeometry(10,80,281,21);
     ui->spinBox_6->setGeometry(310,80,49,22);
     ui->label_3->setGeometry(380,80,31,16);
     ui->label_4->setGeometry(10,120,351,20);
     ui->label_4->setStyleSheet("font-family: Arial;font-style: normal;font-size: 9pt");
     ui->label_5->setGeometry(310,120,55,16);
     ui->label_5->setStyleSheet("font-family: Arial;font-style: normal;font-size: 9pt");
     setStyleSheet("background-color:#C8E6C9;");
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()//угломерный
{
    check=false;
    check1=false;
    check2=true;

    if (((ui->spinBox_5->value())<2)) {ui->stackedWidget_2->setCurrentIndex(1);}
     else ui->stackedWidget_2->setCurrentIndex(0);


     ui->label->hide();
     ui->spinBox_6->hide();
     ui->label->hide();
     ui->doubleSpinBox->show();
     ui->label_2->show();
     ui->label_3->hide();
     ui->label_2->setGeometry(10,80,281,21);
     ui->doubleSpinBox->setGeometry(310,80,49,22);
     ui->label_4->setGeometry(10,120,371,20);
     ui->label_4->setStyleSheet("font-family: Arial;font-style: normal;font-size: 9pt");
     ui->label_5->setGeometry(310,120,55,16);
     ui->label_5->setStyleSheet("font-family: Arial;font-style: normal;font-size: 9pt");
     setStyleSheet("background-color:#B3E5FC;");
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_6_clicked()
{

        window2 = new info11;
        window2->show();

}

void MainWindow::on_pushButton_7_clicked()
{
    window3 = new info21;
    window3->show();
}

void MainWindow::configureSpinBox(QSpinBox *spinBox, int min, int max){
    spinBox->setMinimum(min);
    spinBox->setMaximum(max);
}

void MainWindow::on_spinBox_5_valueChanged(int arg1)
{
    if (((ui->spinBox_5->value())<3) && (check==true)) {ui->stackedWidget_2->setCurrentIndex(1);}
     else ui->stackedWidget_2->setCurrentIndex(0);

    if (((ui->spinBox_5->value())<3) && (check1==true)) {ui->stackedWidget_2->setCurrentIndex(1);}
     else ui->stackedWidget_2->setCurrentIndex(0);

    if (((ui->spinBox_5->value())<2) && (check2==true)) {ui->stackedWidget_2->setCurrentIndex(1);}
     else ui->stackedWidget_2->setCurrentIndex(0);


         count1=ui->spinBox_5->value();

     if (ui->spinBox_5->value()==0 && count>count1){
         ui->spinBox_75->setValue(0);
         ui->spinBox_77->setValue(0);
         item.resize(0);
         scene->removeItem(item[0]);

     }

     if (ui->spinBox_5->value() == 1){
         if(count>count1){
             ui->spinBox_121->setValue(0);
             ui->spinBox_125->setValue(0);
              item.resize(0);
              scene->removeItem(item[1]);

         }
         else{
             item[0] = new MoveItem();
             item[0]->setPos(randomBetween(30,400), randomBetween(200,400));
             scene->addItem(item[0]);

             ui->spinBox_75->setValue(item[0]->scenePos().x());
             ui->spinBox_77->setValue(item[0]->scenePos().y());

             connect(item[0],SIGNAL(n()), this, SLOT(change1()));
         }
     }

     if (ui->spinBox_5->value() == 2 ){


         if(count>count1){
               ui->spinBox_122->setValue(0);
               ui->spinBox_126->setValue(0);
               item.resize(1);
               scene->removeItem(item[2]);
         }
         else{
             item[1] = new MoveItem();
             item[1]->setPos(randomBetween(30,400), randomBetween(200,400));
             scene->addItem(item[1]);

             ui->spinBox_121->setValue(item[1]->scenePos().x());
             ui->spinBox_125->setValue(item[1]->scenePos().y());

             connect(item[1],SIGNAL(n()), this, SLOT(change2()));
         }
     }

     if (ui->spinBox_5->value() == 3){


         if(count>count1){
               ui->spinBox_123->setValue(0);
               ui->spinBox_127->setValue(0);
               item.resize(2);
               scene->removeItem(item[3]);
         }
         else{
             item[2] = new MoveItem();
             item[2]->setPos(randomBetween(30,400), randomBetween(200,400));
             scene->addItem(item[2]);

             ui->spinBox_122->setValue(item[2]->scenePos().x());
             ui->spinBox_126->setValue(item[2]->scenePos().y());

             connect(item[2],SIGNAL(n()), this, SLOT(change3()));
         }
     }
     if (ui->spinBox_5->value() == 4){


         if(count>count1){
               ui->spinBox_124->setValue(0);
               ui->spinBox_128->setValue(0);
               item.resize(3);

               ui->spinBox_123->setValue(item[3]->scenePos().x());
               ui->spinBox_127->setValue(item[3]->scenePos().y());

               scene->removeItem(item[4]);
         }
         else{
             item[3] = new MoveItem();
             item[3]->setPos(randomBetween(30,400), randomBetween(200,400));
             scene->addItem(item[3]);

             ui->spinBox_123->setValue(item[3]->scenePos().x());
             ui->spinBox_127->setValue(item[3]->scenePos().y());

             connect(item[3],SIGNAL(n()), this, SLOT(change4()));

         }
     }
     if (ui->spinBox_5->value() == 5){

             item[4] = new MoveItem();
             item[4]->setPos(randomBetween(30,400), randomBetween(200,400));
             scene->addItem(item[4]);

             ui->spinBox_124->setValue(item[4]->scenePos().x());
             ui->spinBox_128->setValue(item[4]->scenePos().y());

             connect(item[4],SIGNAL(n()), this, SLOT(change5()));
     }

             count=ui->spinBox_5->value();


}



void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
//    onMouseEvent("DoubleClicked", event->pos());
//    A=event->pos().x();

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
//    onMouseEvent("Press", event->pos());
//        ui->spinBox_46->setValue(item[0]->scenePos().x());

}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
//    onMouseEvent("Move", event->pos());
//      ui->spinBox_46->setValue(item[0]->scenePos().x());
//    QWidget::mouseMoveEvent(event);
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
//    onMouseEvent("Release", event->pos());

}
void MainWindow::onMouseEvent(const QString &eventName, const QPoint &pos)
{



}



void MainWindow::changeGraph()
{
    //угломерный

    int xc = ui->spinBox_74->value();
    int yc = ui->spinBox_76->value();

    int x1 = ui->spinBox_75->value();
    int y1 = ui->spinBox_77->value();

    int x2 = ui->spinBox_121->value();
    int y2 = ui->spinBox_125->value();

    int x3 = ui->spinBox_122->value();
    int y3 = ui->spinBox_126->value();

    int x4 = ui->spinBox_123->value();
    int y4 = ui->spinBox_127->value();

    int x5 = ui->spinBox_124->value();
    int y5 = ui->spinBox_128->value();

    double U12=0;
    double U23=0;
    double U34=0;
    double U45=0;


    double p = ui->doubleSpinBox->value();
    double k = 0.0175;//0,0175

    //1 и 2 станции

    double r12 = sqrt((xc-x1)*(xc-x1)+(yc-y1)*(yc-y1));
    double r22 = sqrt((xc-x2)*(xc-x2)+(yc-y2)*(yc-y2));
    double r2 = ((xc-x1)*(xc-x2)+(yc-y1)*(yc-y2))/(r12*r22);
    double ac = acos(r2);
    double phi = sin(ac);



    double sq = sqrt(r12*r12+r22*r22);


    U12=k*p*sq/phi;
//    ui->lineEdit->setText(QString::number(ac));


    //2 и 3 станции

    double r13 = sqrt((xc-x2)*(xc-x2)+(yc-y2)*(yc-y2));
    double r23 = sqrt((xc-x3)*(xc-x3)+(yc-y3)*(yc-y3));
    double r3 = ((xc-x2)*(xc-x3)+(yc-y2)*(yc-y3))/(r13*r23);
    double ac3 = acos(r3);
    double phi3 = sin(ac3);

    double sq3 = sqrt(r13*r13+r23*r23);

    U23=k*p*sq3/phi3;

    //3 и 4 станции

    double r14 = sqrt((xc-x4)*(xc-x4)+(yc-y4)*(yc-y4));
    double r24 = sqrt((xc-x3)*(xc-x3)+(yc-y3)*(yc-y3));
    double r4 = ((xc-x3)*(xc-x4)+(yc-y3)*(yc-y4))/(r14*r24);
    double ac4 = acos(r4);
    double phi4 = sin(ac4);

    double sq4 = sqrt(r14*r14+r24*r24);

    U34=k*p*sq4/phi4;

    //4 и 5 станции

    double r15 = sqrt((xc-x4)*(xc-x4)+(yc-y4)*(yc-y4));
    double r25 = sqrt((xc-x5)*(xc-x5)+(yc-y5)*(yc-y5));
    double r5 = ((xc-x4)*(xc-x5)+(yc-y4)*(yc-y5))/(r15*r25);
    double ac5 = acos(r5);
    double phi5 = sin(ac5);

    double sq5 = sqrt(r15*r15+r25*r25);

    U45=k*p*sq5/phi5;

    int num=ui->spinBox_5->value();

    if (num==2) U = U12;
    if (num==3) U = (U12+U23)/2.;
    if (num==4) U = (U12+U23+U34)/3.;
    if (num==5) U = (U12+U23+U34+U45)/4.;

    ui->lineEdit->setText(QString::number(U));
    ui->lineEdit_2->setText(QString::number(U*U*M_PI));




    QVector<QCPCurveData> dataSpiral(pointCount), dataSpiral1(pointCount);
    for (int i=0; i<pointCount; ++i)
    {
       double phi = i/(double)(pointCount-1)*2*M_PI;

      dataSpiral[i] = QCPCurveData(i, U*qCos(phi), U*qSin(phi));
//  эллипс    dataSpiral1[i]=QCPCurveData(i, qCos(phi), qSin(phi));

    }
    // pass the data to the curves; we know t (i in loop above) is ascending, so set alreadySorted=true (saves an extra internal sort):
//  эллипс  fermatSpiral1->data()->set(dataSpiral1, true);
    deltoidRadial->data()->set(dataSpiral, true);
    // color the curves:
// эллипс   fermatSpiral1->setPen(QPen(Qt::blue));


    deltoidRadial->setPen(QPen(QColor(Qt::red)));

    ui->widget->axisRect()->setupFullAxesBox();
    ui->widget->xAxis->setRange(-50, 50);
    ui->widget->yAxis->setRange(-50, 50);

    ui->widget->replot();


}

void MainWindow::changeGraph1()
{

    //разностно-дальномерный

    int xc = ui->spinBox_74->value();
    int yc = ui->spinBox_76->value();

    int x1 = ui->spinBox_75->value();
    int y1 = ui->spinBox_77->value();

    int x2 = ui->spinBox_121->value();
    int y2 = ui->spinBox_125->value();

    int x3 = ui->spinBox_122->value();
    int y3 = ui->spinBox_126->value();

    int x4 = ui->spinBox_123->value();
    int y4 = ui->spinBox_127->value();

    int x5 = ui->spinBox_124->value();
    int y5 = ui->spinBox_128->value();


    double D12=0;
    double D23=0;
    double D34=0;
    double D45=0;

    int t = ui->spinBox_6->value();
    int num = ui->spinBox_5->value();

    //1 и 2 станции

    double r12 = sqrt((xc-x1)*(xc-x1)+(yc-y1)*(yc-y1));
    double r22 = sqrt((xc-x2)*(xc-x2)+(yc-y2)*(yc-y2));
    double r2 = ((xc-x1)*(xc-x2)+(yc-y1)*(yc-y2))/(r12*r22);
    double ac = acos(r2);
    double phi2 = sin(ac)/2;

    //2 и 3 станции

    double r13 = sqrt((xc-x2)*(xc-x2)+(yc-y2)*(yc-y2));
    double r23 = sqrt((xc-x3)*(xc-x3)+(yc-y3)*(yc-y3));
    double r3 = ((xc-x2)*(xc-x3)+(yc-y2)*(yc-y3))/(r13*r23);
    double ac3 = acos(r3);
    double phi3 = sin(ac3)/2;


    //3 и 4 станции

    double r14 = sqrt((xc-x4)*(xc-x4)+(yc-y4)*(yc-y4));
    double r24 = sqrt((xc-x3)*(xc-x3)+(yc-y3)*(yc-y3));
    double r4 = ((xc-x3)*(xc-x4)+(yc-y3)*(yc-y4))/(r14*r24);
    double ac4 = acos(r4);
    double phi4 = sin(ac4)/2;

    //4 и 5 станции

    double r15 = sqrt((xc-x4)*(xc-x4)+(yc-y4)*(yc-y4));
    double r25 = sqrt((xc-x5)*(xc-x5)+(yc-y5)*(yc-y5));
    double r5 = ((xc-x4)*(xc-x5)+(yc-y4)*(yc-y5))/(r15*r25);
    double ac5 = acos(r5);
    double phi5 = sin(ac5)/2;


    D12=t/2*phi2;
    D23=t/2*phi3;
    D34=t/2*phi4;
    D45=t/2*phi5;

    if (num==2) D = D12;
    if (num==3) D = (D12+D23)/2.;
    if (num==4) D = (D12+D23+D34)/3.;
    if (num==5) D = (D12+D23+D34+D45)/4.;

    ui->lineEdit->setText(QString::number(D));
    ui->lineEdit_2->setText(QString::number(D*D*M_PI));





    QVector<QCPCurveData> dataSpiral(pointCount), dataSpiral1(pointCount);
    for (int i=0; i<pointCount; ++i)
    {
       double phi = i/(double)(pointCount-1)*2*M_PI;

      dataSpiral[i] = QCPCurveData(i, D*qCos(phi), D*qSin(phi));
//      dataSpiral1[i]=QCPCurveData(i, qCos(phi), qSin(phi));

    }
    // pass the data to the curves; we know t (i in loop above) is ascending, so set alreadySorted=true (saves an extra internal sort):
//    fermatSpiral1->data()->set(dataSpiral1, true);
    deltoidRadial->data()->set(dataSpiral, true);
    // color the curves:
//    fermatSpiral1->setPen(QPen(Qt::blue));


    deltoidRadial->setPen(QPen(QColor(Qt::red)));

    ui->widget->axisRect()->setupFullAxesBox();
    ui->widget->xAxis->setRange(-40,40);
    ui->widget->yAxis->setRange(-40,40);

    ui->widget->replot();


}

void MainWindow::changeGraph2()
{
    //суммарно угломерно дальномерный
    int xc = ui->spinBox_74->value();
    int yc = ui->spinBox_76->value();

    int x1 = ui->spinBox_75->value();
    int y1 = ui->spinBox_77->value();

    int x2 = ui->spinBox_121->value();
    int y2 = ui->spinBox_125->value();

    int x3 = ui->spinBox_122->value();
    int y3 = ui->spinBox_126->value();

    int x4 = ui->spinBox_123->value();
    int y4 = ui->spinBox_127->value();

    int x5 = ui->spinBox_124->value();
    int y5 = ui->spinBox_128->value();

    double S12=0;
    double S23=0;
    double S34=0;
    double S45=0;

    int p = ui->doubleSpinBox->value();
    int num = ui->spinBox_5->value();

    //1 и 2 станции

    double r12 = sqrt((xc-x1)*(xc-x1)+(yc-y1)*(yc-y1));
    double r22 = sqrt((xc-x2)*(xc-x2)+(yc-y2)*(yc-y2));
    double r2 = ((xc-x1)*(xc-x2)+(yc-y1)*(yc-y2))/(r12*r22);
    double ac = acos(r2);
    double phi2 = cos(ac)/2;

    //2 и 3 станции

    double r13 = sqrt((xc-x2)*(xc-x2)+(yc-y2)*(yc-y2));
    double r23 = sqrt((xc-x3)*(xc-x3)+(yc-y3)*(yc-y3));
    double r3 = ((xc-x2)*(xc-x3)+(yc-y2)*(yc-y3))/(r13*r23);
    double ac3 = acos(r3);
    double phi3 = cos(ac3)/2;


    //3 и 4 станции

    double r14 = sqrt((xc-x4)*(xc-x4)+(yc-y4)*(yc-y4));
    double r24 = sqrt((xc-x3)*(xc-x3)+(yc-y3)*(yc-y3));
    double r4 = ((xc-x3)*(xc-x4)+(yc-y3)*(yc-y4))/(r14*r24);
    double ac4 = acos(r4);
    double phi4 = cos(ac4)/2;

    //4 и 5 станции

    double r15 = sqrt((xc-x4)*(xc-x4)+(yc-y4)*(yc-y4));
    double r25 = sqrt((xc-x5)*(xc-x5)+(yc-y5)*(yc-y5));
    double r5 = ((xc-x4)*(xc-x5)+(yc-y4)*(yc-y5))/(r15*r25);
    double ac5 = acos(r5);
    double phi5 = cos(ac5)/2;


    S12=p/2*phi2;
    S23=p/2*phi3;
    S34=p/2*phi4;
    S45=p/2*phi5;

    if (num==2) S = S12;
    if (num==3) S = (S12+S23)/2.;
    if (num==4) S = (S12+S23+S34)/3.;
    if (num==5) S = (S12+S23+S34+S45)/4.;

    ui->lineEdit->setText(QString::number(S));
    ui->lineEdit_2->setText(QString::number(S*S*M_PI));



    QVector<QCPCurveData> dataSpiral(pointCount), dataSpiral1(pointCount);
    for (int i=0; i<pointCount; ++i)
    {
       double phi = i/(double)(pointCount-1)*2*M_PI;

      dataSpiral[i] = QCPCurveData(i, S*qCos(phi), S*qSin(phi));
//      dataSpiral1[i]=QCPCurveData(i, qCos(phi), qSin(phi));

    }
    // pass the data to the curves; we know t (i in loop above) is ascending, so set alreadySorted=true (saves an extra internal sort):
//    fermatSpiral1->data()->set(dataSpiral1, true);
    deltoidRadial->data()->set(dataSpiral, true);
    // color the curves:
//    fermatSpiral1->setPen(QPen(Qt::blue));


    deltoidRadial->setPen(QPen(QColor(Qt::red)));

    ui->widget->axisRect()->setupFullAxesBox();
    ui->widget->xAxis->setRange(-40,40);
    ui->widget->yAxis->setRange(-40,40);

    ui->widget->replot();


}


void MainWindow::on_spinBox_74_valueChanged(int arg1)
{
    if (check==true) changeGraph2();
    if (check1==true) changeGraph1();
    if (check2==true) changeGraph();

}

void MainWindow::on_spinBox_76_valueChanged(int arg1)
{
    if (check==true) changeGraph2();
    if (check1==true) changeGraph1();
    if (check2==true) changeGraph();

}

void MainWindow::on_spinBox_75_valueChanged(int arg1)
{
    if (check==true) changeGraph2();
    if (check1==true) changeGraph1();
    if (check2==true) changeGraph();

}

void MainWindow::on_spinBox_77_valueChanged(int arg1)
{
    if (check==true) changeGraph2();
    if (check1==true) changeGraph1();
    if (check2==true) changeGraph();

}

void MainWindow::on_spinBox_121_valueChanged(int arg1)
{
    if (check==true) changeGraph2();
    if (check1==true) changeGraph1();
    if (check2==true) changeGraph();

}

void MainWindow::on_spinBox_125_valueChanged(int arg1)
{
    if (check==true) changeGraph2();
    if (check1==true) changeGraph1();
    if (check2==true) changeGraph();

}

void MainWindow::on_spinBox_122_valueChanged(int arg1)
{
    if (check==true) changeGraph2();
    if (check1==true) changeGraph1();
    if (check2==true) changeGraph();

}

void MainWindow::on_spinBox_126_valueChanged(int arg1)
{
    if (check==true) changeGraph2();
    if (check1==true) changeGraph1();
    if (check2==true) changeGraph();

}

void MainWindow::on_spinBox_123_valueChanged(int arg1)
{
    if (check==true) changeGraph2();
    if (check1==true) changeGraph1();
    if (check2==true) changeGraph();

}

void MainWindow::on_spinBox_127_valueChanged(int arg1)
{
    if (check==true) changeGraph2();
    if (check1==true) changeGraph1();
    if (check2==true) changeGraph();

}

void MainWindow::on_spinBox_124_valueChanged(int arg1)
{
    if (check==true) changeGraph2();
    if (check1==true) changeGraph1();
    if (check2==true) changeGraph();

}

void MainWindow::on_spinBox_128_valueChanged(int arg1)
{
    if (check==true) changeGraph2();
    if (check1==true) changeGraph1();
    if (check2==true) changeGraph();

}

void MainWindow::change(){
    ui->spinBox_74->setValue(item1->scenePos().x());
    ui->spinBox_76->setValue(item1->scenePos().y());
}
void MainWindow::change1(){
    ui->spinBox_75->setValue(item[0]->scenePos().x());
    ui->spinBox_77->setValue(item[0]->scenePos().y());
}
void MainWindow::change2(){
    ui->spinBox_121->setValue(item[1]->scenePos().x());
    ui->spinBox_125->setValue(item[1]->scenePos().y());
}
void MainWindow::change3(){
    ui->spinBox_122->setValue(item[2]->scenePos().x());
    ui->spinBox_126->setValue(item[2]->scenePos().y());
}
void MainWindow::change4(){
    ui->spinBox_123->setValue(item[3]->scenePos().x());
    ui->spinBox_127->setValue(item[3]->scenePos().y());
}
void MainWindow::change5(){
    ui->spinBox_124->setValue(item[4]->scenePos().x());
    ui->spinBox_128->setValue(item[4]->scenePos().y());
}


void MainWindow::on_spinBox_6_valueChanged(int arg1)
{
    //t
    changeGraph1();


}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{

    //p
    changeGraph2();

}
