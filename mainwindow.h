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
    QTimer * mytimer;
    bool started;

private slots:

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_restartButton_clicked();

    void on_numberOfParticles_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
