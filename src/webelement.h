/*
 *   This file is part of WebPageTraverser.
 * 
 *   Copyright 2012-2013 Andrea Scarpino <me@andreascarpino.it>
 *   Copyright 2012-2013 Fabio Fumarola <fabiofumarola@gmail.com>
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

#ifndef WEBELEMENT_H
#define WEBELEMENT_H

// Qt headers
#include <QHash>
#include <QList>
#include <QVariant>

struct Position {
    qint16 top;
    qint16 left;
    qint16 right;
    qint16 bottom;
};

struct Size {
    qint16 height;
    qint16 width;
};

class WebElement : public QObject
{
    Q_OBJECT

public:
    explicit WebElement(const QString &parentPath, const QString &tagName,
                        const Position &position, const Size &size,
                        const QHash<QString, QString> attributes,
                        const QString &text, QObject *parent = 0);
    virtual ~WebElement();
    QList<WebElement *>* getChildren();
    QString toString();
    QVariantMap toQVariant();

private:
    QString m_parentPath;
    QString m_nodetag;
    Position m_position;
    Size m_size;
    QHash<QString, QString> m_attributes;
    QList<WebElement *> m_children;
    QString m_text;
    qint32 webPageTraverserId;
    static qint32 next_id;
};
#endif // WEBELEMENT_H
