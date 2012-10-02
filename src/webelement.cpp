// our headers
#include "webelement.h"

// Qt headers
#include <QtCore/QStringList>
#include <QtCore/QVariantMap>

WebElement::WebElement(QString parentPath, QString tagName, Position &position,
                       Size &size, QHash<QString, QString> &attributes,
                       QObject *parent)
    : QObject(parent)
    , m_parentPath(parentPath)
    , m_tagname(tagName)
    , m_position(position)
    , m_size(size)
    , m_attributes(attributes)
{
}

WebElement::~WebElement()
{
    delete &m_parentPath;
    delete &m_tagname;
    delete &m_position;
    delete &m_size;
    delete &m_attributes;
    delete &m_children;
}

QList<WebElement *>* WebElement::getChildren()
{
    return &m_children;
}

QString WebElement::toString()
{
    QString str;

    str.append("Parent Path: " + this->m_parentPath + " Node Tag: " + this->m_tagname + "\n");
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

QVariantList WebElement::toQVariant()
{
    QVariantList qvariant;
    QVariantMap map;

    map.insert("ParentPath", this->m_parentPath);
    map.insert("NodeTag", this->m_tagname);

    QVariantList position;
    QVariantMap pos_map;
    pos_map.insert("top", this->m_position.top);
    pos_map.insert("left", this->m_position.left);
    pos_map.insert("right", this->m_position.right);
    pos_map.insert("bottom", this->m_position.bottom);
    position.append(pos_map);
    map.insert("Position", position);

    QVariantList size;
    QVariantMap size_map;
    size_map.insert("height", this->m_size.height);
    size_map.insert("width", this->m_size.width);
    size.append(size_map);
    map.insert("Size", size);

    if (!this->m_attributes.isEmpty()) {
        QVariantList attributes;
        QVariantMap attr_map;
        foreach (QString attr, this->m_attributes.keys()) {
            attr_map.insert(attr, this->m_attributes.value(attr));
        }
        attributes.append(attr_map);
        map.insert("Attributes", attributes);
    }

    if (!this->m_children.isEmpty()) {
        QVariantList children;
        foreach (WebElement *element, this->m_children) {
            children.append(element->toQVariant());
        }
        map.insert("Children", children);
    }

    qvariant.append(map);

    return qvariant;
}
