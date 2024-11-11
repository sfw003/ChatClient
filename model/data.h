/******************************************************************************
 * Copyright 2020-xxxx xxx Co., Ltd.
 * All right reserved. See COPYRIGHT for detailed Information.
 *
 * @file       data.h
 * @brief      XXXX Function
 *
 * @author     xxx<xxx@xxx.com>
 * @date       2024/10/21
 * @history
 *****************************************************************************/
#ifndef _CHATCLIENT_MODEL_DATA_H
#define _CHATCLIENT_MODEL_DATA_H

#include <QString>
#include <QIcon>
#include <QByteArray>
#include <QUuid>
#include <QDateTime>
#include <QPixmap>
#include <QFile>
namespace model {

/**
 * 工具函数
 */
//生成消息Id
QString MakeMessageId();
//获取时间戳
int64_t GetTimestamp();
//时间戳格式化为时间
QString FormatTime(int64_t timestamp);
// 根据 QByteArray 转成 QIcon
QIcon ByteArrayToIcon(const QByteArray& byteArray);
// 读取二进制文件内容到QByteArray
QByteArray ReadFileToByteArray(const QString& filename);
// 写入内容到二进制文件
void WriteByteArrayToFile(const QString& filename, const QByteArray& byteArray);


/**
 * @brief The UserInfo class 用户信息类
 *
 */

class UserInfo
{
public:
    QString m_userId = "";			// 用户编号
    QString m_nickName = "";		// 用户昵称
    QString m_description = ""; 	// 用户签名
    QString m_phone = "";			// 手机号码 (暂时不用)
    QString m_email = "";			// 用户邮箱
    QIcon m_avatar;					// 用户头像
};

/**
 * @brief The MessageType enum  消息类型
 * @brief The Message class     消息类
 * @brief The MessageFactory class 消息工厂
 *
 */
enum class MessageType : int
{
    TextMessageType,                // 文本类型
    ImageMessageType,               // 图片类型
    FileMessageType,                // 文件类型
    SpeechMessageType,              // 语言类型
    UnkownMessageType               // 未知类型
};

class Message
{
public:
    QString m_messageId = "";       // 消息ID
    QString m_chatSessionId = "";   // 会话ID
    QString m_time = "";            // 消息发送时间
    MessageType m_messageType = MessageType::TextMessageType;   //消息类型
    UserInfo m_sender;              // 发送者信息
    QByteArray m_content;           // 消息内容
    QString m_fileId = "";          // 图⽚, ⽂件, 语⾳类型, 表⽰对应的⽂件id
    QString m_filename = "";        // 文件类型，表示文件名，其他为空
};

class TextMessage : public Message
{
public:
    TextMessage(const QString& chatSessionId, const UserInfo& sender, const QByteArray& content);
};

class ImageMessage : public Message
{
public:
    ImageMessage(const QString& chatSessionId, const UserInfo& sender, const QByteArray& content);
};

class FileMessage : public Message
{
public:
    FileMessage(const QString& chatSessionId, const UserInfo& sender,
                const QByteArray& content, const QString& extraInfo);
};

class SpeechMessage : public Message
{
public:
    SpeechMessage(const QString& chatSessionId, const UserInfo& sender, const QByteArray& content);
};

class MessageFactory
{
public:
    static std::shared_ptr<Message> CreateMessage(MessageType messageType,const QString& chatSessionId,
                            const UserInfo& sender, const QByteArray& content, const QString& extraInfo);
};


/**
 * @brief The ChatSessionInfo class 聊天会话类
 *
 */
class ChatSessionInfo
{
public:
    QString m_chatSessionId = "";       // 会话Id
    QString m_chatSessionName = "";     // 会话名
    QIcon m_avatar;                     // 会话头像
    Message m_lastMessage;              // 显示最近的一条消息
    QString m_userId;                   // 会话用户Id
};


}

#endif
