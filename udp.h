#include <QCoreApplication>
#include <QThread>
#include <QApplication>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <udp_bridge.h>
#include <loggingthread.h>

#ifndef UDP_H
#define UDP_H

class udp : public QThread {
    Q_OBJECT
public:
    UdpBridge packet_recieve_handler;

    explicit udp(QObject* parent = nullptr) : QThread(parent) {}
    void run();
private:
        int counter_plot=0;
        int counter_gui=0;
        int cnt_plot=0;

};

#endif // UDP_H
