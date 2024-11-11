#include "mainwidget.h"
#include "./ui_mainwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "userinfodialog.h"
MainWidget* MainWidget::getInstance()
{
    if(s_instance == nullptr)
    {
        s_instance = new MainWidget;
    }
    return s_instance;
}

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("chat");
    this->setWindowIcon(QIcon(":/resource/image/chat_11.png"));
    //初始化
    initUI();
    initSlots();
}

void MainWidget::initUI()
{

    //windowMid
    ui->m_itemSrollArea->init();

    //windowRight
    ui->m_messageShowArea->init();
}
void MainWidget::initSlots()
{
    //windowLeft
    connect(ui->m_userAvatar, &QPushButton::clicked, this, [=](){
        auto* userInfoDialog = new UserInfoDialog(this);
        userInfoDialog->show();
    });



    connect(ui->m_sessionTabBtn, &QPushButton::clicked, this, &MainWidget::switchTabSessionList);
    connect(ui->m_friendTabBtn, &QPushButton::clicked, this, &MainWidget::switchTabFriendList);
    connect(ui->m_applyTabBtn, &QPushButton::clicked, this, &MainWidget::switchTabApplyList);
}


void MainWidget::switchTabSessionList()
{
    //1. 设置状态
    m_activeTab = ActiveTab::SESSION_LIST;
    //2. 切好图片
    ui->m_sessionTabBtn->setIcon(QIcon(":/resource/image/session_active"));
    ui->m_friendTabBtn->setIcon(QIcon(":/resource/image/friendTab_unactive"));
    ui->m_applyTabBtn->setIcon(QIcon(":/resource/image/applyfriend_unactive"));
    //3.
    this->loadSessionList();
}
void MainWidget::switchTabFriendList()
{
    //1. 设置状态
    m_activeTab = ActiveTab::FRIEND_LIST;
    //2. 切好图片
    ui->m_sessionTabBtn->setIcon(QIcon(":/resource/image/session_unactive"));
    ui->m_friendTabBtn->setIcon(QIcon(":/resource/image/friendTab_active"));
    ui->m_applyTabBtn->setIcon(QIcon(":/resource/image/applyfriend_unactive"));
    //3.
    this->loadFriendList();
}
void MainWidget::switchTabApplyList()
{
    //1. 设置状态
    m_activeTab = ActiveTab::APPLY_LIST;
    //2. 切好图片
    ui->m_sessionTabBtn->setIcon(QIcon(":/resource/image/session_unactive"));
    ui->m_friendTabBtn->setIcon(QIcon(":/resource/image/friendTab_unactive"));
    ui->m_applyTabBtn->setIcon(QIcon(":/resource/image/applyfriend_active"));
    //3.
    this->loadApplyList();
}
void MainWidget::loadSessionList()
{

}
void MainWidget::loadFriendList()
{

}
void MainWidget::loadApplyList()
{

}
MainWidget::~MainWidget()
{
    delete ui;
}
