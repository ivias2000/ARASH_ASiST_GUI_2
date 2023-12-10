
#include "mainwindow.h"
#include "udp.h"
#include "ui_mainwindow.h"
#include <udp_bridge.h>
#include <udp.h>
#include "loggingthread.h"

#include <QList>
#include <QVector>
#include <QCoreApplication>

//#include <qcustomplot.cpp>
extern int global_x;
extern int startlog_gui;
extern QVector<double> qv_counter;
extern QVector<double> qv_xValues;
extern QVector<double> qv_yValues;
extern QVector<double> qv_zValues;
extern QVector<double> qv_phiValues;
extern QVector<double> qv_psiValues;
extern QVector<double> qv_dValues;
extern QList<QVector<double>> existingVectors;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    // ui is pointer
    , ui(new Ui::MainWindow)
{
    //  UI

    ui->setupUi(this);
    ui->plot->setBackground(QColor(210,231,255,255));
    ui->plot->axisRect()->setBackground(QColor(255,255,255,255));

    ui->plot->xAxis->setTickLabelColor(QColor(0,0,0,255));
    ui->plot->yAxis->setTickLabelColor(QColor(0,0,0,255));
    ui->plot->legend->setVisible(true);
    ui->plot->addGraph();
    ui->plot->addGraph();
    ui->plot->addGraph();
    ui->plot->addGraph();
    ui->plot->addGraph();
    ui->plot->addGraph();
    ui->plot->xAxis->setLabel("TIME");

    //phi
    ui->plot->graph(0)->setPen(QPen(Qt::red));
    ui->plot->graph(0)->setName("PHI");
    //psi
    ui->plot->graph(1)->setPen(QPen(Qt::green));
    ui->plot->graph(1)->setName("PSI");
    //d
    ui->plot->graph(2)->setPen(QPen(Qt::blue));
    ui->plot->graph(2)->setName("D");
    //x
    ui->plot->graph(3)->setPen(QPen(Qt::yellow));
    ui->plot->graph(3)->setName("X");
    //y
    ui->plot->graph(4)->setPen(QPen(Qt::gray));
    ui->plot->graph(4)->setName("Y");
    //z
    ui->plot->graph(5)->setPen(QPen(Qt::red));
    ui->plot->graph(5)->setName("Z");
}    // distructor
    MainWindow::~MainWindow()
    {
        delete ui;
        //loggingThread->quit();
            //loggingThread->wait();
    }
    // signal slot
    void MainWindow::receiverGuiSlot(float x,float y,float z,float counter,float phi,float psi,float d){
     ui->label_phi->setText(QString::number(round(phi*10)));
     ui->label_psi->setText(QString::number(round(psi*10)));
     ui->label_time->setText(QString::number(counter));
     ui->horizontalSlider->setValue(phi);
     ui->horizontalSlider_2->setValue(psi);
     ui->horizontalSlider_3->setValue(d);

        plot_all();}

    void MainWindow::plot_all()
   {
       ui->plot->graph(0)->setData(qv_counter,qv_phiValues);
       ui->plot->graph(1)->setData(qv_counter,qv_psiValues);
       ui->plot->graph(2)->setData(qv_counter,qv_dValues);
       ui->plot->graph(3)->setData(qv_counter,qv_xValues);
       ui->plot->graph(4)->setData(qv_counter,qv_yValues);
       ui->plot->graph(5)->setData(qv_counter,qv_zValues);
       ui->plot->replot();
       ui->plot->rescaleAxes();
       //ui->plot->update();
   }

void MainWindow::on_radioButton_clicked()
{
    ui->plot->yAxis->setLabel("phi");
    ui->plot->graph(0)->setVisible(true);
    ui->plot->graph(1)->setVisible(false);
    ui->plot->graph(2)->setVisible(false);
    ui->plot->graph(3)->setVisible(false);
    ui->plot->graph(4)->setVisible(false);
    ui->plot->graph(5)->setVisible(false);
    //ui->plot->rescaleAxes();
    //ui->plot->replot();

}

void MainWindow::on_radioButton_psi_clicked()
{
    ui->plot->yAxis->setLabel("psi");
    ui->plot->graph(0)->setVisible(false);
    ui->plot->graph(1)->setVisible(true);
    ui->plot->graph(2)->setVisible(false);
    ui->plot->graph(3)->setVisible(false);
    ui->plot->graph(4)->setVisible(false);
    ui->plot->graph(5)->setVisible(false);
    //ui->plot->rescaleAxes();
    //ui->plot->replot();
}

void MainWindow::on_radioButton_insertion_clicked()
{
    ui->plot->yAxis->setLabel("insertion");
    ui->plot->graph(0)->setVisible(false);
    ui->plot->graph(1)->setVisible(false);
    ui->plot->graph(2)->setVisible(true);
    ui->plot->graph(3)->setVisible(false);
    ui->plot->graph(4)->setVisible(false);
    ui->plot->graph(5)->setVisible(false);
    //ui->plot->rescaleAxes();
    //ui->plot->replot();
}

void MainWindow::on_radioButton_x_clicked()
{
    ui->plot->yAxis->setLabel("x");
    ui->plot->graph(0)->setVisible(false);
    ui->plot->graph(1)->setVisible(false);
    ui->plot->graph(2)->setVisible(false);
    ui->plot->graph(3)->setVisible(true);
    ui->plot->graph(4)->setVisible(false);
    ui->plot->graph(5)->setVisible(false);
    //ui->plot->rescaleAxes();
    //ui->plot->replot();
}

void MainWindow::on_radioButton_y_clicked()
{
    ui->plot->yAxis->setLabel("y");
    ui->plot->graph(0)->setVisible(false);
    ui->plot->graph(1)->setVisible(false);
    ui->plot->graph(2)->setVisible(false);
    ui->plot->graph(3)->setVisible(false);
    ui->plot->graph(4)->setVisible(true);
    ui->plot->graph(5)->setVisible(false);
    //ui->plot->rescaleAxes();
    //ui->plot->replot();
}

void MainWindow::on_radioButton_z_clicked()
{
    ui->plot->yAxis->setLabel("z");
    ui->plot->graph(0)->setVisible(false);
    ui->plot->graph(1)->setVisible(false);
    ui->plot->graph(2)->setVisible(false);
    ui->plot->graph(3)->setVisible(false);
    ui->plot->graph(4)->setVisible(false);
    ui->plot->graph(5)->setVisible(true);
    //ui->plot->rescaleAxes();
    //ui->plot->replot();
}

void MainWindow::on_pushButton_start_clicked()
{
    startlog_gui=1;
}

void MainWindow::on_pushButton_stop_clicked()
{
    startlog_gui=0;
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->plot->yAxis->setLabel("ALL");
    ui->plot->graph(0)->setVisible(true);
    ui->plot->graph(1)->setVisible(true);
    ui->plot->graph(2)->setVisible(true);
    ui->plot->graph(3)->setVisible(true);
    ui->plot->graph(4)->setVisible(true);
    ui->plot->graph(5)->setVisible(true);
}
