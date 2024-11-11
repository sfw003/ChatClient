#ifndef SESSIONTITLE_H
#define SESSIONTITLE_H

#include <QWidget>

namespace Ui {
class SessionTitle;
}

class SessionTitle : public QWidget
{
    Q_OBJECT

public:
    explicit SessionTitle(QWidget *parent = nullptr);
    ~SessionTitle();

private:
    Ui::SessionTitle *ui;
};

#endif // SESSIONTITLE_H
