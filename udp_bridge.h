#ifndef UDP_BRIDGE_H
#define UDP_BRIDGE_H

#include <QObject>

class UdpBridge : public QObject
{
    Q_OBJECT

public:
    UdpBridge() { m_value = 0; }

    int value() const { return m_value; }

public slots:
    void setValue(float x,float y,float z,float phi,float psi,float d,float counter);

signals:
    void valueChanged(float x,float y,float z,float phi,float psi,float d,float counter);

private:
    float m_value;
};

#endif // UDP_BRIDGE_H
