#include <QApplication>
#include <QtCore/QString>
#include <QtCore/QTextStream>
#include "pagetraverser.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    PageTraverser* traverser = new PageTraverser();

    WebElement* root = traverser->traverse(QString("http://bari.repubblica.it"));

    QTextStream qout(stdout);
    qout << root->toString();
    qout.flush();

    return a.exec();
}
