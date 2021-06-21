#include "mainwindow.h"
#include "ui_mainwindow.h"

#include    <QComboBox>
#include    <QPushButton>
#include    <QSerialPortInfo>
#include    <QPlainTextEdit>
#include    <QFileInfo>
#include    <QHeaderView>
#include    <QAction>
#include    <QFileDialog>
#include    <QStandardPaths>
#include    <QDebug>
#include    <QBitArray>
#include    <QMap>
#include    <QThread>
#include    <config_form.h>
#include    <QTime>
#include    <QDate>
#include    <QStringList>

enum
{
    PORT_LIST_UPDATE_INTERVAL = 100
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);  

    QTime time_now = QTime::currentTime();
    QDate date_now = QDate::currentDate();
    ui->lb_time->setText(time_now.toString("hh:mm:ss"));
    ui->lb_date->setText(date_now.toString("dd MMMM yyyy"));

    otvet = new QByteArray();
    otvet_groz = new QByteArray();

    findPort();

    modnet = new ModbusNetwork(this);
    modnet_groz = new ModbusNetwork(this);

    connect(modnet, &ModbusNetwork::logPrint, this, &MainWindow::logPring);
    connect(modnet, &ModbusNetwork::send_data_array, this, &MainWindow::up);
    connect(modnet_groz, &ModbusNetwork::send_data_array_groz, this, &MainWindow::up_groz);

    db.setDatabaseName("zenit");
    db.setUserName("uzorky2_0_00");
    db.setHostName("10.1.57.87");
    db.setPassword("uzorky2_0_00");
    db.setPort(6003);

    if(!db.open())
    {
      QMessageBox::warning(this,"Ошибка","Не удалось подключиться к базе данных",QMessageBox::Ok);
    }

    updateTimer = new QTimer(this);
    updateTimer->setInterval(PORT_LIST_UPDATE_INTERVAL);

    updateReg = new QTimer(this);
    updateReg -> setInterval(2000);

    timer_session = new QTimer(this);
    timer_session -> setInterval(1000);

    ports_count = 0;

    connect(updateTimer, &QTimer::timeout,
            this, &MainWindow::updatePortsList);

    connect(timer_session, &QTimer::timeout,
            this, &MainWindow::updTime);

    connect(updateReg, &QTimer::timeout,
            this, &MainWindow::updateRegisters);

    updateTimer -> start();
    updateReg -> start();
    timer_session -> start();

    connect(ui->pushButton_connect, &QPushButton::released,
            this, &MainWindow::onConnectionRelease);
    connect(ui->pushButton_connect_groz, &QPushButton::released,
            this, &MainWindow::onConnectionRelease_groz);
    connect(ui->pushButton_config, &QPushButton::released, this, &MainWindow::config_init);

    ui->pushButton_connect->setStyleSheet("background-color: green; color: white;");
    ui->comboBox_port->setFocus();

    //==========================================================

    mSpeedGauge = new QcGaugeWidget;
    mSpeedGauge->addArc(55);
    QcDegreesItem *deg_speed = mSpeedGauge ->addDegrees(65);
    deg_speed->setStep(2.5);
    deg_speed->setValueRange(0,30);
    QcValuesItem *values_speed = mSpeedGauge->addValues(80);
    values_speed->setStep(5);
    values_speed->setValueRange(0,30);
    QcLabelItem *lab_speed = mSpeedGauge ->addLabel(50);
    lab_speed->setText("0");
    lab_speed->setColor("steelblue");
    mSpeedNeedle = mSpeedGauge ->addNeedle(60);
    mSpeedNeedle->setLabel(lab_speed);
    mSpeedNeedle->setColor(Qt::red);
    mSpeedNeedle->setValueRange(0,30);
    mSpeedGauge->addBackground(7);
    //mSpeedGauge->addLabel(80)->setText("V, м/с");

    QLabel *lb_speed = new QLabel("Скорость ветра\nV,м/с");
    lb_speed->setAlignment(Qt::AlignHCenter);
    lb_speed->setStyleSheet("font-style: Meiryo UI; font: bold; font-size: 18px;");


    ui->gridLayout_3->addWidget(lb_speed,0,0);
    ui->gridLayout_3->addWidget(mSpeedGauge,1,0);

    //==================================================

    mTempGauge = new QcGaugeWidget;
    mTempGauge->addArc(55);
    QcDegreesItem *deg_temp = mTempGauge->addDegrees(65);
    deg_temp->setStep(5);
    deg_temp->setValueRange(-45,45);
    QcValuesItem *values_temp = mTempGauge->addValues(80);
    values_temp->setStep(15);
    values_temp->setValueRange(-45,45);
    QcLabelItem *lab_temp = mTempGauge -> addLabel(50);
    lab_temp->setText("0");
    lab_temp->setColor("steelblue");
    mTempNeedle = mTempGauge ->addNeedle(60);
    mTempNeedle->setLabel(lab_temp);
    mTempNeedle->setColor(Qt::red);
    mTempNeedle->setValueRange(-45,45);
    mTempGauge->addBackground(7);
   //mTempGauge->addLabel(80)->setText("T,°C");

    QLabel *lb_temp = new QLabel("Температура\nT,°C");
    lb_temp->setAlignment(Qt::AlignHCenter);
    lb_temp->setStyleSheet("font-style: Meiryo UI; font: bold; font-size: 18px;");

    ui->gridLayout_3->addWidget(lb_temp,0,1);
    ui->gridLayout_3->addWidget(mTempGauge,1,1);

    //==================================================

    mPressureGauge = new QcGaugeWidget;
    mPressureGauge ->addArc(55);
    QcDegreesItem *deg_pressure = mPressureGauge ->addDegrees(65);
    deg_pressure->setStep(25);
    deg_pressure->setValueRange(500,800);
    QcValuesItem *values_pressure = mPressureGauge->addValues(80);
    values_pressure->setStep(50);
    values_pressure->setValueRange(500,800);
    QcLabelItem *lab_pressure = mPressureGauge -> addLabel(50);
    lab_pressure->setText("0");
    lab_pressure->setColor("steelblue");
    mPressureNeedle = mPressureGauge -> addNeedle(60);
    mPressureNeedle->setLabel(lab_pressure);
    mPressureNeedle->setColor(Qt::red);
    mPressureNeedle->setValueRange(500,800);
    mPressureGauge->addBackground(7);

    QLabel *lb_pressure = new QLabel("Давление\nP, мм.рт.ст.");
    lb_pressure->setAlignment(Qt::AlignHCenter);
    lb_pressure->setStyleSheet("font-style: Meiryo UI; font: bold; font-size: 18px;");

    ui->gridLayout_3->addWidget(lb_pressure,0,2);
    ui->gridLayout_3->addWidget(mPressureGauge,1,2);

    //==========================================================

    mDirectionGauge = new QcGaugeWidget;

    QcLabelItem *w = mDirectionGauge->addLabel(80);
    w->setText("З");
    w->setAngle(0);
    w->setColor(Qt::black);

    QcLabelItem *g_292_5 = mDirectionGauge->addLabel(85);
    g_292_5->setText("292.5");
    g_292_5->setAngle(22.5);
    g_292_5->setColor(QColor("steelblue"));
    g_292_5->setSize(1.5);

    QcLabelItem *nw = mDirectionGauge->addLabel(85);
    nw->setText("СЗ");
    nw->setAngle(45);
    nw->setColor(Qt::darkGray);

    QcLabelItem *g_337_5 = mDirectionGauge->addLabel(85);
    g_337_5->setText("337.5");
    g_337_5->setAngle(67.5);
    g_337_5->setColor(QColor("steelblue"));
    g_337_5->setSize(1.5);

    QcLabelItem *n = mDirectionGauge->addLabel(85);
    n->setText("С");
    n->setAngle(90);
    n->setColor(Qt::black);

    QcLabelItem *g_22_5 = mDirectionGauge->addLabel(85);
    g_22_5->setText("22.5");
    g_22_5->setAngle(112.5);
    g_22_5->setColor(QColor("steelblue"));
    g_22_5->setSize(1.5);

    QcLabelItem *ne = mDirectionGauge->addLabel(85);
    ne->setText("СВ");
    ne->setAngle(135);
    ne->setColor(Qt::darkGray);

    QcLabelItem *g_67_5 = mDirectionGauge->addLabel(85);
    g_67_5->setText("67.5");
    g_67_5->setAngle(157.5);
    g_67_5->setColor(QColor("steelblue"));
    g_67_5->setSize(1.5);

    QcLabelItem *e = mDirectionGauge->addLabel(85);
    e->setText("В");
    e->setAngle(180);
    e->setColor(Qt::black);

    QcLabelItem *g_112_5 = mDirectionGauge->addLabel(85);
    g_112_5->setText("112.5");
    g_112_5->setAngle(202.5);
    g_112_5->setColor(QColor("steelblue"));
    g_112_5->setSize(1.5);

    QcLabelItem *se = mDirectionGauge->addLabel(85);
    se->setText("ЮВ");
    se->setAngle(225);
    se->setColor(Qt::darkGray);

    QcLabelItem *g_157_5 = mDirectionGauge->addLabel(85);
    g_157_5->setText("157.5");
    g_157_5->setAngle(247.5);
    g_157_5->setColor(QColor("steelblue"));
    g_157_5->setSize(1.5);

    QcLabelItem *s = mDirectionGauge->addLabel(85);
    s->setText("Ю");
    s->setAngle(270);
    s->setColor(Qt::black);

    QcLabelItem *g_202_5 = mDirectionGauge->addLabel(85);
    g_202_5->setText("202.5");
    g_202_5->setAngle(292.5);
    g_202_5->setColor(QColor("steelblue"));
    g_202_5->setSize(1.5);

    QcLabelItem *sw = mDirectionGauge->addLabel(85);
    sw->setText("ЮЗ");
    sw->setAngle(315);
    sw->setColor(Qt::darkGray);

    QcLabelItem *g_247_5 = mDirectionGauge->addLabel(85);
    g_247_5->setText("247.5");
    g_247_5->setAngle(337.5);
    g_247_5->setColor(QColor("steelblue"));
    g_247_5->setSize(1.5);

    QcDegreesItem *deg = mDirectionGauge->addDegrees(65);
    deg->setStep(5);
    deg->setMaxDegree(270);
    deg->setMinDegree(-75);
    deg->setColor(Qt::black);

    mDirectionNeedle = mDirectionGauge->addNeedle(65);
    mDirectionNeedle->setNeedle(QcNeedleItem::DiamonNeedle);
    mDirectionNeedle->setColor(Qt::red);
    mDirectionNeedle->setValueRange(0,360);
    mDirectionNeedle->setMaxDegree(360);
    mDirectionNeedle->setMinDegree(0);
    mDirectionGauge->addBackground(3);

    QLabel *lb_direction = new QLabel("Направление ветра\nD,°");
    lb_direction->setAlignment(Qt::AlignHCenter);
    lb_direction->setStyleSheet("font-style: Meiryo UI; font: bold; font-size: 18px;");

    ui->gridLayout_3->addWidget(lb_direction,2,0,1,2);
    ui->gridLayout_3->addWidget(mDirectionGauge,3,1);

    //==========================================================

    mWaterGauge = new QcGaugeWidget;
    mWaterGauge->addArc(55);
    mWaterGauge->addDegrees(65)->setValueRange(0,100);
    mWaterGauge->addValues(80)->setValueRange(0,100);
    QcLabelItem *lab_water = mWaterGauge -> addLabel(50);
    lab_water->setText("0");
    lab_water->setColor("steelblue");
    mWaterNeedle = mWaterGauge -> addNeedle(60);
    mWaterNeedle->setLabel(lab_water);
    mWaterNeedle->setColor(Qt::red);
    mWaterNeedle->setValueRange(0,100);
    mWaterGauge->addBackground(7);

    QLabel *lb_water = new QLabel("Влажность\nr, %");
    lb_water->setAlignment(Qt::AlignHCenter);
    lb_water->setStyleSheet("font-style: Meiryo UI; font: bold; font-size: 18px;");

    ui->gridLayout_3->addWidget(lb_water,2,2);
    ui->gridLayout_3->addWidget(mWaterGauge,3,2);

   //==========================================================

    lb_ugol_wind = new QLabel();
    lb_ugol_wind->setAlignment(Qt::AlignRight);
    lb_ugol_wind->setAlignment(Qt::AlignHCenter);
    lb_ugol_wind->setStyleSheet("font-style: Meiryo UI; font: bold; font-size: 35px; color: steelblue;");
    ui->gridLayout_3->addWidget(lb_ugol_wind, 3, 0);

    QLabel *lb_str = new QLabel();
    ui->gridLayout_3->addWidget(lb_str,4,0,1,3);

    speedwind = 0;
    temperature = 0;
    waterprocent = 0;
    pressure = 0;
    direction = 0;

    mSpeedNeedle->setCurrentValue(speedwind);
    mTempNeedle->setCurrentValue(temperature);
    mWaterNeedle->setCurrentValue(waterprocent);
    mPressureNeedle->setCurrentValue(pressure);
    mDirectionNeedle->setCurrentValue(direction);
    lb_ugol_wind->setText(QString::number(direction,'f',1)+"°");


    QLabel *lb_grafic_T = new QLabel("T,°C");
    lb_grafic_T->setStyleSheet("background-color: dimgrey; color: white; font: bold; font-size: 14px;");
    lb_grafic_T->setMaximumHeight(30);
    lb_grafic_T->setMinimumHeight(30);
    lb_grafic_T->setAlignment(Qt::AlignHCenter);
    ui->gridLayout->addWidget(lb_grafic_T,0,0);

    grafic_T = new QCustomPlot();
    grafic_T->xAxis->setRange(0,1800);
    grafic_T->xAxis->setVisible(false);
    grafic_T->yAxis->setRange(-45,45);
    grafic_T->setMinimumHeight(150);
    ui->gridLayout->addWidget(grafic_T,1,0);

    QLabel *lb_grafic_V = new QLabel("V, м\\с");
    lb_grafic_V->setStyleSheet("background-color: dimgrey; color: white; font: bold; font-size: 14px;");
    lb_grafic_V->setMaximumHeight(30);
    lb_grafic_V->setMinimumHeight(30);
    lb_grafic_V->setAlignment(Qt::AlignHCenter);
    ui->gridLayout->addWidget(lb_grafic_V,2,0);

    grafic_V = new QCustomPlot();
    grafic_V->xAxis->setRange(0,1800);
    grafic_V->xAxis->setVisible(false);
    grafic_V->yAxis->setRange(0,30);
    grafic_V->setMinimumHeight(150);
    ui->gridLayout->addWidget(grafic_V,3,0);

    QLabel *lb_grafic_D = new QLabel("D,°");
    lb_grafic_D->setStyleSheet("background-color: dimgrey; color: white; font: bold; font-size: 14px;");
    lb_grafic_D->setMaximumHeight(30);
    lb_grafic_D->setMinimumHeight(30);
    lb_grafic_D->setAlignment(Qt::AlignHCenter);
    ui->gridLayout->addWidget(lb_grafic_D,4,0);

    grafic_D = new QCustomPlot();
    grafic_D->xAxis->setRange(0,1800);
    grafic_D->xAxis->setVisible(false);
    grafic_D->yAxis->setRange(0,360);
    grafic_D->setMinimumHeight(150);
    ui->gridLayout->addWidget(grafic_D,5,0);

    QLabel *lb_grafic_P = new QLabel("P, мм.рт.");
    lb_grafic_P->setStyleSheet("background-color: dimgrey; color: white; font: bold; font-size: 14px;");
    lb_grafic_P->setMaximumHeight(30);
    lb_grafic_P->setMinimumHeight(30);
    lb_grafic_P->setAlignment(Qt::AlignHCenter);
    ui->gridLayout->addWidget(lb_grafic_P,6,0);

    grafic_P = new QCustomPlot();
    grafic_P->xAxis->setRange(0,1800);
    grafic_P->xAxis->setVisible(false);
    grafic_P->yAxis->setRange(600,1000);
    grafic_P->setMinimumHeight(150);
    ui->gridLayout->addWidget(grafic_P,7,0);

    QLabel *lb_grafic_r = new QLabel("r, %");
    lb_grafic_r->setStyleSheet("background-color: dimgrey; color: white; font: bold; font-size: 14px;");
    lb_grafic_r->setMaximumHeight(25);
    lb_grafic_r->setMinimumHeight(25);
    lb_grafic_r->setAlignment(Qt::AlignHCenter);
    ui->gridLayout->addWidget(lb_grafic_r ,8,0);

    grafic_r = new QCustomPlot();
    grafic_r->xAxis->setRange(0,1800);
    grafic_r->xAxis->setVisible(false);
    grafic_r->yAxis->setRange(0,100);
    grafic_r->setMinimumHeight(150);
    ui->gridLayout->addWidget(grafic_r,9,0);

    grafic_init();

    // ===================================================

    mGrozGauge = new QcGaugeWidget;

    QcLabelItem *w_groz = mGrozGauge->addLabel(95);
    w_groz->setText("З");
    w_groz->setAngle(0);
    w_groz->setColor("black");
    w_groz->setSize(2);

    QcLabelItem *n_groz = mGrozGauge->addLabel(95);
    n_groz->setText("С");
    n_groz->setAngle(90);
    n_groz->setColor("black");
    n_groz->setSize(2);

    QcLabelItem *e_groz = mGrozGauge->addLabel(95);
    e_groz->setText("В");
    e_groz->setAngle(180);
    e_groz->setColor("black");
    e_groz->setSize(2);

    QcLabelItem *s_groz = mGrozGauge->addLabel(95);
    s_groz->setText("Ю");
    s_groz->setAngle(270);
    s_groz->setColor("black");
    s_groz->setSize(2);

    QcBackgroundItem *bkgdeg = mGrozGauge->addBackground(85);
    bkgdeg->clearrColors();
    bkgdeg->addColor(1,Qt::white);

    mSector1 = mGrozGauge->addDegrees(85);
    mSector1->setStep(0.5);
    mSector1->setMaxDegree(135);
    mSector1->setMinDegree(90);
    mSector1->setpointAtstart(0.765);
    mSector1->setpointAtfinish(1);
    mSector1->setColor("white");

    mSector2 = mGrozGauge->addDegrees(85);
    mSector2->setStep(0.5);
    mSector2->setMaxDegree(180);
    mSector2->setMinDegree(135);
    mSector2->setpointAtstart(0.765);
    mSector2->setpointAtfinish(1);
    mSector2->setColor("white");

    mSector3 = mGrozGauge->addDegrees(85);
    mSector3->setStep(0.5);
    mSector3->setMaxDegree(225);
    mSector3->setMinDegree(180);
    mSector3->setpointAtstart(0.765);
    mSector3->setpointAtfinish(1);
    mSector3->setColor("white");

    mSector4 = mGrozGauge->addDegrees(85);
    mSector4->setStep(0.5);
    mSector4->setMaxDegree(270);
    mSector4->setMinDegree(225);
    mSector4->setpointAtstart(0.765);
    mSector4->setpointAtfinish(1);
    mSector4->setColor("white");

    mSector5 = mGrozGauge->addDegrees(85);
    mSector5->setStep(0.5);
    mSector5->setMaxDegree(315);
    mSector5->setMinDegree(270);
    mSector5->setpointAtstart(0.765);
    mSector5->setpointAtfinish(1);
    mSector5->setColor("white");

    mSector6 = mGrozGauge->addDegrees(85);
    mSector6->setStep(0.5);
    mSector6->setMaxDegree(360);
    mSector6->setMinDegree(315);
    mSector6->setpointAtstart(0.765);
    mSector6->setpointAtfinish(1);
    mSector6->setColor("white");

    mSector7 = mGrozGauge->addDegrees(85);
    mSector7->setStep(0.5);
    mSector7->setMaxDegree(45);
    mSector7->setMinDegree(0);
    mSector7->setpointAtstart(0.765);
    mSector7->setpointAtfinish(1);
    mSector7->setColor("white");

    mSector8 = mGrozGauge->addDegrees(85);
    mSector8->setStep(0.5);
    mSector8->setMaxDegree(90);
    mSector8->setMinDegree(45);
    mSector8->setpointAtstart(0.765);
    mSector8->setpointAtfinish(1);
    mSector8->setColor("white");

    mSector9 = mGrozGauge->addDegrees(85);
    mSector9->setStep(0.5);
    mSector9->setMaxDegree(135);
    mSector9->setMinDegree(90);
    mSector9->setpointAtstart(0.536);
    mSector9->setpointAtfinish(0.75);
    mSector9->setColor("white");

    mSector10 = mGrozGauge->addDegrees(85);
    mSector10->setStep(0.5);
    mSector10->setMaxDegree(180);
    mSector10->setMinDegree(135);
    mSector10->setpointAtstart(0.536);
    mSector10->setpointAtfinish(0.75);
    mSector10->setColor("white");

    mSector11 = mGrozGauge->addDegrees(85);
    mSector11->setStep(0.5);
    mSector11->setMaxDegree(225);
    mSector11->setMinDegree(180);
    mSector11->setpointAtstart(0.536);
    mSector11->setpointAtfinish(0.75);
    mSector11->setColor("white");

    mSector12 = mGrozGauge->addDegrees(85);
    mSector12->setStep(0.5);
    mSector12->setMaxDegree(270);
    mSector12->setMinDegree(225);
    mSector12->setpointAtstart(0.536);
    mSector12->setpointAtfinish(0.75);
    mSector12->setColor("white");

    mSector13 = mGrozGauge->addDegrees(85);
    mSector13->setStep(0.5);
    mSector13->setMaxDegree(315);
    mSector13->setMinDegree(270);
    mSector13->setpointAtstart(0.536);
    mSector13->setpointAtfinish(0.75);
    mSector13->setColor("white");

    mSector14 = mGrozGauge->addDegrees(85);
    mSector14->setStep(0.5);
    mSector14->setMaxDegree(360);
    mSector14->setMinDegree(315);
    mSector14->setpointAtstart(0.536);
    mSector14->setpointAtfinish(0.75);
    mSector14->setColor("white");

    mSector15 = mGrozGauge->addDegrees(85);
    mSector15->setStep(0.5);
    mSector15->setMaxDegree(45);
    mSector15->setMinDegree(0);
    mSector15->setpointAtstart(0.536);
    mSector15->setpointAtfinish(0.75);
    mSector15->setColor("white");

    mSector16 = mGrozGauge->addDegrees(85);
    mSector16->setStep(0.5);
    mSector16->setMaxDegree(90);
    mSector16->setMinDegree(45);
    mSector16->setpointAtstart(0.536);
    mSector16->setpointAtfinish(0.75);
    mSector16->setColor("white");

    mSector17 = mGrozGauge->addDegrees(85);
    mSector17->setStep(0.5);
    mSector17->setMaxDegree(135);
    mSector17->setMinDegree(90);
    mSector17->setpointAtstart(0.166);
    mSector17->setpointAtfinish(0.52);
    mSector17->setColor("white");

    mSector18 = mGrozGauge->addDegrees(85);
    mSector18->setStep(0.5);
    mSector18->setMaxDegree(180);
    mSector18->setMinDegree(135);
    mSector18->setpointAtstart(0.166);
    mSector18->setpointAtfinish(0.52);
    mSector18->setColor("white");

    mSector19 = mGrozGauge->addDegrees(85);
    mSector19->setStep(0.5);
    mSector19->setMaxDegree(225);
    mSector19->setMinDegree(180);
    mSector19->setpointAtstart(0.166);
    mSector19->setpointAtfinish(0.52);
    mSector19->setColor("white");

    mSector20 = mGrozGauge->addDegrees(85);
    mSector20->setStep(0.5);
    mSector20->setMaxDegree(270);
    mSector20->setMinDegree(225);
    mSector20->setpointAtstart(0.166);
    mSector20->setpointAtfinish(0.52);
    mSector20->setColor("white");

    mSector21 = mGrozGauge->addDegrees(85);
    mSector21->setStep(0.5);
    mSector21->setMaxDegree(315);
    mSector21->setMinDegree(270);
    mSector21->setpointAtstart(0.166);
    mSector21->setpointAtfinish(0.52);
    mSector21->setColor("white");

    mSector22 = mGrozGauge->addDegrees(85);
    mSector22->setStep(0.5);
    mSector22->setMaxDegree(360);
    mSector22->setMinDegree(270);
    mSector22->setpointAtstart(0.166);
    mSector22->setpointAtfinish(0.52);
    mSector22->setColor("white");

    mSector23 = mGrozGauge->addDegrees(85);
    mSector23->setStep(0.5);
    mSector23->setMaxDegree(45);
    mSector23->setMinDegree(0);
    mSector23->setpointAtstart(0.166);
    mSector23->setpointAtfinish(0.52);
    mSector23->setColor("white");

    mSector24 = mGrozGauge->addDegrees(85);
    mSector24->setStep(0.5);
    mSector24->setMaxDegree(90);
    mSector24->setMinDegree(45);
    mSector24->setpointAtstart(0.166);
    mSector24->setpointAtfinish(0.52);
    mSector24->setColor("white");

    mSector25 = mGrozGauge->addDegrees(85);
    mSector25->setStep(0.5);
    mSector25->setMaxDegree(135);
    mSector25->setMinDegree(90);
    mSector25->setpointAtstart(0);
    mSector25->setpointAtfinish(0.165);
    mSector25->setColor("white");

    mSector26 = mGrozGauge->addDegrees(85);
    mSector26->setStep(0.5);
    mSector26->setMaxDegree(180);
    mSector26->setMinDegree(135);
    mSector26->setpointAtstart(0);
    mSector26->setpointAtfinish(0.165);
    mSector26->setColor("white");

    mSector27 = mGrozGauge->addDegrees(85);
    mSector27->setStep(0.5);
    mSector27->setMaxDegree(225);
    mSector27->setMinDegree(180);
    mSector27->setpointAtstart(0);
    mSector27->setpointAtfinish(0.165);
    mSector27->setColor("white");

    mSector28 = mGrozGauge->addDegrees(85);
    mSector28->setStep(0.5);
    mSector28->setMaxDegree(270);
    mSector28->setMinDegree(225);
    mSector28->setpointAtstart(0);
    mSector28->setpointAtfinish(0.165);
    mSector28->setColor("white");

    mSector29 = mGrozGauge->addDegrees(85);
    mSector29->setStep(0.5);
    mSector29->setMaxDegree(315);
    mSector29->setMinDegree(270);
    mSector29->setpointAtstart(0);
    mSector29->setpointAtfinish(0.165);
    mSector29->setColor("white");

    mSector30 = mGrozGauge->addDegrees(85);
    mSector30->setStep(0.5);
    mSector30->setMaxDegree(360);
    mSector30->setMinDegree(315);
    mSector30->setpointAtstart(0);
    mSector30->setpointAtfinish(0.165);
    mSector30->setColor("white");

    mSector31 = mGrozGauge->addDegrees(85);
    mSector31->setStep(0.5);
    mSector31->setMaxDegree(45);
    mSector31->setMinDegree(0);
    mSector31->setpointAtstart(0);
    mSector31->setpointAtfinish(0.165);
    mSector31->setColor("white");

    mSector32 = mGrozGauge->addDegrees(85);
    mSector32->setStep(0.5);
    mSector32->setMaxDegree(90);
    mSector32->setMinDegree(45);
    mSector32->setpointAtstart(0);
    mSector32->setpointAtfinish(0.165);
    mSector32->setColor("white");

    mGrozGauge->addBackground(1);
    ui->gridLayout_groz->addWidget(mGrozGauge);

    QcArcItem *k1 = mGrozGauge->addArc(20);
    k1->setKof(25);
    k1->setColor("dimgray");
    QcArcItem *k2 = mGrozGauge->addArc(40);
    k2->setKof(25);
    k2->setColor("dimgray");
    QcArcItem *k3 = mGrozGauge->addArc(70);
    k3->setKof(25);
    k3->setColor("dimgray");
    QcArcItem *k4 = mGrozGauge->addArc(86);
    k4->setKof(25);
    k4->setColor("dimgray");

    QcDegreesItem *deg1 = mGrozGauge->addDegrees(85);
    deg1->setStep(45);
    deg1->setMaxDegree(100);
    deg1->setMinDegree(0);
    deg1->setpointAtstart(0);
    deg1->setpointAtfinish(1);
    deg1->setColor("dimgray");

    QcDegreesItem *deg2 = mGrozGauge->addDegrees(85);
    deg2->setStep(45);
    deg2->setMaxDegree(190);
    deg2->setMinDegree(90);
    deg2->setpointAtstart(0);
    deg2->setpointAtfinish(1);
    deg2->setColor("dimgray");

    QcDegreesItem *deg3 = mGrozGauge->addDegrees(85);
    deg3->setStep(45);
    deg3->setMaxDegree(280);
    deg3->setMinDegree(180);
    deg3->setpointAtstart(0);
    deg3->setpointAtfinish(1);
    deg3->setColor("dimgray");

    QcDegreesItem *deg4 = mGrozGauge->addDegrees(85);
    deg4->setStep(45);
    deg4->setMaxDegree(370);
    deg4->setMinDegree(270);
    deg4->setpointAtstart(0);
    deg4->setpointAtfinish(1);
    deg4->setColor("dimgray");

    QcLabelItem *s_zona1 = mGrozGauge->addLabel(24);
    s_zona1->setText("9");
    s_zona1->setAngle(190);
    s_zona1->setColor("black");
    s_zona1->setSize(3.5);

    QcLabelItem *s_zona2 = mGrozGauge->addLabel(45);
    s_zona2->setText("19");
    s_zona2->setAngle(185.2);
    s_zona2->setColor("black");
    s_zona2->setSize(3.5);

    QcLabelItem *s_zona3 = mGrozGauge->addLabel(75);
    s_zona3->setText("56");
    s_zona3->setAngle(182.9);
    s_zona3->setColor("black");
    s_zona3->setSize(3.5);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 9; j++)
        mas[i][j] = 0;
    }

    mModel = new QStandardItemModel(ui->tableView);
    mModel->setHorizontalHeaderLabels(QStringList()<<"0° - 45°"<<"45° - 90°"<<"90° - 135°"<<"135° - 180°"<<"180° - 225°"<<"225° - 270°"<<"270° - 315°"<<"315° - 360°");
    mModel->setVerticalHeaderLabels(QStringList()<<"00 - 09 км"<<"09 - 19 км"<<"19 - 56 км"<<"  >56 км");

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 8; j++)
        {
        chislo = new QStandardItem(QString::number(mas[i][j]));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(i,j, chislo);
        }
    }

    ui->tableView->setModel(mModel);
    ui->tableView->show();

    ui->tableView->verticalHeader()->setStyleSheet("background-color: dimgrey; color: white;");
    ui->tableView->horizontalHeader()->setStyleSheet("background-color: dimgrey; color: white;");

    mModel_2 = new QStandardItemModel(ui->tableView_2);
    mModel_2 ->setHorizontalHeaderLabels(QStringList()<<"0° - 45°"<<"45° - 90°"<<"90° - 135°"<<"135° - 180°"<<"180° - 225°"<<"225° - 270°"<<"270° - 315°"<<"315° - 360°"<<"Всего");
    mModel_2->setVerticalHeaderLabels(QStringList()<<"00 - 09 км"<<"09 - 19 км"<<"19 - 56 км"<<"  >56 км"<<"Всего");

    //QFile inputFile(QDir::currentPath() + "//" + "config_porog.txt");
    QFile inputFile("//home//user//weather//weather_master//config_porog.txt");
    int g = 0;

    if(inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        in.setCodec("cp1251");

        while(!in.atEnd())
        {
            QString line = in.readLine();

                QStringList list = line.split(QRegExp("\\s+"), QString::SkipEmptyParts);

                for(int i = 0; i < list.count(); i++)
                {
                    QString str = list[i];
                    int ch = str.toInt();
                    chislo_2 = new QStandardItem(QString::number(ch));
                    mModel_2->setItem(g,i,chislo_2);

                    mas[g][i] = ch;
                }
            g++;
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 9; j++)
        {
        chislo_2 = new QStandardItem(QString::number(mas[i][j]));
        chislo_2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel_2->setItem(i,j, chislo_2);
        }
    }

    ui->tableView_2->setModel(mModel_2);
    ui->tableView_2->show();

    ui->tableView_2->verticalHeader()->setStyleSheet("background-color: dimgrey; color: white;");
    ui->tableView_2->verticalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableView_2->verticalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableView_2->verticalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->tableView_2->verticalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);
    ui->tableView_2->verticalHeader()->setSectionResizeMode(4,QHeaderView::Stretch);
    ui->tableView_2->horizontalHeader()->setStyleSheet("background-color: dimgrey; color: white;");
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(4,QHeaderView::Stretch);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(5,QHeaderView::Stretch);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(6,QHeaderView::Stretch);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(7,QHeaderView::Stretch);

    otvet_groz->clear();

    for(int i = 0; i < 32; i++)
    {
        mas_razr[i] = 0;
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 9; j++)
        mas_porog[i][j] = 0;
    }

    ui->lb_groza->setVisible(false);
    ui->lb_pict_groza->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updTime()
{
    ++sec;

    int hh = 0;
    int mm = 0;
    int ss = 0;

    hh = sec / 3600;
    mm = (sec - hh * 3600) / 60;
    ss = sec - hh * 3600 - mm * 60;

    ui->lb_time_session->setText(QString::number(hh) + " ч " + QString::number(mm) + " м " + QString::number(ss) + " с ");

    QTime time_now = QTime::currentTime();
    ui->lb_time->setText(time_now.toString("hh:mm:ss"));

    srand(time(0));//test
/*
    for(int i = 0; i < 32; i++)
    {
        mas_razr[i] = 0 + rand() % 32;
    }

    for(int i = 0; i < 32; i++)
    {
        drawSector(i+1, mas_razr[i]);
    }
*/
    int p = 0;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 9; j++)
        p += mas_porog[i][j];
    }

    if(p > 0)
    {
        ui->lb_groza->setVisible(true);
        ui->lb_pict_groza->setVisible(true);
    }
    else
    {
        ui->lb_groza->setVisible(false);
        ui->lb_pict_groza->setVisible(false);
    }
}

