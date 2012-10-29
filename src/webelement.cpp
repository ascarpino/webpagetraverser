// our headers
#include "webelement.h"

// Qt headers
#include <QtCore/QStringList>
#include <QtCore/QVariantMap>

WebElement::WebElement(QString parentPath, QString nodeTag, Position &position,
                       Size &size, QHash<QString, QString> &attributes,
                       QObject *parent)
    : QObject(parent)
    , m_parentPath(parentPath)
    , m_nodetag(nodeTag)
    , m_position(position)
    , m_size(size)
    , m_attributes(attributes)
{
}

WebElement::~WebElement()
{
    delete &m_parentPath;
    delete &m_nodetag;
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

    str.append("Parent Path: " + this->m_parentPath + " Node Tag: " + this->m_nodetag + "\n");
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

    return map;
}
