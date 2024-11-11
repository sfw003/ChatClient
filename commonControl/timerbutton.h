#ifndef TIMERBUTTON_H
#define TIMERBUTTON_H

static constexpr int gs_defaulteTimerButtonGapTime =10;

#include <QPushButton>
#include <QTimer>
#include <QMouseEvent>
class TimerButton : public QPushButton
{
    Q_OBJECT
public:
    explicit TimerButton(QWidget *parent = nullptr);
    ~TimerButton();
    virtual void mouseReleaseEvent(QMouseEvent *e) override;
    void SetTimeout(int timeout);
signals:

private:
    QTimer* m_timer;
    int m_timeout;
    int m_count;

};

#endif // TIMERBUTTON_H
