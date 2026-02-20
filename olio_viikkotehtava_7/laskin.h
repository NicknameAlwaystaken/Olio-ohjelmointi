#ifndef LASKIN_H
#define LASKIN_H

#include <QMainWindow>
#include <qlineedit.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Laskin; }
QT_END_NAMESPACE

class Laskin : public QMainWindow
{
    Q_OBJECT

public:
    Laskin(QWidget *parent = nullptr);
    ~Laskin();

private:
    Ui::Laskin *ui;
    QString number1, number2;
    int state;
    float result;
    short operand;

    void clearAndEnterClickHandler();
    void addSubMulDivClickHandler();
    void resetLineEdits();

    void changeCurrentField();
    void calculateNumbers();
signals:
    void mySignal(QString number);

public slots:
    void numberClickedHandler(QString number);

private slots:
    void on_enterButton_clicked();
    void on_additionButton_clicked();
    void on_substractButton_clicked();
    void on_multiplyButton_clicked();
    void on_divideButton_clicked();
    void on_clearButton_clicked();
};
#endif // LASKIN_H
