#include "pagetraverser.h"

PageTraverser::PageTraverser(QObject *parent) :
    QObject(parent)
{
    page = new QWebPage();
    loop = new QEventLoop();

    connect(page, SIGNAL(loadFinished(bool)), this, SLOT(extractElements()));
    connect(this, SIGNAL(fetched()), loop, SLOT(quit()));
}

 WebElement* PageTraverser::traverse(const QString &url)
 {
    //load the page
    QWebFrame *frame = page->mainFrame();
    frame->load(QUrl(url));

    //wait for page loaded signal
    loop->exec();

     //return the root WebElement
 }

 void PageTraverser::extractElements()
 {
     QTextStream qout(stdout);
     qout << "Loaded webpage: " << page->mainFrame()->url().toString() << "\n";
     qout.flush();

     QWebFrame *frame = page->mainFrame();
     QWebElement doc = frame->documentElement();
     QWebElement head = doc.firstChild();
     QWebElement body = head.nextSibling();

     root =  populateTree(body);

     emit fetched();
 }

 WebElement* PageTraverser::populateTree(const QWebElement &e)
 {
    //visita nodo



     //per ogni figlio
     //lista dei figli add populateTree(figlio);
 }











