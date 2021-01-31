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

    void changeFunctionLabel(std::string path);

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_restartButton_clicked();

    void on_numberOfParticles_valueChanged(int arg1);


    void on_deJongButton1_toggled(bool checked);

    void on_deJongButton2_toggled(bool checked);

    void on_RastriginButton6_toggled(bool checked);

    void on_InerciaBox1_valueChanged(double arg1);

    void on_InerciaBox2_valueChanged(double arg1);

    void on_InercialWeightBox_valueChanged(double arg1);

    void on_RosenbrockButton_toggled(bool checked);

    void on_SchafferButton_toggled(bool checked);

    void on_GriewankButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
