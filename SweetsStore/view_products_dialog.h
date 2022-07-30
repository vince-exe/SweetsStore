#ifndef VIEW_PRODUCTS_DIALOG_H
#define VIEW_PRODUCTS_DIALOG_H

#include <QDialog>
#include <QStandardItem>

/* return an item with the text aligned */
QStandardItem* getItem(QString string);

namespace Ui {
class ViewProductsDialog;
}

class ViewProductsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewProductsDialog(QWidget *parent = nullptr);
    ~ViewProductsDialog();

private slots:
    void on_addProdBtn_4_clicked();

    void on_addProdBtn_2_clicked();

    void on_addProdBtn_5_clicked();

    void on_infoBtn_clicked();

    void on_rmProdBtn_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::ViewProductsDialog *ui;
};

#endif // VIEW_PRODUCTS_DIALOG_H
