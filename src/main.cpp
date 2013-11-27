/*
 *   This file is part of WebPageTraverser.
 *
 *   Copyright 2012-2013 Andrea Scarpino <me@andreascarpino.it>
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
 *   You should have received a copy of the GNU Lesser General Public License
 *   along with WebPageTraverser.  If not, see <http://www.gnu.org/licenses/>.
 */

// our headers
#include "webpagetraverser.h"
#include "pagetraverser.h"

// Qt headers
#include <QApplication>
#include <QByteArray>
#include <QJsonDocument>
#include <QDir>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>

void usage();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringList arguments = a.arguments();

    QString url, fileName;
    bool json = false;

    if (arguments.size() > 1) {
        QTextStream qout(stdout);

        Q_FOREACH (const QString arg, arguments.mid(1, arguments.size())) {
            if (arg == "-u") {
                int pos = arguments.indexOf(arg);

                // No file name have been specified
                if (pos != arguments.size() - 1) {
                    url = arguments.at(pos + 1);
                }
                continue;
            }

            if (arg == "-f") {
                int pos = arguments.indexOf(arg);

                // No file name have been specified
                if (pos != arguments.size() - 1) {
                    fileName = arguments.at(pos + 1);
                }
                continue;
            }

            if (arg == "-j") {
                json = true;
                continue;
            }

            if (arg == "-h") {
                usage();
                exit(0);
            }

            if (arg == "-V") {
                qout << "Version: " <<
                WebPageTraverser_VERSION_MAJOR << "." <<
                WebPageTraverser_VERSION_MINOR << "\n";
                qout.flush(); exit(0);
            }
        }

        if (url.isEmpty()) {
            usage();
            exit(1);
        }

        PageTraverser *traverser = new PageTraverser();
        WebElement *root = traverser->traverse(url);

        QByteArray serialized;
        if (json) {
           serialized = QJsonDocument::fromVariant(root->toQVariant()).toJson();
        }

        if (!fileName.isEmpty()) {
            QFileInfo file(fileName);
            QDir dir;
            dir.mkpath(file.absolutePath());

            QFile out(fileName);
            if (out.open(QIODevice::WriteOnly)) {
                if (json) {
                    out.write(serialized);
                } else {
                    out.write(root->toString().toUtf8());
                }
                out.close();
            }

            if (out.exists()) {
                qout << fileName << " written.\n";
            } else {
                qout << "Something went wrong writing" << fileName << ".\n";
            }
            qout.flush();
        } else {
            if (json) {
                qout << serialized;
            } else {
                qout << root->toString();
            }
            qout.flush();
        }

        exit(0);
    } else {
        usage();
        exit(1);
    }
}

void usage()
{
    QTextStream qout(stdout);
    qout << "Usage: " << QApplication::applicationName() << " -u <url> [-f <filename>] [-j]\n";
    qout << "\n";
    qout << "Options:\n";
    qout << "  -u        the webpage url\n";
    qout << "  -f        redirect the output to a file\n";
    qout << "  -j        use the Json format\n";
    qout << "  -V        print the version\n";
    qout.flush();
}
