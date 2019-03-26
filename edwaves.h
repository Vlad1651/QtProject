#ifndef EDWAVES_H
#define EDWAVES_H

#include <QMainWindow>

namespace Ui {
class EDWaves;
}

class EDWaves : public QMainWindow
{
    Q_OBJECT

public:
    explicit EDWaves(QWidget *parent = nullptr);
    ~EDWaves();

private:
    Ui::EDWaves *ui;
};

#endif // EDWAVES_H
