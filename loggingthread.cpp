// loggingthread.cpp
#include "loggingthread.h"
#include <QCoreApplication>
#include <QFile>
extern QList<QVector<double>> existingVectors;
extern QList<QVector<double>> existingVectors2;
extern QList<QVector<double>> loglist;
extern QList<QVector<double>> loglist2;
extern int log_start;
extern int global_log;
extern double log_data1[7][60];
extern double log_data2[7][60];
extern int startlog_gui;
LoggingThread::LoggingThread(QObject *parent)
   : QThread(parent)
{
}

LoggingThread::~LoggingThread()
{
}

void LoggingThread::run()
{
   // Logging

   QFile file("logdata.txt");

   if (file.open(QIODevice::Append | QIODevice::Text))
   {
       QTextStream stream(&file);
       while(true){
        if(startlog_gui==1){
           if(log_start==1){
               if(global_log==0){
                   //this->data = log_data1;
                   //this->data = loglist;
                   for (int j = 0; j < 60; ++j) {
                       for (int i = 0; i < 7; ++i) {
                           stream << log_data2[i][j] << ",";
                       }
                       stream << "\n";
                   }
               }
               else if(global_log==1){
                   //this->data = log_data2;
                   //this->data = loglist2;
                   for (int j = 0; j < 60; ++j) {
                       for (int i = 0; i < 7; ++i) {
                           stream << log_data1[i][j] << ",";
                       }
                       stream << "\n";
                   }
               }
//                for (const QVector<double> &vec : data)
//                {
//                    for (double value : vec)
//                    {
//                        stream << value << ",";
//                    }
//                    stream << "\n";
//                }

               log_start=0;

   }}}}
   else
   {
       qWarning() << "Failed to open file for writing:" << file.errorString();
         file.close();
   }


}

