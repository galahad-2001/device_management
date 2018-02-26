#include "devicecheck.h"
#include "ui_devicecheck.h"
#include <QSqlQuery>
#include <QString>
#include <QDebug>

devicecheck::devicecheck(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::devicecheck)
{
    ui->setupUi(this);
}

devicecheck::~devicecheck()
{
    delete ui;
}



void devicecheck::on_pushButton_insert_device_clicked()
{
    QSqlQuery query;
    QString modle = ui->lineEdit_modle->text();
    QString pn = ui->lineEdit_PN->text();
    QString sn = ui->lineEdit_SN->text();
    query.prepare("call sp_insert_device(:_modle, :_pn, :_sn)");
    query.bindValue(0, modle);
    query.bindValue(1, pn);
    query.bindValue(2, sn);
    query.exec();
}

void devicecheck::on_pushButton_query_device_clicked()
{
    QString modle = ui->lineEdit_modle->text();
    QString sn = ui->lineEdit_SN->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from view_device_human_sa where modle like '%"+modle+"%'");
//  qDebug() << "select * from view_device where modle like '%"+modle+"%'";
    ui->devicetable->setModel(model);
    ui->devicetable->resizeColumnsToContents();
    ui->devicetable->resizeRowsToContents();
}

void devicecheck::on_pushButton_update_device_clicked()
{
    QSqlQuery query;
    QString sn = ui->lineEdit_SN->text();
    query.prepare("call sp_update_device(:_sn)");
    query.bindValue(0, sn);
    query.exec();
}
