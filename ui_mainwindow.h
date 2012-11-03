/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: 
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New_Game;
    QAction *action_Options;
    QAction *actionE_xit;
    QAction *action_Statistics;
    QAction *actionStatus_Bar;
    QAction *action_About;
    QAction *action_Programmer;
    QAction *action_About_Qt;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *lbl_player_1;
    QLabel *lbl_Score_1;
    QLabel *lbl_player_2;
    QLabel *lbl_Score_2;
    QLabel *lbl_player_3;
    QLabel *lbl_Score_3;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnNewGame;
    QPushButton *btnExit;
    QMenuBar *menuBar;
    QMenu *menu_Game;
    QMenu *menu_View;
    QMenu *menu_Help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(414, 328);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Pictures/tictactoe.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_New_Game = new QAction(MainWindow);
        action_New_Game->setObjectName(QString::fromUtf8("action_New_Game"));
        action_Options = new QAction(MainWindow);
        action_Options->setObjectName(QString::fromUtf8("action_Options"));
        actionE_xit = new QAction(MainWindow);
        actionE_xit->setObjectName(QString::fromUtf8("actionE_xit"));
        action_Statistics = new QAction(MainWindow);
        action_Statistics->setObjectName(QString::fromUtf8("action_Statistics"));
        actionStatus_Bar = new QAction(MainWindow);
        actionStatus_Bar->setObjectName(QString::fromUtf8("actionStatus_Bar"));
        actionStatus_Bar->setCheckable(true);
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QString::fromUtf8("action_About"));
        action_Programmer = new QAction(MainWindow);
        action_Programmer->setObjectName(QString::fromUtf8("action_Programmer"));
        action_About_Qt = new QAction(MainWindow);
        action_About_Qt->setObjectName(QString::fromUtf8("action_About_Qt"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn1 = new QPushButton(centralWidget);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setMinimumSize(QSize(61, 61));
        btn1->setMaximumSize(QSize(61, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(48);
        btn1->setFont(font);
        btn1->setLayoutDirection(Qt::LeftToRight);
        btn1->setCheckable(false);
        btn1->setChecked(false);
        btn1->setAutoRepeat(false);
        btn1->setAutoExclusive(false);
        btn1->setAutoDefault(false);
        btn1->setDefault(false);
        btn1->setFlat(false);

        gridLayout->addWidget(btn1, 0, 0, 1, 1);

        btn2 = new QPushButton(centralWidget);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setMinimumSize(QSize(61, 61));
        btn2->setMaximumSize(QSize(61, 61));
        btn2->setFont(font);
        btn2->setLayoutDirection(Qt::LeftToRight);
        btn2->setCheckable(false);
        btn2->setChecked(false);
        btn2->setAutoRepeat(false);
        btn2->setAutoExclusive(false);
        btn2->setAutoDefault(false);
        btn2->setDefault(false);
        btn2->setFlat(false);

        gridLayout->addWidget(btn2, 0, 1, 1, 1);

        btn3 = new QPushButton(centralWidget);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        btn3->setMinimumSize(QSize(61, 61));
        btn3->setMaximumSize(QSize(61, 61));
        btn3->setFont(font);
        btn3->setMouseTracking(false);
        btn3->setAcceptDrops(false);
        btn3->setLayoutDirection(Qt::LeftToRight);
        btn3->setAutoFillBackground(true);
        btn3->setStyleSheet(QString::fromUtf8(""));
        btn3->setCheckable(false);
        btn3->setChecked(false);
        btn3->setAutoRepeat(false);
        btn3->setAutoExclusive(false);
        btn3->setAutoDefault(false);
        btn3->setDefault(false);
        btn3->setFlat(false);

        gridLayout->addWidget(btn3, 0, 2, 1, 1);

        btn4 = new QPushButton(centralWidget);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        btn4->setMinimumSize(QSize(61, 61));
        btn4->setMaximumSize(QSize(61, 61));
        btn4->setFont(font);
        btn4->setLayoutDirection(Qt::LeftToRight);
        btn4->setCheckable(false);
        btn4->setChecked(false);
        btn4->setAutoRepeat(false);
        btn4->setAutoExclusive(false);
        btn4->setAutoDefault(false);
        btn4->setDefault(false);
        btn4->setFlat(false);

        gridLayout->addWidget(btn4, 1, 0, 1, 1);

        btn5 = new QPushButton(centralWidget);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        btn5->setMinimumSize(QSize(61, 61));
        btn5->setMaximumSize(QSize(61, 61));
        btn5->setFont(font);
        btn5->setLayoutDirection(Qt::LeftToRight);
        btn5->setCheckable(false);
        btn5->setChecked(false);
        btn5->setAutoRepeat(false);
        btn5->setAutoExclusive(false);
        btn5->setAutoDefault(false);
        btn5->setDefault(false);
        btn5->setFlat(false);

        gridLayout->addWidget(btn5, 1, 1, 1, 1);

        btn6 = new QPushButton(centralWidget);
        btn6->setObjectName(QString::fromUtf8("btn6"));
        btn6->setMinimumSize(QSize(61, 61));
        btn6->setMaximumSize(QSize(61, 61));
        btn6->setFont(font);
        btn6->setLayoutDirection(Qt::LeftToRight);
        btn6->setCheckable(false);
        btn6->setChecked(false);
        btn6->setAutoRepeat(false);
        btn6->setAutoExclusive(false);
        btn6->setAutoDefault(false);
        btn6->setDefault(false);
        btn6->setFlat(false);

        gridLayout->addWidget(btn6, 1, 2, 1, 1);

        btn7 = new QPushButton(centralWidget);
        btn7->setObjectName(QString::fromUtf8("btn7"));
        btn7->setMinimumSize(QSize(61, 61));
        btn7->setMaximumSize(QSize(61, 61));
        btn7->setFont(font);
        btn7->setLayoutDirection(Qt::LeftToRight);
        btn7->setCheckable(false);
        btn7->setChecked(false);
        btn7->setAutoRepeat(false);
        btn7->setAutoExclusive(false);
        btn7->setAutoDefault(false);
        btn7->setDefault(false);
        btn7->setFlat(false);

        gridLayout->addWidget(btn7, 2, 0, 1, 1);

        btn8 = new QPushButton(centralWidget);
        btn8->setObjectName(QString::fromUtf8("btn8"));
        btn8->setMinimumSize(QSize(61, 61));
        btn8->setMaximumSize(QSize(61, 61));
        btn8->setFont(font);
        btn8->setLayoutDirection(Qt::LeftToRight);
        btn8->setCheckable(false);
        btn8->setChecked(false);
        btn8->setAutoRepeat(false);
        btn8->setAutoExclusive(false);
        btn8->setAutoDefault(false);
        btn8->setDefault(false);
        btn8->setFlat(false);

        gridLayout->addWidget(btn8, 2, 1, 1, 1);

        btn9 = new QPushButton(centralWidget);
        btn9->setObjectName(QString::fromUtf8("btn9"));
        btn9->setMinimumSize(QSize(61, 61));
        btn9->setMaximumSize(QSize(61, 61));
        btn9->setFont(font);
        btn9->setLayoutDirection(Qt::LeftToRight);
        btn9->setCheckable(false);
        btn9->setChecked(false);
        btn9->setAutoRepeat(false);
        btn9->setAutoExclusive(false);
        btn9->setAutoDefault(false);
        btn9->setDefault(false);
        btn9->setFlat(false);

        gridLayout->addWidget(btn9, 2, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(50, 194, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 1, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(131, 181));
        groupBox->setFlat(false);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lbl_player_1 = new QLabel(groupBox);
        lbl_player_1->setObjectName(QString::fromUtf8("lbl_player_1"));

        gridLayout_2->addWidget(lbl_player_1, 0, 0, 1, 1);

        lbl_Score_1 = new QLabel(groupBox);
        lbl_Score_1->setObjectName(QString::fromUtf8("lbl_Score_1"));

        gridLayout_2->addWidget(lbl_Score_1, 0, 1, 1, 1);

        lbl_player_2 = new QLabel(groupBox);
        lbl_player_2->setObjectName(QString::fromUtf8("lbl_player_2"));

        gridLayout_2->addWidget(lbl_player_2, 1, 0, 1, 1);

        lbl_Score_2 = new QLabel(groupBox);
        lbl_Score_2->setObjectName(QString::fromUtf8("lbl_Score_2"));

        gridLayout_2->addWidget(lbl_Score_2, 1, 1, 1, 1);

        lbl_player_3 = new QLabel(groupBox);
        lbl_player_3->setObjectName(QString::fromUtf8("lbl_player_3"));

        gridLayout_2->addWidget(lbl_player_3, 2, 0, 1, 1);

        lbl_Score_3 = new QLabel(groupBox);
        lbl_Score_3->setObjectName(QString::fromUtf8("lbl_Score_3"));

        gridLayout_2->addWidget(lbl_Score_3, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        verticalSpacer = new QSpacerItem(390, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 1, 0, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnNewGame = new QPushButton(centralWidget);
        btnNewGame->setObjectName(QString::fromUtf8("btnNewGame"));

        horizontalLayout->addWidget(btnNewGame);

        btnExit = new QPushButton(centralWidget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        horizontalLayout->addWidget(btnExit);


        gridLayout_4->addLayout(horizontalLayout, 2, 0, 1, 4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 414, 29));
        menu_Game = new QMenu(menuBar);
        menu_Game->setObjectName(QString::fromUtf8("menu_Game"));
        menu_View = new QMenu(menuBar);
        menu_View->setObjectName(QString::fromUtf8("menu_View"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(btnNewGame, btnExit);
        QWidget::setTabOrder(btnExit, btn1);
        QWidget::setTabOrder(btn1, btn2);
        QWidget::setTabOrder(btn2, btn3);
        QWidget::setTabOrder(btn3, btn4);
        QWidget::setTabOrder(btn4, btn5);
        QWidget::setTabOrder(btn5, btn6);
        QWidget::setTabOrder(btn6, btn7);
        QWidget::setTabOrder(btn7, btn8);
        QWidget::setTabOrder(btn8, btn9);

        menuBar->addAction(menu_Game->menuAction());
        menuBar->addAction(menu_View->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_Game->addAction(action_New_Game);
        menu_Game->addAction(action_Options);
        menu_Game->addSeparator();
        menu_Game->addAction(actionE_xit);
        menu_View->addAction(action_Statistics);
        menu_View->addAction(actionStatus_Bar);
        menu_Help->addAction(action_About);
        menu_Help->addAction(action_Programmer);
        menu_Help->addSeparator();
        menu_Help->addAction(action_About_Qt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action_New_Game->setText(QApplication::translate("MainWindow", "&New Game...", 0, QApplication::UnicodeUTF8));
        action_Options->setText(QApplication::translate("MainWindow", "&Options...", 0, QApplication::UnicodeUTF8));
        actionE_xit->setText(QApplication::translate("MainWindow", "E&xit", 0, QApplication::UnicodeUTF8));
        action_Statistics->setText(QApplication::translate("MainWindow", "&Statistics...", 0, QApplication::UnicodeUTF8));
        actionStatus_Bar->setText(QApplication::translate("MainWindow", "Status&Bar", 0, QApplication::UnicodeUTF8));
        action_About->setText(QApplication::translate("MainWindow", "&About...", 0, QApplication::UnicodeUTF8));
        action_Programmer->setText(QApplication::translate("MainWindow", "&Programmer...", 0, QApplication::UnicodeUTF8));
        action_About_Qt->setText(QApplication::translate("MainWindow", "About &Qt...", 0, QApplication::UnicodeUTF8));
        btn1->setText(QApplication::translate("MainWindow", "T", 0, QApplication::UnicodeUTF8));
        btn2->setText(QApplication::translate("MainWindow", "I", 0, QApplication::UnicodeUTF8));
        btn3->setText(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        btn4->setText(QApplication::translate("MainWindow", "T", 0, QApplication::UnicodeUTF8));
        btn5->setText(QApplication::translate("MainWindow", "A", 0, QApplication::UnicodeUTF8));
        btn6->setText(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        btn7->setText(QApplication::translate("MainWindow", "T", 0, QApplication::UnicodeUTF8));
        btn8->setText(QApplication::translate("MainWindow", "O", 0, QApplication::UnicodeUTF8));
        btn9->setText(QApplication::translate("MainWindow", "E", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Statistics", 0, QApplication::UnicodeUTF8));
        lbl_player_1->setText(QApplication::translate("MainWindow", "CPU           ", 0, QApplication::UnicodeUTF8));
        lbl_Score_1->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        lbl_player_2->setText(QApplication::translate("MainWindow", "Player        ", 0, QApplication::UnicodeUTF8));
        lbl_Score_2->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        lbl_player_3->setText(QApplication::translate("MainWindow", "No wins", 0, QApplication::UnicodeUTF8));
        lbl_Score_3->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        btnNewGame->setText(QApplication::translate("MainWindow", "&New Game", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("MainWindow", "E&xit", 0, QApplication::UnicodeUTF8));
        menu_Game->setTitle(QApplication::translate("MainWindow", "&Game", 0, QApplication::UnicodeUTF8));
        menu_View->setTitle(QApplication::translate("MainWindow", "&View", 0, QApplication::UnicodeUTF8));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
