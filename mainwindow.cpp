/*******************************************************************************
 * QtTicTacToe Version 1.1                                                     *
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

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->statusBar->addWidget(statusLabel=new QLabel(tr("Tic Tac Toe Version 0.1")));
    ui->statusBar->addWidget(statusLabelTime=new QLabel);
    turn="O";
    winner="N";
    mode="P2C";
    playerOWins=0;
    playerXWins=0;
    noWinner=0;

    ui->actionStatus_Bar->toggle();

    connect(ui->action_New_Game,SIGNAL(triggered()),this,SLOT(clearBoard()));
    connect(ui->actionE_xit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->btnNewGame,SIGNAL(clicked()),this,SLOT(clearBoard()));
    connect(ui->btnExit,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->actionStatus_Bar,SIGNAL(toggled(bool)),ui->statusBar,SLOT(setShown(bool)));
    connect(ui->action_About,SIGNAL(triggered()),this,SLOT(showAbout()));
    connect(ui->action_Programmer,SIGNAL(triggered()),this,SLOT(showProgrammer()));
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
    ui->btn1->setText("");
    ui->btn2->setText("");
    ui->btn3->setText("");
    ui->btn4->setText("");
    ui->btn5->setText("");
    ui->btn6->setText("");
    ui->btn7->setText("");
    ui->btn8->setText("");
    ui->btn9->setText("");
    if(turn=="O" && mode=="P2C")
        cpuTurn();
    else if(turn=="O" && mode=="P2P")
        changeTurnToX();
}

bool MainWindow::checkWin()
{
    if(ui->btn1->text()==ui->btn2->text() && ui->btn1->text()==ui->btn3->text() && !(canFillBoard(ui->btn1)))
    {
        winner=turn;
        return true;
    }
    else if(ui->btn4->text()==ui->btn5->text() && ui->btn4->text()==ui->btn6->text() && !(canFillBoard(ui->btn4)))
    {
        winner=turn;
        return true;
    }
    else if(ui->btn7->text()==ui->btn8->text() && ui->btn7->text()==ui->btn9->text() && !(canFillBoard(ui->btn7)))
    {
        winner=turn;
        return true;
    }
    else if(ui->btn1->text()==ui->btn4->text() && ui->btn1->text()==ui->btn7->text() && !(canFillBoard(ui->btn1)))
    {
        winner=turn;
        return true;
    }
    else if(ui->btn2->text()==ui->btn5->text() && ui->btn2->text()==ui->btn8->text() && !(canFillBoard(ui->btn2)))
    {
        winner=turn;
        return true;
    }
    else if(ui->btn3->text()==ui->btn6->text() && ui->btn3->text()==ui->btn9->text() && !(canFillBoard(ui->btn3)))
    {
        winner=turn;
        return true;
    }
    else if(ui->btn1->text()==ui->btn5->text() && ui->btn1->text()==ui->btn9->text() && !(canFillBoard(ui->btn1)))
    {
        winner=turn;
        return true;
    }
    else if(ui->btn3->text()==ui->btn5->text() && ui->btn3->text()==ui->btn7->text() && !(canFillBoard(ui->btn3)))
    {
        winner=turn;
        return true;
    }
    winner="N";
    return false;
}

void MainWindow::cpuTurn()
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

void MainWindow::on_btn1_clicked()
{
    if(canFillBoard(ui->btn1))
    {
        ui->btn1->setText(turn);
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
            cpuTurn();
        else changeTurn();
    }
}

void MainWindow::on_btn2_clicked()
{
    if(canFillBoard(ui->btn2))
    {
        ui->btn2->setText(turn);
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
            cpuTurn();
        else changeTurn();
    }
}

void MainWindow::on_btn3_clicked()
{
    if(canFillBoard(ui->btn3))
    {
        ui->btn3->setText(turn);
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
            cpuTurn();
        else changeTurn();
    }
}

void MainWindow::on_btn4_clicked()
{
    if(canFillBoard(ui->btn4))
    {
        ui->btn4->setText(turn);
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
            cpuTurn();
        else changeTurn();
    }
}

void MainWindow::on_btn5_clicked()
{
    if(canFillBoard(ui->btn5))
    {
        ui->btn5->setText(turn);
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
            cpuTurn();
        else changeTurn();
    }
}

void MainWindow::on_btn6_clicked()
{
    if(canFillBoard(ui->btn6))
    {
        ui->btn6->setText(turn);
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
            cpuTurn();
        else changeTurn();
    }
}

void MainWindow::on_btn7_clicked()
{
    if(canFillBoard(ui->btn7))
    {
        ui->btn7->setText(turn);
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
            cpuTurn();
        else changeTurn();
    }
}

void MainWindow::on_btn8_clicked()
{
    if(canFillBoard(ui->btn8))
    {
        ui->btn8->setText(turn);
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
            cpuTurn();
        else changeTurn();
    }
}

void MainWindow::on_btn9_clicked()
{
    if(canFillBoard(ui->btn9))
    {
        ui->btn9->setText(turn);
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
            cpuTurn();
        else changeTurn();
    }
}
///
void MainWindow::endGame()
{
    if(mode=="P2C"){
        if(winner=="X"){
            QMessageBox::information(this,tr("Game Over"),tr("You win.     <br>Good Work"));
            playerXWins++;
        }
        else if(winner=="O"){
            QMessageBox::information(this,tr("Game Over"),tr("You lose.    <br>Try more."));
            playerOWins++;
        }
        else{
            QMessageBox::information(this,tr("Game Over"),tr("No winner."));
            noWinner++;
        }
    }
    else{ //if mode=P2C
        if(winner=="X"){
            QMessageBox::information(this,tr("Game Over"),tr("Player X win.     <br>Good Work"));
            playerXWins++;
        }
        else if(winner=="O"){
            QMessageBox::information(this,tr("Game Over"),tr("Player O win.     <br>Good Work"));
            playerOWins++;
        }
        else{
            QMessageBox::information(this,tr("Game Over"),tr("No winner."));
            noWinner++;
        }
    }
    ui->btn1->setText("T");
    ui->btn2->setText("I");
    ui->btn3->setText("C");
    ui->btn4->setText("T");
    ui->btn5->setText("A");
    ui->btn6->setText("C");
    ui->btn7->setText("T");
    ui->btn8->setText("O");
    ui->btn9->setText("E");

    ui->lbl_Score_1->setText(QString::number(playerOWins));
    ui->lbl_Score_2->setText(QString::number(playerXWins));
    ui->lbl_Score_3->setText(QString::number(noWinner));
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
                             ,tr("Tic Tac Toe Game<br>Version 1.1"));
}

void MainWindow::showProgrammer()
{
    QMessageBox::information(this,tr("About Programmer")
                             ,tr("This program written by:<br>"
                             "Ali Reza Pazhouhesh<br>"
                             "By Qt Version 4.8<br>"));
}

void MainWindow::showStatistics()
{
    QDialog *dlg=new QDialog();
    QVBoxLayout *verticalLayout=new QVBoxLayout;
    QHBoxLayout *topHorizonalLayout=new QHBoxLayout;
    QHBoxLayout *downHorizonalLayout=new QHBoxLayout;
    QProgressBar *cpuProgressBar=new QProgressBar;
    QProgressBar *playerProgressBar=new QProgressBar;
    QProgressBar *noWinnerProgressBar=new QProgressBar;
    cpuProgressBar->setOrientation(Qt::Vertical);
    playerProgressBar->setOrientation(Qt::Vertical);
    noWinnerProgressBar->setOrientation(Qt::Vertical);
    QLabel *cpuLabel=new QLabel(tr("    CPU"));
    QLabel *playerLabel=new QLabel(tr("Player"));
    QLabel *noWinnerLabel=new QLabel(tr("No winner"));
    QPushButton *exitDialogButton=new QPushButton(tr("E&xit"));

    int maxWins=playerOWins;
    if(playerXWins>maxWins)
        maxWins=playerXWins;
    else if(noWinner>maxWins)
        maxWins=noWinner;

    cpuProgressBar->setValue(playerOWins);
    cpuProgressBar->setFormat("%v");
    cpuProgressBar->setMaximum(maxWins);
    playerProgressBar->setValue(playerXWins);
    playerProgressBar->setFormat("%v");
    playerProgressBar->setMaximum(maxWins);
    noWinnerProgressBar->setValue(noWinner);
    noWinnerProgressBar->setFormat("%v");
    noWinnerProgressBar->setMaximum(maxWins);
    dlg->setModal(true);

    topHorizonalLayout->addWidget(cpuProgressBar,60);
    topHorizonalLayout->addWidget(playerProgressBar);
    topHorizonalLayout->addWidget(noWinnerProgressBar);
    downHorizonalLayout->addWidget(cpuLabel,60);
    downHorizonalLayout->addWidget(playerLabel);
    downHorizonalLayout->addWidget(noWinnerLabel);

    verticalLayout->addLayout(topHorizonalLayout);
    verticalLayout->addLayout(downHorizonalLayout);
    verticalLayout->addWidget(exitDialogButton);

    dlg->setLayout(verticalLayout);
    dlg->show();

    connect(exitDialogButton,SIGNAL(clicked()),dlg,SLOT(close()));
}

void MainWindow::showOptions()
{
    QDialog *dlg=new QDialog;
    QGroupBox *gBoxTurn=new QGroupBox(tr("Start game with"));
    QGroupBox *gBoxMode=new QGroupBox(tr("Game mode"));
    QRadioButton *cpuRadio=new QRadioButton(tr("CPU"));
    QRadioButton *playerRadio=new QRadioButton(tr("Player"));
    QRadioButton *p2pRadio=new QRadioButton(tr("Two Player"));
    QRadioButton *p2cRadio=new QRadioButton(tr("One Player"));
    QVBoxLayout *turnLayout=new QVBoxLayout;
    QVBoxLayout *modeLayout=new QVBoxLayout;
    QVBoxLayout *topLayout=new QVBoxLayout;
    QHBoxLayout *downLayout=new QHBoxLayout;
    QVBoxLayout *layout=new QVBoxLayout;
    QPushButton *okButton=new QPushButton(tr("&Ok"));
    QPushButton *cancelButton=new QPushButton(tr("&Cancel"));

    turnLayout->addWidget(cpuRadio);
    turnLayout->addWidget(playerRadio);
    modeLayout->addWidget(p2cRadio);
    modeLayout->addWidget(p2pRadio);
    gBoxTurn->setLayout(turnLayout);
    gBoxMode->setLayout(modeLayout);
    topLayout->addWidget(gBoxTurn);
    topLayout->addWidget(gBoxMode);
    downLayout->addStretch();
    downLayout->addWidget(cancelButton);
    downLayout->addWidget(okButton);
    layout->addLayout(topLayout);
    layout->addLayout(downLayout);

    dlg->setLayout(layout);
    dlg->setModal(true);

    if(turn=="X")
        playerRadio->setChecked(true);
    else
        cpuRadio->setChecked(true);

    if(mode=="P2C")
        p2cRadio->setChecked(true);
    else
        p2pRadio->setChecked(true);

    connect(cpuRadio,SIGNAL(toggled(bool)),this,SLOT(changeTurnToO()));
    connect(playerRadio,SIGNAL(toggled(bool)),this,SLOT(changeTurnToX()));
    connect(p2pRadio,SIGNAL(toggled(bool)),this,SLOT(changeModeToP2P()));
    connect(p2cRadio,SIGNAL(toggled(bool)),this,SLOT(changeModeToP2C()));
    connect(okButton,SIGNAL(clicked()),dlg,SLOT(accept()));
    connect(cancelButton,SIGNAL(clicked()),dlg,SLOT(reject()));

    dlg->show();
    dlg->exec();
    clearBoard();
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
