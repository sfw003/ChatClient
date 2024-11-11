#ifndef MESSAGESHOWAREA_H
#define MESSAGESHOWAREA_H

#include <QWidget>
#include <QScrollArea>
#include "messageitem.h"
class MessageShowArea : public QScrollArea
{
    Q_OBJECT
public:
    MessageShowArea(QWidget* parent);

    void init();
    //尾插一条消息
    void addMessageItem(model::MessageType type, bool isLeft, std::shared_ptr<model::Message> pmessage);
private:
    QWidget* m_container;
};

#endif // MESSAGESHOWAREA_H
