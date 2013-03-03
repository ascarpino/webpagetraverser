/*
 *   This file is part of WebPageTraverser.
 * 
 *   Copyright 2012-2013 Andrea Scarpino <andrea@archlinux.org>
 *
 *   WebPageTraverser is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   WebPageTraverser is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with WebPageTraverser.  If not, see <http://www.gnu.org/licenses/>.
 */

// our headers
#include "pagetraverser.h"

// Qt headers
#include <QApplication>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QString>
#include <QTextStream>

void usage();

QString appPath;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    appPath = a.arguments().first();

    QString url, fileName;
    double version = 1.00;
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
                a.quit();
            }

            if (arg == "-V") {
                qout << "Version: " << QString::number(version, 'f', 2) << "\n";
                qout.flush();
                a.quit();
            }
        }

        PageTraverser* traverser = new PageTraverser();
        WebElement* root = traverser->traverse(url);

        QByteArray serialized;
        if (json) {
           serialized = QJsonDocument::fromVariant(root->toQVariant()).toJson();
        }

        if (!fileName.isEmpty()) {
            QFile out(fileName);

            if (out.open(QIODevice::WriteOnly)) {
                if (json)
                    out.write(serialized);
                else
                    out.write(root->toString().toUtf8());
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
        a.exit(1);
    }
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
    qout << "  -V        print the version\n";
    qout.flush();
}
