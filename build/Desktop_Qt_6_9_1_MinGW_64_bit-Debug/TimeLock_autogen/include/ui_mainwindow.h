/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QGroupBox *groupBoxReport;
    QVBoxLayout *verticalLayoutTable;
    QTableWidget *tableWidget;
    QGroupBox *groupBoxSetting;
    QGridLayout *gridLayoutSetting;
    QPushButton *startTrackingButton;
    QPushButton *checklimitButton;
    QLabel *labelLimit;
    QSpinBox *limitdurationBox;
    QLabel *currentAppLabel;
    QPushButton *stopTrackingButton;
    QPushButton *resetButton;
    QGroupBox *groupBoxInput;
    QHBoxLayout *horizontalLayoutInput;
    QComboBox *appSelectCombo;
    QPushButton *addButton;
    QGroupBox *groupBoxSetting_2;
    QGridLayout *gridLayoutSetting_2;
    QLabel *statusLabel;
    QLabel *labelLimit_2;
    QLabel *totalLabel;
    QLabel *labelLimit_3;
    QProgressBar *progressBar;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *loadCsvButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(550, 720);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 551, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Montserrat Ace")});
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setFrameShadow(QFrame::Shadow::Plain);
        label->setLineWidth(1);
        label->setTextFormat(Qt::TextFormat::AutoText);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label->setWordWrap(false);
        groupBoxReport = new QGroupBox(centralwidget);
        groupBoxReport->setObjectName("groupBoxReport");
        groupBoxReport->setGeometry(QRect(10, 300, 517, 191));
        verticalLayoutTable = new QVBoxLayout(groupBoxReport);
        verticalLayoutTable->setObjectName("verticalLayoutTable");
        tableWidget = new QTableWidget(groupBoxReport);
        tableWidget->setObjectName("tableWidget");

        verticalLayoutTable->addWidget(tableWidget);

        groupBoxSetting = new QGroupBox(centralwidget);
        groupBoxSetting->setObjectName("groupBoxSetting");
        groupBoxSetting->setGeometry(QRect(10, 155, 517, 148));
        gridLayoutSetting = new QGridLayout(groupBoxSetting);
        gridLayoutSetting->setObjectName("gridLayoutSetting");
        startTrackingButton = new QPushButton(groupBoxSetting);
        startTrackingButton->setObjectName("startTrackingButton");

        gridLayoutSetting->addWidget(startTrackingButton, 1, 0, 1, 1);

        checklimitButton = new QPushButton(groupBoxSetting);
        checklimitButton->setObjectName("checklimitButton");

        gridLayoutSetting->addWidget(checklimitButton, 0, 2, 1, 1);

        labelLimit = new QLabel(groupBoxSetting);
        labelLimit->setObjectName("labelLimit");

        gridLayoutSetting->addWidget(labelLimit, 0, 0, 1, 1);

        limitdurationBox = new QSpinBox(groupBoxSetting);
        limitdurationBox->setObjectName("limitdurationBox");

        gridLayoutSetting->addWidget(limitdurationBox, 0, 1, 1, 1);

        currentAppLabel = new QLabel(groupBoxSetting);
        currentAppLabel->setObjectName("currentAppLabel");

        gridLayoutSetting->addWidget(currentAppLabel, 1, 1, 1, 2);

        stopTrackingButton = new QPushButton(groupBoxSetting);
        stopTrackingButton->setObjectName("stopTrackingButton");

        gridLayoutSetting->addWidget(stopTrackingButton, 2, 0, 1, 1);

        resetButton = new QPushButton(groupBoxSetting);
        resetButton->setObjectName("resetButton");

        gridLayoutSetting->addWidget(resetButton, 2, 1, 1, 1);

        groupBoxInput = new QGroupBox(centralwidget);
        groupBoxInput->setObjectName("groupBoxInput");
        groupBoxInput->setGeometry(QRect(10, 68, 517, 80));
        horizontalLayoutInput = new QHBoxLayout(groupBoxInput);
        horizontalLayoutInput->setObjectName("horizontalLayoutInput");
        appSelectCombo = new QComboBox(groupBoxInput);
        appSelectCombo->setObjectName("appSelectCombo");

        horizontalLayoutInput->addWidget(appSelectCombo);

        addButton = new QPushButton(groupBoxInput);
        addButton->setObjectName("addButton");

        horizontalLayoutInput->addWidget(addButton);

        groupBoxSetting_2 = new QGroupBox(centralwidget);
        groupBoxSetting_2->setObjectName("groupBoxSetting_2");
        groupBoxSetting_2->setGeometry(QRect(10, 490, 517, 148));
        gridLayoutSetting_2 = new QGridLayout(groupBoxSetting_2);
        gridLayoutSetting_2->setObjectName("gridLayoutSetting_2");
        statusLabel = new QLabel(groupBoxSetting_2);
        statusLabel->setObjectName("statusLabel");

        gridLayoutSetting_2->addWidget(statusLabel, 1, 1, 1, 1);

        labelLimit_2 = new QLabel(groupBoxSetting_2);
        labelLimit_2->setObjectName("labelLimit_2");
        labelLimit_2->setMaximumSize(QSize(100, 16777215));

        gridLayoutSetting_2->addWidget(labelLimit_2, 0, 0, 1, 1);

        totalLabel = new QLabel(groupBoxSetting_2);
        totalLabel->setObjectName("totalLabel");

        gridLayoutSetting_2->addWidget(totalLabel, 0, 1, 1, 1);

        labelLimit_3 = new QLabel(groupBoxSetting_2);
        labelLimit_3->setObjectName("labelLimit_3");
        labelLimit_3->setMaximumSize(QSize(100, 16777215));

        gridLayoutSetting_2->addWidget(labelLimit_3, 1, 0, 1, 1);

        progressBar = new QProgressBar(groupBoxSetting_2);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        gridLayoutSetting_2->addWidget(progressBar, 2, 0, 1, 2);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 650, 251, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        saveButton = new QPushButton(horizontalLayoutWidget);
        saveButton->setObjectName("saveButton");

        horizontalLayout->addWidget(saveButton);

        loadCsvButton = new QPushButton(horizontalLayoutWidget);
        loadCsvButton->setObjectName("loadCsvButton");

        horizontalLayout->addWidget(loadCsvButton);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TimeLock", nullptr));
        groupBoxReport->setTitle(QCoreApplication::translate("MainWindow", "Laporan Penggunaan", nullptr));
        groupBoxSetting->setTitle(QCoreApplication::translate("MainWindow", "Pengaturan dan Kontrol", nullptr));
        startTrackingButton->setText(QCoreApplication::translate("MainWindow", "Mulai Tracking", nullptr));
        checklimitButton->setText(QCoreApplication::translate("MainWindow", "Cek Semua Batas", nullptr));
        labelLimit->setText(QCoreApplication::translate("MainWindow", "Batas Waktu Harian:", nullptr));
        currentAppLabel->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        stopTrackingButton->setText(QCoreApplication::translate("MainWindow", "Berhenti Tracking", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        groupBoxInput->setTitle(QCoreApplication::translate("MainWindow", "Input dan Penggunaan", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Tambah", nullptr));
        groupBoxSetting_2->setTitle(QCoreApplication::translate("MainWindow", "Ringkasan Penggunaan", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        labelLimit_2->setText(QCoreApplication::translate("MainWindow", "Total Waktu :", nullptr));
        totalLabel->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        labelLimit_3->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Simpan", nullptr));
        loadCsvButton->setText(QCoreApplication::translate("MainWindow", "Muat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
