#include "messageitem.h"
#include <QGridLayout>

#include <QFont>
#include <QPainter>

#include "otherinfodialog.h"
MessageItem::MessageItem(bool isLeft, std::shared_ptr<model::Message> pmessage)
{
    // 1. 创建对象和布局管理器
    QGridLayout* layout = new QGridLayout();
    layout->setContentsMargins(30, 10, 40, 0);
    layout->setSpacing(10);

    this->setMinimumHeight(100);
    this->setLayout(layout);

    // 2. 创建头像
    m_avatarBtn = new QPushButton();
    m_avatarBtn->setFixedSize(40, 40);
    m_avatarBtn->setIconSize(QSize(40, 40));
    m_avatarBtn->setIcon(pmessage->m_sender.m_avatar);
    m_avatarBtn->setStyleSheet("QPushButton { border: none;}");
    if (isLeft)
    {
        layout->addWidget(m_avatarBtn, 0, 0, 2, 1, Qt::AlignTop | Qt::AlignLeft);
    } else
    {
        layout->addWidget(m_avatarBtn, 0, 1, 2, 1, Qt::AlignTop | Qt::AlignRight);
    }

    // 3. 创建名字和时间
    m_nameLabel = new QLabel();
    m_nameLabel->setText(pmessage->m_sender.m_nickName + " | " + pmessage->m_time);
    m_nameLabel->setAlignment(Qt::AlignBottom);
    m_nameLabel->setStyleSheet("QLabel { font-size: 12px; color: rgb(178, 178, 178); }");
    if (isLeft)
    {
        layout->addWidget(m_nameLabel, 0, 1, Qt::AlignTop | Qt::AlignLeft);
    } else
    {
        layout->addWidget(m_nameLabel, 0, 0, Qt::AlignRight);
    }

    initSlots();
}

void MessageItem::initSlots()
{
    connect(m_avatarBtn, &QPushButton::clicked, this, [&](){
        OtherInfoDialog* other = new OtherInfoDialog(this);
        other->show();
    });
}


TextMessageItem::TextMessageItem(bool isLeft, std::shared_ptr<model::Message> pmessage)
    :MessageItem(isLeft, pmessage)
{
    //4. 创建消息体
    QWidget* content = new MessageContent(isLeft, pmessage->m_content);
    if (isLeft)
    {
        QGridLayout* layout = dynamic_cast<QGridLayout*>(this->layout());
        layout->addWidget(content, 1, 1);
    } else
    {
        QGridLayout* layout = dynamic_cast<QGridLayout*>(this->layout());
        layout->addWidget(content, 1, 0);
    }
}

FileMessageItem::FileMessageItem(bool isLeft, std::shared_ptr<model::Message> pmessage)
    :MessageItem(isLeft, pmessage)
{
    QWidget* content = new MessageContent(isLeft, pmessage->m_content);
    if (isLeft)
    {
        QGridLayout* layout = dynamic_cast<QGridLayout*>(this->layout());
        layout->addWidget(content, 1, 1);
    } else
    {
        QGridLayout* layout = dynamic_cast<QGridLayout*>(this->layout());
        layout->addWidget(content, 1, 0);
    }
}

ImageMessageItem::ImageMessageItem(bool isLeft, std::shared_ptr<model::Message> pmessage)
    :MessageItem(isLeft, pmessage)
{
    QWidget* content = new MessageContent(isLeft, pmessage->m_content);
    if (isLeft)
    {
        QGridLayout* layout = dynamic_cast<QGridLayout*>(this->layout());
        layout->addWidget(content, 1, 1);
    } else
    {
        QGridLayout* layout = dynamic_cast<QGridLayout*>(this->layout());
        layout->addWidget(content, 1, 0);
    }
}

SpeechMessageItem::SpeechMessageItem(bool isLeft, std::shared_ptr<model::Message> pmessage)
    :MessageItem(isLeft, pmessage)
{
    QWidget* content = new MessageContent(isLeft, pmessage->m_content);
    if (isLeft)
    {
        QGridLayout* layout = dynamic_cast<QGridLayout*>(this->layout());
        layout->addWidget(content, 1, 1);
    } else
    {
        QGridLayout* layout = dynamic_cast<QGridLayout*>(this->layout());
        layout->addWidget(content, 1, 0);
    }
}



MessageItem *MessageItemFactory::createMessageItem(model::MessageType type, bool isLeft, std::shared_ptr<model::Message> pmessage)
{
    if(type == model::MessageType::TextMessageType)
    {
        return new TextMessageItem(isLeft, pmessage);
    }
    else if(type == model::MessageType::ImageMessageType)
    {
        return new ImageMessageItem(isLeft, pmessage);
    }
    else if(type == model::MessageType::FileMessageType)
    {
        return new FileMessageItem(isLeft, pmessage);
    }
    else if(type == model::MessageType::SpeechMessageType)
    {
        return new SpeechMessageItem(isLeft, pmessage);
    }
    else
    {
        return nullptr;
    }
}

//MessageContent
MessageContent::MessageContent(bool isLeft, const QString &content)
    :m_isLeft(isLeft)
{
    //如果不设置，会等宽
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //设置样式
    //1. 设置字体
    QFont font;
    font.setFamily("微软雅黑");
    font.setPixelSize(16);

    //2. 设置m_content
    m_content = new QLabel(this);
    m_content->setFont(font);
    m_content->setText(content);
    m_content->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    m_content->setWordWrap(true);    // 设置文本自动换行
    m_content->setStyleSheet("QLabel { padding: 0 10px; line-height: 1.2; background-color: transparent; }");

    //3.
}

void MessageContent::paintEvent(QPaintEvent *event)
{
    (void)event;
    QObject* object = this->parent();
    if(!object->isWidgetType())
    {
        //error
        return;
    }

    QWidget* parent = dynamic_cast<QWidget*>(object);

    int width = parent->width() * 0.6;

    //3. 计算行数
    QFontMetrics metrics(this->m_content->font());
    int totalWidth = metrics.horizontalAdvance(this->m_content->text());

    int rows = totalWidth / (width - 40) + 1;
    if(rows == 1)
    {
        width = totalWidth + 40;
    }

    //4. 计算高度: 高度 = 行数 * (字体大小 * 1.2) + 20(上下边距和)
    int height = rows * (this->m_content->font().pixelSize()*1.2) + 20;

    //5. 绘制圆角矩形
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if(m_isLeft)
    {
        painter.setPen(QPen(QColor(255, 255, 255)));
        painter.setBrush(QColor(255, 255, 255));

        painter.drawRoundedRect(10, 0, width, height, 10, 10);

        this->m_content->setGeometry(10, 0, width, height);
    }
    else
    {
        painter.setPen(QPen(QColor(0, 153,255)));
        painter.setBrush(QColor(0, 153,255));

        // 圆角矩形左侧边的横坐标位置
        int leftPos = this->width() - width;
        // 绘制圆角矩形
        painter.drawRoundedRect(leftPos, 0, width, height, 10, 10);

        this->m_content->setGeometry(leftPos, 0, width, height);
    }

    //重新修改父元素高度，确保能容下消息
    parent->setFixedHeight(height + 50);
}
