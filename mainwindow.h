//File : mainwindow.h
//Class Name : MainWindow
//QtTicTacToe
//Version 0.1
//Written by Ali Reza Pazhouhesh
//Qt Version 4.8

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void clearBoard();
    void showAbout();
    void showProgrammer();
    void showOptions();
    void showStatistics();
    void changeOptionsToO();
    void changeOptionsToX();
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
    void on_btn5_clicked();
    void on_btn6_clicked();
    void on_btn7_clicked();
    void on_btn8_clicked();
    void on_btn9_clicked();
private:
    //Variables and Objects
    Ui::MainWindow *ui;
    QString turn;
    QString winner;
    int cpuWins;
    int playerWins;
    int noWinner;
    QLabel *statusLabel;
    QLabel *statusLabelTime;
    //Functions
    void cpuTurn();
    void endGame();
    bool checkWin();
    void nextMove();
    int makeRandomNumber();
    bool canFillBoard(QPushButton *btn);
    bool fullBoard();
};

#endif // MAINWINDOW_H
