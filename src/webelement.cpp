/*
 *   This file is part of WebPageTraverser.
 *
 *   Copyright 2012-2014 Andrea Scarpino <me@andreascarpino.it>
 *   Copyright 2012-2014 Fabio Fumarola <fabiofumarola@gmail.com>
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
#include "webelement.h"

// Qt headers
#include <QVariantMap>

qint32 WebElement::next_id = 0;

WebElement::WebElement(const QString &parentPath, const QString &parentCSSPath, const QString &nodeTag,
                       const Position &position, const Size &size,
                       const QHash<QString, QString> attributes,
                       const QString &text, QObject *parent)
    : QObject(parent)
    , m_parentPath(parentPath)
    , m_parentCSSPath(parentCSSPath)
    , m_nodetag(nodeTag)
    , m_position(position)
    , m_size(size)
    , m_attributes(attributes)
    , m_text(text)
{
    webPageTraverserId = WebElement::next_id++;
}

WebElement::~WebElement()
{
}

QList<WebElement *>* WebElement::getChildren()
{
    return &m_children;
}

QString WebElement::toString()
{
    QString str;

    str.append("webPageTraverserId: " + QString::number(webPageTraverserId) +
               " Parent Path: " + m_parentPath +
               " Parent CSS Path: " + m_parentCSSPath +
               " Node Tag: " + m_nodetag + "\n");
    str.append(" Position: " + QString::number(m_position.top) + " " +
               QString::number(m_position.left) + " " +
               QString::number(m_position.right) + " " +
               QString::number(m_position.bottom) + "\n");
    str.append(" Size: " + QString::number(m_size.height) + " " + QString::number(m_size.width) + "\n");

    if (!m_attributes.isEmpty()) {
        str.append(" Attributes: ");
        Q_FOREACH (const QString &attr, m_attributes.keys()) {
            str.append(" " + attr + " = \"" + m_attributes.value(attr) + "\"");
        }
    }

    if (!m_children.isEmpty()) {
        str.append("\tInnerList: (size: " + QString::number(m_children.count()) + ")\n");
        Q_FOREACH (WebElement *element, m_children) {
            str.append("\t" + element->toString() + "\n");
        }
    }

    return str;
}

QVariantMap WebElement::toQVariant()
{
    QVariantMap map;
    map.insert("webPageTraverserId", webPageTraverserId);
    map.insert("parentPath", m_parentPath);
    map.insert("parentCSSPath", m_parentCSSPath);
    map.insert("nodeTag", m_nodetag);

    QVariantMap position;
    position.insert("top", m_position.top);
    position.insert("left", m_position.left);
    position.insert("right", m_position.right);
    position.insert("bottom", m_position.bottom);
    map.insert("position", position);

    QVariantMap size;
    size.insert("height", m_size.height);
    size.insert("width", m_size.width);
    map.insert("size", size);

    if (!m_attributes.isEmpty()) {
        QVariantMap attributes;
        Q_FOREACH (const QString &attr, m_attributes.keys()) {
            attributes.insert(attr, m_attributes.value(attr));
        }
        map.insert("attributes", attributes);
    }

    if (!m_children.isEmpty()) {
        QVariantList children;
        Q_FOREACH (WebElement *element, m_children) {
            children.append(element->toQVariant());
        }
        map.insert("children", children);
    }

    map.insert("text", m_text);

    return map;
}
