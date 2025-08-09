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

    // Table setup
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"Nama Aplikasi", "Durasi (menit)", "Status"});
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    ui->limitdurationBox->setValue(dailyLimit);

    // Connect tombol tracking
    connect(ui->startTrackingButton, &QPushButton::clicked, this, &MainWindow::startAutoTracking);
    connect(ui->stopTrackingButton, &QPushButton::clicked, this, &MainWindow::stopAutoTracking);
    connect(trackingTimer, &QTimer::timeout, this, &MainWindow::trackActiveWindow);
}

MainWindow::~MainWindow() {
    delete ui;
}

// ========================== MANUAL MODE ==========================
void MainWindow::on_addButton_clicked() {
    QString name = ui->nameAppinput->text().trimmed();
    int duration = ui->durationBox->value();
    if(name.isEmpty() || duration <= 0) {
        QMessageBox::warning(this, "Input Salah", "Nama aplikasi dan durasi harus diisi.");
        return;
    }

    QString status = (duration > dailyLimit) ? "Melebihi Batas" : "Aman";
    dataList.append({name, duration, status});

    updateTable();
    updateSummary();
    ui->nameAppinput->clear();
    ui->durationBox->setValue(0);
}

void MainWindow::on_checklimitButton_clicked() {
    dailyLimit = ui->limitdurationBox->value();
    checkLimitForAll();
    updateTable();
    updateSummary();
}

void MainWindow::on_searchButton_clicked() {
    QString keyword = ui->searchInput->text().trimmed();
    if(keyword.isEmpty()) {
        updateTable();
        return;
    }
    ui->tableWidget->setRowCount(0);
    for (const auto &app : dataList) {
        if (app.name.contains(keyword, Qt::CaseInsensitive)) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(app.name));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(app.duration)));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(app.status));
        }
    }
}

void MainWindow::on_sortButton_clicked() {
    std::sort(dataList.begin(), dataList.end(), [](const AppUsage &a, const AppUsage &b) {
        return a.duration > b.duration;
    });
    updateTable();
}

void MainWindow::on_saveButton_clicked() {
    QString filePath = QFileDialog::getSaveFileName(this, "Simpan CSV", "", "CSV Files (*.csv)");
    if(!filePath.isEmpty()) saveToCsv(filePath);
}

void MainWindow::on_loadCsvButton_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "Muat CSV", "", "CSV Files (*.csv)");
    if(!filePath.isEmpty()) {
        loadFromCsv(filePath);
        updateTable();
        updateSummary();
    }
}

// ========================== AUTO MODE ==========================
void MainWindow::startAutoTracking() {
    if (!ui->autoTrackCheck->isChecked()) {
        QMessageBox::warning(this, "Tracking Tidak Aktif", "Centang 'Aktifkan pelacakan Otomatis' untuk memulai.");
        return;
    }
    trackingTimer->start(1000);
    QMessageBox::information(this, "Tracking Dimulai", "Pelacakan otomatis dimulai.");
}

void MainWindow::stopAutoTracking() {
    trackingTimer->stop();
    ui->currentAppLabel->clear();
    QMessageBox::information(this, "Tracking Berhenti", "Pelacakan otomatis dihentikan.");
}

void MainWindow::trackActiveWindow() {
    QString activeTitle = getActiveWindowTitle();

    // Cek Chrome + kata kunci
    if (activeTitle.contains("Instagram", Qt::CaseInsensitive) ||
        activeTitle.contains("YouTube", Qt::CaseInsensitive)) {

        ui->currentAppLabel->setText(activeTitle);

        if (lastTrackedApp != activeTitle) {
            lastTrackedApp = activeTitle;
            elapsedSeconds = 0;
        }

        elapsedSeconds++;

        // Tiap 60 detik → tambah durasi
        if (elapsedSeconds % 60 == 0) {
            bool found = false;
            for (auto &app : dataList) {
                if (app.name == lastTrackedApp) {
                    app.duration++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                dataList.append({lastTrackedApp, 1, "Aman"});
            }
            updateTable();
            updateSummary();
        }
    }
}

// ========================== UTIL ==========================
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

void MainWindow::checkLimitForAll() {
    for (auto &app : dataList) {
        app.status = (app.duration > dailyLimit) ? "Melebihi Batas" : "Aman";
    }
}

void MainWindow::saveToCsv(const QString &filePath) {
    QFile file(filePath);
    if(file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << "Nama Aplikasi,Durasi,Status\n";
        for (const auto &app : dataList) {
            out << app.name << "," << app.duration << "," << app.status << "\n";
        }
    }
}

void MainWindow::loadFromCsv(const QString &filePath) {
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly)) {
        dataList.clear();
        QTextStream in(&file);
        QString header = in.readLine();
        while(!in.atEnd()) {
            QString line = in.readLine();
            auto parts = line.split(",");
            if(parts.size() >= 3) {
                dataList.append({parts[0], parts[1].toInt(), parts[2]});
            }
        }
    }
}
