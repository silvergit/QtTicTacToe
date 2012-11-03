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

#include <QMessageBox>
#include <QTime>
#include <QProgressBar>
#include <QRadioButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QProgressBar>

#include "mainwindow.h"
#include "ui_mainwindow.h"

QString strBtnDefaultColor="background-color:white;color:black";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    turn="O";
    winner="N";
    mode="P2C";
    playerOWins=0;
    playerXWins=0;
    tie=0;

    boardButtons.append(ui->btn1);
    boardButtons.append(ui->btn2);
    boardButtons.append(ui->btn3);
    boardButtons.append(ui->btn4);
    boardButtons.append(ui->btn5);
    boardButtons.append(ui->btn6);
    boardButtons.append(ui->btn7);
    boardButtons.append(ui->btn8);
    boardButtons.append(ui->btn9);

    ui->statusBar->addWidget(statusLabel=new QLabel());
    updateStatusLabel("Tic Tac Toe Version 1.3");

    ui->actionStatus_Bar->toggle();

    connect(ui->action_New_Game,SIGNAL(triggered()),this,SLOT(clearBoard()));
    connect(ui->actionE_xit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->btnNewGame,SIGNAL(clicked()),this,SLOT(clearBoard()));
    connect(ui->btnExit,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->actionStatus_Bar,SIGNAL(toggled(bool)),ui->statusBar,SLOT(setShown(bool)));
    connect(ui->action_About,SIGNAL(triggered()),this,SLOT(showAbout()));
    connect(ui->action_Statistics,SIGNAL(triggered()),this,SLOT(showStatistics()));
    connect(ui->action_Options,SIGNAL(triggered()),this,SLOT(showOptions()));
    connect(ui->action_About_Qt,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearBoard()
{
    winner="N";

    for (int i=0;i<boardButtons.size();i++){
        boardButtons.at(i)->setText("");
        boardButtons.at(i)->setStyleSheet(strBtnDefaultColor);
    }

    updateStatusLabel("Tic Tac Toe Version 1.3");

    for(int i=0;i<boardButtons.size();i++)
        boardButtons.at(i)->setEnabled(true);

    if(turn=="O" && mode=="P2C")
        cpuMove();
}

bool MainWindow::checkWin()
{
    QString strBtnColor="background-color:black;color:yellow;";
    if(ui->btn1->text()==ui->btn2->text() && ui->btn1->text()==ui->btn3->text() && !(canFillBoard(ui->btn1)))
    {
        ui->btn1->setStyleSheet(strBtnColor);
        ui->btn2->setStyleSheet(strBtnColor);
        ui->btn3->setStyleSheet(strBtnColor);
        winner=turn;
        return true;
    }
    else if(ui->btn4->text()==ui->btn5->text() && ui->btn4->text()==ui->btn6->text() && !(canFillBoard(ui->btn4)))
    {
        ui->btn4->setStyleSheet(strBtnColor);
        ui->btn5->setStyleSheet(strBtnColor);
        ui->btn6->setStyleSheet(strBtnColor);
        winner=turn;
        return true;
    }
    else if(ui->btn7->text()==ui->btn8->text() && ui->btn7->text()==ui->btn9->text() && !(canFillBoard(ui->btn7)))
    {
        ui->btn7->setStyleSheet(strBtnColor);
        ui->btn8->setStyleSheet(strBtnColor);
        ui->btn9->setStyleSheet(strBtnColor);
        winner=turn;
        return true;
    }
    else if(ui->btn1->text()==ui->btn4->text() && ui->btn1->text()==ui->btn7->text() && !(canFillBoard(ui->btn1)))
    {
        ui->btn1->setStyleSheet(strBtnColor);
        ui->btn4->setStyleSheet(strBtnColor);
        ui->btn7->setStyleSheet(strBtnColor);
        winner=turn;
        return true;
    }
    else if(ui->btn2->text()==ui->btn5->text() && ui->btn2->text()==ui->btn8->text() && !(canFillBoard(ui->btn2)))
    {
        ui->btn2->setStyleSheet(strBtnColor);
        ui->btn5->setStyleSheet(strBtnColor);
        ui->btn8->setStyleSheet(strBtnColor);
        winner=turn;
        return true;
    }
    else if(ui->btn3->text()==ui->btn6->text() && ui->btn3->text()==ui->btn9->text() && !(canFillBoard(ui->btn3)))
    {
        ui->btn3->setStyleSheet(strBtnColor);
        ui->btn6->setStyleSheet(strBtnColor);
        ui->btn9->setStyleSheet(strBtnColor);
        winner=turn;
        return true;
    }
    else if(ui->btn1->text()==ui->btn5->text() && ui->btn1->text()==ui->btn9->text() && !(canFillBoard(ui->btn1)))
    {
        ui->btn1->setStyleSheet(strBtnColor);
        ui->btn5->setStyleSheet(strBtnColor);
        ui->btn9->setStyleSheet(strBtnColor);
        winner=turn;
        return true;
    }
    else if(ui->btn3->text()==ui->btn5->text() && ui->btn3->text()==ui->btn7->text() && !(canFillBoard(ui->btn3)))
    {
        ui->btn3->setStyleSheet(strBtnColor);
        ui->btn5->setStyleSheet(strBtnColor);
        ui->btn7->setStyleSheet(strBtnColor);
        winner=turn;
        return true;
    }
    winner="N";
    return false;
}

void MainWindow::cpuMove()
{
    if(fullBoard())
    {
        endGame();
        return;
    }
    QString tempTurn;
    turn="O";
    tempTurn="X";
    ////////////////////////////////////////////////////////////////////////////////
    if(ui->btn1->text()==turn && ui->btn2->text()==turn && ui->btn3->text().isEmpty())
        ui->btn3->setText(turn);
    else if(ui->btn1->text()==turn && ui->btn2->text().isEmpty() && ui->btn3->text()==turn)
        ui->btn2->setText(turn);
    else if(ui->btn1->text().isEmpty() && ui->btn2->text()==turn && ui->btn3->text()==turn)
        ui->btn1->setText(turn);
    ////////////////////////////////////////////////////////////////////////////////
    else if(ui->btn4->text()==turn && ui->btn5->text()==turn && ui->btn6->text().isEmpty())
        ui->btn6->setText(turn);
    else if(ui->btn4->text()==turn && ui->btn5->text().isEmpty() && ui->btn6->text()==turn)
        ui->btn5->setText(turn);
    else if(ui->btn4->text().isEmpty() && ui->btn5->text()==turn && ui->btn6->text()==turn)
        ui->btn4->setText(turn);
    ////////////////////////////////////////////////////////////////////////////////
    else if(ui->btn7->text()==turn && ui->btn8->text()==turn && ui->btn9->text().isEmpty())
        ui->btn9->setText(turn);
    else if(ui->btn7->text()==turn && ui->btn8->text().isEmpty() && ui->btn9->text()==turn)
        ui->btn8->setText(turn);
    else if(ui->btn7->text().isEmpty() && ui->btn8->text()==turn && ui->btn9->text()==turn)
        ui->btn7->setText(turn);
    ////////////////////////////////////////////////////////////////////////////////
    else if(ui->btn1->text()==turn && ui->btn4->text()==turn && ui->btn7->text().isEmpty())
        ui->btn7->setText(turn);
    else if(ui->btn1->text()==turn && ui->btn4->text().isEmpty() && ui->btn7->text()==turn)
        ui->btn4->setText(turn);
    else if(ui->btn1->text().isEmpty() && ui->btn4->text()==turn && ui->btn7->text()==turn)
        ui->btn1->setText(turn);
    ////////////////////////////////////////////////////////////////////////////////
    else if(ui->btn2->text()==turn && ui->btn5->text()==turn && ui->btn8->text().isEmpty())
        ui->btn8->setText(turn);
    else if(ui->btn2->text()==turn && ui->btn5->text().isEmpty() && ui->btn8->text()==turn)
        ui->btn5->setText(turn);
    else if(ui->btn2->text().isEmpty() && ui->btn5->text()==turn && ui->btn8->text()==turn)
        ui->btn2->setText(turn);
    ////////////////////////////////////////////////////////////////////////////////
    else if(ui->btn3->text()==turn && ui->btn6->text()==turn && ui->btn9->text().isEmpty())
        ui->btn9->setText(turn);
    else if(ui->btn3->text()==turn && ui->btn6->text().isEmpty() && ui->btn9->text()==turn)
        ui->btn6->setText(turn);
    else if(ui->btn3->text().isEmpty() && ui->btn6->text()==turn && ui->btn9->text()==turn)
        ui->btn3->setText(turn);
    ////////////////////////////////////////////////////////////////////////////////
    else if(ui->btn1->text()==turn && ui->btn5->text()==turn && ui->btn9->text().isEmpty())
        ui->btn9->setText(turn);
    else if(ui->btn1->text()==turn && ui->btn5->text().isEmpty() && ui->btn9->text()==turn)
        ui->btn5->setText(turn);
    else if(ui->btn1->text().isEmpty() && ui->btn5->text()==turn && ui->btn9->text()==turn)
        ui->btn1->setText(turn);
    ////////////////////////////////////////////////////////////////////////////////
    else if(ui->btn3->text()==turn && ui->btn5->text()==turn && ui->btn7->text().isEmpty())
        ui->btn7->setText(turn);
    else if(ui->btn3->text()==turn && ui->btn5->text().isEmpty() && ui->btn7->text()==turn)
        ui->btn5->setText(turn);
    else if(ui->btn3->text().isEmpty() && ui->btn5->text()==turn && ui->btn7->text()==turn)
        ui->btn3->setText(turn);
    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    else if(ui->btn1->text()==tempTurn && ui->btn2->text()==tempTurn && ui->btn3->text().isEmpty())
        ui->btn3->setText(turn);
    else if(ui->btn1->text()==tempTurn && ui->btn2->text().isEmpty() && ui->btn3->text()==tempTurn)
        ui->btn2->setText(turn);
    else if(ui->btn1->text().isEmpty() && ui->btn2->text()==tempTurn && ui->btn3->text()==tempTurn)
        ui->btn1->setText(turn);
    ////////////////////////////////////////////////////////////////////////////////
    else if(ui->btn4->text()==tempTurn && ui->btn5->text()==tempTurn && ui->btn6->text().isEmpty())
        ui->btn6->setText(turn);
    else if(ui->btn4->text()==tempTurn && ui->btn5->text().isEmpty() && ui->btn6->text()==tempTurn)
        ui->btn5->setText(turn);
    else if(ui->btn4->text().isEmpty() && ui->btn5->text()==tempTurn && ui->btn6->text()==tempTurn)
        ui->btn4->setText(turn);
    ////////////////////////////////////////////////////////////////////////////////
    else if(ui->btn7->text()==tempTurn && ui->btn8->text()==tempTurn && ui->btn9->text().isEmpty())
        ui->btn9->setText(turn);
    else if(ui->btn7->text()==tempTurn && ui->btn8->text().isEmpty() && ui->btn9->text()==tempTurn)
        ui->btn8->setText(turn);
    else if(ui->btn7->text().isEmpty() && ui->btn8->text()==tempTurn && ui->btn9->text()==tempTurn)
        ui->btn7->setText(turn);
    ////////////////////////////////////////////////////////////////////////////////
    else if(ui->btn1->text()==tempTurn && ui->btn4->text()==tempTurn && ui->btn7->text().isEmpty())
        ui->btn7->setText(turn);
    else if(ui->btn1->text()==tempTurn && ui->btn4->text().isEmpty() && ui->btn7->text()==tempTurn)
        ui->btn4->setText(turn);
    else if(ui->btn1->text().isEmpty() && ui->btn4->text()==tempTurn && ui->btn7->text()==tempTurn)
        ui->btn1->setText(turn);
    ////////////////////////////////////////////////////////////////////////////////
    else if(ui->btn2->text()==tempTurn && ui->btn5->text()==tempTurn && ui->btn8->text().isEmpty())
        ui->btn8->setText(turn);
    else if(ui->btn2->text()==tempTurn && ui->btn5->text().isEmpty() && ui->btn8->text()==tempTurn)
        ui->btn5->setText(turn);
    else if(ui->btn2->text().isEmpty() && ui->btn5->text()==tempTurn && ui->btn8->text()==tempTurn)
        ui->btn2->setText(turn);
    ////////////////////////////////////////////////////////////////////////////////
    else if(ui->btn3->text()==tempTurn && ui->btn6->text()==tempTurn && ui->btn9->text().isEmpty())
        ui->btn9->setText(turn);
    else if(ui->btn3->text()==tempTurn && ui->btn6->text().isEmpty() && ui->btn9->text()==tempTurn)
        ui->btn6->setText(turn);
    else if(ui->btn3->text().isEmpty() && ui->btn6->text()==tempTurn && ui->btn9->text()==tempTurn)
        ui->btn3->setText(turn);
    ////////////////////////////////////////////////////////////////////////////////
    else if(ui->btn1->text()==tempTurn && ui->btn5->text()==tempTurn && ui->btn9->text().isEmpty())
        ui->btn9->setText(turn);
    else if(ui->btn1->text()==tempTurn && ui->btn5->text().isEmpty() && ui->btn9->text()==tempTurn)
        ui->btn5->setText(turn);
    else if(ui->btn1->text().isEmpty() && ui->btn5->text()==tempTurn && ui->btn9->text()==tempTurn)
        ui->btn1->setText(turn);
    ////////////////////////////////////////////////////////////////////////////////
    else if(ui->btn3->text()==tempTurn && ui->btn5->text()==tempTurn && ui->btn7->text().isEmpty())
        ui->btn7->setText(turn);
    else if(ui->btn3->text()==tempTurn && ui->btn5->text().isEmpty() && ui->btn7->text()==tempTurn)
        ui->btn5->setText(turn);
    else if(ui->btn3->text().isEmpty() && ui->btn5->text()==tempTurn && ui->btn7->text()==tempTurn)
        ui->btn3->setText(turn);
    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    else
    {
        bool flag=true;
        int randomNumber;

        do
        {
            randomNumber=makeRandomNumber();

            if(randomNumber==1 && canFillBoard(ui->btn1))
            {
                ui->btn1->setText(turn);
                flag=false;
            }
            else if(randomNumber==2 && canFillBoard(ui->btn2))
            {
                ui->btn2->setText(turn);
                flag=false;
            }
            else if(randomNumber==3 && canFillBoard(ui->btn3))
            {
                ui->btn3->setText(turn);
                flag=false;
            }
            else if(randomNumber==4 && canFillBoard(ui->btn4))
            {
                ui->btn4->setText(turn);
                flag=false;
            }
            else if(randomNumber==5 && canFillBoard(ui->btn5))
            {
                ui->btn5->setText(turn);
                flag=false;
            }
            else if(randomNumber==6 && canFillBoard(ui->btn6))
            {
                ui->btn6->setText(turn);
                flag=false;
            }
            else if(randomNumber==7 && canFillBoard(ui->btn7))
            {
                ui->btn7->setText(turn);
                flag=false;
            }
            else if(randomNumber==8 && canFillBoard(ui->btn8))
            {
                ui->btn8->setText(turn);
                flag=false;
            }
            else if(randomNumber==9 && canFillBoard(ui->btn9))
            {
                ui->btn9->setText(turn);
                flag=false;
            }
        }while(flag);
    }

    if(checkWin())
    {
        endGame();
        turn="X";
        return;
    }
    if(fullBoard())
    {
        endGame();
        turn="X";
        return;
    }
    turn="X";
}

void MainWindow::playerMove(int index)
{
    if(canFillBoard(boardButtons.at(--index)))
    {
        boardButtons.at(index)->setText(turn);
        if(checkWin())
        {
            endGame();
            return;
        }
        if(fullBoard())
        {
            endGame();
            return;
        }
        if(mode=="P2C")
            cpuMove();
        else changeTurn();
    }
}

void MainWindow::on_btn1_clicked()
{
    playerMove(1);
}

void MainWindow::on_btn2_clicked()
{
    playerMove(2);
}

void MainWindow::on_btn3_clicked()
{
    playerMove(3);
}

void MainWindow::on_btn4_clicked()
{
    playerMove(4);
}

void MainWindow::on_btn5_clicked()
{
    playerMove(5);
}

void MainWindow::on_btn6_clicked()
{
    playerMove(6);
}

void MainWindow::on_btn7_clicked()
{
    playerMove(7);
}

void MainWindow::on_btn8_clicked()
{
    playerMove(8);
}

void MainWindow::on_btn9_clicked()
{
    playerMove(9);
}

void MainWindow::endGame()
{
    if(mode=="P2C"){
        if(winner=="X"){
            updateStatusLabel("You has won. Good Work.");
            playerXWins++;
        }
        else if(winner=="O"){
            updateStatusLabel("CPU has won. Try more.");
            playerOWins++;
        }
        else{
            updateStatusLabel("It is a tie.");
            tie++;
        }
    }
    else{ //if mode=P2P
        if(winner=="X"){
            updateStatusLabel("Player X has won. Good Work");
            playerXWins++;
        }
        else if(winner=="O"){
            updateStatusLabel("Player O has won. Good Work");
            playerOWins++;
        }
        else{
            updateStatusLabel("It is a tie.");
            tie++;
        }
    }



    ui->lbl_Score_1->setText(QString::number(playerOWins));
    ui->lbl_Score_2->setText(QString::number(playerXWins));
    ui->lbl_Score_3->setText(QString::number(tie));

    for(int i=0;i<boardButtons.size();i++)
        boardButtons.at(i)->setEnabled(false);
}

int MainWindow::makeRandomNumber()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    return rand() % 9 + 1;
}

