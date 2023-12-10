// loggingthread.h
#ifndef LOGGINGTHREAD_H
#define LOGGINGTHREAD_H

#include <QThread>
#include <QList>
#include <QVector>
#include <QDebug>


class LoggingThread : public QThread
{
    Q_OBJECT

public:
    LoggingThread(QObject *parent = nullptr);
    ~LoggingThread();

    void setData(const QList<QVector<double>> &data);

protected:
    void run() override;

private:
    double data[7][60];
};

#endif // LOGGINGTHREAD_H
