#include "shakkikello.h"
#include "./ui_shakkikello.h"
#include <QTimer>

Shakkikello::Shakkikello(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Shakkikello)
{
    ui->setupUi(this);

    pQTimer = new QTimer(this);
    connect(pQTimer, &QTimer::timeout, this, &Shakkikello::updateProgressBar);
    pQTimer->setInterval(100); // 100ms
    pQTimer->start();
    state = 0;

    ui->p1ProgressBar->setValue(0);
    ui->p2ProgressBar->setValue(0);
}

Shakkikello::~Shakkikello()
{
    delete ui;
}

void Shakkikello::updateProgressBar()
{
    if(state == 1) { // player 1 turn
        player1Time -= 10; // 10 -> 100 ms due to limitation for variable
        if(player1Time <= 0) {
            state = 3;
            ui->gameStatus->setText(QString("Player 2 WON!!"));
        }
    } else if (state == 2) { // player 2 turn
        player2Time -= 10; // 10 -> 100 ms due to limitation for variable
        if(player2Time <= 0) {
            state = 3;
            ui->gameStatus->setText(QString("Player 1 WON!!"));
        }
    }

    if(state != 0) {
        int p1Time = int(100 * (float(player1Time) / float(gameTime))); // turning current time and max time into %
        int p2Time = int(100 * (float(player2Time) / float(gameTime)));
        ui->p1ProgressBar->setValue(p1Time);
        ui->p2ProgressBar->setValue(p2Time);
    }
}

void Shakkikello::on_startButton_clicked()
{
    if(state == 0) {
        state = 1;
        ui->gameStatus->setText(QString("Game ongoing"));
    }
}


void Shakkikello::on_stopButton_clicked()
{
    state = 0;
    ui->gameStatus->setText(QString("New game via start button"));
}

void Shakkikello::on_twoMinButton_clicked()
{
    ui->gameStatus->setText(QString("Ready to play"));
    int newTime = 1000;
    gameTime = newTime;
    player1Time = newTime;
    player2Time = newTime;
}


void Shakkikello::on_fiveMinButton_clicked()
{
    ui->gameStatus->setText(QString("Ready to play"));
    int newTime = 30000;
    gameTime = newTime;
    player1Time = newTime;
    player2Time = newTime;
}


void Shakkikello::on_p1SwitchButton_clicked()
{
    if(state == 1) {
        state = 2;
    }
}


void Shakkikello::on_p2SwitchButton_clicked()
{
    if(state == 2) {
        state = 1;
    }
}

