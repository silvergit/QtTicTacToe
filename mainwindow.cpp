//File : mainwindow.cpp
//Header : mainwindow.h
//Class Name : MainWindow
//QtTicTacToe
//Version 0.1
//Written by Ali Reza Pazhouhesh
//Qt Version 4.8

#include <QMessageBox>
#include <QTime>
#include <QProgressBar>
#include <QRadioButton>
#include <QGroupBox>

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
    cpuWins=0;
    playerWins=0;
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
    if(turn=="O")
        cpuTurn();
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
        return;
    }
    if(fullBoard())
    {
        endGame();
        return;
    }
}

void MainWindow::on_btn1_clicked()
{
    turn="X";
    if(canFillBoard(ui->btn1))
    {
        ui->btn1->setText(turn);
        if(checkWin())
        {
            endGame();
            return;
        }
        cpuTurn();
    }
}

void MainWindow::on_btn2_clicked()
{
    turn="X";
    if(canFillBoard(ui->btn2))
    {
        ui->btn2->setText(turn);
        if(checkWin())
        {
            endGame();
            return;
        }
        cpuTurn();
    }
}

void MainWindow::on_btn3_clicked()
{
    turn="X";
    if(canFillBoard(ui->btn3))
    {
        ui->btn3->setText(turn);
        if(checkWin())
        {
            endGame();
            return;
        }
        cpuTurn();
    }
}

void MainWindow::on_btn4_clicked()
{
    turn="X";
    if(canFillBoard(ui->btn4))
    {
        ui->btn4->setText(turn);
        if(checkWin())
        {
            endGame();
            return;
        }
        cpuTurn();
    }
}

void MainWindow::on_btn5_clicked()
{
    turn="X";
    if(canFillBoard(ui->btn5))
    {
        ui->btn5->setText(turn);
        if(checkWin())
        {
            endGame();
            return;
        }
        cpuTurn();
    }
}

void MainWindow::on_btn6_clicked()
{
    turn="X";
    if(canFillBoard(ui->btn6))
    {
        ui->btn6->setText(turn);
        if(checkWin())
        {
            endGame();
            return;
        }
        cpuTurn();
    }
}

void MainWindow::on_btn7_clicked()
{
    turn="X";
    if(canFillBoard(ui->btn7))
    {
        ui->btn7->setText(turn);
        if(checkWin())
        {
            endGame();
            return;
        }
        cpuTurn();
    }
}

void MainWindow::on_btn8_clicked()
{
    turn="X";
    if(canFillBoard(ui->btn8))
    {
        ui->btn8->setText(turn);
        if(checkWin())
        {
            endGame();
            return;
        }
        cpuTurn();
    }
}

void MainWindow::on_btn9_clicked()
{
    turn="X";
    if(canFillBoard(ui->btn9))
    {
        ui->btn9->setText(turn);
        if(checkWin())
        {
            endGame();
            return;
        }
        cpuTurn();
    }
}
///
void MainWindow::endGame()
{
    if(winner=="X")
    {
        QMessageBox::information(this,tr("Game Over"),tr("You win.     <br>Good Work"));
        playerWins++;
    }
    else if(winner=="O")
    {
        QMessageBox::information(this,tr("Game Over"),tr("You lose.    <br>Try more."));
        cpuWins++;
    }
    else
    {
        QMessageBox::information(this,tr("Game Over"),tr("No winner."));
        noWinner++;
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

    ui->lbl_Score_1->setText(QString::number(cpuWins));
    ui->lbl_Score_2->setText(QString::number(playerWins));
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
                             ,tr("Tic Tac Toe Game<br>Version 0.1"));
}

void MainWindow::showProgrammer()
{
    QMessageBox::information(this,tr("About Programmer")
                             ,tr("This program written by:<br>"
                             "Ali Reza Pazhouhesh<br>"
                             "By Qt Version 4.7<br>"
                             "<font color=red>Special thanks to:<br>"
                             "Mehdi Akbari"));
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

    int maxWins=cpuWins;
    if(playerWins>maxWins)
        maxWins=playerWins;
    else if(noWinner>maxWins)
        maxWins=noWinner;

    cpuProgressBar->setValue(cpuWins);
    cpuProgressBar->setFormat("%v");
    cpuProgressBar->setMaximum(maxWins);
    playerProgressBar->setValue(playerWins);
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
    QRadioButton *cpuRadio=new QRadioButton(tr("CPU"));
    QRadioButton *playerRadio=new QRadioButton(tr("Player"));
    QGroupBox *groupBox=new QGroupBox(tr("Start game with"));
    QVBoxLayout *verticalLayout =new QVBoxLayout;
    QHBoxLayout *horizonalLayout=new QHBoxLayout;
    QVBoxLayout *layout=new QVBoxLayout;
    QPushButton *okButton=new QPushButton(tr("&Ok"));
    QPushButton *cancelButton=new QPushButton(tr("&Cancel"));

    cpuRadio->setChecked(true);
    dlg->setModal(true);

    verticalLayout->addWidget(cpuRadio);
    verticalLayout->addWidget(playerRadio);
    groupBox->setLayout(verticalLayout);
    horizonalLayout->addStretch();
    horizonalLayout->addWidget(okButton);
    horizonalLayout->addWidget(cancelButton);
    layout->addWidget(groupBox);
    layout->addStretch();
    layout->addLayout(horizonalLayout);

    connect(cpuRadio,SIGNAL(toggled(bool)),this,SLOT(changeOptionsToO()));
    connect(playerRadio,SIGNAL(toggled(bool)),this,SLOT(changeOptionsToX()));
    connect(okButton,SIGNAL(clicked()),this,SLOT(clearBoard()));
    connect(okButton,SIGNAL(clicked()),dlg,SLOT(accept()));
    connect(cancelButton,SIGNAL(clicked()),dlg,SLOT(reject()));

    dlg->setLayout(layout);
    dlg->show();
}

void MainWindow::changeOptionsToO()
{
    turn="O";
}

void MainWindow::changeOptionsToX()
{
    turn="X";
}
