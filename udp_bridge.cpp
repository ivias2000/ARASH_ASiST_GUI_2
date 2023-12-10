#include "udp_bridge.h"
#include <QCoreApplication>
#include <QThread>
#include <QApplication>
#include <iostream>
#include <unistd.h>

void UdpBridge::setValue(float value,float value2,float value3,float value4,float value5,float value6,float value7)
{
        // send data
        emit valueChanged(value,value2,value3,value4,value5,value6,value7);

}

