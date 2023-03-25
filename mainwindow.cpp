#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(onPushButtonMinusClicked()));
  connect(ui->pushButton_negNumb, SIGNAL(clicked()), this,
          SLOT(makeNegOrPosNubmer()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this,
          SLOT(onPushButtonPlusClicked()));
  connect(ui->pushButtonInterest, SIGNAL(clicked()), this,
          SLOT(onPushButtonInterestClicked()));
  connect(ui->pushButtonEqual, SIGNAL(clicked()), this,
          SLOT(onPushButtonEqualClicked()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();

  firstNumbers = (ui->displayLine->text() + button->text()).toDouble();
  new_label = QString::number(firstNumbers, 'g', 15);

  ui->displayLine->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked() {
  if (!(ui->displayLine->text().contains('.')))
    ui->displayLine->setText(ui->displayLine->text() + '.');
}
void MainWindow::onPushButtonPlusClicked() {
  // QPushButton *button = (QPushButton *)sender();
  buttonPlus = true;
  firstNumbers = (ui->displayLine->text()).toDouble();
  ui->displayLine->setText(ui->displayLine->text() + "+");

  //  secondNumbers = (ui->displayLine->text()).toDouble();
  //  firstNumbers += secondNumbers;
  //  new_label = QString::number(firstNumbers, 'g', 15);

  //  ui->displayLine->setText(new_label);
}

void MainWindow::on_pushButton_AC_clicked() {
  ui->displayLine->clear();
  ui->displayLine->setText(QStringLiteral("0"));
}

void MainWindow::makeNegOrPosNubmer() {

  firstNumbers = (ui->displayLine->text()).toDouble();
  firstNumbers = firstNumbers * -1;
  new_label = QString::number(firstNumbers, 'g', 15);

  ui->displayLine->setText(new_label);
}

void MainWindow::onPushButtonInterestClicked() {

  firstNumbers = (ui->displayLine->text()).toDouble();
  firstNumbers = firstNumbers * 0.01;
  new_label = QString::number(firstNumbers, 'g', 15);

  ui->displayLine->setText(new_label);
}

void MainWindow::onPushButtonMinusClicked() {

  firstNumbers = (ui->displayLine->text()).toDouble();
  firstNumbers = firstNumbers - 1;
  new_label = QString::number(firstNumbers, 'g', 15);

  ui->displayLine->setText(new_label);
}

void MainWindow::onPushButtonEqualClicked() {}
