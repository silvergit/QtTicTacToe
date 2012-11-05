/*******************************************************************************
 * QtTicTacToe Version 1.4.1                                                   *
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

#include "options.h"
#include "ui_options.h"

Options::Options(QWidget *parent) :
    QDialog(parent),ui(new Ui::Options)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(reject()));
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(accept()));
    connect(ui->p2cRadio,SIGNAL(toggled(bool)),this,SLOT(changeTitles(bool)));

    showDialog();
}

Options::~Options()
{
    delete ui;
}

void Options::showDialog()
{
    this->setModal(true);

    ui->playerORadio->setChecked(true);
    ui->p2cRadio->setChecked(true);

    this->show();
}

void Options::setChanges()
{
    if(ui->playerORadio->isChecked())
        turn="O";
    else //if palyerXRadio is checked
        turn="X";

    if(ui->p2pRadio->isChecked())
        mode="P2P";
    else if (ui->p2cRadio->isChecked())
        mode="P2C";
    else //if c2c radio is checked
        mode="C2C";

    setMode(mode);
    setTurn(turn);
}

void Options::changeTitles(bool state)
{
    if(state){
        ui->playerORadio->setText("CPU");
        ui->playerXRadio->setText("Player");
    } else {
        ui->playerORadio->setText("Player O");
        ui->playerXRadio->setText("Player X");
    }
}

void Options::on_c2cRadio_toggled(bool checked)
{
    if(checked){
        ui->playerORadio->hide();
        ui->playerXRadio->hide();
    }
    else{
        ui->playerORadio->show();
        ui->playerXRadio->show();
    }
}
