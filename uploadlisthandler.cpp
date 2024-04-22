#include "uploadlisthandler.h"
#include <QFile>
#include <QTextStream>

uploadListHandler::uploadListHandler(QListWidget *listWidget) : listWidget(listWidget)
{

}

void uploadListHandler::loadFromFileToList(const QString &filepath) {
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
