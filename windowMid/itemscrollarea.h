#ifndef ITEMSCROLLAREA_H
#define ITEMSCROLLAREA_H

#include <QWidget>
#include <QScrollArea>
#include "itemfactory.h"
class ItemScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    explicit ItemScrollArea(QWidget *parent = nullptr);
    //初始化
    void init();
    //清空
    void clear();
    //添加一个Item到该区域中
    void addItem(ItemType type, const QString& id, const QIcon& avatar, const QString& name, const QString& text);
signals:

private:
    QWidget* m_container;
};

#endif // ITEMSCROLLAREA_H
