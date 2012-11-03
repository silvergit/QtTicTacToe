/*******************************************************************************
 * QtTicTacToe Version 1.3                                                     *
 *                                                                             *
 * Copyright (C) 2010-2012 Ali Reza Pazhouhesh <hitman2c47@gmail.com>          *
 *                                                                             *
 * This program is free software: you can redistribute it and/or modify it     *
 * under the terms of the GNU General Public License as published by the Free  *
 * Software Foundation, either version 3 of the License, or (at your option)   *
 * any later version.                                                          *
 *                                                                             *
 * This program is distributed in the hope that it will be useful, but WITHOUT *
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for    *
 * more details.                                                               *
 *                                                                             *
 * You should have received a copy of the GNU General Public License along     *
 * with this program. If not, see <http://www.gnu.org/licenses/>.              *
 *******************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include "options.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void changeoi(QString str);

private slots:
    void clearBoard();
    void showAbout();
    void showOptions();
    void showStatistics();
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
    void on_btn5_clicked();
    void on_btn6_clicked();
    void on_btn7_clicked();
    void on_btn8_clicked();
    void on_btn9_clicked();
    void changeTurnToO();
    void changeTurnToX();
    void changeModeToP2P();
    void changeModeToP2C();
    void getTurn(QString s);
    void getMode(QString s);

private:
    //Variables and Objects
    Ui::MainWindow *ui;
    QString winner;
    int playerOWins;
    int playerXWins;
    int tie;
    QLabel *statusLabel;
    QLabel *statusLabelTime;
    QList<QPushButton*> boardButtons ;

    int w1,w2,w3; //Cell numbers for change back color
    //Functions
    void cpuMove();
    void playerMove(int index);
    void endGame();
    bool checkWin();
    void nextMove();
    int makeRandomNumber();
    bool canFillBoard(QPushButton *btn);
    bool fullBoard();
    void changeTurn();
    void updateStatusLabel(const QString str);
    QString turn;
    QString mode;
    Options *opt;
};

#endif // MAINWINDOW_H
