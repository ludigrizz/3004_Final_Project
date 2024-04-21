#include "pcwindow.h"
#include "ui_pcwindow.h"

pcwindow::pcwindow(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::pcwindow)
{
    ui->setupUi(this);

    uploadItem("uploaded first item");
    QStringList sessItems = {"up1", "up2", "up3"};
    uploadItems(sessItems);
}

pcwindow::~pcwindow()
{
    delete ui;
}

void pcwindow::uploadItem(const QString &item) {
    ui->listWidget->addItem(item);
//    emit itemUploaded(item);
}

void pcwindow::uploadItems(const QStringList &items) {
    ui->listWidget->addItems(items);
}
