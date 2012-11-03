/*******************************************************************************
 * QtTicTacToe Version 1.4                                                     *
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
#include "downloadupdate.h"

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
    void check4UpdateVersion(QString);
    void getTurn(QString s);
    void getMode(QString s);
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
    void on_btn5_clicked();
    void on_btn6_clicked();
    void on_btn7_clicked();
    void on_btn8_clicked();
    void on_btn9_clicked();
    void clearStatistics();
    void changeModeToP2P();
    void changeModeToP2C();
    void showStatistics();
    void changeTurnToO();
    void changeTurnToX();
    void check4Update();
    void updateScores();
    void showOptions();
    void clearBoard();
    void showAbout();

private:
    //Variables and Objects
    Ui::MainWindow *ui;
    DownloadUpdate *dUpdate;
    QList<QPushButton*> boardButtons;QString winner;
    QLabel *statusLabelTime;
    QLabel *statusLabel;
    int playerOWins;
    int playerXWins;
    QString version;
    QString turn;
    QString mode;
    Options *opt;
    int w1,w2,w3; //Cell numbers for change back color
    int tie;

    //Functions
    void updateStatusLabel(const QString str);
    bool canFillBoard(QPushButton *btn);
    void playerMove(int index);
    int makeRandomNumber();
    void changeTurn();
    bool fullBoard();
    bool checkWin();
    void nextMove();
    void cpuMove();
    void endGame();
};

#endif // MAINWINDOW_H
