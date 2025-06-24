#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include <memory>
#include "User.h"
#include "Buyer.h"
#include "Seller.h"

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

    std::shared_ptr<User> getNewUser() const;

private slots:
    void on_registerButton_clicked();

private:
    Ui::RegisterWindow *ui;
    std::shared_ptr<User> newUser = nullptr;
};

#endif // REGISTERWINDOW_H
