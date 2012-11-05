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

#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>

namespace Ui{
    class Options;
}

class QRadioButton;
class QGroupBox;
class QVBoxLayout;
class QHBoxLayout;
class QPushButton;

class Options : public QDialog
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = 0);
    ~Options();

private:
    Ui::Options *ui;
    QString turn;
    QString mode;
    void showDialog();

private slots:
    void setChanges();
    void changeTitles(bool state);
    void on_c2cRadio_toggled(bool checked);

signals:
    void setTurn(QString s);
    void setMode(QString s);
};

#endif // OPTIONS_H
