#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    connect(ui->pbuttonCloseApp, &QPushButton::clicked,
            this, &MainWindow::slotProcessCloseAppRequest);
}

void MainWindow::slotProcessCloseAppRequest(int code)
{
    QMessageBox confirmClose;

    confirmClose.addButton(QMessageBox::Ok);
    confirmClose.addButton(QMessageBox::Cancel);

    confirmClose.setText("Are you sure to close app?");
    confirmClose.setInformativeText("Connection will be stopped");


    auto result = confirmClose.exec();

    if(QMessageBox::Ok == result)
    {
        emit signalCloseAppConfirmed(code);
    }

}
