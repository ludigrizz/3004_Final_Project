#ifndef UPLOADLISTHANDLER_H
#define UPLOADLISTHANDLER_H

#include <QListWidget>
#include "pcwindow.h"


class uploadListHandler
{
public:
    uploadListHandler(QListWidget *listWidget);
    void loadFromFileToList(const QString &filepath);

private:
    QListWidget *listWidget;

};

#endif // UPLOADLISTHANDLER_H
