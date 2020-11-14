#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
#include <QPalette>


void setButtonColor(QPushButton *button, Qt::GlobalColor color) {
    QPalette pal = button->palette();
    pal.setColor(QPalette::Button, QColor(color));
    button->setAutoFillBackground(true);
    button->setPalette(pal);
    button->update();
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , state(new Game::GameState())
{
    ui->setupUi(this);


    // Set button colors
    setButtonColor(ui->red, Qt::red);
    setButtonColor(ui->green, Qt::green);
    setButtonColor(ui->blue, Qt::blue);
    setButtonColor(ui->yellow, Qt::yellow);

    // Connect buttons to gamestate
    connect(ui->red, SIGNAL(pressed()), this, SLOT(colorPressed()));
    connect(ui->green, SIGNAL(pressed()), this, SLOT(colorPressed()));
    connect(ui->blue, SIGNAL(pressed()), this, SLOT(colorPressed()));
    connect(ui->yellow, SIGNAL(pressed()), this, SLOT(colorPressed()));

    ui->timerBar->setRange(0, 5000);
    connect(state, SIGNAL(timeRemaining(int)), ui->timerBar, SLOT(setValue(int)));


    // Connect new levels to visuals
    // TODO: at the start of the game, we always start with green. Fix this
    connect(state, SIGNAL(generateLevel()), this, SLOT(generatedLevel()));

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


void MainWindow::generatedLevel()
{
    // Update input visuals
    Game::INPUT input = state->getInput();

    QLabel *inputs[] = {
        ui->input0,
        ui->input1,
        ui->input2,
        ui->input3,
        ui->input4,
        ui->input5,
        ui->input6,
        ui->input7
    };
    // Clear all the inputs
    for (int i = 0; i < 8; i++)
        inputs[i]->clear();

    QString input_texts[] = {
        "RED",
        "GREEN",
        "BLUE",
        "YELLOW",
        "UP",
        "DOWN",
        "LEFT",
        "RIGHT"
    };

    QLabel *to_update = inputs[input];
    to_update->setText(input_texts[input]);


    // Update negation visuals
    QLabel *negation_label = ui->notIndicator;
    QString negation_string = "";
    for (int i = 1; i <= state->getNegation(); ++i) {
        negation_string += "NOT ";
    }
    negation_label->setText(negation_string);
}

