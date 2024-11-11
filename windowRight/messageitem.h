#ifndef MESSAGEITEM_H
#define MESSAGEITEM_H
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "model/data.h"
class MessageItem : public QWidget
{
    Q_OBJECT
public:
    MessageItem(bool isLeft, std::shared_ptr<model::Message> message);

    //展示消息

    void initSlots();
private:
    QPushButton* m_avatarBtn;
    QLabel* m_nameLabel;
};

class TextMessageItem : public MessageItem
{
public:
    TextMessageItem(bool isLeft, std::shared_ptr<model::Message> pmessage);
};

class ImageMessageItem : public MessageItem
{
public:
    ImageMessageItem(bool isLeft, std::shared_ptr<model::Message> pmessage);
};

class FileMessageItem : public MessageItem
{
public:
    FileMessageItem(bool isLeft, std::shared_ptr<model::Message> pmessage);
};

class SpeechMessageItem : public MessageItem
{
public:
    SpeechMessageItem(bool isLeft, std::shared_ptr<model::Message> pmessage);
};


class MessageItemFactory
{
public:
    static MessageItem* createMessageItem(model::MessageType type, bool isLeft, std::shared_ptr<model::Message> pmessage);
};

//消息内容

class MessageContent : public QWidget
{
    Q_OBJECT
public:
    MessageContent(bool isLeft, const QString& content);
    void paintEvent(QPaintEvent* event) override;

private:
    QLabel* m_content;
    bool m_isLeft;
};

#endif // MESSAGEITEM_H
