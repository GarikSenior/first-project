#pragma once

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initWindow();

    void digits_numbers();
    void on_pushButton_dot_clicked();
    void onPushButtonACClicked();
    void makeNegOrPosNubmer();
    void onPushButtonPercentClicked();
    void onPushButtonEqualClicked();
    void mathOperations();

    Ui::MainWindow *ui;
    double FinalFirstNumber;
    double firstNumbers;
    QString new_label;
    bool buttonPlus;
};
