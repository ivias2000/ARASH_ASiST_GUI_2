#include "mainwindow.h"
#include <QApplication>
#include "udp.h"
#include "loggingthread.h"
#include <QCoreApplication>
using namespace std;
int global_log=0;
int startlog_gui=0;
QVector<double> qv_counter(600);
int log_start=0;
QVector<double> qv_xValues(600);
QVector<double> qv_yValues(600);
QVector<double> qv_zValues(600);
QVector<double> qv_phiValues(600);
QVector<double> qv_psiValues(600);
QVector<double> qv_dValues(600);
QList<QVector<double>> existingVectors;
QList<QVector<double>> existingVectors2;
double log_data1[7][60];
double log_data2[7][60];

#include <QThread>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow main_screen;
    udp UDP;
    LoggingThread loggingThread;

    QObject::connect(&(UDP.packet_recieve_handler), &UdpBridge::valueChanged, &main_screen, &MainWindow::receiverGuiSlot);

    UDP.start();
    loggingThread.start();

    main_screen.show();
    return a.exec();
}
