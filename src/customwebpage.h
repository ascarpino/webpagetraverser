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

#ifndef CUSTOMWEBPAGE_H
#define CUSTOMWEBPAGE_H

#include <QWebPage>

class CustomWebPage : public QWebPage
{
    Q_OBJECT
public:
    explicit CustomWebPage(QObject *parent = 0);

    virtual QString userAgentForUrl(const QUrl &url) const;
};

#endif // CUSTOMWEBPAGE_H
