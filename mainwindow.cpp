#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QString>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_query_device_clicked()
{
    QString modle = ui->lineEdit_2->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from device_management.view_device where modle like '%"+modle+"%'");
//    qDebug() << "select * from device_management.view_device where modle like '%"+modle+"%'";
    ui->devicetable->setModel(model);
    ui->devicetable->resizeColumnsToContents();
    ui->devicetable->resizeRowsToContents();
}

void MainWindow::on_querydevicehuman_clicked()
{
    QString name = ui->lineEdit_4->text();
    QString sn = ui->lineEdit_5->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from device_management.view_device_human where name = '"+name+"'");
//    qDebug() << "select * from device_management.view_device_human where name = '"+name+"'";
    ui->devicehumantable->setModel(model);
    ui->devicehumantable->resizeColumnsToContents();
    ui->devicehumantable->resizeRowsToContents();
}

void MainWindow::on_insertdevicehuman_clicked()
{
    QSqlQuery query;
    QString name = ui->lineEdit_4->text();
    QString sn = ui->lineEdit_5->text();
    query.prepare("call device_management.sp_insert_human(:_name)");
    query.bindValue(0, name);
    query.exec();
    query.prepare("call device_management.sp_insert_device_human(:_sn, :_name)");
    query.bindValue(0, sn);
    query.bindValue(1, name);
    query.exec();
}

void MainWindow::on_updatedevicehuman_clicked()
{
    QSqlQuery query;
    QString sn = ui->lineEdit_5->text();
    query.prepare("call device_management.sp_update_device_human(:_sn)");
    query.bindValue(0, sn);
    query.exec();
}

void MainWindow::on_humanmanagement_triggered()
{
    humanmanagement *h = new humanmanagement;
    h->show();
}

void MainWindow::on_devicecheck_triggered()
{
    devicecheck *d = new devicecheck;
    d->show();
}
