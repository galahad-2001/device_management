#ifndef DEVICECHECK_H
#define DEVICECHECK_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class devicecheck;
}

class devicecheck : public QWidget
{
    Q_OBJECT

public:
    explicit devicecheck(QWidget *parent = 0);
    ~devicecheck();

private slots:
    void on_pushButton_insert_device_clicked();

    void on_pushButton_query_device_clicked();

    void on_pushButton_update_device_clicked();

private:
    Ui::devicecheck *ui;
};

#endif // DEVICECHECK_H
