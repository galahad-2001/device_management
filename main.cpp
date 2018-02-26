#include "mainwindow.h"
#include <QApplication>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("device_management");
    db.setUserName("root");
    db.setPassword("pass");
    if (!db.open())
        qDebug() << "Fail to connect mysql";
    else qDebug() << "Succeed to connect mysql";

    w.show();

    return a.exec();
}
