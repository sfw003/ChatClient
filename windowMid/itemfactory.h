#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H


#include <QWidget>

enum class ItemType : int
{
    SessionType,
    FriendType,
    ApplyType
};

class BasedItem : public QWidget
{
    Q_OBJECT
public:
    explicit BasedItem(QWidget *area, const QIcon &avatar, const QString &name, const QString &text);


    // 让item在鼠标进入，按下，离开呈现颜色变化
    void select(); //mousePressEvent子函数
    void mousePressEvent(QMouseEvent *event) override;
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;

    //背景色
    void paintEvent(QPaintEvent *event) override;

    virtual void active();
signals:

private:
    // item在鼠标进入，按下，离开呈现颜色变化
    const QString m_defaultColor = "QWidget {background-color: #ffffff; }";
    const QString m_selectedColor = "QWidget {background-color: #ccebff; }";
    const QString m_enderColor = "QWidget {background-color: #e7e7e7; }";

    // parent指针
    QWidget* m_area;
    //是否被选中
    bool m_selected = false;
};

// SessionItem
class SessionItem : public BasedItem
{
    Q_OBJECT
public:
    SessionItem(QWidget* area, const QString& sessionId,
              const QIcon& avatar, const QString &name, const QString& lastMessage);
    void active() override;
private:
    QString m_sessionId;
};

// FriendItem
class FriendItem : public BasedItem
{
    Q_OBJECT
public:
    FriendItem(QWidget* area, const QString& userId,
              const QIcon& avatar, const QString &name, const QString& description);
    void active() override;
private:
    QString m_userId;
};

// ApplyItem
class ApplyItem : public BasedItem
{
    Q_OBJECT
public:
    ApplyItem(QWidget* area, const QString& userId,
              const QIcon& avatar, const QString &name, const QString& description);
    void active() override;
private:
    QString m_userId;
};

// ItemFactory
class ItemFactory
{
public:
    static BasedItem* createItem(ItemType type, QWidget* area, const QString& id,
                                 const QIcon& avatar, const QString &name, const QString& text);
};

#endif // ITEMFACTORY_H
