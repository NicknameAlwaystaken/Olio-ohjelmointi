#include "laskin.h"
#include "./ui_laskin.h"
#include <qvariant.h>
#include <string>

using namespace std;

Laskin::Laskin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Laskin)
{
    ui->setupUi(this);

    for (int i = 0; i < 10; i++) {
        const string button_name = "N" + to_string(i);
        QPushButton *button = this->findChild<QPushButton *>(button_name);
        const QString number = QString::number(i);
        connect(
            button,
            &QPushButton::clicked,
            this,
            [this, i, number](){ this->numberClickedHandler(number);}
        );
    }

    this->state = 0;
}

Laskin::~Laskin()
{
    delete ui;
}

void Laskin::numberClickedHandler(QString number)
{

    int state = this->state;
    if(state == 0) {
        QString current_number = ui->Number1->text();
        ui->Number1->setText(current_number + number);
    } else if(state == 1) {
        QString current_number = ui->Number2->text();
        ui->Number2->setText(current_number + number);
    }

    emit mySignal(number);
}


void Laskin::on_enterButton_clicked()
{
    int state = this->state;
    if(state == 0) {
        this->state = 1;
        this->number1 = ui->Number1->text();
    } else if(state == 1) {
        this->state = 2;
        this->number2 = ui->Number2->text();
    }
}

void Laskin::calculateNumbers() {
    short current_operand = this->operand;
    float number1 = this->number1.toFloat();
    float number2 = this->number2.toFloat();
    qDebug() << "numero 1: " << number1;
    qDebug() << "numero 2: " << number2;
    if(current_operand == '+') {
        const QString result = QString::number(number1 + number2);
        this->result = result.toFloat();
    } else if (current_operand == '-') {
        const QString result = QString::number(number1 - number2);
        this->result = result.toFloat();
    } else if (current_operand == '/') {
        const QString result = QString::number(number1 / number2);
        this->result = result.toFloat();
    } else if (current_operand == '*') {
        const QString result = QString::number(number1 * number2);
        this->result = result.toFloat();
    }
    qDebug() << "result: " << this->result;
}


void Laskin::on_additionButton_clicked()
{
    if(this->state == 2) {
        this->operand = '+';
        calculateNumbers();
        ui->Result->setText(QString::number(this->result));
        this->state = 0;
    }
}

void Laskin::on_substractButton_clicked()
{
    if(this->state == 2) {
        this->operand = '-';
        calculateNumbers();
        ui->Result->setText(QString::number(this->result));
        this->state = 0;
    }
}


void Laskin::on_multiplyButton_clicked()
{
    if(this->state == 2) {
        this->operand = '*';
        calculateNumbers();
        ui->Result->setText(QString::number(this->result));
        this->state = 0;
    }
}


void Laskin::on_divideButton_clicked()
{
    if(this->state == 2) {
        this->operand = '/';
        calculateNumbers();
        ui->Result->setText(QString::number(this->result));
        this->state = 0;
    }
}


void Laskin::on_clearButton_clicked()
{
    ui->Number1->setText(QString(""));
    this->number1 = QString("0");
    ui->Number2->setText(QString(""));
    this->number2 = QString("0");
    ui->Result->setText(QString(""));
    this->result = 0.0;
    this->state = 0;
}

