#ifndef LISTHANDLER_H
#define LISTHANDLER_H
#include <QString>
#include "mainwindow.h"
#include "pcwindow.h"
#include <QListWidget>


class listHandler
{
public:
    listHandler();
    void writeToFile(QListWidget *listWidget, const QString &filepath);
    void loadFileToList(QListWidget *listWidget, const QString &filepath);
};

#endif // LISTHANDLER_H
