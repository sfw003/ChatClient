#ifndef OTHERINFODIALOG_H
#define OTHERINFODIALOG_H

#include <QDialog>

namespace Ui {
class OtherInfoDialog;
}

class OtherInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OtherInfoDialog(QWidget *parent = nullptr);
    ~OtherInfoDialog();

private:
    Ui::OtherInfoDialog *ui;
};

#endif // OTHERINFODIALOG_H
