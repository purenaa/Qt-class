#include <QtTest>
#include <QCoreApplication>
#include <QtWidgets>

// add necessary includes here

class GuiTest : public QWidget
{
    Q_OBJECT

public:
    GuiTest(QWidget *parent = nullptr);
    ~GuiTest();

    QLineEdit* lineEdit;

private slots:
    void test_case1();
    void test_case1_data();
};

GuiTest::GuiTest(QWidget *parent) : QWidget(parent)
{
    lineEdit = new QLineEdit(this);
}

GuiTest::~GuiTest()
{

}

void GuiTest::test_case1_data()
{
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<QString>("expected");

    QTestEventList list1;
    list1.addKeyClick('a');
    QTest::newRow("char") << list1 << "a";

    QTestEventList list2;
    list2.addKeyClick('a');
    list2.addKeyClick(Qt::Key_Backspace);
    QTest::newRow("there+back-again") << list2 << "a";
}

void GuiTest::test_case1()
{
    //    QLineEdit lineEdit;
    //    QTest::keyClicks(&lineEdit, "hi KDE");
    //    QCOMPARE(lineEdit.text(), "hi KDE");
    //    QVERIFY2(true, "Failure");

    QFETCH(QTestEventList, events);
    QFETCH(QString, expected);
    events.simulate(lineEdit);
    QCOMPARE(lineEdit->text(), expected);
}

QTEST_MAIN(GuiTest)

#include "tst_guitest.moc"
