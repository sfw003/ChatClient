#include "mainwidget.h"

#include <QApplication>
MainWidget* MainWidget::s_instance = nullptr;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto instance = MainWidget::getInstance();

    instance->show();
    return a.exec();
}
