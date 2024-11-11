#ifndef MESSAGEEDIT_H
#define MESSAGEEDIT_H

#include <QWidget>

namespace Ui {
class MessageEdit;
}

class MessageEdit : public QWidget
{
    Q_OBJECT

public:
    explicit MessageEdit(QWidget *parent = nullptr);
    ~MessageEdit();


    void paintEvent(QPaintEvent *event) override;

    void initConnect();

    void sendMessage();
private:
    Ui::MessageEdit *ui;
};

#endif // MESSAGEEDIT_H
