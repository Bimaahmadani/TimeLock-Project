#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <algorithm>

// Windows API: Ambil judul jendela aktif
QString MainWindow::getActiveWindowTitle() {
    HWND hwnd = GetForegroundWindow();
    if (!hwnd) return "";

    wchar_t windowTitle[256];
    GetWindowTextW(hwnd, windowTitle, sizeof(windowTitle) / sizeof(wchar_t));
    return QString::fromWCharArray(windowTitle);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), trackingTimer(new QTimer(this)) {
    ui->setupUi(this);

    // Isi combo box aplikasi
    ui->appSelectCombo->addItems({"Instagram", "YouTube", "TikTok", "Facebook", "Twitter"});

    // Setup tabel
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"Nama Aplikasi", "Durasi (menit)", "Status"});
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    ui->limitdurationBox->setValue(dailyLimit);

    // Connect tombol
    connect(ui->startTrackingButton, &QPushButton::clicked, this, &MainWindow::startAutoTracking);
    connect(ui->stopTrackingButton, &QPushButton::clicked, this, &MainWindow::stopAutoTracking);
    connect(trackingTimer, &QTimer::timeout, this, &MainWindow::trackActiveWindow);
}

MainWindow::~MainWindow() {
    delete ui;
}

// Tambah aplikasi dari combo box
void MainWindow::on_addButton_clicked() {
    QString selectedApp = ui->appSelectCombo->currentText();
    for (const auto &app : dataList) {
        if (app.name == selectedApp) {
            QMessageBox::warning(this, "Sudah Ada", "Aplikasi ini sudah ada di daftar tracking.");
            return;
        }
    }
    dataList.append({selectedApp, 0, "Aman"});
    updateTable();
    updateSummary();
}

// Cek batas harian
void MainWindow::on_checklimitButton_clicked() {
    dailyLimit = ui->limitdurationBox->value();
    checkLimitForAll();
    updateTable();
    updateSummary();
}

// Urutkan data
void MainWindow::on_sortButton_clicked() {
    std::sort(dataList.begin(), dataList.end(), [](const AppUsage &a, const AppUsage &b) {
        return a.duration > b.duration;
    });
    updateTable();
}

// Simpan CSV
void MainWindow::on_saveButton_clicked() {
    QString filePath = QFileDialog::getSaveFileName(this, "Simpan CSV", "", "CSV Files (*.csv)");
    if (!filePath.isEmpty()) saveToCsv(filePath);
}

// Muat CSV
void MainWindow::on_loadCsvButton_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "Muat CSV", "", "CSV Files (*.csv)");
    if (!filePath.isEmpty()) {
        loadFromCsv(filePath);
        updateTable();
        updateSummary();
    }
}

// Mulai tracking
void MainWindow::startAutoTracking() {
    trackingTimer->start(1000); // cek setiap detik
    QMessageBox::information(this, "Tracking Dimulai", "Pelacakan otomatis dimulai.");

    // 🔹 Nonaktifkan elemen saat tracking
    ui->limitdurationBox->setEnabled(false);
    ui->checklimitButton->setEnabled(false);
    ui->startTrackingButton->setEnabled(false);
}

// Berhenti tracking
void MainWindow::stopAutoTracking() {
    trackingTimer->stop();
    ui->currentAppLabel->clear();
    QMessageBox::information(this, "Tracking Berhenti", "Pelacakan otomatis dihentikan.");

    // 🔹 Aktifkan kembali elemen
    ui->limitdurationBox->setEnabled(true);
    ui->checklimitButton->setEnabled(true);
    ui->startTrackingButton->setEnabled(true);
}

// Proses tracking aktif
void MainWindow::trackActiveWindow() {
    QString activeTitle = getActiveWindowTitle();
    ui->currentAppLabel->setText(activeTitle);

    for (auto &app : dataList) {
        if (activeTitle.contains(app.name, Qt::CaseInsensitive)) {
            static int secCounter = 0;
            secCounter++;
            if (secCounter >= 60) {
                app.duration++;
                secCounter = 0;
                checkLimitForAll();
                updateTable();
                updateSummary();
            }

            // 🔹 Progress bar untuk aplikasi yang sedang aktif
            ui->progressBar->setMaximum(dailyLimit);
            ui->progressBar->setValue(app.duration);

            // 🔹 Notifikasi jika melebihi batas
            if (app.duration > dailyLimit && !notifiedApps.contains(app.name)) {
                QMessageBox::warning(this, "Batas Terlampaui",
                                     QString("Penggunaan %1 melebihi batas waktu!").arg(app.name));
                notifiedApps.insert(app.name);
            }
            break;
        }
    }
}

// Update tabel
void MainWindow::updateTable() {
    ui->tableWidget->setRowCount(0);
    for (const auto &app : dataList) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(app.name));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(app.duration)));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(app.status));
    }
}

// Update ringkasan
void MainWindow::updateSummary() {
    int total = 0;
    for (const auto &app : dataList) total += app.duration;
    ui->totalLabel->setText(QString::number(total));
    ui->progressBar->setMaximum(dailyLimit);
    ui->progressBar->setValue(total);

    QString status;
    if (total > dailyLimit) status = "Melebihi Batas";
    else if (total >= dailyLimit * 0.8) status = "Mendekati Batas";
    else status = "Aman";

    ui->statusLabel->setText(status);
}

// Cek batas untuk semua aplikasi
void MainWindow::checkLimitForAll() {
    for (auto &app : dataList) {
        app.status = (app.duration > dailyLimit) ? "Melebihi Batas" : "Aman";
    }
}

// Simpan ke CSV
void MainWindow::saveToCsv(const QString &filePath) {
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << "Nama Aplikasi,Durasi,Status\n";
        for (const auto &app : dataList) {
            out << app.name << "," << app.duration << "," << app.status << "\n";
        }
    }
}

// Muat dari CSV
void MainWindow::loadFromCsv(const QString &filePath) {
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        dataList.clear();
        QTextStream in(&file);
        QString header = in.readLine();
        while (!in.atEnd()) {
            QString line = in.readLine();
            auto parts = line.split(",");
            if (parts.size() >= 3) {
                dataList.append({parts[0], parts[1].toInt(), parts[2]});
            }
        }
    }
}

void MainWindow::on_resetButton_clicked() {
    QString selectedApp = ui->appSelectCombo->currentText();
    for (auto &app : dataList) {
        if (app.name == selectedApp) {
            app.duration = 0;
            app.status = "Aman";
            break;
        }
    }
    updateTable();
    updateSummary();
}
