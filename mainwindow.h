#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QListWidget>
#include <QTableWidget>
#include "modbus.h"
#include <qcgaugewidget.h>
#include <QLabel>
#include <qcustomplot.h>
#include <QVector>
#include <QtSql>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ModbusNetwork   *modnet;
    ModbusNetwork   *modnet_groz;

    QTimer          *updateTimer;
    QTimer          *updateReg;
    QTimer          *timer_session;
    int             sec = 0;
    int             ports_count;

    QcGaugeWidget * mSpeedGauge;
    QcNeedleItem *mSpeedNeedle;

    QcGaugeWidget * mTempGauge;
    QcNeedleItem *mTempNeedle;

    QcGaugeWidget * mWaterGauge;
    QcNeedleItem *mWaterNeedle;

    QcGaugeWidget * mPressureGauge;
    QcNeedleItem *mPressureNeedle;

    QcGaugeWidget * mDirectionGauge;
    QcNeedleItem *mDirectionNeedle;

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    QLabel *lb_ugol_wind;

    double speedwind;
    double temperature;
    double waterprocent;
    double pressure;
    double direction;

    QcGaugeWidget * mGrozGauge;
    QcNeedleItem *mGrozNeedle;

    QcDegreesItem *mSector1;
    QcDegreesItem *mSector2;
    QcDegreesItem *mSector3;
    QcDegreesItem *mSector4;
    QcDegreesItem *mSector5;
    QcDegreesItem *mSector6;
    QcDegreesItem *mSector7;
    QcDegreesItem *mSector8;
    QcDegreesItem *mSector9;
    QcDegreesItem *mSector10;
    QcDegreesItem *mSector11;
    QcDegreesItem *mSector12;
    QcDegreesItem *mSector13;
    QcDegreesItem *mSector14;
    QcDegreesItem *mSector15;
    QcDegreesItem *mSector16;
    QcDegreesItem *mSector17;
    QcDegreesItem *mSector18;
    QcDegreesItem *mSector19;
    QcDegreesItem *mSector20;
    QcDegreesItem *mSector21;
    QcDegreesItem *mSector22;
    QcDegreesItem *mSector23;
    QcDegreesItem *mSector24;
    QcDegreesItem *mSector25;
    QcDegreesItem *mSector26;
    QcDegreesItem *mSector27;
    QcDegreesItem *mSector28;
    QcDegreesItem *mSector29;
    QcDegreesItem *mSector30;
    QcDegreesItem *mSector31;
    QcDegreesItem *mSector32;

    QStandardItemModel *mModel;
    QStandardItem *chislo;

    QStandardItemModel *mModel_2;
    QStandardItem *chislo_2;

    int mas[4][8];
    int sum0_9 = 0;
    int sum9_19 = 0;
    int sum19_56 = 0;
    int sum56 = 0;
    int sum_all = 0;

    int mas_razr[32];
    int mas_porog[5][9];

    void findPort();
    void onConnectionRelease();
    void onConnectionRelease_groz();
    void updatePortsList();
    void updateRegisters();
    void updTime();
    void clearSlave();
    void drawSector(int n_sector, int n_molniy);

    QByteArray bitsToBytes(QBitArray bits);

    QByteArray convertFloatToValues(float f);
    float convertArrayToFloat(QByteArray array_bytes, quint8 position);

    void config_init();

    Slave *slave;
    void send(quint8 time, quint8 command);
    void onApplicationQuit();
    void filesave(QString mes, int flag);

    QByteArray *otvet;
    QByteArray *otvet_groz;

    QByteArray *etx;

    QCustomPlot *grafic_T;
    QCustomPlot *grafic_V;
    QCustomPlot *grafic_D;
    QCustomPlot *grafic_P;
    QCustomPlot *grafic_r;

    void grafic_init();
    void grafic_change(double T, double V, double P, double D, double r);

    QVector<double> x;
    QVector<double> graf_T_y;
    QVector<double> graf_V_y;
    QVector<double> graf_D_y;
    QVector<double> graf_P_y;
    QVector<double> graf_r_y;

    int graf_i = 0;

private slots:
    void logPring(QString msg);
    void up(QByteArray arr);
    void up_groz(QByteArray arr);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
