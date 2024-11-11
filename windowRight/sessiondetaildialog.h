#ifndef SESSIONDETAILDIALOG_H
#define SESSIONDETAILDIALOG_H

#include <QDialog>

namespace Ui {
class SessionDetailDialog;
}

class SessionDetailDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SessionDetailDialog(QWidget *parent = nullptr);
    ~SessionDetailDialog();

private:
    Ui::SessionDetailDialog *ui;
};

#endif // SESSIONDETAILDIALOG_H
