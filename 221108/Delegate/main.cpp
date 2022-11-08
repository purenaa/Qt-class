//#include "delegate.h"
#include "widget.h"

#include <QTableView>
#include <QStandardItemModel>
#include <QApplication>
#include <QModelIndex>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QTableView tableView;
//    QStandardItem* model = new QStandardItemModel(4, 2, &tableView);
//    Delegate* delegete = new Delegate(tableView);

//    for(int row= 0; row <4; row++)
//        for(int column =0; column < 2; column++)
//            QModelIndex index = model->index(row, column, QModelIndex());
//    model->setData(index, row+column);


    Widget w;
    w.show();
    return a.exec();
}



