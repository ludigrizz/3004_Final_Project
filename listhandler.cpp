#include "listhandler.h"
#include <QFile>
#include <QTextStream>
#include <QIODevice>

listHandler::listHandler()
{}

void listHandler::writeToFile(QListWidget *listWidget, const QString &filepath) {
    QFile file(filepath);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        for (int i=0; i<listWidget->count();++i) {
            QListWidgetItem* item = listWidget->item(i);
            out << item->text() << "\n";
        }
        file.close();
    }
}

void listHandler::loadFileToList(QListWidget *listWidget, const QString &filepath) {
    QFile file(filepath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while(!in.atEnd()) {
            QString line = in.readLine();
            listWidget->addItem(line);
        }
        file.close();
    }
}
