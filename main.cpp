#include "mainwindow.h"
#include <iostream>
#include <QTextStream>
#include <QApplication>
#include <QCameraInfo>
#include <QDebug>

QTextStream out(stdout);

bool checkCameraAvailability()
{
    if (QCameraInfo::availableCameras().count() > 0){
        const QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
        for (const QCameraInfo &cameraInfo : cameras)
            qDebug() << cameraInfo.deviceName();
//        out << "true\n";
//        const QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
//        qDebug() << "cameras" << QCameraInfo::availableCameras();
        return true;
    }
    else
        return false;
}

int main(int argc, char *argv[])
{
    checkCameraAvailability();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
