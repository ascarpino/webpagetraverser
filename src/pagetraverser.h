/*
 *   This file is part of WebPageTraverser.
 *
 *   Copyright 2012-2014 Andrea Scarpino <me@andreascarpino.it>
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

#ifndef PAGETRAVERSER_H
#define PAGETRAVERSER_H

#include "customwebpage.h"
#include "webelement.h"

#include <QEventLoop>
#include <QWebElement>

class PageTraverser : public QObject
{
    Q_OBJECT
public:
    explicit PageTraverser(QObject *parent = 0);
    virtual ~PageTraverser();
    WebElement* traverse(const QString &url);

private:
    CustomWebPage page;
    QEventLoop loop;
    WebElement* root;

    WebElement* populateTree(const QString &parentPath, const QString &parentDomCSSPath,
                             const QString &parentCSSPath, const QWebElement &element);

Q_SIGNALS:
    void fetched();

public Q_SLOTS:
    void extractElements(const bool ok);
    void httpResponse(QNetworkReply *reply);
};

#endif // PAGETRAVERSER_H