void MainWindow::drawSector(int n_sector, int n_molniy)
{
    QString Color = "";

    if(0 < n_molniy && n_molniy < 6)
        Color = "lightgreen";
    else if(5 < n_molniy && n_molniy < 11)
        Color = "yellow";
    else if(10 < n_molniy)
        Color = "tomato";
    else
        Color = "white";

    switch(n_sector)
    {
    case 1:
        mSector1->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(0,0, chislo);
        mas_razr[0] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(0,0)).toInt()){
        mModel->setData(mModel->index(0,0),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(0,0),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[0][0] = 1;
        }
        else {
        mModel->setData(mModel->index(0,0),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(0,0),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[0][0] = 0;
        }
        break;
    case 2:
        mSector2->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(0,1, chislo);
        mas_razr[1] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(0,1)).toInt()) {
        mModel->setData(mModel->index(0,1),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(0,1),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[0][1] = 1;
        }
        else {
        mModel->setData(mModel->index(0,1),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(0,1),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[0][1] = 0;
        }
        break;
    case 3:
        mSector3->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(0,2, chislo);
        mas_razr[2] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(0,2)).toInt()){
        mModel->setData(mModel->index(0,2),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(0,2),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[0][2] = 1;
        }
        else {
        mModel->setData(mModel->index(0,2),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(0,2),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[0][2] = 0;
        }
        break;
    case 4:
        mSector4->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(0,3, chislo);
        mas_razr[3] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(0,3)).toInt()){
        mModel->setData(mModel->index(0,3),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(0,3),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[0][3] = 1;
        }
        else {
        mModel->setData(mModel->index(0,3),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(0,3),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[0][3] = 0;
        }
        break;
    case 5:
        mSector5->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(0,4, chislo);
        mas_razr[4] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(0,4)).toInt()) {
        mModel->setData(mModel->index(0,4),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(0,4),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[0][4] = 1;
        }
        else {
        mModel->setData(mModel->index(0,4),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(0,4),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[0][4] = 0;
        }
        break;
    case 6:
        mSector6->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(0,5, chislo);
        mas_razr[5] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(0,5)).toInt()){
        mModel->setData(mModel->index(0,5),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(0,5),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[0][5] = 1;
        }
        else {
        mModel->setData(mModel->index(0,5),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(0,5),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[0][5] = 0;
        }
        break;
    case 7:
        mSector7->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(0,6, chislo);
        mas_razr[6] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(0,6)).toInt()) {
        mModel->setData(mModel->index(0,6),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(0,6),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[0][6] = 1;
        }
        else {
        mModel->setData(mModel->index(0,6),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(0,6),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[0][6] = 0;
        }
        break;
    case 8:
        mSector8->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(0,7, chislo);
        mas_razr[7] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(0,7)).toInt()) {
        mModel->setData(mModel->index(0,7),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(0,7),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[0][7] = 1;
        }
        else {
        mModel->setData(mModel->index(0,7),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(0,7),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[0][7] = 0;
        }
        break;
    case 9:
        mSector9->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(1,0, chislo);
        mas_razr[8] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(1,0)).toInt()){
        mModel->setData(mModel->index(1,0),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(1,0),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[1][0] = 1;
        }
        else {
        mModel->setData(mModel->index(1,0),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(1,0),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[1][0] = 0;
        }
        break;
    case 10:
        mSector10->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(1,1, chislo);
        mas_razr[9] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(1,1)).toInt()){
        mModel->setData(mModel->index(1,1),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(1,1),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[1][1] = 1;
        }
        else{
        mModel->setData(mModel->index(1,1),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(1,1),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[1][1] = 0;
        }
        break;
    case 11:
        mSector11->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(1,2, chislo);
        mas_razr[10] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(1,2)).toInt()){
        mModel->setData(mModel->index(1,2),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(1,2),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[1][2] = 1;
        }
        else {
        mModel->setData(mModel->index(1,2),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(1,2),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[1][2] = 0;
        }
        break;
    case 12:
        mSector12->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(1,3, chislo);
        mas_razr[11] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(1,3)).toInt()){
        mModel->setData(mModel->index(1,3),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(1,3),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[1][3] = 1;
        }
        else {
        mModel->setData(mModel->index(1,3),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(1,3),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[1][3] = 0;
        }
        break;
    case 13:
        mSector13->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(1,4, chislo);
        mas_razr[12] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(1,4)).toInt()){
        mModel->setData(mModel->index(1,4),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(1,4),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[1][4] = 1;
        }
        else {
        mModel->setData(mModel->index(1,4),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(1,4),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[1][4] = 0;
        }
        break;
    case 14:
        mSector14->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(1,5, chislo);
        mas_razr[13] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(1,5)).toInt()) {
        mModel->setData(mModel->index(1,5),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(1,5),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[1][5] = 1;
        }
        else {
        mModel->setData(mModel->index(1,5),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(1,5),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[1][5] = 0;
        }
        break;
    case 15:
        mSector15->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(1,6, chislo);
        mas_razr[14] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(1,6)).toInt()) {
        mModel->setData(mModel->index(1,6),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(1,6),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[1][6] = 1;
        }
        else {
        mModel->setData(mModel->index(1,6),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(1,6),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[1][6] = 0;
        }
        break;
    case 16:
        mSector16->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(1,7, chislo);
        mas_razr[15] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(1,7)).toInt()){
        mModel->setData(mModel->index(1,7),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(1,7),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[1][7] = 1;
        }
        else {
        mModel->setData(mModel->index(1,7),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(1,7),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[1][7] = 0;
        }
        break;
    case 17:
        mSector17->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(2,0, chislo);
        mas_razr[16] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(2,0)).toInt()){
        mModel->setData(mModel->index(2,0),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(2,0),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[2][0] = 1;
        }
        else {
        mModel->setData(mModel->index(2,0),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(2,0),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[2][0] = 0;
        }
        break;
    case 18:
        mSector18->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(2,1, chislo);
        mas_razr[17] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(2,1)).toInt()){
        mModel->setData(mModel->index(2,1),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(2,1),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[2][1] = 1;
        }
        else {
        mModel->setData(mModel->index(2,1),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(2,1),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[2][1] = 0;
        }
        break;
    case 19:
        mSector19->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(2,2, chislo);
        mas_razr[18] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(2,2)).toInt()){
        mModel->setData(mModel->index(2,2),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(2,2),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[2][2] = 1;
        }
        else {
        mModel->setData(mModel->index(2,2),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(2,2),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[2][2] = 0;
        }
        break;
    case 20:
        mSector20->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(2,3, chislo);
        mas_razr[19] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(2,3)).toInt()) {
        mModel->setData(mModel->index(2,3),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(2,3),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[2][3] = 1;
        }
        else {
        mModel->setData(mModel->index(2,3),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(2,3),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[2][3] = 0;
        }
        break;
    case 21:
        mSector21->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(2,4, chislo);
        mas_razr[20] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(2,4)).toInt()){
        mModel->setData(mModel->index(2,4),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(2,4),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[2][4] = 1;
        }
        else {
        mModel->setData(mModel->index(2,4),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(2,4),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[2][4] = 0;
        }
        break;
    case 22:
        mSector22->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(2,5, chislo);
        mas_razr[21] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(2,5)).toInt()) {
        mModel->setData(mModel->index(2,5),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(2,5),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[2][5] = 1;
        }
        else {
        mModel->setData(mModel->index(2,5),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(2,5),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[2][5] = 0;
        }
        break;
    case 23:
        mSector23->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(2,6, chislo);
        mas_razr[22] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(2,6)).toInt()){
        mModel->setData(mModel->index(2,6),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(2,6),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[2][6] = 1;
        }
        else {
        mModel->setData(mModel->index(2,6),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(2,6),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[2][6] = 0;
        }
        break;
    case 24:
        mSector24->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(2,7, chislo);
        mas_razr[23] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(2,7)).toInt()){
        mModel->setData(mModel->index(2,7),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(2,7),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[2][7] = 1;
        }
        else {
        mModel->setData(mModel->index(2,7),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(2,7),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[2][7] = 0;
        }
        break;
    case 25:
        mSector25->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(3,0, chislo);
        mas_razr[24] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(3,0)).toInt()) {
        mModel->setData(mModel->index(3,0),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(3,0),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[3][0] = 1;
        }
        else {
        mModel->setData(mModel->index(3,0),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(3,0),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[3][0] = 0;
        }
        break;
    case 26:
        mSector26->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(3,1, chislo);
        mas_razr[25] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(3,1)).toInt()) {
        mModel->setData(mModel->index(3,1),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(3,1),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[3][1] = 1;
        }
        else {
        mModel->setData(mModel->index(3,1),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(3,1),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[3][1] = 0;
        }
        break;
    case 27:
        mSector27->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(3,2, chislo);
        mas_razr[26] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(3,2)).toInt()) {
        mModel->setData(mModel->index(3,2),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(3,2),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[3][2] = 1;
        }
        else {
        mModel->setData(mModel->index(3,2),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(3,2),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[3][2] = 0;
        }
        break;
    case 28:
        mSector28->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(3,3, chislo);
        mas_razr[27] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(3,3)).toInt()){
        mModel->setData(mModel->index(3,3),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(3,3),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[3][3] = 1;
        }
        else{
        mModel->setData(mModel->index(3,3),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(3,3),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[3][3] = 0;
        }
        break;
    case 29:
        mSector29->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(3,4, chislo);
        mas_razr[28] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(3,4)).toInt()){
        mModel->setData(mModel->index(3,4),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(3,4),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[3][4] = 1;
        }
        else {
        mModel->setData(mModel->index(3,4),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(3,4),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[3][4] = 0;
        }
        break;
    case 30:
        mSector30->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(3,5, chislo);
        mas_razr[29] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(3,6)).toInt()){
        mModel->setData(mModel->index(3,5),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(3,5),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[3][5] = 1;
        }
        else{
        mModel->setData(mModel->index(3,5),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(3,5),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[3][5] = 0;
        }
        break;
    case 31:
        mSector31->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(3,6, chislo);
        mas_razr[30] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(3,6)).toInt()){
        mModel->setData(mModel->index(3,6),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(3,6),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[3][6] = 1;
        }
        else {
        mModel->setData(mModel->index(3,6),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(3,6),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[3][6] = 0;
        }
        break;
    case 32:
        mSector32->setColor(Color);
        chislo = new QStandardItem(QString::number(n_molniy));
        chislo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        mModel->setItem(3,7, chislo);
        mas_razr[31] = n_molniy;

        if(n_molniy > mModel_2->data(mModel_2->index(3,7)).toInt()){
        mModel->setData(mModel->index(3,7),QBrush(Qt::red),Qt::BackgroundRole);
        mModel->setData(mModel->index(3,7),QBrush(Qt::white),Qt::ForegroundRole);
        mas_porog[3][7] = 1;
        }
        else {
        mModel->setData(mModel->index(3,7),QBrush(Qt::white),Qt::BackgroundRole);
        mModel->setData(mModel->index(3,7),QBrush(Qt::black),Qt::ForegroundRole);
        mas_porog[3][7] = 0;
        }
        break;
    default:
        qDebug()<<"Сектор не найден!";
        break;
    }

    sum0_9 = 0;
    sum9_19 = 0;
    sum19_56 = 0;
    sum56 = 0;
    sum_all = 0;

    for(int i = 0; i < 32; i++)
    {
        if(i < 8)
        sum0_9 += mas_razr[i];
        else if(7 < i && i < 16)
        sum9_19 += mas_razr[i];
        else if(15 < i && i < 24)
        sum19_56 += mas_razr[i];
        else if(23 < i && i < 32)
        sum56 += mas_razr[i];
    }

    sum_all = sum0_9 + sum9_19 + sum19_56 + sum56;

    ui->lb_zona1->setText(QString::number(sum0_9));
    ui->lb_zona2->setText(QString::number(sum9_19));
    ui->lb_zona3->setText(QString::number(sum19_56));
    ui->lb_zona4->setText(QString::number(sum56));
    ui->lb_zona_sum->setText(QString::number(sum_all));

    if(sum0_9 > 0)
    ui->lb_status->setText("Грозы в опасной близости");
    else
    ui->lb_status->setText("Поблизости гроз нет");
}

