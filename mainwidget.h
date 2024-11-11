#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;
}
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    static MainWidget* getInstance();
    ~MainWidget();


private:
    MainWidget(QWidget *parent = nullptr);
    MainWidget(const MainWidget&) = delete;
    MainWidget& operator=(const MainWidget&) = delete;


    void initUI();
    void initSlots();

    //windowleft
    void switchTabSessionList();
    void switchTabFriendList();
    void switchTabApplyList();

    void loadSessionList();
    void loadFriendList();
    void loadApplyList();
private:
    Ui::MainWidget *ui;
    static MainWidget* s_instance;

    //windowleft
    enum class ActiveTab : int
    {
        SESSION_LIST,   // 会话列表
        FRIEND_LIST,    // 好友列表
        APPLY_LIST      // 好友申请列表
    };
    ActiveTab m_activeTab = ActiveTab::SESSION_LIST;

    //windowsMid
};

#endif // MAINWIDGET_H
