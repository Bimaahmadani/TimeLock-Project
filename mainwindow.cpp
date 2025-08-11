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
    dataList.append({selectedApp, 0, 0, "Aman"});
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

            // Tambah detik penggunaan
            app.seconds++;

            // Jika sudah 60 detik → tambah menit
            if (app.seconds >= 60) {
                app.duration++;
                app.seconds = 0;
            }

            // Hitung total detik penggunaan aplikasi aktif
            double totalSecondsUsed = (app.duration * 60) + app.seconds;
            double totalSecondsLimit = dailyLimit * 60;

            // Update progress bar aplikasi aktif
            int progressValue = static_cast<int>((totalSecondsUsed / totalSecondsLimit) * 100);
            ui->progressBar->setMaximum(100);
            ui->progressBar->setValue(progressValue);

            // Status per aplikasi → langsung berubah jika lewat 1 detik dari batas
            if (totalSecondsUsed > totalSecondsLimit) {
                app.status = "Melebihi Batas";

                if (!notifiedApps.contains(app.name)) {
                    QMessageBox::warning(this, "Batas Terlampaui",
                                         QString("Penggunaan %1 melebihi batas waktu!").arg(app.name));
                    notifiedApps.insert(app.name);
                }
            } else if (totalSecondsUsed >= totalSecondsLimit * 0.8) {
                app.status = "Mendekati Batas";
            } else {
                app.status = "Aman";
            }

            // Update tabel dan ringkasan
            updateTable();
            updateSummary();
            break;
        }
    }
}

// Update tabel
void MainWindow::updateTable() {
    ui->tableWidget->setRowCount(dataList.size());
    for (int i = 0; i < dataList.size(); ++i) {
        const auto &app = dataList[i];

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(app.name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(
                                           QString("%1:%2")
                                               .arg(app.duration, 2, 10, QChar('0'))
                                               .arg(app.seconds, 2, 10, QChar('0'))
                                           ));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(app.status));
    }
}


// Update ringkasan
void MainWindow::updateSummary() {
    QString activeTitle = getActiveWindowTitle();

    for (const auto &app : dataList) {
        if (activeTitle.contains(app.name, Qt::CaseInsensitive)) {

            // Hitung total detik penggunaan aplikasi aktif
            int totalSeconds = (app.duration * 60) + app.seconds;

            // Format total waktu jadi MM:SS
            int minutes = totalSeconds / 60;
            int seconds = totalSeconds % 60;
            ui->totalLabel->setText(QString("%1:%2")
                                        .arg(minutes, 2, 10, QChar('0'))
                                        .arg(seconds, 2, 10, QChar('0')));

            // Hitung batas total harian (dalam detik)
            int totalLimitSeconds = dailyLimit * 60;

            // Tentukan status untuk aplikasi aktif
            QString status;
            if (totalSeconds > totalLimitSeconds) {
                status = "Melebihi Batas";
            } else if (totalSeconds >= totalLimitSeconds * 0.8) {
                status = "Mendekati Batas";
            } else {
                status = "Aman";
            }
            ui->statusLabel->setText(status);

            return; // keluar setelah menemukan aplikasi aktif
        }
    }

    // Jika tidak ada aplikasi yang cocok
    ui->totalLabel->setText("00:00");
    ui->statusLabel->setText("-");
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
        QString header = in.readLine(); // Lewati header
        while (!in.atEnd()) {
            QString line = in.readLine();
            auto parts = line.split(",");
            if (parts.size() >= 3) {
                // name, duration, seconds, status
                dataList.append({parts[0], parts[1].toInt(), 0, parts[2]});
            }
        }
    }
}


void MainWindow::on_resetButton_clicked() {
    QList<QTableWidgetItem*> selectedItems = ui->tableWidget->selectedItems();
    QSet<int> selectedRows;

    // Ambil semua baris yang dipilih
    for (auto *item : selectedItems) {
        selectedRows.insert(item->row());
    }

    // Reset semua baris terpilih
    for (int row : selectedRows) {
        if (row >= 0 && row < dataList.size()) {
            dataList[row].duration = 0;
            dataList[row].seconds = 0;
            dataList[row].status = "Aman";
            notifiedApps.remove(dataList[row].name);
        }
    }

    updateTable();
    updateSummary();
}

