#ifndef UTIL_H
#define UTIL_H
#include <QString>
#include <QWidget>
class Util
{
public:
    static void repolish(QWidget* w);
    //正则表达式匹配邮箱
    static bool matchEmail(QString& email);
    //正则表达式匹配密码
    static bool matchPasswd(QString& passwd);
};

#endif // UTIL_H
