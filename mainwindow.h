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
    QString status;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Manual input
    void on_addButton_clicked();
    void on_checklimitButton_clicked();
    void on_searchButton_clicked();
    void on_sortButton_clicked();
    void on_saveButton_clicked();
    void on_loadCsvButton_clicked();

    // Auto tracking
    void startAutoTracking();
    void stopAutoTracking();
    void trackActiveWindow();

private:
    Ui::MainWindow *ui;
    QVector<AppUsage> dataList;
    int dailyLimit = 120;
    QTimer *trackingTimer;
    QString lastTrackedApp;
    int elapsedSeconds = 0;

    // Utility
    QString getActiveWindowTitle();
    void updateTable();
    void updateSummary();
    void checkLimitForAll();
    void saveToCsv(const QString &filePath);
    void loadFromCsv(const QString &filePath);
};

#endif // MAINWINDOW_H
