#ifndef HUMANMANAGEMENT_H
#define HUMANMANAGEMENT_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class humanmanagement;
}

class humanmanagement : public QWidget
{
    Q_OBJECT

public:
    explicit humanmanagement(QWidget *parent = 0);
    ~humanmanagement();

private:
    Ui::humanmanagement *ui;

private slots:
    void on_insert_human_clicked();

    void on_query_human_clicked();

    void on_update_human_clicked();
};

#endif // HUMANMANAGEMENT_H
