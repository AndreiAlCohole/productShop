#pragma once

#include <QMainWindow>
#include "AppController.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(AppController* ctrl, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showLoginScreen();
    void on_loginButton_clicked();
  void on_exitButton_clicked();
    void on_registerButton_clicked();

private:
    Ui::MainWindow *ui;
    AppController* controller;
    void loginUser(std::shared_ptr<User> user);
};
