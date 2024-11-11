#include "itemfactory.h"

#include <QGridLayout>
#include <QPushButton>
#include <QPainter>
#include <QLabel>
#include <QStyleOption>
BasedItem::BasedItem(QWidget *area, const QIcon &avatar, const QString &name, const QString &text)
    : m_area(area)
{
    this->setFixedHeight(70);
    this->setStyleSheet(m_defaultColor);

    QGridLayout* layout = new QGridLayout();
    layout->setContentsMargins(20, 0, 0, 0);
    layout->setHorizontalSpacing(10);
    layout->setVerticalSpacing(0);
    this->setLayout(layout);

    // 创建头像
    QPushButton* avatarBtn = new QPushButton();
    avatarBtn->setFixedSize(50, 50);
    avatarBtn->setIconSize(QSize(50, 50));
    avatarBtn->setIcon(avatar);
    avatarBtn->setStyleSheet("QPushButton {border: none;}");
    avatarBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // 创建名字
    QLabel* nameLabel = new QLabel();
    nameLabel->setText(name);
    nameLabel->setStyleSheet("QLabel { font-size: 18px; font-weight: 600; }");
    nameLabel->setFixedHeight(35);
    nameLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    // 创建消息预览的 label
    QLabel* messageLabel = new QLabel();
    messageLabel->setText(text);
    messageLabel->setFixedHeight(35);
    messageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    // 头像处于 0, 0 位置, 占据 2 行, 占据 2 列
    layout->addWidget(avatarBtn, 0, 0, 2, 2);
    // 名字处于 0, 2 位置, 占据 1 行, 占据 1 列
    layout->addWidget(nameLabel, 0, 2, 1, 8);
    // 消息预览处于 1, 2 位置, 占据 1 行, 占据 1 列
    layout->addWidget(messageLabel, 1, 2, 1, 8);
}

void BasedItem::paintEvent(QPaintEvent *event)
{
    (void) event;
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void BasedItem::mousePressEvent(QMouseEvent *event)
{
    (void) event;
    select();
}

void BasedItem::enterEvent(QEnterEvent *event)
{
    (void) event;
    if (this->m_selected) {
        return;
    }
    this->setStyleSheet(m_enderColor);
}

void BasedItem::leaveEvent(QEvent *event)
{
    (void) event;
    if (this->m_selected) {
        return;
    }
    this->setStyleSheet(m_defaultColor);
}

void BasedItem::select()
{
    //1. 清除其他会话的选中效果
    const QObjectList children = this->parentWidget()->children();
    for (QObject* child : children)
    {
        if (!child->isWidgetType())
        {
            continue;
        }
        BasedItem* item = dynamic_cast<BasedItem*>(child);
        if (item->m_selected)
        {
            item->m_selected = false;
            item->setStyleSheet(m_defaultColor);
        }
    }
    //2. 设置选中状态
    this->setStyleSheet(m_selectedColor);
    this->m_selected = true;

    //3. 执行加载函数
    this->active();
}

void BasedItem::active()
{}

// SessionItem

SessionItem::SessionItem(QWidget* area, const QString& sessionId, const QIcon &avatar, const QString &name, const QString &lastMessage)
    :BasedItem(area, avatar, name, lastMessage)
    ,m_sessionId(sessionId)
{

}

void SessionItem::active()
{

}

//FriendItem
FriendItem::FriendItem(QWidget *area, const QString &userId, const QIcon &avatar, const QString &name, const QString &description)
    : BasedItem(area, avatar, name, description)
    , m_userId(userId)
{

}

void FriendItem::active()
{

}




// ApplyItem
ApplyItem::ApplyItem(QWidget *area, const QString &userId, const QIcon &avatar, const QString &name, const QString &description)
    : BasedItem(area, avatar, name, description)
    , m_userId(userId)
{
    //添加2个按钮

}

void ApplyItem::active()
{

}


BasedItem *ItemFactory::createItem(ItemType type, QWidget *area, const QString &id, const QIcon &avatar, const QString &name, const QString &text)
{
    if(type == ItemType::SessionType)
    {
        return new SessionItem(area, id, avatar, name, text);
    }
    else if(type == ItemType::FriendType)
    {
        return new FriendItem(area, id, avatar, name, text);
    }
    else if(type == ItemType::ApplyType)
    {
        return new ApplyItem(area, id, avatar, name, text);
    }
    else
    {
        //error
        return nullptr;
    }
}