void MainWindow::grafic_init()
{
    x.push_back(0);

    grafic_T->addGraph(grafic_T->xAxis, grafic_T->yAxis);
    graf_T_y.push_back(0);
    grafic_T->graph()->setPen(QPen(Qt::red, 2));
    grafic_T->graph()->setData(x,graf_T_y);
    grafic_T->replot();

    grafic_V->addGraph(grafic_V->xAxis, grafic_V->yAxis);
    graf_V_y.push_back(0);
    grafic_V->graph()->setPen(QPen(Qt::red, 2));
    grafic_V->graph()->setData(x,graf_V_y);
    grafic_V->replot();

    grafic_D->addGraph(grafic_D->xAxis, grafic_D->yAxis);
    graf_D_y.push_back(0);
    grafic_D->graph()->setPen(QPen(Qt::red, 2));
    grafic_D->graph()->setData(x,graf_D_y);
    grafic_D->replot();

    grafic_P->addGraph(grafic_P->xAxis, grafic_P->yAxis);
    graf_P_y.push_back(0);
    grafic_P->graph()->setPen(QPen(Qt::red, 2));
    grafic_P->graph()->setData(x,graf_P_y);
    grafic_P->replot();

    grafic_r->addGraph(grafic_r->xAxis, grafic_r->yAxis);
    graf_r_y.push_back(0);
    grafic_r->graph()->setPen(QPen(Qt::red, 2));
    grafic_r->graph()->setData(x,graf_r_y);
    grafic_r->replot();
}

