#include "timerbutton.h"

TimerButton::TimerButton(QWidget* parent):QPushButton(parent), m_timeout(gs_defaulteTimerButtonGapTime), m_count(m_timeout)
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, [this](){
        --m_count;
        if(m_count <= 0)
        {
            m_timer->stop();
            m_count = m_timeout;
            this->setText("获取验证码");
            this->setEnabled(true);
            return;
        }
        this->setText(QString::number(m_count));
    });
}
TimerButton::~TimerButton()
{
    m_timer->stop();
}
void TimerButton::SetTimeout(int timeout)
{
    m_timeout = timeout;
}
void TimerButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        this->setEnabled(false);
        this->setText(QString::number(m_count));
        m_timer->start(1000);
        emit clicked();
    }
}
