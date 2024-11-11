#include "sessiondetaildialog.h"
#include "ui_sessiondetaildialog.h"

SessionDetailDialog::SessionDetailDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SessionDetailDialog)
{
    ui->setupUi(this);
}

SessionDetailDialog::~SessionDetailDialog()
{
    delete ui;
}
