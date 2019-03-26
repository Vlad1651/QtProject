#ifndef INFO11_H
#define INFO11_H

#include <QMainWindow>
#include <QMainWindow>
#include <QPixmap>
#include <QDialog>
#include <QVideoWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimediaWidgets/QVideoWidget>

namespace Ui {
class info11;
}

class info11 : public QMainWindow
{
    Q_OBJECT

public:
    explicit info11(QWidget *parent = nullptr);
    ~info11();


private:
    Ui::info11 *ui;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // INFO11_H
