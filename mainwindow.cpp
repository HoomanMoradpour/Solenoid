#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <wiringPi.h>
#include <iostream>
#include <unistd.h> // for sleep()

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->pushButton->setText("Turn on");
    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(on_click()));
    // Prevent warnings from GPIO
    wiringPiSetupGpio(); // Use BCM pin numbering
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_click()
{
    if (on)
    {
        on = false;
        digitalWrite(18, HIGH);
        ui->pushButton->setText("Turn on");
    }
    else
    {
        on = true;
        digitalWrite(18, LOW);
        ui->pushButton->setText("Turn off");
    }
}

