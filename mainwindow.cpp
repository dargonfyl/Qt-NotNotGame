#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , state(new Game::GameState())
{
    ui->setupUi(this);

    // Connect buttons to gamestate
    connect(ui->red, SIGNAL(pressed()), this, SLOT(colorPressed()));
    connect(ui->green, SIGNAL(pressed()), this, SLOT(colorPressed()));
    connect(ui->blue, SIGNAL(pressed()), this, SLOT(colorPressed()));
    connect(ui->yellow, SIGNAL(pressed()), this, SLOT(colorPressed()));

    ui->timerBar->setRange(0, 5000);
    connect(state, SIGNAL(timeRemaining(int)), ui->timerBar, SLOT(setValue(int)));

    state->startGame();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete state;
}


void MainWindow::colorPressed()
{
    QPushButton *button = (QPushButton *)sender();
    (void)button; // TODO: do something with the button
    state->increaseScore();
}


void MainWindow::updateTimerBar(int remaining)
{

}
