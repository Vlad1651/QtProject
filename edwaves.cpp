#include "edwaves.h"
#include "ui_edwaves.h"

EDWaves::EDWaves(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EDWaves)
{
    ui->setupUi(this);
}

EDWaves::~EDWaves()
{
    delete ui;
}
