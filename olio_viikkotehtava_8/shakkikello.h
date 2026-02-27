#ifndef SHAKKIKELLO_H
#define SHAKKIKELLO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Shakkikello;
}
QT_END_NAMESPACE

class Shakkikello : public QMainWindow
{
    Q_OBJECT

public:
    Shakkikello(QWidget *parent = nullptr);
    ~Shakkikello();
    void timeout();
    void updateProgressBar();
    void setGameInfoText(QString, short);

private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();

    void on_twoMinButton_clicked();

    void on_fiveMinButton_clicked();

    void on_p1SwitchButton_clicked();

    void on_p2SwitchButton_clicked();

private:
    Ui::Shakkikello *ui;
    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;
    QTimer *pQTimer;

    int state;
};
#endif // SHAKKIKELLO_H
