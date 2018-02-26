#include "humanmanagement.h"
#include "ui_humanmanagement.h"
#include <QSqlQuery>
#include <QString>
#include <QDebug>

humanmanagement::humanmanagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::humanmanagement)
{
    ui->setupUi(this);
}

humanmanagement::~humanmanagement()
{
    delete ui;
}

void humanmanagement::on_insert_human_clicked()
{
    QSqlQuery query;
    QString name = ui->lineEdit->text();
    query.prepare("call sp_insert_human(:_name)");
    query.bindValue(0, name);
    query.exec();
}

void humanmanagement::on_query_human_clicked()
{
    QString name = ui->lineEdit->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from view_human");
//    qDebug() << "select * from view_device_human where name = '"+name+"'";
    ui->humantable->setModel(model);
    ui->humantable->resizeColumnsToContents();
    ui->humantable->resizeRowsToContents();
}

void humanmanagement::on_update_human_clicked()
{
    QSqlQuery query;
    QString name = ui->lineEdit->text();
    query.prepare("call sp_update_human(:_name)");
    query.bindValue(0, name);
    query.exec();
}
