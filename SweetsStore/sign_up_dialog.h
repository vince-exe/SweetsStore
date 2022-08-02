#ifndef SIGN_UP_DIALOG_H
#define SIGN_UP_DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QCheckBox>
#include <QSpinBox>

void clearBoxes(QLineEdit* l1, QLineEdit* l2, QLineEdit* l3, QLineEdit* l4, QLineEdit* l5, QSpinBox* s1, QCheckBox* c1, QCheckBox* c2);

namespace Ui {
class SignUpDialog;
}

class SignUpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignUpDialog(QWidget *parent = nullptr);
    ~SignUpDialog();

private slots:
    void on_firstNameBox_textChanged(const QString &arg1);

    void on_lastNameBox_textChanged(const QString &arg1);

    void on_emailBox_textChanged(const QString &arg1);

    void on_passBox_textChanged(const QString &arg1);

    void on_moneyBox_textChanged(const QString &arg1);

    void on_femaleBox_clicked();

    void on_maleBox_clicked();

    void on_signUpBtn_clicked();

private:
    Ui::SignUpDialog *ui;
};

#endif // SIGN_UP_DIALOG_H