void MainWindow::grafic_change(double T, double V, double P, double D, double r)
{
    if(graf_i == 1800)
    {
    x.push_back(++graf_i);
    grafic_T->graph(0)->setData(x, graf_T_y);
    grafic_T->replot();

    grafic_V->graph(0)->setData(x, graf_V_y);
    grafic_V->replot();

    grafic_P->graph(0)->setData(x, graf_P_y);
    grafic_P->replot();

    grafic_D->graph(0)->setData(x, graf_D_y);
    grafic_D->replot();

    grafic_r->graph(0)->setData(x, graf_r_y);
    grafic_r->replot();

    x.clear();

    graf_T_y.clear();
    graf_T_y.push_back(T);

    graf_V_y.clear();
    graf_V_y.push_back(V);

    graf_P_y.clear();
    graf_P_y.push_back(P);

    graf_D_y.clear();
    graf_D_y.push_back(D);

    graf_r_y.clear();
    graf_r_y.push_back(r);

    x.push_back(graf_i = 0);
    x.push_back(++graf_i);
    }
    else
    {
    x.push_back(++graf_i);
    }

    graf_T_y.push_back(T);
    grafic_T->graph(0)->setData(x, graf_T_y);
    grafic_T->replot();

    graf_V_y.push_back(V);
    grafic_V->graph(0)->setData(x, graf_V_y);
    grafic_V->replot();

    graf_P_y.push_back(P);
    grafic_P->graph(0)->setData(x, graf_P_y);
    grafic_P->replot();

    graf_D_y.push_back(D);
    grafic_D->graph(0)->setData(x, graf_D_y);
    grafic_D->replot();

    graf_r_y.push_back(r);
    grafic_r->graph(0)->setData(x, graf_r_y);
    grafic_r->replot();
}

