#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWindow()
{
    connect(ui->pushButton_0, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::digits_numbers);

    connect(ui->pushButtonAC, &QPushButton::clicked, this, &MainWindow::onPushButtonACClicked);
    connect(ui->pushButtonNegNumb, &QPushButton::clicked, this, &MainWindow::makeNegOrPosNubmer);
    connect(ui->pushButtonPercent, &QPushButton::clicked, this,
            &MainWindow::onPushButtonPercentClicked);
    connect(ui->pushButtonDivide, &QPushButton::clicked, this, &MainWindow::mathOperations);
    connect(ui->pushButtonMult, &QPushButton::clicked, this, &MainWindow::mathOperations);
    connect(ui->pushButtonMinus, &QPushButton::clicked, this, &MainWindow::mathOperations);
    connect(ui->pushButtonPlus, &QPushButton::clicked, this, &MainWindow::mathOperations);
    connect(ui->pushButtonEqual, &QPushButton::clicked, this,
            &MainWindow::onPushButtonEqualClicked);

    ui->pushButtonDivide->setCheckable(true);
    ui->pushButtonMult->setCheckable(true);
    ui->pushButtonMinus->setCheckable(true);
    ui->pushButtonPlus->setCheckable(true);
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    if (ui->displayLine->text().contains(".") && button->text() == "0")
    {
        new_label = ui->displayLine->text() + button->text();
    }
    else
    {
        firstNumbers = (ui->displayLine->text() + button->text()).toDouble();
        new_label = QString::number(firstNumbers, 'g', 15);
    }
    ui->displayLine->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (!(ui->displayLine->text().contains('.')))
        ui->displayLine->setText(ui->displayLine->text() + '.');
}
void MainWindow::onPushButtonACClicked()
{
    ui->displayLine->clear();
    ui->displayLine->setText(QStringLiteral("0"));
    ui->displayLineUp->setText(QStringLiteral(""));
}
void MainWindow::makeNegOrPosNubmer()
{

    firstNumbers = (ui->displayLine->text()).toDouble();
    firstNumbers = firstNumbers * -1;
    new_label = QString::number(firstNumbers, 'g', 15);

    ui->displayLine->setText(new_label);
}
void MainWindow::onPushButtonPercentClicked()
{

    firstNumbers = (ui->displayLine->text()).toDouble();
    firstNumbers = firstNumbers * 0.01;
    new_label = QString::number(firstNumbers, 'g', 15);

    ui->displayLine->setText(new_label);
}

void MainWindow::mathOperations()
{
    QPushButton *button = (QPushButton *)sender();
    FinalFirstNumber = ui->displayLine->text().toDouble();
    ui->displayLineUp->setText(ui->displayLine->text());
    ui->displayLine->setText("");
    button->setChecked(true);
}

void MainWindow::onPushButtonEqualClicked()
{
    double labelNumber, secondNumber;
    QString newLabel;
    secondNumber = ui->displayLine->text().toDouble();

    if (ui->pushButtonDivide->isChecked())
    {
        if (secondNumber == 0)
        {
            ui->displayLine->setText("Error");
        }
        else
        {
            labelNumber = FinalFirstNumber / secondNumber;
            newLabel = QString::number(labelNumber, 'g', 15);

            ui->displayLine->setText(newLabel);
        }
        ui->pushButtonDivide->setChecked(false);
    }
    else if (ui->pushButtonMult->isChecked())
    {
        labelNumber = FinalFirstNumber * secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);

        ui->displayLine->setText(newLabel);
        ui->pushButtonMult->setChecked(false);
    }
    else if (ui->pushButtonMinus->isChecked())
    {
        labelNumber = FinalFirstNumber - secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);

        ui->displayLine->setText(newLabel);
        ui->pushButtonMinus->setChecked(false);
    }
    else if (ui->pushButtonPlus->isChecked())
    {
        labelNumber = FinalFirstNumber + secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);

        ui->displayLine->setText(newLabel);
        ui->pushButtonPlus->setChecked(false);
    }
    ui->displayLineUp->setText("");
}
