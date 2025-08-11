#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QString>
#include <QTimer>
#include <windows.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct AppUsage {
    QString name;
    int duration; // menit
    int seconds;
    QString status;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();      // Tambah aplikasi dari combo box
    void on_checklimitButton_clicked();
    void on_sortButton_clicked();
    void on_saveButton_clicked();
    void on_loadCsvButton_clicked();
    void startAutoTracking();
    void stopAutoTracking();
    void trackActiveWindow();
    void on_resetButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<AppUsage> dataList;
    int dailyLimit = 120;
    QTimer *trackingTimer;
    QSet<QString> notifiedApps;
    int currentAppSeconds = 0; // detik penggunaan aplikasi aktif
    QString lastActiveApp;     // untuk cek pergantian aplikas

    QString getActiveWindowTitle();
    // QString currentActiveApp;
    void updateTable();
    void updateSummary();
    void checkLimitForAll();
    void saveToCsv(const QString &filePath);
    void loadFromCsv(const QString &filePath);
};

#endif // MAINWINDOW_H
