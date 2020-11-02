#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    state = new Game::GameState();
    connect(ui->red, SIGNAL(pressed()), this, SLOT(colorPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete state;
}


void MainWindow::colorPressed()
{
    state->increaseScore();
}
