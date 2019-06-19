#include "mainwindow.h"
#include <QApplication>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("device_management");
    db.setUserName("root");
    db.setPassword("pass");
    if (!db.open())
        qDebug() << "Fail to connect mysql";
    else qDebug() << "Succeed to connect mysql";

    MainWindow w;
    w.show();

    return a.exec();
}
