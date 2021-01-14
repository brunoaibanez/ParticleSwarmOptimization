/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *startButton;
    QPushButton *stopButton;
    QLabel *labelGrid;
    QPushButton *restartButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *numberOfParticles;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QDoubleSpinBox *InerciaBox1;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QDoubleSpinBox *InerciaBox2;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_4;
    QDoubleSpinBox *InercialWeightBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *deJongButton1;
    QRadioButton *deJongButton2;
    QRadioButton *RastriginButton6;
    QLabel *functionLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(774, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(420, 510, 112, 32));
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(530, 510, 112, 32));
        labelGrid = new QLabel(centralwidget);
        labelGrid->setObjectName(QString::fromUtf8("labelGrid"));
        labelGrid->setGeometry(QRect(10, 5, 611, 491));
        restartButton = new QPushButton(centralwidget);
        restartButton->setObjectName(QString::fromUtf8("restartButton"));
        restartButton->setGeometry(QRect(640, 510, 112, 32));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(640, 10, 111, 242));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        numberOfParticles = new QSpinBox(verticalLayoutWidget);
        numberOfParticles->setObjectName(QString::fromUtf8("numberOfParticles"));
        numberOfParticles->setMinimum(1);
        numberOfParticles->setMaximum(100);

        verticalLayout->addWidget(numberOfParticles);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        InerciaBox1 = new QDoubleSpinBox(verticalLayoutWidget);
        InerciaBox1->setObjectName(QString::fromUtf8("InerciaBox1"));
        InerciaBox1->setSingleStep(0.100000000000000);
        InerciaBox1->setValue(0.100000000000000);

        verticalLayout->addWidget(InerciaBox1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        InerciaBox2 = new QDoubleSpinBox(verticalLayoutWidget);
        InerciaBox2->setObjectName(QString::fromUtf8("InerciaBox2"));
        InerciaBox2->setSingleStep(0.100000000000000);
        InerciaBox2->setValue(0.100000000000000);

        verticalLayout->addWidget(InerciaBox2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        InercialWeightBox = new QDoubleSpinBox(verticalLayoutWidget);
        InercialWeightBox->setObjectName(QString::fromUtf8("InercialWeightBox"));
        InercialWeightBox->setSingleStep(0.100000000000000);
        InercialWeightBox->setValue(0.900000000000000);

        verticalLayout->addWidget(InercialWeightBox);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(640, 310, 111, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        deJongButton1 = new QRadioButton(verticalLayoutWidget_2);
        deJongButton1->setObjectName(QString::fromUtf8("deJongButton1"));
        deJongButton1->setChecked(true);

        verticalLayout_2->addWidget(deJongButton1);

        deJongButton2 = new QRadioButton(verticalLayoutWidget_2);
        deJongButton2->setObjectName(QString::fromUtf8("deJongButton2"));

        verticalLayout_2->addWidget(deJongButton2);

        RastriginButton6 = new QRadioButton(verticalLayoutWidget_2);
        RastriginButton6->setObjectName(QString::fromUtf8("RastriginButton6"));

        verticalLayout_2->addWidget(RastriginButton6);

        functionLabel = new QLabel(centralwidget);
        functionLabel->setObjectName(QString::fromUtf8("functionLabel"));
        functionLabel->setGeometry(QRect(540, 420, 221, 81));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 774, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SWORM", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        labelGrid->setText(QString());
        restartButton->setText(QCoreApplication::translate("MainWindow", "Restart", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", " Part\303\255culas", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Inercia Individual", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Inercia Colectiva", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Peso inercial", nullptr));
        deJongButton1->setText(QCoreApplication::translate("MainWindow", "De Jong 1", nullptr));
        deJongButton2->setText(QCoreApplication::translate("MainWindow", "De Jong 2", nullptr));
        RastriginButton6->setText(QCoreApplication::translate("MainWindow", "Rastrigin 6", nullptr));
        functionLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
