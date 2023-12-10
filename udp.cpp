#include "udp.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cmath>
#include <typeinfo>
#include <QDebug>



using namespace std;
extern int log_start;
extern int global_log;
extern QVector<double> qv_counter;
extern QVector<double> qv_xValues;
extern QVector<double> qv_yValues;
extern QVector<double> qv_zValues;
extern QVector<double> qv_phiValues;
extern QVector<double> qv_psiValues;
extern QVector<double> qv_dValues;
extern QList<QVector<double>> existingVectors;
extern QList<QVector<double>> existingVectors2;
extern QList<QVector<double>> loglist;
extern QList<QVector<double>> loglist2;
extern double log_data1[7][60];
extern double log_data2[7][60];

void udp::run() {
    const char* UDP_IP = "0.0.0.0";
    const int UDP_PORT = 5500;

    int sockfd;
    //Structure describing
    struct sockaddr_in server_addr;
    //Initialization
    socklen_t addr_len = sizeof(server_addr);
    //AF_INET IPV4
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    //If PROTOCOL is zero ok  and -1 for errors
    if (sockfd < 0) {
        std::cerr << "Error opening socket" << std::endl;
    }
//memset:fill memory
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    //htons:converts the unsigned short integer
    server_addr.sin_port = htons(UDP_PORT);
    //presentation to network       //sin_addr:store it
    inet_pton(AF_INET, UDP_IP, &server_addr.sin_addr);
    // if bind.....
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Error binding socket" << std::endl;
    }
    std::cout << "UDP server listening on port " << 5500 << std::endl;
    const double pi = 3.14159265358979323846;
    //float l__0=0.006;
    float l__1=0.1820;
    float l__3=0.05;
    float l__5=0.1150;
    //float l__2=0.07;
    //float l__7=0.0342;
    float theta=42*(pi/180);
    float alpha=50*(pi/180);
    //log_start=10;

//    // Initialize SQLite database
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("example4.db");

//    if (!db.open()) {
//        qDebug() << "Error: Couldn't open database";

//    }

//    // Create a table to store values
//    QSqlQuery query;
//    query.exec("CREATE TABLE IF NOT EXISTS sample_table ("
//               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
//               "value1 REAL, "
//               "value2 REAL, "
//               "value3 REAL, "
//               "value4 REAL, "
//               "value5 REAL, "
//               "value6 REAL)");


    while (true) {
        char data[32];
        //ssize_t Used for a count of bytes or an error indication
        ssize_t data_len = recvfrom(sockfd, data, sizeof(data), 0, (struct sockaddr*)&server_addr, &addr_len);
        if (data_len < 0) {
        std::cerr << "Error receiving data" << std::endl;
         continue;
                }
        //Working with Raw Memory
        double* np_data = reinterpret_cast<double*>(data);

        float data_q1 = static_cast<float>(np_data[0]) ;
        float data2_q2 = static_cast<float>(np_data[1]);
        float data3_q3 = static_cast<float>(np_data[2]);
        float counter = static_cast<float>(np_data[3]) ;
        float phi = static_cast<float>((data_q1) * (pi / 180));
        float psi = static_cast<float>((data2_q2) * (pi / 180));
        float d = static_cast<float>((-data3_q3) / 1000);
        float x = static_cast<float>((sin(theta) * cos(psi + alpha) * d + cos(theta) * cos(phi) * sin(psi + alpha) * d + sin(theta) * (l__1 + l__3 + l__5)));
        float y = static_cast<float>(sin(phi) * sin(psi + alpha) * d);
        float z = static_cast<float>((cos(theta) * cos(psi + alpha) * d - cos(phi) * sin(theta) * sin(psi + alpha) * d + cos(theta) * (l__1 + l__3 + l__5)));
        int a =round(counter*1000.0);
        float mostafa = a/1000.0;
//        qv_counter[counter_plot]=counter;
//        qv_xValues[counter_plot]=x;
//        qv_yValues[counter_plot]=y;
//        qv_zValues[counter_plot]=z;
//        qv_phiValues[counter_plot]=phi;
//        qv_psiValues[counter_plot]=psi;
//        qv_dValues[counter_plot]=d;

        if(global_log==0){
            log_data1[0][counter_gui]=counter;
            log_data1[1][counter_gui]=phi;
            log_data1[2][counter_gui]=psi;
            log_data1[3][counter_gui]=d;
            log_data1[4][counter_gui]=x;
            log_data1[5][counter_gui]=y;
            log_data1[6][counter_gui]=z;
        }
        else if(global_log==1){
            log_data2[0][counter_gui]=counter;
            log_data2[1][counter_gui]=phi;
            log_data2[2][counter_gui]=psi;
            log_data2[3][counter_gui]=d;
            log_data2[4][counter_gui]=x;
            log_data2[5][counter_gui]=y;
            log_data2[6][counter_gui]=z;
        }


//        query.bindValue(":lastId", phi);
//                query.bindValue(":value1", psi);
//                query.bindValue(":value2", d);
//                query.bindValue(":value3", x);
//                query.bindValue(":value4", y);
//                query.bindValue(":value5", z);
//                query.bindValue(":value6", counter);

        counter_gui=counter_gui+1;

        cnt_plot++;
        if(cnt_plot>=99){
            cnt_plot=0;
            global_log=(global_log+1)%2;
            log_start=1;
            packet_recieve_handler.setValue(x, y, z, mostafa,phi,psi,d);
            //std::cout << a<< std::endl;

            qv_counter[counter_plot]=counter;
            qv_xValues[counter_plot]=x;
            qv_yValues[counter_plot]=y;
            qv_zValues[counter_plot]=z;
            qv_phiValues[counter_plot]=phi;
            qv_psiValues[counter_plot]=psi;
            qv_dValues[counter_plot]=d;
            counter_plot=counter_plot+1;
            if(counter_plot>=600){
                counter_plot=0;
            }
        }

        if(counter_gui>=60){


            counter_gui=0;

            //std::cout << counter<< std::endl;
        }

//        query.prepare("INSERT INTO sample_table (value1, value2, value3, value4, value5, value6) "
//                      "VALUES (:value1, :value2, :value3, :value4, :value5, :value6)");

//        query.bindValue(":value1", counter);
//        query.bindValue(":value2", psi);
//        query.bindValue(":value3", d);
//        query.bindValue(":value4", x);
//        query.bindValue(":value5", y);
//        query.bindValue(":value6", z);

//        if (!query.exec()) {
//            qDebug() << "Error inserting values:" << query.lastError().text();
//            //db.close();

//        }
    }
        // Close the database connection

        //std::cout << global_x<< std::endl;

    //db.close();
    close(sockfd);
    //db.close();

}
