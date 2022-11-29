#include <QApplication>
#include <QWidget>
#include <QLineEdit>            /* 해상도 입력을 위해 */
#include <QLabel>               /* 이미지 표시 */
#include <QPushButton>          /* 이미지 로드 동작 수행 */
#include <QBoxLayout>           /* 위젯들을 배치 */
#include <QFileDialog>          /* 이미지 파일 선택 */
#include <QDir>                 /* 홈디렉터리 */
#include <QFile>                /* 이미지 파일 읽기 */

#include "rawdata.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);         // QApplicaion 객체 생성
    RawData w;                          // 메인 위젯

    QLineEdit* widthLineEdit = new QLineEdit("256", &w);        // X 해상도 입력
    QLineEdit* heightLineEdit = new QLineEdit("256", &w);       // Y 해상도 입력
    QPushButton* button = new QPushButton("Load", &w);          // 버튼 생성
    QLabel* imageLabel = new QLabel(&w);                        // 이미지 표시를 위한 위젯

    QHBoxLayout* layout = new QHBoxLayout();                    // 위젯을 배치
    layout->addWidget(widthLineEdit);
    layout->addWidget(heightLineEdit);
    layout->addStretch(1);
    layout->addWidget(button);

    QVBoxLayout* mainLayout = new QVBoxLayout(&w);
    mainLayout->addLayout(layout);
    mainLayout->addWidget(imageLabel);

    QObject::connect(button, &QPushButton::clicked, [&](){
        QString fileName = QFileDialog::getOpenFileName(0, "Open a file", QDir::homePath( ), "Image file(*.raw *.pbm *.pgm *.ppm *.bmp *.jpg *.png)");

        if(!fileName.length( )) return;

        QFile file(fileName);
        file.open(QFile::ReadOnly);
        QByteArray byteArray = file.readAll();
        file.close();

        int width = widthLineEdit->text().toInt();
        int height = heightLineEdit->text().toInt();
        uchar* data = (uchar*)(byteArray.data());

        QImage image = QImage(data, width, height, QImage::Format_Grayscale8);
        imageLabel->setPixmap(QPixmap::fromImage(image, Qt::AutoColor));
        w.setWindowTitle(fileName);

        QFileInfo fileInfo(fileName);
        if(fileInfo.suffix() == "raw")
            imageLabel->setPixmap(QPixmap::fromImage(image, Qt::AutoColor));
        else
            imageLabel->setPixmap(QPixmap(fileName).scaled(width, height));

    });

    w.show();
    return a.exec();

}
