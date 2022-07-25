#ifndef ABOUT_ME_DIALOG_H
#define ABOUT_ME_DIALOG_H

#include <QDialog>

namespace Ui {
class AboutMeDialog;
}

class AboutMeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutMeDialog(QWidget *parent = nullptr);
    ~AboutMeDialog();

private:
    Ui::AboutMeDialog *ui;
};

#endif // ABOUT_ME_DIALOG_H
