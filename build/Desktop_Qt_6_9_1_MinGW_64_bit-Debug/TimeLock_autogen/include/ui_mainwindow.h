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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *nameAppinput;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *durationBox;
    QPushButton *addButton;
    QGroupBox *groupBox_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpinBox *limitdurationBox;
    QLabel *label_6;
    QPushButton *checklimitButton;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *searchInput;
    QPushButton *searchButton;
    QPushButton *sortButton;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *autoTrackCheck;
    QLabel *label_15;
    QLabel *currentAppLabel;
    QWidget *horizontalLayoutWidget_11;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *startTrackingButton;
    QPushButton *stopTrackingButton;
    QGroupBox *groupBox_3;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_4;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLabel *totalLabel;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *statusLabel;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QProgressBar *progressBar;
    QLabel *label_9;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *saveButton;
    QPushButton *loadCsvButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 900);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 900, 51));
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
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(70, 70, 751, 141));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Montserrat Ace")});
        font1.setPointSize(11);
        font1.setBold(true);
        groupBox->setFont(font1);
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 29, 751, 53));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(9);
        font2.setBold(false);
        label_2->setFont(font2);

        horizontalLayout->addWidget(label_2);

        nameAppinput = new QLineEdit(horizontalLayoutWidget);
        nameAppinput->setObjectName("nameAppinput");

        horizontalLayout->addWidget(nameAppinput);

        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(0, 80, 751, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(120, 16777215));
        label_3->setFont(font2);

        horizontalLayout_2->addWidget(label_3);

        durationBox = new QSpinBox(horizontalLayoutWidget_2);
        durationBox->setObjectName("durationBox");

        horizontalLayout_2->addWidget(durationBox);

        addButton = new QPushButton(horizontalLayoutWidget_2);
        addButton->setObjectName("addButton");
        addButton->setEnabled(true);
        addButton->setMaximumSize(QSize(120, 16777215));
        addButton->setFont(font2);

        horizontalLayout_2->addWidget(addButton);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(70, 210, 751, 231));
        groupBox_2->setFont(font1);
        horizontalLayoutWidget_3 = new QWidget(groupBox_2);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(0, 29, 751, 53));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_3);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(180, 16777215));
        label_4->setFont(font2);

        horizontalLayout_3->addWidget(label_4);

        limitdurationBox = new QSpinBox(horizontalLayoutWidget_3);
        limitdurationBox->setObjectName("limitdurationBox");

        horizontalLayout_3->addWidget(limitdurationBox);

        label_6 = new QLabel(horizontalLayoutWidget_3);
        label_6->setObjectName("label_6");
        label_6->setMaximumSize(QSize(50, 16777215));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_6);

        checklimitButton = new QPushButton(horizontalLayoutWidget_3);
        checklimitButton->setObjectName("checklimitButton");
        checklimitButton->setEnabled(true);
        checklimitButton->setMaximumSize(QSize(140, 16777215));
        checklimitButton->setFont(font2);

        horizontalLayout_3->addWidget(checklimitButton);

        horizontalLayoutWidget_4 = new QWidget(groupBox_2);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(0, 80, 751, 51));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_4);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(120, 16777215));
        label_5->setFont(font2);

        horizontalLayout_4->addWidget(label_5);

        searchInput = new QLineEdit(horizontalLayoutWidget_4);
        searchInput->setObjectName("searchInput");

        horizontalLayout_4->addWidget(searchInput);

        searchButton = new QPushButton(horizontalLayoutWidget_4);
        searchButton->setObjectName("searchButton");
        searchButton->setEnabled(true);
        searchButton->setMaximumSize(QSize(120, 16777215));
        searchButton->setFont(font2);

        horizontalLayout_4->addWidget(searchButton);

        sortButton = new QPushButton(horizontalLayoutWidget_4);
        sortButton->setObjectName("sortButton");
        sortButton->setEnabled(true);
        sortButton->setMaximumSize(QSize(120, 16777215));
        sortButton->setFont(font2);

        horizontalLayout_4->addWidget(sortButton);

        horizontalLayoutWidget_10 = new QWidget(groupBox_2);
        horizontalLayoutWidget_10->setObjectName("horizontalLayoutWidget_10");
        horizontalLayoutWidget_10->setGeometry(QRect(0, 130, 751, 51));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget_10);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        autoTrackCheck = new QCheckBox(horizontalLayoutWidget_10);
        autoTrackCheck->setObjectName("autoTrackCheck");
        autoTrackCheck->setMaximumSize(QSize(210, 16777215));
        autoTrackCheck->setFont(font2);
        autoTrackCheck->setAcceptDrops(false);

        horizontalLayout_10->addWidget(autoTrackCheck);

        label_15 = new QLabel(horizontalLayoutWidget_10);
        label_15->setObjectName("label_15");
        label_15->setMaximumSize(QSize(120, 16777215));
        label_15->setFont(font2);

        horizontalLayout_10->addWidget(label_15);

        currentAppLabel = new QLabel(horizontalLayoutWidget_10);
        currentAppLabel->setObjectName("currentAppLabel");
        currentAppLabel->setMaximumSize(QSize(300, 16777215));
        currentAppLabel->setFont(font2);

        horizontalLayout_10->addWidget(currentAppLabel);

        horizontalLayoutWidget_11 = new QWidget(groupBox_2);
        horizontalLayoutWidget_11->setObjectName("horizontalLayoutWidget_11");
        horizontalLayoutWidget_11->setGeometry(QRect(0, 180, 281, 51));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_11);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        startTrackingButton = new QPushButton(horizontalLayoutWidget_11);
        startTrackingButton->setObjectName("startTrackingButton");
        startTrackingButton->setEnabled(true);
        startTrackingButton->setMaximumSize(QSize(120, 16777215));
        startTrackingButton->setFont(font2);

        horizontalLayout_11->addWidget(startTrackingButton);

        stopTrackingButton = new QPushButton(horizontalLayoutWidget_11);
        stopTrackingButton->setObjectName("stopTrackingButton");
        stopTrackingButton->setEnabled(true);
        stopTrackingButton->setMaximumSize(QSize(120, 16777215));
        stopTrackingButton->setFont(font2);

        horizontalLayout_11->addWidget(stopTrackingButton);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(70, 440, 751, 221));
        groupBox_3->setFont(font1);
        tableWidget = new QTableWidget(groupBox_3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 21, 751, 201));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(70, 660, 751, 141));
        groupBox_4->setFont(font1);
        horizontalLayoutWidget_5 = new QWidget(groupBox_4);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(0, 29, 751, 53));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(horizontalLayoutWidget_5);
        label_7->setObjectName("label_7");
        label_7->setMaximumSize(QSize(140, 16777215));
        label_7->setFont(font2);

        horizontalLayout_5->addWidget(label_7);

        totalLabel = new QLabel(horizontalLayoutWidget_5);
        totalLabel->setObjectName("totalLabel");
        totalLabel->setMaximumSize(QSize(200, 16777215));
        totalLabel->setFont(font2);
        totalLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(totalLabel);

        label_8 = new QLabel(horizontalLayoutWidget_5);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(50, 16777215));
        label_8->setFont(font2);
        label_8->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_5->addWidget(label_8);

        label_12 = new QLabel(horizontalLayoutWidget_5);
        label_12->setObjectName("label_12");
        label_12->setMaximumSize(QSize(50, 16777215));
        label_12->setFont(font2);
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(label_12);

        statusLabel = new QLabel(horizontalLayoutWidget_5);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setMaximumSize(QSize(200, 16777215));
        statusLabel->setFont(font2);
        statusLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(statusLabel);

        horizontalLayoutWidget_6 = new QWidget(groupBox_4);
        horizontalLayoutWidget_6->setObjectName("horizontalLayoutWidget_6");
        horizontalLayoutWidget_6->setGeometry(QRect(0, 80, 751, 51));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(horizontalLayoutWidget_6);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        horizontalLayout_6->addWidget(progressBar);

        label_9 = new QLabel(horizontalLayoutWidget_6);
        label_9->setObjectName("label_9");
        label_9->setMaximumSize(QSize(150, 16777215));
        label_9->setFont(font2);

        horizontalLayout_6->addWidget(label_9);

        horizontalLayoutWidget_7 = new QWidget(centralwidget);
        horizontalLayoutWidget_7->setObjectName("horizontalLayoutWidget_7");
        horizontalLayoutWidget_7->setGeometry(QRect(70, 810, 281, 41));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        saveButton = new QPushButton(horizontalLayoutWidget_7);
        saveButton->setObjectName("saveButton");

        horizontalLayout_7->addWidget(saveButton);

        loadCsvButton = new QPushButton(horizontalLayoutWidget_7);
        loadCsvButton->setObjectName("loadCsvButton");

        horizontalLayout_7->addWidget(loadCsvButton);

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
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Input dan Penggunaan", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Nama Aplikasi :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Durasi (menit) :", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Tambah", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Pengaturan dan Kontrol", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Batas Waktu harian :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Menit", nullptr));
        checklimitButton->setText(QCoreApplication::translate("MainWindow", "Cek Semua Batas", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Cari :", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        sortButton->setText(QCoreApplication::translate("MainWindow", "Urutkan Durasi", nullptr));
        autoTrackCheck->setText(QCoreApplication::translate("MainWindow", "Aktifkan pelacakan Otomatis", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Aplikasi saat ini :", nullptr));
        currentAppLabel->setText(QString());
        startTrackingButton->setText(QCoreApplication::translate("MainWindow", "Mulai Tracking", nullptr));
        stopTrackingButton->setText(QCoreApplication::translate("MainWindow", "Berhenti Tracking", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Laporan Penggunaan", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Ringkasan Penggunaan", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Total Waktu :", nullptr));
        totalLabel->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Menit", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Status :", nullptr));
        statusLabel->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "dari batas", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Simpan ke CSV", nullptr));
        loadCsvButton->setText(QCoreApplication::translate("MainWindow", "Muat dari CSV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
