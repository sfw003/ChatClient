#include "sessiontitle.h"
#include "ui_sessiontitle.h"

SessionTitle::SessionTitle(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SessionTitle)
{
    ui->setupUi(this);
}

SessionTitle::~SessionTitle()
{
    delete ui;
}
