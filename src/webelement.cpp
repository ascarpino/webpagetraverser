/*
 *   This file is part of WebPageTraverser.
 * 
 *   Copyright 2012-2013 Andrea Scarpino <andrea@archlinux.org>
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

// our headers
#include "webelement.h"

// Qt headers
#include <QStringList>
#include <QVariantMap>

qint32 WebElement::next_id = 0;

WebElement::WebElement(QString parentPath, QString nodeTag, Position &position,
                       Size &size, QHash<QString, QString> &attributes,
                       QString text, QObject *parent)
    : QObject(parent)
    , m_parentPath(parentPath)
    , m_nodetag(nodeTag)
    , m_position(position)
    , m_size(size)
    , m_attributes(attributes)
    , m_text(text)
{
    id = WebElement::next_id++;
}

WebElement::~WebElement()
{
    delete &m_parentPath;
    delete &m_nodetag;
    delete &m_position;
    delete &m_size;
    delete &m_attributes;
    delete &m_children;
    delete &m_text;
}

QList<WebElement *>* WebElement::getChildren()
{
    return &m_children;
}

QString WebElement::toString()
{
    QString str;

    str.append("Id: " + QString::number(this->id) + " Parent Path: " + this->m_parentPath + " Node Tag: " + this->m_nodetag + "\n");
    str.append(" Position: " + QString::number(this->m_position.top) + " " +
               QString::number(this->m_position.left) + " " +
               QString::number(this->m_position.right) + " " +
               QString::number(this->m_position.bottom) + "\n");
    str.append(" Size: " + QString::number(this->m_size.height) + " " + QString::number(this->m_size.width) + "\n");

    if (!this->m_attributes.isEmpty()) {
        str.append(" Attributes: ");
        foreach (QString attr, this->m_attributes.keys()) {
            str.append(" " + attr + " = \"" + this->m_attributes.value(attr) + "\"");
        }
    }

    if (!this->m_children.isEmpty()) {
        str.append("\tInnerList: (size: " + QString::number(this->m_children.count()) + ")\n");
        foreach (WebElement *element, this->m_children) {
                str.append("\t" + element->toString() + "\n");
        }
    }

    return str;
}

QVariantMap WebElement::toQVariant()
{
    QVariantMap map;

    map.insert("id", this->id);
    map.insert("parentPath", this->m_parentPath);
    map.insert("nodeTag", this->m_nodetag);

    QVariantMap position;
    position.insert("top", this->m_position.top);
    position.insert("left", this->m_position.left);
    position.insert("right", this->m_position.right);
    position.insert("bottom", this->m_position.bottom);
    map.insert("position", position);

    QVariantMap size;
    size.insert("height", this->m_size.height);
    size.insert("width", this->m_size.width);
    map.insert("size", size);

    if (!this->m_attributes.isEmpty()) {
        QVariantMap attributes;
        foreach (QString attr, this->m_attributes.keys()) {
            attributes.insert(attr, this->m_attributes.value(attr));
        }
        map.insert("attributes", attributes);
    }

    if (!this->m_children.isEmpty()) {
        QVariantList children;
        foreach (WebElement *element, this->m_children) {
            children.append(element->toQVariant());
        }
        map.insert("children", children);
    }

    map.insert("text", this->m_text);

    return map;
}
