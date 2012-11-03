/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QRadioButton *p2cRadio;
    QRadioButton *p2pRadio;
    QRadioButton *c2cRadio;
    QGroupBox *groupBox;
    QRadioButton *playerORadio;
    QRadioButton *playerXRadio;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QString::fromUtf8("Options"));
        Options->resize(359, 196);
        Options->setMinimumSize(QSize(359, 196));
        gridLayout = new QGridLayout(Options);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox_2 = new QGroupBox(Options);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        p2cRadio = new QRadioButton(groupBox_2);
        p2cRadio->setObjectName(QString::fromUtf8("p2cRadio"));
        p2cRadio->setGeometry(QRect(30, 30, 125, 26));
        p2pRadio = new QRadioButton(groupBox_2);
        p2pRadio->setObjectName(QString::fromUtf8("p2pRadio"));
        p2pRadio->setGeometry(QRect(30, 60, 135, 26));
        c2cRadio = new QRadioButton(groupBox_2);
        c2cRadio->setObjectName(QString::fromUtf8("c2cRadio"));
        c2cRadio->setGeometry(QRect(30, 90, 112, 26));

        horizontalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(Options);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        playerORadio = new QRadioButton(groupBox);
        playerORadio->setObjectName(QString::fromUtf8("playerORadio"));
        playerORadio->setGeometry(QRect(30, 30, 112, 26));
        playerXRadio = new QRadioButton(groupBox);
        playerXRadio->setObjectName(QString::fromUtf8("playerXRadio"));
        playerXRadio->setGeometry(QRect(30, 60, 112, 26));

        horizontalLayout->addWidget(groupBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(151, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Options);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 1);


        retranslateUi(Options);

        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QDialog *Options)
    {
        Options->setWindowTitle(QApplication::translate("Options", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Options", "Set Mode", 0, QApplication::UnicodeUTF8));
        p2cRadio->setText(QApplication::translate("Options", "Player VS CPU", 0, QApplication::UnicodeUTF8));
        p2pRadio->setText(QApplication::translate("Options", "Player VS Player", 0, QApplication::UnicodeUTF8));
        c2cRadio->setText(QApplication::translate("Options", "CPU VS CPU", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Options", "Set turn", 0, QApplication::UnicodeUTF8));
        playerORadio->setText(QApplication::translate("Options", "CPU", 0, QApplication::UnicodeUTF8));
        playerXRadio->setText(QApplication::translate("Options", "Player", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
