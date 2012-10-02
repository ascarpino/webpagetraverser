// our headers
#include "pagetraverser.h"

// Qt headers
#include <QApplication>
#include <QtCore/QByteArray>
#include <QtCore/QString>
#include <QtCore/QTextStream>

#include <qjson/serializer.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    PageTraverser* traverser = new PageTraverser();

    WebElement* root = traverser->traverse(QString("http://bari.repubblica.it"));

//    QTextStream qout(stdout);
//    qout << root->toString();
//    qout.flush();

    QJson::Serializer serializer;
    QVariantList qvariant = root->toQVariant();
    const QByteArray serialized = serializer.serialize(qvariant);

    QTextStream qout(stdout);
    qout << serialized;
    qout.flush();

    return a.exec();
}
