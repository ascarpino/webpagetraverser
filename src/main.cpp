// our headers
#include "pagetraverser.h"

// Qt headers
#include <QApplication>
#include <QtCore/QByteArray>
#include <QtCore/QFile>
#include <QtCore/QString>
#include <QtCore/QTextStream>

// QJson headers
#include <qjson/serializer.h>

void usage();

QString appPath;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    appPath = a.arguments().first();

    QString url, fileName;
    bool json = false;

    if (a.arguments().size() > 1) {
        QTextStream qout(stdout);

        foreach(QString arg, a.arguments()) {
            if (arg == "-u") {
                url = a.arguments().at(a.arguments().indexOf(arg) + 1);
                continue;
            }

            if (arg == "-f") {
                fileName = a.arguments().at(a.arguments().indexOf(arg) + 1);
                continue;
            }

            if (arg == "-j") {
                json = true;
                continue;
            }

            if (arg == "-h") {
                usage();
                exit(0);
                continue;
            }
        }

        PageTraverser* traverser = new PageTraverser();
        WebElement* root = traverser->traverse(url);

        QByteArray serialized;
        if (json) {
            QJson::Serializer serializer;
            serialized = serializer.serialize(root->toQVariant());
        }

        if (!fileName.isEmpty()) {
            QFile out(fileName);

            if (out.open(QIODevice::WriteOnly)) {
                if (json)
                    out.write(serialized);
                else
                    out.write(serialized);
                out.close();
            }

            qout << fileName << " written.\n";
            qout.flush();
        } else {
            if (json)
                qout << serialized;
            else
                qout << root->toString();
            qout.flush();
        }

        a.quit();
    } else {
        usage();
        exit(0);
    }

    return 0;
}

void usage()
{
    QTextStream qout(stdout);
    qout << "Usage: " << appPath << " -u <url> [-f <filename>] [-j]\n";
    qout << "\n";
    qout << "Options:\n";
    qout << "  -u        the webpage url\n";
    qout << "  -f        redirect the output to a file\n";
    qout << "  -j        use the Json format\n";
    qout.flush();
}
