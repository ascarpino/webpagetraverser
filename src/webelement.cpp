#include "webelement.h"

#include <QtCore/QStringList>

WebElement::WebElement(QString parentPath, QString tagName, Position &position, Size &size, QHash<QString, QString> &attributes, QObject *parent)
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
    str.append("Parent Path: " + this->m_parentPath + "\n");
    str.append("Tagname: " + this->m_tagname + "\n");
    str.append("\t\tTop: " + QString::number(this->m_position.m_top) + "\n");
    str.append("\tLeft: " + QString::number(this->m_position.m_left) + "\tRight: "
               + QString::number(this->m_position.m_right) + "\n");
    str.append("\t\tBottom: " + QString::number(this->m_position.m_bottom) + "\n");
    str.append("\tHeight: " + QString::number(this->m_size.m_height) + "\n");
    str.append("\tWidth: " + QString::number(this->m_size.m_width) + "\n");

    if (!this->m_attributes.isEmpty()) {
        str.append("\tAttributes:\n");
        foreach (QString attr, this->m_attributes.keys()) {
            str.append("\t\t" + attr + " = \"" + this->m_attributes.value(attr) + "\"\n");
        }
    }

    if (!this->m_children.isEmpty()) {
        str.append("\tInnerList: (" + QString::number(this->m_children.count()) + ")\n");
        foreach (WebElement *element, this->m_children) {
            QStringList lines = element->toString().split("\n");
            foreach (QString line, lines) {
                str.append("\t\t" + line + "\n");
            }
        }
    }

    return str;
}
