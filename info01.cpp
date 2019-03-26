#include "info01.h"
#include "ui_info01.h"
#include <QFile>
#include <QTextStream>

#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimediaWidgets/QVideoWidget>

info01::info01(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::info01)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);



    ui->pushButton_2->hide();

    QPixmap p("V:/Progects_Qt/Analitics/K.jpg");

//    QImage img;

//    p.convertFromImage(img, Qt::AutoColor);

   QSize imageSize(200,200);
    QSize labelSize = ui->pix->size();

//    if ((imageSize.height()>labelSize.height()) || (imageSize.width()>labelSize.width()))
//       imageSize.scaled(labelSize,Qt::KeepAspectRatio);
    p=p.scaled(labelSize/*,Qt::KeepAspectRatio*/);
    ui->pix->setPixmap(p);
}

info01::~info01()
{
    delete ui;
}

void info01::on_pushButton_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
    ui->pushButton_2->show();
    QMediaPlayer *player = new QMediaPlayer;
    QVideoWidget *videoWidget = new QVideoWidget;
   player->setVideoOutput(videoWidget);
   player->setMedia(QUrl::fromLocalFile("V:/Progects_Qt/Analitics/Srds.gif"));
   videoWidget->setGeometry(30,20,855,481);
   videoWidget->show();

   player->play();
}
void info01::on_pushButton_2_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
    ui->pushButton_2->hide();
}


