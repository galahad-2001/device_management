#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include "humanmanagement.h"
#include "devicecheck.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_query_device_clicked();

    void on_querydevicehuman_clicked();

    void on_insertdevicehuman_clicked();

    void on_updatedevicehuman_clicked();

    void on_humanmanagement_triggered();

    void on_devicecheck_triggered();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    Ui::humanmanagement *h;
    Ui::devicecheck *d;
};

#endif // MAINWINDOW_H
