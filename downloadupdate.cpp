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

#include "downloadupdate.h"
#include <QMessageBox>

DownloadUpdate::DownloadUpdate()
{
    m_manager = new QNetworkAccessManager(this);

    connect(m_manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
}

void DownloadUpdate::fetch()
{
    m_manager->get(QNetworkRequest(QUrl("https://raw.github.com/silvergit/QtTicTacToe/master/Version")));
}

void DownloadUpdate::replyFinished(QNetworkReply* pReply)
{
    QByteArray data=pReply->readAll();
    QString str(data);
    checkUpdateVersion(str);

}