bool MainWindow::canFillBoard(QPushButton *object)
{
    if(object->text().isEmpty())
        return true;
    return false;
}

bool MainWindow::fullBoard()
{
    if(!canFillBoard(ui->btn1) && !canFillBoard(ui->btn2) &&
       !canFillBoard(ui->btn3) && !canFillBoard(ui->btn4) &&
       !canFillBoard(ui->btn5) && !canFillBoard(ui->btn6) &&
       !canFillBoard(ui->btn7) && !canFillBoard(ui->btn8) &&
       !canFillBoard(ui->btn9))
            return true;
    return false;
}

void MainWindow::showAbout()
{
    QMessageBox::information(this,tr("About Tic Tac Toe")
                             ,tr("Tic Tac Toe Game<br>Version 1.3<br>"
                                 "<a href=\"https://github.com/silvergit/tictactoe\">Tic Tac Toe Website</a>"
                                 "<br><br>Ali Reza Pazhouhesh<br>"
                                 "hitman2c47@gmail.com<br>"));
}

void MainWindow::showOptions()
{
    opt=new Options();

    connect(MainWindow::opt,SIGNAL(setMode(QString)),this,SLOT(getMode(QString)));
    connect(MainWindow::opt,SIGNAL(setTurn(QString)),this,SLOT(getTurn(QString)));
    connect(MainWindow::opt,SIGNAL(accepted()),MainWindow::opt,SLOT(setChanges()));
    connect(MainWindow::opt,SIGNAL(accepted()),this,SLOT(clearBoard()));
}

