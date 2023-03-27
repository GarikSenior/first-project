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

  connect(ui->pushButtonAC, SIGNAL(clicked()), this,
          SLOT(on_pushButton_AC_clicked()));

  connect(ui->pushButtonNegNumb, SIGNAL(clicked()), this,
          SLOT(makeNegOrPosNubmer()));

  connect(ui->pushButtonPercent, SIGNAL(clicked()), this,
          SLOT(onPushButtonPercentClicked()));

  connect(ui->pushButtonDivide, SIGNAL(clicked()), this,
          SLOT(mathOperations()));

  connect(ui->pushButtonMult, SIGNAL(clicked()), this, SLOT(mathOperations()));
  connect(ui->pushButtonMinus, SIGNAL(clicked()), this, SLOT(mathOperations()));
  connect(ui->pushButtonPlus, SIGNAL(clicked()), this, SLOT(mathOperations()));

  connect(ui->pushButtonEqual, SIGNAL(clicked()), this,
          SLOT(onPushButtonEqualClicked()));

  ui->pushButtonDivide->setCheckable(true);
  ui->pushButtonMult->setCheckable(true);
  ui->pushButtonMinus->setCheckable(true);
  ui->pushButtonPlus->setCheckable(true);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();

  if (ui->displayLine->text().contains(".") && button->text() == "0") {
    new_label = ui->displayLine->text() + button->text();
  } else {
    firstNumbers = (ui->displayLine->text() + button->text()).toDouble();
    new_label = QString::number(firstNumbers, 'g', 15);
  }
  ui->displayLine->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked() {
  if (!(ui->displayLine->text().contains('.')))
    ui->displayLine->setText(ui->displayLine->text() + '.');
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
void MainWindow::onPushButtonPercentClicked() {

  firstNumbers = (ui->displayLine->text()).toDouble();
  firstNumbers = firstNumbers * 0.01;
  new_label = QString::number(firstNumbers, 'g', 15);

  ui->displayLine->setText(new_label);
}

void MainWindow::mathOperations() {
  QPushButton *button = (QPushButton *)sender();
  fNumber = ui->displayLine->text().toDouble();
  ui->displayLineUp->setText(ui->displayLine->text());
  ui->displayLine->setText("");
  button->setChecked(true);
}

void MainWindow::onPushButtonEqualClicked() {
  double labelNumber, secondNumber;
  QString newLabel;
  secondNumber = ui->displayLine->text().toDouble();

  if (ui->pushButtonDivide->isChecked()) {
    if (secondNumber == 0) {
      ui->displayLine->setText("Error");
    } else {
      labelNumber = fNumber / secondNumber;
      newLabel = QString::number(labelNumber, 'g', 15);

      ui->displayLine->setText(newLabel);
    }
    ui->pushButtonDivide->setChecked(false);

  } else if (ui->pushButtonMult->isChecked()) {
    labelNumber = fNumber * secondNumber;
    newLabel = QString::number(labelNumber, 'g', 15);

    ui->displayLine->setText(newLabel);
    ui->pushButtonMult->setChecked(false);
  } else if (ui->pushButtonMinus->isChecked()) {
    labelNumber = fNumber - secondNumber;
    newLabel = QString::number(labelNumber, 'g', 15);

    ui->displayLine->setText(newLabel);
    ui->pushButtonMinus->setChecked(false);
  } else if (ui->pushButtonPlus->isChecked()) {
    labelNumber = fNumber + secondNumber;
    newLabel = QString::number(labelNumber, 'g', 15);

    ui->displayLine->setText(newLabel);
    ui->pushButtonPlus->setChecked(false);
  }
  ui->displayLineUp->setText("");
}
