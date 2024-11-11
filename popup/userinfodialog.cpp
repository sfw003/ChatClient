#include "userinfodialog.h"
#include "ui_userinfodialog.h"
#include <QCursor>
UserInfoDialog::UserInfoDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserInfoDialog)
{
    ui->setupUi(this);

    this->move(QCursor::pos());

    ui->m_emailEdit->setEnabled(false);
    ui->m_signature->setEnabled(false);
    ui->m_nickNameEdit->setEnabled(false);

    connect(ui->m_emailModifyBtn, &QPushButton::clicked, this, [=](){
        ui->m_emailEdit->setEnabled(true);
    });
    connect(ui->m_signatureModifyBtn, &QPushButton::clicked, this, [=](){
        ui->m_signature->setEnabled(true);
    });
    connect(ui->m_nameModifyBtn, &QPushButton::clicked, this, [=](){
        ui->m_nickNameEdit->setEnabled(true);
    });
}

UserInfoDialog::~UserInfoDialog()
{
    delete ui;
}
