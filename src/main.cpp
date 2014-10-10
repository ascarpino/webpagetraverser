/*
 *   This file is part of WebPageTraverser.
 *
 *   Copyright 2012-2014 Andrea Scarpino <me@andreascarpino.it>
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

#include "webpagetraverser.h"
#include "pagetraverser.h"

#include <QApplication>
#include <QByteArray>
#include <QJsonDocument>
#include <QDir>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QCommandLineParser>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("WebPageTraverser");
    a.setApplicationVersion(QString::number(WebPageTraverser_VERSION_STRING));

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("url", "Webpage URL.");

    QCommandLineOption destFileName(QStringList() << "f" << "filename",
                                    "Redirect the output to a file.", "filename");
    parser.addOption(destFileName);

    QCommandLineOption useJson(QStringList() << "j" << "json",
                               "Use JSON output instead of plain text.");
    parser.addOption(useJson);

    parser.process(a);

    QTextStream qout(stdout);
    if (parser.positionalArguments().isEmpty()) {
        qout << parser.helpText();
        qout.flush();
        exit(1);
    }

    const QString url = parser.positionalArguments().at(0);

    const QString fileName = parser.value(destFileName);

    const bool json = parser.isSet(useJson);

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
            qDebug() << fileName << " written.";
        } else {
            qCritical() << "Something went wrong writing" << fileName << ".";
            exit(1);
        }
    } else {
        if (json) {
            qout << serialized;
        } else {
            qout << root->toString();
        }
        qout.flush();
    }

    exit(0);
}
