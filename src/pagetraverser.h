#ifndef PAGETRAVERSER_H
#define PAGETRAVERSER_H

// our headers
#include "webelement.h"

// Qt headers
#include <QtCore/QEventLoop>
#include <QtCore/QObject>
#include <QtWebKit/QWebElement>
#include <QtWebKit/QWebPage>

class PageTraverser : public QObject
{
    Q_OBJECT
public:
    explicit PageTraverser(QObject *parent = 0);
    virtual ~PageTraverser();
    WebElement* traverse(const QString &url);

private:
    QWebPage *page;
    QEventLoop *loop;
    WebElement *root;

    WebElement* populateTree(const QString parentPath, const QWebElement &e);
    
signals:
    void fetched();

public slots:
    void extractElements();    
};

#endif // PAGETRAVERSER_H
