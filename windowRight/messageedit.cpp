#include "messageedit.h"
#include "ui_messageedit.h"
#include <QPushButton>
#include <QPainter>
#include <QStyleOption>
MessageEdit::MessageEdit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MessageEdit)
{
    ui->setupUi(this);
}

void MessageEdit::initConnect()
{
    connect(ui->pushButton, &QPushButton::clicked, this, &MessageEdit::sendMessage);
}

void MessageEdit::sendMessage()
{

}
void MessageEdit::paintEvent(QPaintEvent *event)
{
    (void) event;
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}


MessageEdit::~MessageEdit()
{
    delete ui;
}
