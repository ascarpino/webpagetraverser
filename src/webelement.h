#ifndef WEBELEMENT_H
#define WEBELEMENT_H

#include <QtCore/QHash>
#include <QtCore/QList>
#include <QtCore/QObject>
#include <QtCore/QString>

struct Position {
    qint16 m_top;
    qint16 m_left;
    qint16 m_right;
    qint16 m_bottom;
};

struct Size {
    qint16 m_height;
    qint16 m_width;
};

class WebElement : public QObject
{
    Q_OBJECT
public:
    explicit WebElement(QString parentPath, QString tagName, Position &position, Size &size,
                        QHash<QString, QString> &attributes, QObject *parent = 0);
    virtual ~WebElement();
    QList<WebElement *> *getChildren();
    QString toString();

private:
    QString m_parentPath;
    QString m_tagname;
    Position m_position;
    Size m_size;
    QHash<QString, QString> m_attributes;
    QList<WebElement *> m_children;   
};

#endif // WEBELEMENT_H
