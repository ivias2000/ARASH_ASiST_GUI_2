#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<udp.h>
#include<qcustomplot.h>
#include "qcgaugewidget.h"
#include "loggingthread.h"

#include <QVariant>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    udp UDP;
    LoggingThread loggingthread;

    void ClearData();
    void plot_all();

 public slots:
       void receiverGuiSlot (float x,float y,float z,float phi,float psi,float d,float counter);

private slots:



       void on_radioButton_clicked();

       void on_radioButton_psi_clicked();

       void on_radioButton_insertion_clicked();

       void on_radioButton_x_clicked();

       void on_radioButton_y_clicked();

       void on_radioButton_z_clicked();

       void on_pushButton_start_clicked();

       void on_pushButton_stop_clicked();

       void on_radioButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QThread* loggingThread;


    //int gui_value;
    //float cnt;

};

#endif // MAINWINDOW_H
