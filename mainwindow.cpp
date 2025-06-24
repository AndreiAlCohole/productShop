#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "BuyerWindow.h"
#include "SellerWindow.h"
#include "AdminWindow.h"

#include <QMessageBox>
#include "RegisterWindow.h"

// ...
MainWindow::MainWindow(AppController* ctrl, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller(ctrl)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString username = ui->lineEditLogin->text();
    QString password = ui->lineEditPassword->text();

    auto user = controller->login(username.toStdString(), password.toStdString());

    if (user) {
        loginUser(user);
    } else {
        QMessageBox::warning(this, "Login error", "Incorrect username or password.");
    }
}

void MainWindow::loginUser(std::shared_ptr<User> user)
{
    if (user->getType() == "Admin") {
        AdminWindow *adminWindow = new AdminWindow(user, controller, this);
        connect(adminWindow, &AdminWindow::logoutRequested, this, &MainWindow::showLoginScreen);
        adminWindow->show();
        this->hide();
    }
    else if (user->getType() == "Buyer") {
        BuyerWindow *buyerWindow = new BuyerWindow(user, controller, this);
        connect(buyerWindow, &BuyerWindow::logoutRequested, this, &MainWindow::showLoginScreen);
        buyerWindow->show();
        this->hide();
    }
    else if (user->getType() == "Seller") {
        SellerWindow *sellerWindow = new SellerWindow(user, controller, this);
        connect(sellerWindow, &SellerWindow::logoutRequested, this, &MainWindow::showLoginScreen);
        sellerWindow->show();
        this->hide();
    }
}

void MainWindow::on_registerButton_clicked()
{
    RegisterWindow regDialog(this);
    if (regDialog.exec() == QDialog::Accepted) {
        std::shared_ptr<User> newUser = regDialog.getNewUser();
        if (newUser) {
            controller->addUser(newUser);
            QMessageBox::information(this, "Success", "User registered.");
        }
    }
}

void MainWindow::showLoginScreen() {
    this->show();
}

void MainWindow::on_exitButton_clicked()
{
    controller->saveData();
    QApplication::quit();
}
