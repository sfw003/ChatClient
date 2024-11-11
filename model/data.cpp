#include "data.h"

//生成消息ID
QString model::MakeMessageId()
{
    return "M" + QUuid::createUuid().toString().sliced(25, 12);
}
//获取时间戳
int64_t model::GetTimestamp()
{
    return QDateTime::currentSecsSinceEpoch();
}
//格式化时间戳
QString model::FormatTime(int64_t timestamp)
{
    QDateTime dateTime = QDateTime::fromSecsSinceEpoch(static_cast<time_t>(timestamp));
    return dateTime.toString("MM-dd HH:mm:ss");
}

QIcon model::ByteArrayToIcon(const QByteArray& byteArray)
{
    QPixmap pixMap;
    pixMap.loadFromData(byteArray);
    return QIcon(pixMap);
}
// 读取二进制文件内容到QByteArray
QByteArray model::ReadFileToByteArray(const QString& filename)
{
    QFile file(filename);
    bool ok = file.open(QFile::ReadOnly);
    if(ok)
    {
        qDebug() << "file open fail";
        return QByteArray();
    }
    QByteArray content = file.readAll();
    file.close();
    return content;
}
// 写入内容到二进制文件
void model::WriteByteArrayToFile(const QString& filename, const QByteArray& byteArray)
{
    QFile file(filename);
    bool ok = file.open(QFile::WriteOnly);
    if(ok)
    {
        qDebug() << "file open fail";
        return;
    }
    file.write(byteArray);
    file.flush();
    file.close();
    return;
}



model::TextMessage::TextMessage(const QString& chatSessionId, const UserInfo& sender, const QByteArray& content)
{
    m_messageId = MakeMessageId();
    m_chatSessionId = chatSessionId;
    m_time = FormatTime(GetTimestamp());
    m_messageType = MessageType::TextMessageType;
    m_sender = sender;
    m_content = content;
}

model::ImageMessage::ImageMessage(const QString& chatSessionId, const UserInfo& sender, const QByteArray& content)
{
    m_messageId = MakeMessageId();
    m_chatSessionId = chatSessionId;
    m_time = FormatTime(GetTimestamp());
    m_messageType = MessageType::ImageMessageType;
    m_sender = sender;
    m_content = content;
}

model::FileMessage::FileMessage(const QString& chatSessionId, const UserInfo& sender,
            const QByteArray& content, const QString& extraInfo)
{
    m_messageId = MakeMessageId();
    m_chatSessionId = chatSessionId;
    m_time = FormatTime(GetTimestamp());
    m_messageType = MessageType::FileMessageType;
    m_sender = sender;
    m_content = content;

    m_filename = extraInfo;
}

model::SpeechMessage::SpeechMessage(const QString& chatSessionId, const UserInfo& sender, const QByteArray& content)
{
    m_messageId = MakeMessageId();
    m_chatSessionId = chatSessionId;
    m_time = FormatTime(GetTimestamp());
    m_messageType = MessageType::SpeechMessageType;
    m_sender = sender;
    m_content = content;
}


std::shared_ptr<model::Message> model::MessageFactory::CreateMessage(model::MessageType messageType,const QString& chatSessionId,
                                                                    const UserInfo& sender, const QByteArray& content, const QString& extraInfo)
{
    if(messageType == MessageType::TextMessageType)
    {
        return std::make_shared<TextMessage>(chatSessionId, sender, content);
    }
    else if(messageType == MessageType::ImageMessageType)
    {
        return std::make_shared<ImageMessage>(chatSessionId, sender, content);
    }
    else if(messageType == MessageType::FileMessageType)
    {
        return std::make_shared<FileMessage>(chatSessionId, sender, content, extraInfo);
    }
    else if(messageType == MessageType::SpeechMessageType)
    {
        return std::make_shared<SpeechMessage>(chatSessionId, sender, content);
    }
    else
    {
        return nullptr;
    }
}
