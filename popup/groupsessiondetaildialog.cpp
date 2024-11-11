#include "groupsessiondetaildialog.h"
#include "ui_groupsessiondetaildialog.h"

GroupSessionDetailDialog::GroupSessionDetailDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GroupSessionDetailDialog)
{
    ui->setupUi(this);
}

GroupSessionDetailDialog::~GroupSessionDetailDialog()
{
    delete ui;
}
