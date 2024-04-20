#ifndef PCWINDOW_H
#define PCWINDOW_H

#include <QDockWidget>
#include "mainwindow.h"

namespace Ui {
class pcwindow;
}

class pcwindow : public QDockWidget
{
    Q_OBJECT

public:
    explicit pcwindow(QWidget *parent = nullptr);
    ~pcwindow();

public slots:
    void uploadItem(const QString &item);
    void uploadItems(const QStringList &items);

//signals:
//    void itemUploaded(const QString &item);

private:
    Ui::pcwindow *ui;
};

#endif // PCWINDOW_H