QByteArray MainWindow::bitsToBytes(QBitArray bits)
{
    QByteArray bytes;
    QDataStream stream(&bytes, QIODevice::WriteOnly);
    stream << bits;
    return bytes;
}

void MainWindow::findPort()
{
    ui->comboBox_port->clear();
    ui->comboBox_port_groz->clear();

        const auto infos = QSerialPortInfo::availablePorts();

        for (const QSerialPortInfo &info : infos)
        {
            QStringList list;
            list << info.portName();
            ui->comboBox_port->addItem(list.first());
            ui->comboBox_port_groz->addItem(list.first());
        }
 }

void MainWindow::updatePortsList()
{
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();

    if (ports.count() != ports_count)
    {
        ports_count = ports.count();
        ui->comboBox_port->clear();

        for (int i = 0; i < ports_count; i++)
            ui->comboBox_port->addItem(ports.at(i).portName());
    }
}

QByteArray MainWindow::convertFloatToValues(float f)
{
    QByteArray array(reinterpret_cast<const char*>(&f), sizeof(f));
    return array;
}

float MainWindow::convertArrayToFloat(QByteArray array_bytes, quint8 position)
{
    QByteArray tmp;

    tmp[0] = array_bytes[position];
    tmp[1] = array_bytes[position+1];
    tmp[2] = array_bytes[position+2];
    tmp[3] = array_bytes[position+3];
    float f;
    if (tmp.size() >= sizeof(f))
    f = *reinterpret_cast<const float*>(tmp.data());
    qDebug()<<f;
    return f;
}

