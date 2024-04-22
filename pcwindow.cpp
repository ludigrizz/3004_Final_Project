#include "pcwindow.h"
#include "ui_pcwindow.h"
#include "listhandler.h"

pcwindow::pcwindow(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::pcwindow)
{
    ui->setupUi(this);

    listHandler lhandle_pc;
    lhandle_pc.loadFileToList(ui->listWidget, "data.txt");

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
