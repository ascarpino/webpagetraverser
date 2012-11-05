#ifndef WEBELEMENT_H
#define WEBELEMENT_H

// Qt headers
#include <QtCore/QHash>
#include <QtCore/QList>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QVariant>

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
    explicit WebElement(QString parentPath, QString tagName, Position &position, Size &size,
                        QHash<QString, QString> &attributes, QString text,
                        QObject *parent = 0);
    virtual ~WebElement();
    QList<WebElement *> *getChildren();
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
};

#endif // WEBELEMENT_H
