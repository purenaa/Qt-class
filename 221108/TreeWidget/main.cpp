#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTreeWidget treeWidget;
    treeWidget.setColumnCount(2);               //열이 2개
    treeWidget.setHeaderLabels(QStringList() << "Col One" << "Col Two");      //열 첫번째 이름, 열 두번째 이름


    for(int i=0; i<3; i++) {                   //열
        QTreeWidgetItem* pltem = new QTreeWidgetItem(&treeWidget);
        pltem->setText(0, QString::number(i));      // (열의 자리, int i의 값을 QStirng으로 출력) : 0열에 숫자 0출력
        pltem->setText(1, "Hello");                 // 1열에 Hello 출력

        for(int j=0; j<3; j++) {              //행
            QTreeWidgetItem * itm = new QTreeWidgetItem(pltem);     //부모 pltem을 상속받음
            itm->setText(0, QString::number(j));        // (열의 자리, int j의 값을 QString으로 출력) : 0행에 숫자
            itm->setText(1, "world");
            pltem->addChild(itm);
        }
    }

    treeWidget.resize(250, 180);
    treeWidget.show();
    return a.exec();
}
