#ifndef ABOUT_H
#define ABOUT_H

#include <QtWidgets/QDialog>

namespace Ui {
    class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();

private:
    Ui::About *ui;

protected:

};

#endif // ABOUT_H
