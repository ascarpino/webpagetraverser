/*
 *   This file is part of WebPageTraverser.
 * 
 *   Copyright 2012-2013 Andrea Scarpino <andrea@archlinux.org>
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
 *   You should have received a copy of the GNU General Public License
 *   along with WebPageTraverser.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PAGETRAVERSER_H
#define PAGETRAVERSER_H

// our headers
#include "webelement.h"

// Qt headers
#include <QEventLoop>
#include <QObject>
#include <QWebElement>
#include <QWebPage>

class PageTraverser : public QObject
{
    Q_OBJECT
public:
    explicit PageTraverser(QObject *parent = 0);
    virtual ~PageTraverser();
    WebElement* traverse(const QString &url);

private:
    QWebPage *page;
    QEventLoop *loop;
    WebElement *root;

    WebElement* populateTree(const QString parentPath, const QWebElement &e);
    
signals:
    void fetched();

public slots:
    void extractElements();    
};

#endif // PAGETRAVERSER_H
