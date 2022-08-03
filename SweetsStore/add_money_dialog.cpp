#include "add_money_dialog.h"
#include "ui_add_money_dialog.h"

#include <QMessageBox>

#include "employee_utilities.h"
#include "utilities.h"

AddMoneyDialog::AddMoneyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMoneyDialog) {
    ui->setupUi(this);

    this->setGeometry(100, 100, 441, 354);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    ui->phraseLabel->setAlignment(Qt::AlignCenter);
    ui->titleLabel->setAlignment(Qt::AlignCenter);
}

AddMoneyDialog::~AddMoneyDialog() {
    delete ui;
}

/* check if the user doesn't pass the limit for the amount of money */
void AddMoneyDialog::on_moneyBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > 4) { ui->moneyBox->backspace(); }
}

void AddMoneyDialog::on_saveBtn_clicked() {
    float money;
    try {
        auto it = customersDatabase.find(currentCustomer.getEmail());
        money = it->second.getMoney();
        money += std::stof(ui->moneyBox->text().toStdString());

        /* check if he confirm to add the amount of money */
        QMessageBox confirmBox;
        confirmBox.setText(tr("The application will proceed with adding the amount of money to the bank account, are you sure you want to continue?"));
        confirmBox.addButton(tr("Yes"), QMessageBox::YesRole);
        QAbstractButton* noBtn = confirmBox.addButton(tr("No"), QMessageBox::YesRole);
        /* show the message box */
        confirmBox.exec();
        /* if the user doesn't want to save the money, close */
        if(confirmBox.clickedButton() == noBtn) { this->close(); return; }

        it->second.setMoney(money);

        QMessageBox messageBox;
        messageBox.information(0, "Success", "Successfully added the amount of money to the bank account");
        messageBox.setFixedSize(550, 300);

        /* store the informations in the file */
        FILE* f = fopen("files/customers.txt", "w");
        storeCustomersInformations(f, &customersDatabase);
        fclose(f);

        this->close();
        return;
    }
    catch(std::invalid_argument) {
        QMessageBox messageBox;
        messageBox.warning(0, "Warning", "Invalid amount of money");
        messageBox.setFixedSize(550, 300);

        ui->moneyBox->clear();
        return;
    }
}