void MainWindow::changeTurnToO()
{
    turn="O";
}

void MainWindow::changeTurnToX()
{
    turn="X";
}

void MainWindow::changeModeToP2P()
{
    mode="P2P";
}

void MainWindow::changeModeToP2C()
{
    mode="P2C";
}

void MainWindow::changeTurn()
{
    if(turn=="X")
        turn="O";
    else
        turn="X";
}

void MainWindow::updateStatusLabel(const QString str)
{
    statusLabel->setText(str);
}

void MainWindow::changeoi(QString str)
{
    ui->btn1->setText(str);
}

void MainWindow::getMode(QString s)
{
    mode=s;
}

void MainWindow::getTurn(QString s)
{
    turn=s;
}

void MainWindow::showStatistics()
{
    QDialog *dlg=new QDialog();
    QVBoxLayout *verticalLayout=new QVBoxLayout;
    QHBoxLayout *topHorizonalLayout=new QHBoxLayout;
    QHBoxLayout *downHorizonalLayout=new QHBoxLayout;
    QProgressBar *playerOProgressBar=new QProgressBar;
    QProgressBar *playerXProgressBar=new QProgressBar;
    QProgressBar *tieProgressBar=new QProgressBar;
    playerOProgressBar->setOrientation(Qt::Vertical);
    playerXProgressBar->setOrientation(Qt::Vertical);
    tieProgressBar->setOrientation(Qt::Vertical);
    QLabel *playerOLabel=new QLabel(tr("O"));
    QLabel *playerXLabel=new QLabel(tr("X"));
    QLabel *tieLabel=new QLabel(tr("Tie"));
    QPushButton *exitDialogButton=new QPushButton(tr("E&xit"));

    playerOLabel->setAlignment(Qt::AlignHCenter);
    playerXLabel->setAlignment(Qt::AlignHCenter);
    tieLabel->setAlignment(Qt::AlignHCenter);

    int maxWins=playerOWins;
    if(playerXWins>maxWins)
        maxWins=playerXWins;
    else if(tie>maxWins)
        maxWins=tie;

    playerOProgressBar->setValue(playerOWins);
    playerOProgressBar->setFormat("%v");
    playerOProgressBar->setMaximum(maxWins);
    playerXProgressBar->setValue(playerXWins);
    playerXProgressBar->setFormat("%v");
    playerXProgressBar->setMaximum(maxWins);
    tieProgressBar->setValue(tie);
    tieProgressBar->setFormat("%v");
    tieProgressBar->setMaximum(maxWins);

    dlg->setModal(true);

    topHorizonalLayout->addSpacing(10);
    topHorizonalLayout->addWidget(playerOProgressBar);
    topHorizonalLayout->addSpacing(10);
    topHorizonalLayout->addWidget(playerXProgressBar);
    topHorizonalLayout->addSpacing(10);
    topHorizonalLayout->addWidget(tieProgressBar);
    topHorizonalLayout->addSpacing(10);

    downHorizonalLayout->addWidget(playerOLabel);
    downHorizonalLayout->addWidget(playerXLabel);
    downHorizonalLayout->addWidget(tieLabel);

    verticalLayout->addLayout(topHorizonalLayout);
    verticalLayout->addLayout(downHorizonalLayout);
    verticalLayout->addWidget(exitDialogButton);

    dlg->setLayout(verticalLayout);
    dlg->show();

    connect(exitDialogButton,SIGNAL(clicked()),dlg,SLOT(close()));
}
