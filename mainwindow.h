#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "gamestate.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


private:
    Ui::MainWindow *ui;
    Game::GameState *state;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


protected:
    void keyPressEvent(QKeyEvent *event) override;


private slots:
    void colorPressed();


    void generatedLevel();


    void gameOverModal(unsigned int);
};
#endif // MAINWINDOW_H
