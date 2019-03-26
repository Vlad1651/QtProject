#include "photo.h"
#include "ui_photo.h"

photo::photo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::photo)
{
    ui->setupUi(this);
}

photo::~photo()
{
    delete ui;
}