void MainWindow::updateRegisters()
{
    int time = 1;

    if(ui->radioButton->isChecked())
    time = ui->comboBox->currentText().toUInt()*60;

    send(time,1);
    send(time,2);
    send(time,3);
    send(time,4);
    send(time,5);
}

void MainWindow::send(quint8 time, quint8 command)
{
    QByteArray w;

    w[0] = 170;//AA
    w[1] = 85;//55
    w[2] = loByte(time);
    w[3] = hiByte(time);
    w[4] = command;
    w[5] = 0;
    w[6] = 0;
    w[7] = 0;
    w[8] = 0;
    w[9] = 0;

    quint8 hash = 0;

    for(int i = 2; i < w.length(); i++)
    {
        hash ^= w[i];
    }

    w[10] = hash;

    if (modnet->isConnected())
    {
        QString start = "\n*КОМАНДА*\n";
        QString s0 = "Время усреднения: " + QString::number(time);
        QString s1 = "Код функции: " + QString::number(command);
        QString s2 = "Контрольная сумма: " + QString::number(hash);
        logPring(start + s0 + "||" + s1 + "||" + s2);

        modnet->sendData(w);
    }

}


void MainWindow::config_init()
{
    /*
    double con = graf_i+0.2;
    grafic_change(con);*/

    config_form *f = new config_form;
    f->show();
}

