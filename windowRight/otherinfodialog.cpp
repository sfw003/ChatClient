#include "otherinfodialog.h"
#include "ui_otherinfodialog.h"
#include <QCursor>
OtherInfoDialog::OtherInfoDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OtherInfoDialog)
{
    ui->setupUi(this);

    this->move(QCursor::pos());
}

OtherInfoDialog::~OtherInfoDialog()
{
    delete ui;
}
