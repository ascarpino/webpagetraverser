/*
 *   This file is part of WebPageTraverser.
 *
 *   Copyright 2012-2013 Andrea Scarpino <me@andreascarpino.it>
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

// our headers
#include "pagetraverser.h"

// Qt headers
#include <QTextCodec>
#include <QUrl>
#include <QWebFrame>

PageTraverser::PageTraverser(QObject *parent) :
    QObject(parent),
    page(new QWebPage()),
    loop(new QEventLoop())
{
    connect(&page, SIGNAL(loadFinished(bool)), this, SLOT(extractElements()));
    connect(this, SIGNAL(fetched()), &loop, SLOT(quit()));
}

PageTraverser::~PageTraverser()
{
    delete root;
}

WebElement* PageTraverser::traverse(const QString &url)
{
    //load the page
    QWebFrame *frame = page.mainFrame();
    frame->load(QUrl(url));

    //loop until the fetched signal is emitted
    loop.exec();

    return root;
}

void PageTraverser::extractElements()
{
//     QTextStream qout(stdout);
//     qout << "Loaded webpage: " << page->mainFrame()->url().toString() << "\n";
//     qout.flush();

    QWebFrame *frame = page.mainFrame();
    const QWebElement doc(frame->documentElement());
    const QWebElement head(doc.firstChild());
    const QWebElement body(head.nextSibling());

    root = populateTree("html", body);

    // we've done here
    emit fetched();
}

WebElement* PageTraverser::populateTree(const QString &parentPath, const QWebElement &element)
{
    //position
    Position position;
    position.top = element.geometry().top();
    position.left = element.geometry().left();
    position.right = element.geometry().right();
    position.bottom = element.geometry().bottom();

    //size
    Size size;
    size.height = element.geometry().height();
    size.width = element.geometry().width();

    //attributes
    QHash<QString, QString> attributes;
    Q_FOREACH (const QString attr, element.attributeNames()) {
        attributes.insert(attr, element.attribute(attr));
    }

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    const QString nodeTag(element.tagName().toLower());
    //create the web Element
    WebElement *node = new WebElement(parentPath, nodeTag, position, size,
                                      attributes, element.toPlainText().trimmed());

    //for each child
    //lista dei figli add populateTree(figlio);
    for (QWebElement elem = element.firstChild(); !elem.isNull(); elem = elem.nextSibling()) {
        node->getChildren()->append(populateTree(parentPath + "/" + nodeTag, elem));
    }

    return node;
}
