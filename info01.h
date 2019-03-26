#ifndef INFO01_H
#define INFO01_H

#include <QMainWindow>
#include <QMainWindow>
#include <QPixmap>
#include <QDialog>
#include <QVideoWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimediaWidgets/QVideoWidget>

namespace Ui {
class info01;
}

class info01 : public QMainWindow
{
    Q_OBJECT

public:
    explicit info01(QWidget *parent = nullptr);
    ~info01();

private:
    Ui::info01 *ui;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // INFO01_H
