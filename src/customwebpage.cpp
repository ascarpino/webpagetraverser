/*
 *   This file is part of WebPageTraverser.
 *
 *   Copyright 2014 Andrea Scarpino <me@andreascarpino.it>
 *
 *   WebPageTraverser is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   WebPageTraverser is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public License
 *   along with WebPageTraverser.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "customwebpage.h"

CustomWebPage::CustomWebPage(QObject *parent) :
    QWebPage(parent)
{
}

QString CustomWebPage::userAgentForUrl(const QUrl &url) const
{
    Q_UNUSED(url);

    // Some website blacklist default Qt's User-Agent, set a fake one
    return QStringLiteral("Mozilla/5.0 (X11; Linux x86_64) Gecko/20100101 Firefox/30.0");
}
