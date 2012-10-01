#include "webelement.h"

#include <QtCore/QStringList>

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
    str.append(" Position: " + QString::number(this->m_position.m_top) + " " +
               QString::number(this->m_position.m_left) + " " +
               QString::number(this->m_position.m_right) + " " +
               QString::number(this->m_position.m_bottom) + "\n");
    str.append(" Size: " + QString::number(this->m_size.m_height) + " " + QString::number(this->m_size.m_width) + "\n");

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
