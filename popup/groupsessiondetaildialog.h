#ifndef GROUPSESSIONDETAILDIALOG_H
#define GROUPSESSIONDETAILDIALOG_H

#include <QDialog>

namespace Ui {
class GroupSessionDetailDialog;
}

class GroupSessionDetailDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GroupSessionDetailDialog(QWidget *parent = nullptr);
    ~GroupSessionDetailDialog();

private:
    Ui::GroupSessionDetailDialog *ui;
};

#endif // GROUPSESSIONDETAILDIALOG_H
