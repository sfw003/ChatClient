#include "itemscrollarea.h"
#include "config.h"
#include <QScrollBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QIcon>
#include <QDebug>



ItemScrollArea::ItemScrollArea(QWidget *parent)
    : QScrollArea{parent}
{}

void ItemScrollArea::init()
{
    //1. 设置滚动条
    this->setWidgetResizable(true);
    this->verticalScrollBar()->setStyleSheet("QScrollBar:vertical {width: 4px; background-color: #d7d7d7;}");
    this->horizontalScrollBar()->setStyleSheet("QScrollBar:horizontal {height: 0px}");

    //2. 设置QWidget
    m_container = new QWidget(this);
    m_container->setFixedWidth(310);
    this->setWidget(m_container);

    //3. 为QWidget设置布局
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setAlignment(Qt::AlignTop);

    m_container->setLayout(layout);

#ifdef SFW_Debug
    QIcon icon(":/resource/image/avatar_boy.png");
    for(int i = 0; i < 20; i++)
    {
        this->addItem(ItemType::SessionType, QString::number(i), icon, "sfw", "sfwnb");
    }
#endif

}

void ItemScrollArea::clear()
{
    QLayout* layout = m_container->layout();
    size_t n = layout->count();
    for(int i = (int)n-1; i >= 0; --i)
    {
        auto item = layout->takeAt(i);
        if(item->widget())
        {
            delete item;
        }
    }
}

void ItemScrollArea::addItem(ItemType type, const QString& id, const QIcon& avatar, const QString& name, const QString& text)
{
    auto item = ItemFactory::createItem(type, this, id, avatar, name, text);
    if(item == nullptr) //double check
    {
        return;
    }
    m_container->layout()->addWidget(item);
}
