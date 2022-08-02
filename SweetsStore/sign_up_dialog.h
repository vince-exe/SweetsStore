#ifndef SIGN_UP_DIALOG_H
#define SIGN_UP_DIALOG_H

#include <QDialog>

namespace Ui {
class SignUpDialog;
}

class SignUpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignUpDialog(QWidget *parent = nullptr);
    ~SignUpDialog();

private:
    Ui::SignUpDialog *ui;
};

#endif // SIGN_UP_DIALOG_H
