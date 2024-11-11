#include "messageshowarea.h"
#include "config.h"
#include <QScrollBar>
#include <QPushButton>
#include <QVBoxLayout>
MessageShowArea::MessageShowArea(QWidget* parent)
    : QScrollArea(parent)
{
}
void MessageShowArea::init()
{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //1. 设置滚动条
    this->setWidgetResizable(true);
    this->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { width: 2px; background-color: rgb(240, 240, 240); } QScrollBar::handle:vertical {background-color: rgb(46, 46, 46);}");
    this->horizontalScrollBar()->setStyleSheet("QScrollBar:horizontal {height: 0px}");
    this->setStyleSheet("QScrollArea { border: none;}");

    //2. 设置Qwidget
    m_container = new QWidget(this);
    this->setWidget(m_container);

    //3. 为m_container设置布局管理器
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    m_container->setLayout(layout);

#ifdef SFW_Debug
    QIcon icon(":/resource/image/avatar_boy.png");
    for(int i = 0; i < 20; i++)
    {
        auto type = model::MessageType::TextMessageType;
        model::UserInfo userInfo;
        userInfo.m_avatar = icon;
        userInfo.m_nickName = "sfwnb";
        auto pmessage = model::MessageFactory::CreateMessage(type, QString::number(i), userInfo, "手法松解愤世嫉俗立法解释就是链接发顺丰司法解释来解释九分零四反馈是否", "sfwnb");
        this->addMessageItem(type, false, pmessage);
    }
#endif

}

void MessageShowArea::addMessageItem(model::MessageType type, bool isLeft, std::shared_ptr<model::Message> pmessage)
{
    auto messageItem = MessageItemFactory::createMessageItem(type, isLeft, pmessage);
    m_container->layout()->addWidget(messageItem);
}
