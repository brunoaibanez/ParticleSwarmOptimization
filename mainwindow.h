#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainprogram.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MainProgram mainProgram;
    void setMainProgram(MainProgram * m);
    void showParticles();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_pressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