void MainWindow::onConnectionRelease()
{
    if (modnet->isConnected())
    {
        modnet->closeConnection();

        ui->pushButton_connect->setText("Подключить");
        ui->pushButton_connect->setStyleSheet("background-color: green; color: white;");
        logPring("Устройство отключено");
    }
    else
    {
        serial_config_t sp_config;

        sp_config.portName = ui->comboBox_port->currentText();
        sp_config.baudrate = 57600;
        sp_config.dataBits = 8;
        sp_config.stopBits = 1;
        sp_config.parity = "None";

        modnet->init(sp_config);
        modnet->openConnection();

        ui->pushButton_connect->setText("Отключить");
        ui->pushButton_connect->setStyleSheet("background-color: red; color: white;");

        logPring("Устройство подключено");
    }
    ui->radioButton->setFocus();
}


void MainWindow::onConnectionRelease_groz()
{
    if (modnet_groz->isConnected())
    {
    modnet_groz->closeConnection();

    ui->pushButton_connect_groz->setText("Подключить");
    ui->pushButton_connect_groz->setStyleSheet("background-color: green; color: white;");
    ui->lb_infoGroz->setText("Отключен");
    }
    else
    {
    serial_config_t sp_config;

    sp_config.portName = ui->comboBox_port_groz->currentText();
    sp_config.baudrate = 600;
    sp_config.dataBits = 8;
    sp_config.stopBits = 1;
    sp_config.parity = "None";

    modnet_groz->init(sp_config);
    modnet_groz->openConnection();

    ui->pushButton_connect_groz->setText("Отключить");
    ui->pushButton_connect_groz->setStyleSheet("background-color: red; color: white;");

    ui->lb_infoGroz->setText("Включен");
    }
    ui->lb_status->setFocus();
}


void MainWindow::logPring(QString msg)
{
    ui->ptSystemLog->appendPlainText(msg);
}

void MainWindow::onApplicationQuit()
{
    if (modnet->isConnected())
        modnet->closeConnection();

    if (modnet_groz->isConnected())
        modnet_groz->closeConnection();

    QApplication::quit();
}


void MainWindow::up(QByteArray arr)
{
    otvet->append(arr);
    qDebug()<<otvet->length();

    if(otvet->length() == 55)
    {
    QByteArray array = *otvet;

    double T = (double)convertArrayToFloat(array, 17);
    double V = (double)convertArrayToFloat(array, 50);
    double P = (double)convertArrayToFloat(array, 6);
    double D = (double)convertArrayToFloat(array, 39) + 90;
    double r = (double)convertArrayToFloat(array, 28);

    mPressureNeedle->setCurrentValue(P);
    mTempNeedle->setCurrentValue(T);
    mWaterNeedle->setCurrentValue(r);
    mDirectionNeedle->setCurrentValue(D);
    lb_ugol_wind->setText(QString::number(convertArrayToFloat(array, 39),'f',1)+"°");
    mSpeedNeedle->setCurrentValue(V);

    grafic_change(T,V,P,D-90,r);

    QString otv_start = "\n*ОТВЕТ*\n";
    QString o1 = "V = "+ QString::number(convertArrayToFloat(array, 50));
    QString o2 = "T = "+ QString::number(convertArrayToFloat(array, 17));
    QString o3 = "P = "+ QString::number(convertArrayToFloat(array, 6));
    QString o4 = "W = "+ QString::number(convertArrayToFloat(array, 28));
    QString o5 = "D = "+ QString::number(convertArrayToFloat(array, 39));

    logPring(otv_start + o1 + "||" + o2 + "||" + o3  + "||" + o4  + "||" + o5);

    QDateTime time = QDateTime::currentDateTime();

    QSqlQuery query1 = QSqlQuery(db);

    QString sql_1 = ("INSERT INTO amk (datatime_write, v, t, p, w, d) "
                " VALUES "
                "('" + time.toString("dd-MM-yyyy hh:mm:ss") + "'," + QString::number(convertArrayToFloat(array, 50)) + "," + QString::number(convertArrayToFloat(array, 17)) + ","
                + QString::number(convertArrayToFloat(array, 6)) + "," + QString::number(convertArrayToFloat(array, 28)) + "," + QString::number(convertArrayToFloat(array, 39)) +")");

    qDebug()<<sql_1;

    query1.exec(sql_1);

    otvet->clear();
    }
}

