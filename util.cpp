#include "util.h"
#include <QRegularExpression>
#include "QStyle"
#include <QDebug>
void Util::repolish(QWidget* w)
{
    w->style()->unpolish(w);
    w->style()->polish(w);
}
//正则表达式匹配邮箱
bool Util::matchEmail(QString& email)
{
    QRegularExpression regex("^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\\.[a-zA-Z0-9_-]+)+$");
    qDebug() << email;//输出的结果"2030689364@qq.com"
    if (regex.match(email).hasMatch())
    {
        return true;
    }
    return false;
}
//正则表达式匹配密码
bool Util::matchPasswd(QString& passwd)
{
    QRegularExpression regex("^(?=.*[a-zA-Z])(?=.*\\d)[a-zA-Z\\d]{8,16}$");
    if (regex.match(passwd).hasMatch())
    {
        return true;
    }
    return false;
}
