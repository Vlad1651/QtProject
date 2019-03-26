#ifndef PHOTO_H
#define PHOTO_H

#include <QDialog>

namespace Ui {
class photo;
}

class photo : public QDialog
{
    Q_OBJECT

public:
    explicit photo(QWidget *parent = nullptr);
    ~photo();

private:
    Ui::photo *ui;
};

#endif // PHOTO_H
