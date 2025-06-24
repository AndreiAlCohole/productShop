#include "RegisterWindow.h"
#include "ui_RegisterWindow.h"
#include <QMessageBox>

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

std::shared_ptr<User> RegisterWindow::getNewUser() const {
    return newUser;
}

void RegisterWindow::on_registerButton_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();
    QString type = ui->accountTypeComboBox->currentText();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Podaj nazwę i hasło.");
        return;
    }

    if (type == "Buyer") {
        newUser = std::make_shared<Buyer>(username.toStdString(), password.toStdString());
    } else if (type == "Seller") {
        newUser = std::make_shared<Seller>(username.toStdString(), password.toStdString());
    } else {
        QMessageBox::warning(this, "Błąd", "Wybierz typ konta.");
        return;
    }

    accept(); // zamyka okno rejestracji
}