void MainWindow::up_groz(QByteArray arr)
{
    otvet_groz->append(arr);
    //qDebug()<<otvet_groz->length();

    QByteArray array = *otvet_groz;

    if(otvet_groz->length() >= 50)
    {
        //qDebug()<<"usl1";
    for(int i = 0; i < otvet_groz->length(); i++)
    {
        if((((quint8)array[i] == 71 && (quint8)array[i+1] == 68) && ((quint8)array[i+2] == 65 && (quint8)array[i+3] == 49)) && (((quint8)array[i+33] != 71 && (quint8)array[i+34] != 68) && ((quint8)array[i+35] != 65 && (quint8)array[i+36] != 49)))
        {
            //qDebug()<<"usl2";
            if(i + 49 <= array.length())
            {
                //qDebug()<<"usl3";

                QString error = "0";

                if(getBit(array[i+7],2)) {
                ui->tbrowser->append("Ошибка ПЗУ контроллера");
                error += " 3";
                }

                if(getBit(array[i+7],3)){
                ui->tbrowser->append("Неверный сигнал с усилителя по оси X");
                error += " 4";
                }
                if(getBit(array[i+7],4)){
                ui->tbrowser->append("Неверный сигнал с усилителя по оси Y");
                error += " 5";
                }
                if(getBit(array[i+7],5)){
                ui->tbrowser->append("Неверный сигнал с усилителя по оси Z");
                error += " 6";
                }
                if(getBit(array[i+7],6)){
                ui->tbrowser->append("Превышен уровень шумов");
                error += " 7";
                }
                if(getBit(array[i+7],7)){
                ui->tbrowser->append("Признак критичной ошибки");
                error += " 8";
                }
                //0-45
                drawSector(1, (quint8)array[i+8]);
                drawSector(9, (quint8)array[i+9]);
                drawSector(17, (quint8)array[i+10]);
                drawSector(25, (quint8)array[i+11]);
                //45-90
                drawSector(2, (quint8)array[i+12]);
                drawSector(10, (quint8)array[i+13]);
                drawSector(18, (quint8)array[i+14]);
                drawSector(26, (quint8)array[i+15]);
                //90-135
                drawSector(3, (quint8)array[i+16]);
                drawSector(11, (quint8)array[i+17]);
                drawSector(19, (quint8)array[i+18]);
                drawSector(27, (quint8)array[i+19]);
                //135-180
                drawSector(4, (quint8)array[i+20]);
                drawSector(12, (quint8)array[i+21]);
                drawSector(20, (quint8)array[i+22]);
                drawSector(28, (quint8)array[i+23]);
                //180-225
                drawSector(5, (quint8)array[i+24]);
                drawSector(13, (quint8)array[i+25]);
                drawSector(21, (quint8)array[i+26]);
                drawSector(29, (quint8)array[i+27]);
                //225-270
                drawSector(6, (quint8)array[i+28]);
                drawSector(14, (quint8)array[i+29]);
                drawSector(22, (quint8)array[i+30]);
                drawSector(30, (quint8)array[i+31]);
                //270-315
                drawSector(7, (quint8)array[i+32]);
                drawSector(15, (quint8)array[i+33]);
                drawSector(23, (quint8)array[i+34]);
                drawSector(31, (quint8)array[i+35]);
                //315-360
                drawSector(8, (quint8)array[i+36]);
                drawSector(16,(quint8)array[i+37]);
                drawSector(24,(quint8)array[i+38]);
                drawSector(32,(quint8)array[i+39]);

                QString str = "";

                for(int j = i; j < i+50; j++)
                {
                    str += " | "+QString::number((quint8)array[j]);
                }
                qDebug()<<str;

                QDateTime time = QDateTime::currentDateTime();

                if(db.open())
                {
                QSqlQuery query2 = QSqlQuery(db);

                QString sql_2 = ("INSERT INTO gda_1(datatime_write, cod_error, s_0_9_0_45,s_9_19_0_45,s_19_56_0_45,s_56_0_45,"
                               "s_0_9_45_90,s_9_19_45_90,s_19_56_45_90,s_56_45_90,"
                               "s_0_9_90_135,s_9_19_90_135,s_19_56_90_135,s_56_90_135,"
                               "s_0_9_135_180,s_9_19_135_180,s_19_56_135_180,s_56_135_180,"
                               "s_0_9_180_225,s_9_19_180_225,s_19_56_180_225,s_56_180_225,"
                               "s_0_9_225_270,s_9_19_225_270,s_19_56_225_270,s_56_225_270,"
                               "s_0_9_270_315,s_9_19_270_315,s_19_56_270_315,s_56_270_315,"
                               "s_0_9_315_360,s_9_19_315_360,s_19_56_315_360,s_56_315_360,interval_count,all_count,sound_level) "
                            " VALUES "
                            "('" + time.toString("dd-MM-yyyy hh:mm:ss") + "','" + error + "'," + QString::number((quint8)array[i+8])+ "," + QString::number((quint8)array[i+9]) + "," + QString::number((quint8)array[i+10]) + "," + QString::number((quint8)array[i+11]) + ","
                            + QString::number((quint8)array[i+12]) + ","  + QString::number((quint8)array[i+13]) +  ","  + QString::number((quint8)array[i+14]) + ","  + QString::number((quint8)array[i+15]) + ","
                            + QString::number((quint8)array[i+16]) + ","  + QString::number((quint8)array[i+17]) +  ","  + QString::number((quint8)array[i+18]) + ","  + QString::number((quint8)array[i+19]) + ","
                            + QString::number((quint8)array[i+20]) + ","  + QString::number((quint8)array[i+21]) +  ","  + QString::number((quint8)array[i+22]) + ","  + QString::number((quint8)array[i+23]) + ","
                            + QString::number((quint8)array[i+24]) + ","  + QString::number((quint8)array[i+25]) +  ","  + QString::number((quint8)array[i+26]) + ","  + QString::number((quint8)array[i+27]) + ","
                            + QString::number((quint8)array[i+28]) + ","  + QString::number((quint8)array[i+29]) +  ","  + QString::number((quint8)array[i+30]) + ","  + QString::number((quint8)array[i+31]) + ","
                            + QString::number((quint8)array[i+32]) + ","  + QString::number((quint8)array[i+33]) +  ","  + QString::number((quint8)array[i+34]) + ","  + QString::number((quint8)array[i+35]) + ","
                            + QString::number((quint8)array[i+36]) + ","  + QString::number((quint8)array[i+37]) +  ","  + QString::number((quint8)array[i+38]) + ","  + QString::number((quint8)array[i+39]) + ","
                            + QString::number(word(array[i+40],array[i+41]))+ "," + QString::number(word(array[i+42],array[i+43])) + "," + QString::number(word(array[i+44],array[i+45])) + ")");

                qDebug()<<sql_2;

                query2.exec(sql_2);
                }
                else
                {
                    qDebug()<<"запись в файл";
                    QString file_str = "";

                    file_str = time.toString("dd-MM-yyyy hh:mm:ss") + " | " + error + " |s1: " + QString::number((quint8)array[i+8])+ " |s2: " + QString::number((quint8)array[i+9]) + " |s3: " + QString::number((quint8)array[i+10]) + " |s4: " + QString::number((quint8)array[i+11]) + " |s5: "
                                                + QString::number((quint8)array[i+12]) + " |s6: "  + QString::number((quint8)array[i+13]) +  " |s7: "  + QString::number((quint8)array[i+14]) + " |s8: "  + QString::number((quint8)array[i+15]) + " |s9: "
                                                + QString::number((quint8)array[i+16]) + " |s10: "  + QString::number((quint8)array[i+17]) +  " |s11: "  + QString::number((quint8)array[i+18]) + " |s12: "  + QString::number((quint8)array[i+19]) + " |s13: "
                                                + QString::number((quint8)array[i+20]) + " |s14: "  + QString::number((quint8)array[i+21]) +  " |s15: "  + QString::number((quint8)array[i+22]) + " |s16: "  + QString::number((quint8)array[i+23]) + " |s17: "
                                                + QString::number((quint8)array[i+24]) + " |s18: "  + QString::number((quint8)array[i+25]) +  " |s19: "  + QString::number((quint8)array[i+26]) + " |s20: "  + QString::number((quint8)array[i+27]) + " |s21: "
                                                + QString::number((quint8)array[i+28]) + " |s22: "  + QString::number((quint8)array[i+29]) +  " |s23: "  + QString::number((quint8)array[i+30]) + " |s24: "  + QString::number((quint8)array[i+31]) + " |s25: "
                                                + QString::number((quint8)array[i+32]) + " |s26: "  + QString::number((quint8)array[i+33]) +  " |s27: "  + QString::number((quint8)array[i+34]) + " |s28: "  + QString::number((quint8)array[i+35]) + " |s29: "
                                                + QString::number((quint8)array[i+36]) + " |s30: "  + QString::number((quint8)array[i+37]) +  " |s31: "  + QString::number((quint8)array[i+38]) + " |s32: "  + QString::number((quint8)array[i+39]) + " |sum_interval: "
                                                + QString::number(word(array[i+40],array[i+41]))+ " |sum_all: " + QString::number(word(array[i+42],array[i+43])) + " |shum: " + QString::number(word(array[i+44],array[i+45])) + "\n";

                    filesave(file_str,2);
                }

                otvet_groz->clear();
                }
            }
        }
    }
}


void MainWindow::filesave(QString mes, int flag)
{
    QDate dat = QDate::currentDate();

    QFile file_gda_1(dat.toString("dd_MM__yyyy") + "_gda_1.txt");
    QFile file_amk(dat.toString("dd_MM__yyyy") + "_amk.txt");

    if(flag == 2)
    {
    if(file_gda_1.exists() && file_gda_1.open(QIODevice::Append | QIODevice::Text))
    {
       qDebug()<<mes;
       QTextStream out(&file_gda_1);
       out << mes;
       file_gda_1.flush();
       file_gda_1.close();
    }
    else
    {
       file_gda_1.open(QIODevice::WriteOnly | QIODevice::Text);
       qDebug()<<mes;
       QTextStream out(&file_gda_1);
       out << mes;
       file_gda_1.flush();
       file_gda_1.close();
    }
    }
}
