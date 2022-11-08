#include "widget.h"
#include "delegate.h"


#include <QTableView>
#include <QStandardItemModel>

Widget::Widget(QWidget *parent)
    : QWidget{parent}
{
    QStandardItemModel* model = new QStandardItemModel(4, 2, this);
    Delegate* delegete = new Delegate(this);

    for(int row = 0; row < 4; ++row)
    {
        for(int column = 0; column < 2; ++column)
        {
            QModelIndex index = model->index(row, column, QModelIndex());
            model->setData(index, 0);
        }
    }
    QTableView* tableView = new QTableView(this);
    tableView->setModel(model);
    tableView->setItemDelegate(delegete);
}

