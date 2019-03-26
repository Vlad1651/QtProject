#ifndef INFO21_H
#define INFO21_H

#include <QMainWindow>
#include <QPixmap>
#include <QDialog>
#include <QVideoWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimediaWidgets/QVideoWidget>


namespace Ui {
class info21;
}

class info21 : public QMainWindow
{
    Q_OBJECT

public:
    explicit info21(QWidget *parent = nullptr);
    ~info21();


private:
    Ui::info21 *ui;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // INFO21_H
