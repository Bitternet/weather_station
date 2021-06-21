/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_5;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *lb_time;
    QLabel *lb_time_session;
    QLabel *label_7;
    QLabel *lb_date;
    QLabel *label_47;
    QLabel *lb_ico;
    QGroupBox *groupBox_7;
    QLabel *lb_pict_groza;
    QLabel *lb_groza;
    QLabel *label_15;
    QLabel *label_21;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_connect;
    QRadioButton *radioButton;
    QLabel *label;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_config;
    QComboBox *comboBox_port;
    QLabel *label_5;
    QComboBox *comboBox;
    QLabel *label_3;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_4;
    QLabel *label_49;
    QPlainTextEdit *ptSystemLog;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_13;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *lb_status;
    QGridLayout *gridLayout_14;
    QLabel *label_19;
    QLabel *label_26;
    QLabel *lb_zona_sum;
    QLabel *label_25;
    QLabel *label_20;
    QLabel *label_17;
    QLabel *lb_zona2;
    QLabel *lb_zona3;
    QLabel *lb_zona4;
    QLabel *label_18;
    QLabel *label_27;
    QLabel *lb_zona1;
    QLabel *label_16;
    QLabel *label_28;
    QLabel *lb_infoGroz;
    QComboBox *comboBox_port_groz;
    QLabel *label_23;
    QPushButton *pushButton_connect_groz;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_groz;
    QLabel *label_22;
    QGridLayout *gridLayout_17;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_11;
    QTextBrowser *tbrowser;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_10;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_8;
    QTableView *tableView;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_9;
    QTableView *tableView_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1616, 1155);
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font1;
        font1.setPointSize(12);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_4, 0, 5, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_6, 1, 5, 1, 1);

        lb_time = new QLabel(centralwidget);
        lb_time->setObjectName(QStringLiteral("lb_time"));
        lb_time->setFont(font1);
        lb_time->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lb_time, 1, 6, 1, 1);

        lb_time_session = new QLabel(centralwidget);
        lb_time_session->setObjectName(QStringLiteral("lb_time_session"));
        lb_time_session->setFont(font1);
        lb_time_session->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lb_time_session, 0, 6, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_7, 2, 5, 2, 1);

        lb_date = new QLabel(centralwidget);
        lb_date->setObjectName(QStringLiteral("lb_date"));
        lb_date->setFont(font1);
        lb_date->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lb_date, 2, 6, 2, 1);

        label_47 = new QLabel(centralwidget);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setMinimumSize(QSize(270, 75));
        label_47->setMaximumSize(QSize(16777215, 100));
        QFont font2;
        font2.setFamily(QStringLiteral("Arimo"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        label_47->setFont(font2);
        label_47->setStyleSheet(QStringLiteral(""));
        label_47->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_47, 0, 1, 4, 1);

        lb_ico = new QLabel(centralwidget);
        lb_ico->setObjectName(QStringLiteral("lb_ico"));
        lb_ico->setMinimumSize(QSize(0, 0));
        lb_ico->setMaximumSize(QSize(70, 60));
        lb_ico->setPixmap(QPixmap(QString::fromUtf8(":/resource/pressure.png")));
        lb_ico->setScaledContents(true);
        lb_ico->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lb_ico, 0, 0, 4, 1);

        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setMinimumSize(QSize(700, 0));
        groupBox_7->setMaximumSize(QSize(700, 16777215));
        groupBox_7->setFlat(true);
        lb_pict_groza = new QLabel(groupBox_7);
        lb_pict_groza->setObjectName(QStringLiteral("lb_pict_groza"));
        lb_pict_groza->setEnabled(true);
        lb_pict_groza->setGeometry(QRect(10, 10, 70, 60));
        lb_pict_groza->setMinimumSize(QSize(70, 60));
        lb_pict_groza->setMaximumSize(QSize(70, 60));
        lb_pict_groza->setPixmap(QPixmap(QString::fromUtf8(":/new/images/resource/hotpng.com.png")));
        lb_pict_groza->setScaledContents(true);
        lb_groza = new QLabel(groupBox_7);
        lb_groza->setObjectName(QStringLiteral("lb_groza"));
        lb_groza->setGeometry(QRect(90, 0, 600, 75));
        lb_groza->setMinimumSize(QSize(600, 75));
        lb_groza->setMaximumSize(QSize(600, 75));
        QFont font3;
        font3.setFamily(QStringLiteral("Arimo"));
        font3.setPointSize(12);
        lb_groza->setFont(font3);
        lb_groza->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(groupBox_7, 0, 3, 4, 1);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_5->addWidget(label_15, 0, 2, 4, 1);

        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_5->addWidget(label_21, 0, 4, 4, 1);


        verticalLayout->addLayout(gridLayout_5);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font4;
        font4.setPointSize(13);
        tabWidget->setFont(font4);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font5;
        font5.setPointSize(11);
        groupBox->setFont(font5);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        verticalLayout_3->addLayout(gridLayout);


        gridLayout_2->addWidget(groupBox, 0, 1, 2, 1);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(800, 16777215));
        groupBox_2->setFont(font4);
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 30));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        QFont font6;
        font6.setPointSize(13);
        font6.setBold(true);
        font6.setItalic(false);
        font6.setWeight(75);
        label_2->setFont(font6);
        label_2->setStyleSheet(QStringLiteral("background-color: dimgrey; color: white; font: bold; "));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        pushButton_connect = new QPushButton(groupBox_2);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setMinimumSize(QSize(150, 60));
        pushButton_connect->setMaximumSize(QSize(150, 70));
        QFont font7;
        font7.setPointSize(11);
        font7.setBold(true);
        font7.setWeight(75);
        pushButton_connect->setFont(font7);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/images/resource/icons8-\321\201\320\265\321\202\321\214-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_connect->setIcon(icon);
        pushButton_connect->setIconSize(QSize(32, 32));

        gridLayout_6->addWidget(pushButton_connect, 0, 3, 2, 1);

        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setMinimumSize(QSize(0, 0));
        QFont font8;
        font8.setFamily(QStringLiteral("Noto Sans"));
        font8.setPointSize(11);
        radioButton->setFont(font8);

        gridLayout_6->addWidget(radioButton, 0, 1, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(30, 30));
        QFont font9;
        font9.setFamily(QStringLiteral("Noto Sans"));
        font9.setPointSize(11);
        font9.setBold(true);
        font9.setWeight(75);
        label->setFont(font9);

        gridLayout_6->addWidget(label, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setMinimumSize(QSize(150, 0));
        radioButton_2->setFont(font8);

        gridLayout_6->addWidget(radioButton_2, 1, 1, 1, 1);

        pushButton_config = new QPushButton(groupBox_2);
        pushButton_config->setObjectName(QStringLiteral("pushButton_config"));
        pushButton_config->setEnabled(false);
        pushButton_config->setMinimumSize(QSize(150, 60));
        pushButton_config->setMaximumSize(QSize(300, 70));
        pushButton_config->setFont(font7);
        pushButton_config->setStyleSheet(QStringLiteral("background-color: dimgrey; color: white; "));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/resource/config-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_config->setIcon(icon1);
        pushButton_config->setIconSize(QSize(32, 32));

        gridLayout_6->addWidget(pushButton_config, 0, 4, 2, 1);

        comboBox_port = new QComboBox(groupBox_2);
        comboBox_port->setObjectName(QStringLiteral("comboBox_port"));
        comboBox_port->setMinimumSize(QSize(0, 30));

        gridLayout_6->addWidget(comboBox_port, 1, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font9);

        gridLayout_6->addWidget(label_5, 0, 2, 1, 1);

        comboBox = new QComboBox(groupBox_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_6->addWidget(comboBox, 1, 2, 1, 1);


        verticalLayout_4->addLayout(gridLayout_6);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 30));
        label_3->setFont(font6);
        label_3->setStyleSheet(QStringLiteral("background-color: dimgrey; color: white; font: bold;"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));

        verticalLayout_4->addLayout(gridLayout_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_49 = new QLabel(groupBox_2);
        label_49->setObjectName(QStringLiteral("label_49"));
        label_49->setMinimumSize(QSize(0, 30));
        label_49->setFont(font6);
        label_49->setStyleSheet(QStringLiteral("background-color: dimgrey; color: white; font: bold;"));
        label_49->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_49, 0, 0, 1, 1);

        ptSystemLog = new QPlainTextEdit(groupBox_2);
        ptSystemLog->setObjectName(QStringLiteral("ptSystemLog"));
        ptSystemLog->setMinimumSize(QSize(0, 0));
        ptSystemLog->setMaximumSize(QSize(16700000, 16777215));
        QFont font10;
        font10.setPointSize(10);
        ptSystemLog->setFont(font10);

        gridLayout_4->addWidget(ptSystemLog, 1, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_4);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 2, 1);


        gridLayout_7->addLayout(gridLayout_2, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_7);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_7 = new QVBoxLayout(tab_2);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(400, 600));
        groupBox_4->setMaximumSize(QSize(540, 16777215));
        verticalLayout_6 = new QVBoxLayout(groupBox_4);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(100, 40));
        label_9->setMaximumSize(QSize(16777215, 40));
        label_9->setStyleSheet(QStringLiteral("background-color: lightgreen"));

        gridLayout_13->addWidget(label_9, 1, 0, 1, 1);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(100, 40));
        label_11->setMaximumSize(QSize(16777215, 40));
        label_11->setStyleSheet(QStringLiteral("background-color: tomato;"));

        gridLayout_13->addWidget(label_11, 1, 2, 1, 1);

        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(100, 40));
        label_10->setMaximumSize(QSize(16777215, 40));
        label_10->setStyleSheet(QStringLiteral("background-color: yellow;"));

        gridLayout_13->addWidget(label_10, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(400, 40));
        label_8->setMaximumSize(QSize(34545, 40));
        label_8->setFont(font6);
        label_8->setStyleSheet(QStringLiteral("background-color: dimgrey; color: white; font: bold; "));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(label_8, 0, 0, 1, 3);

        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(40, 40));
        label_12->setMaximumSize(QSize(16777215, 40));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(label_12, 2, 0, 1, 1);

        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(40, 40));
        label_13->setMaximumSize(QSize(16777215, 40));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(label_13, 2, 1, 1, 1);

        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(40, 40));
        label_14->setMaximumSize(QSize(16777215, 40));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(label_14, 2, 2, 1, 1);


        verticalLayout_6->addLayout(gridLayout_13);

        lb_status = new QLabel(groupBox_4);
        lb_status->setObjectName(QStringLiteral("lb_status"));
        lb_status->setMinimumSize(QSize(0, 40));
        lb_status->setMaximumSize(QSize(16777215, 40));
        QFont font11;
        font11.setPointSize(13);
        font11.setBold(true);
        font11.setWeight(75);
        lb_status->setFont(font11);
        lb_status->setStyleSheet(QStringLiteral("border-style: outset; border-width: 2px;"));
        lb_status->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(lb_status);

        gridLayout_14 = new QGridLayout();
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMinimumSize(QSize(0, 40));
        label_19->setMaximumSize(QSize(16777215, 40));
        label_19->setSizeIncrement(QSize(0, 40));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_14->addWidget(label_19, 3, 0, 1, 1);

        label_26 = new QLabel(groupBox_4);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setMinimumSize(QSize(0, 40));
        label_26->setSizeIncrement(QSize(0, 40));
        label_26->setFont(font6);
        label_26->setStyleSheet(QStringLiteral("background-color: dimgrey; color: white; font: bold; "));
        label_26->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(label_26, 6, 0, 1, 2);

        lb_zona_sum = new QLabel(groupBox_4);
        lb_zona_sum->setObjectName(QStringLiteral("lb_zona_sum"));

        gridLayout_14->addWidget(lb_zona_sum, 5, 1, 1, 1);

        label_25 = new QLabel(groupBox_4);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_14->addWidget(label_25, 5, 0, 1, 1);

        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMinimumSize(QSize(0, 40));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_14->addWidget(label_20, 4, 0, 1, 1);

        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMinimumSize(QSize(0, 40));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_14->addWidget(label_17, 1, 0, 1, 1);

        lb_zona2 = new QLabel(groupBox_4);
        lb_zona2->setObjectName(QStringLiteral("lb_zona2"));

        gridLayout_14->addWidget(lb_zona2, 2, 1, 1, 1);

        lb_zona3 = new QLabel(groupBox_4);
        lb_zona3->setObjectName(QStringLiteral("lb_zona3"));
        lb_zona3->setMaximumSize(QSize(16777215, 40));
        lb_zona3->setSizeIncrement(QSize(0, 40));

        gridLayout_14->addWidget(lb_zona3, 3, 1, 1, 1);

        lb_zona4 = new QLabel(groupBox_4);
        lb_zona4->setObjectName(QStringLiteral("lb_zona4"));

        gridLayout_14->addWidget(lb_zona4, 4, 1, 1, 1);

        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMinimumSize(QSize(0, 40));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_14->addWidget(label_18, 2, 0, 1, 1);

        label_27 = new QLabel(groupBox_4);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setMinimumSize(QSize(0, 40));
        label_27->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(label_27, 7, 0, 1, 1);

        lb_zona1 = new QLabel(groupBox_4);
        lb_zona1->setObjectName(QStringLiteral("lb_zona1"));

        gridLayout_14->addWidget(lb_zona1, 1, 1, 1, 1);

        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(400, 40));
        label_16->setMaximumSize(QSize(16777215, 40));
        label_16->setFont(font6);
        label_16->setStyleSheet(QStringLiteral("background-color: dimgrey; color: white; font: bold; "));
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(label_16, 0, 0, 1, 2);

        label_28 = new QLabel(groupBox_4);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setMinimumSize(QSize(0, 40));
        label_28->setMaximumSize(QSize(16777215, 12534));
        label_28->setSizeIncrement(QSize(0, 40));
        label_28->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(label_28, 8, 0, 1, 1);

        lb_infoGroz = new QLabel(groupBox_4);
        lb_infoGroz->setObjectName(QStringLiteral("lb_infoGroz"));
        lb_infoGroz->setMinimumSize(QSize(0, 40));
        lb_infoGroz->setMaximumSize(QSize(16777215, 40));
        lb_infoGroz->setSizeIncrement(QSize(0, 40));
        lb_infoGroz->setBaseSize(QSize(0, 40));
        QFont font12;
        font12.setPointSize(12);
        font12.setBold(true);
        font12.setWeight(75);
        lb_infoGroz->setFont(font12);
        lb_infoGroz->setStyleSheet(QStringLiteral("border-style: outset; border-width: 2px;"));
        lb_infoGroz->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(lb_infoGroz, 8, 1, 1, 1);

        comboBox_port_groz = new QComboBox(groupBox_4);
        comboBox_port_groz->setObjectName(QStringLiteral("comboBox_port_groz"));

        gridLayout_14->addWidget(comboBox_port_groz, 9, 0, 1, 1);

        label_23 = new QLabel(groupBox_4);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(label_23, 7, 1, 1, 1);

        pushButton_connect_groz = new QPushButton(groupBox_4);
        pushButton_connect_groz->setObjectName(QStringLiteral("pushButton_connect_groz"));
        pushButton_connect_groz->setMinimumSize(QSize(0, 40));
        pushButton_connect_groz->setFont(font12);

        gridLayout_14->addWidget(pushButton_connect_groz, 9, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout_14);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);


        gridLayout_9->addWidget(groupBox_4, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(0, 0));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        gridLayout_groz = new QGridLayout();
        gridLayout_groz->setObjectName(QStringLiteral("gridLayout_groz"));

        verticalLayout_5->addLayout(gridLayout_groz);


        gridLayout_9->addWidget(groupBox_3, 0, 0, 1, 1);


        verticalLayout_7->addLayout(gridLayout_9);

        label_22 = new QLabel(tab_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMinimumSize(QSize(0, 40));
        label_22->setMaximumSize(QSize(16777215, 40));
        label_22->setFont(font11);
        label_22->setStyleSheet(QStringLiteral("background-color: dimgrey; color: white;"));
        label_22->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_22);

        gridLayout_17 = new QGridLayout();
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        groupBox_6 = new QGroupBox(tab_2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setMinimumSize(QSize(250, 0));
        groupBox_6->setMaximumSize(QSize(250, 16777215));
        verticalLayout_11 = new QVBoxLayout(groupBox_6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        tbrowser = new QTextBrowser(groupBox_6);
        tbrowser->setObjectName(QStringLiteral("tbrowser"));
        tbrowser->setMaximumSize(QSize(16777215, 250));
        tbrowser->setFont(font1);

        verticalLayout_11->addWidget(tbrowser);


        gridLayout_17->addWidget(groupBox_6, 0, 1, 1, 1);

        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_10 = new QVBoxLayout(groupBox_5);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        tabWidget_2 = new QTabWidget(groupBox_5);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_8 = new QVBoxLayout(tab_3);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        tableView = new QTableView(tab_3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setMinimumSize(QSize(0, 200));
        tableView->setMaximumSize(QSize(16777215, 16777215));
        tableView->setSizeIncrement(QSize(0, 0));
        tableView->setBaseSize(QSize(0, 0));
        tableView->setFont(font4);
        tableView->setFrameShape(QFrame::StyledPanel);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableView->horizontalHeader()->setCascadingSectionResizes(false);
        tableView->horizontalHeader()->setDefaultSectionSize(145);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->horizontalHeader()->setMinimumSectionSize(100);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setCascadingSectionResizes(false);
        tableView->verticalHeader()->setDefaultSectionSize(40);
        tableView->verticalHeader()->setHighlightSections(false);
        tableView->verticalHeader()->setMinimumSectionSize(30);
        tableView->verticalHeader()->setStretchLastSection(true);

        verticalLayout_8->addWidget(tableView);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_9 = new QVBoxLayout(tab_4);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        tableView_2 = new QTableView(tab_4);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setFont(font1);
        tableView_2->horizontalHeader()->setDefaultSectionSize(70);
        tableView_2->verticalHeader()->setDefaultSectionSize(30);
        tableView_2->verticalHeader()->setMinimumSectionSize(30);

        verticalLayout_9->addWidget(tableView_2);

        tabWidget_2->addTab(tab_4, QString());

        verticalLayout_10->addWidget(tabWidget_2);


        gridLayout_17->addWidget(groupBox_5, 0, 0, 1, 1);


        verticalLayout_7->addLayout(gridLayout_17);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1616, 29));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201: \320\262\320\265\320\264\321\203\321\211\320\265\320\265 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276 || \320\230\320\275\321\202\320\265\321\200\321\204\320\265\320\271\321\201: RS-232", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \321\201\320\265\321\201\321\201\320\270\320\270:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217:", nullptr));
        lb_time->setText(QApplication::translate("MainWindow", "txt", nullptr));
        lb_time_session->setText(QApplication::translate("MainWindow", "0 \321\207 0 \320\274 0 \321\201", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260:", nullptr));
        lb_date->setText(QApplication::translate("MainWindow", "txt", nullptr));
        label_47->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\265\320\276\321\200\320\276\320\273\320\276\320\263\320\270\321\207\320\265\321\201\320\272\320\276\320\265\n"
"\320\276\320\261\320\276\321\200\321\203\320\264\320\276\320\262\320\260\320\275\320\270\320\265\n"
"\321\201\321\202\320\260\320\275\321\206\320\270\320\270 \"\320\227\320\276\321\200\320\272\320\270\320\271\"", nullptr));
        lb_ico->setText(QString());
        groupBox_7->setTitle(QString());
        lb_pict_groza->setText(QString());
        lb_groza->setText(QApplication::translate("MainWindow", "\320\222\320\235\320\230\320\234\320\220\320\235\320\230\320\225! \320\237\321\200\320\265\320\262\321\213\321\210\320\265\320\275 \320\277\320\276\321\200\320\276\320\263 \320\274\320\276\320\273\320\275\320\270\320\265\320\262\321\213\321\205 (\320\263\321\200\320\276\320\267\320\276\320\262\321\213\321\205) \321\200\320\260\320\267\321\200\321\217\320\264\320\276\320\262 \320\262 \321\201\320\265\320\272\321\202\320\276\321\200\320\265", nullptr));
        label_15->setText(QString());
        label_21->setText(QString());
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QString());
        label_2->setText(QApplication::translate("MainWindow", "\320\237\320\260\320\275\320\265\320\273\321\214 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 ", nullptr));
        pushButton_connect->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\200\320\265\320\264\320\275\320\265\320\275\320\275\321\213\320\265", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\200\321\202 COM:", nullptr));
        radioButton_2->setText(QApplication::translate("MainWindow", "\320\234\320\263\320\275\320\276\320\262\320\265\320\275\320\275\321\213\320\265", nullptr));
        pushButton_config->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \321\203\321\201\321\200\320\265\320\264\320\275\320\265\320\275\320\270\321\217, \320\274\320\270\320\275", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "1", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "10", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "60", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "120", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "180", nullptr));
        comboBox->setItemText(5, QApplication::translate("MainWindow", "240", nullptr));
        comboBox->setItemText(6, QApplication::translate("MainWindow", "300", nullptr));
        comboBox->setItemText(7, QApplication::translate("MainWindow", "360", nullptr));
        comboBox->setItemText(8, QApplication::translate("MainWindow", "420", nullptr));
        comboBox->setItemText(9, QApplication::translate("MainWindow", "480", nullptr));
        comboBox->setItemText(10, QApplication::translate("MainWindow", "540", nullptr));
        comboBox->setItemText(11, QApplication::translate("MainWindow", "600", nullptr));

        comboBox->setCurrentText(QApplication::translate("MainWindow", "1", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\265\320\276\321\200\320\276\320\273\320\276\320\263\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \320\277\320\276\320\272\320\260\320\267\320\260\321\202\320\265\320\273\320\270", nullptr));
        label_49->setText(QApplication::translate("MainWindow", "\320\226\321\203\321\200\320\275\320\260\320\273 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\243\320\273\321\214\321\202\321\200\320\260\320\267\320\262\321\203\320\272\320\276\320\262\320\260\321\217 \320\274\320\265\321\202\320\265\320\276\321\201\321\202\320\260\320\275\321\206\320\270\321\217 \320\220\320\234\320\232-\320\236\320\2373", nullptr));
        groupBox_4->setTitle(QString());
        label_9->setText(QString());
        label_11->setText(QString());
        label_10->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\200\320\260\320\267\321\200\321\217\320\264\320\276\320\262 ", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "1 - 5  ", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "6 - 11", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "> 11", nullptr));
        lb_status->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\261\320\273\320\270\320\267\320\276\321\201\321\202\320\270 \320\263\321\200\320\276\320\267 \320\275\320\265\321\202", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "19 - 56 \320\272\320\274:    ", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\321\207\320\270\320\272", nullptr));
        lb_zona_sum->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "\320\222\320\241\320\225\320\223\320\236:     ", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "> 56 \320\272\320\274:     ", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "00 - 09 \320\272\320\274:    ", nullptr));
        lb_zona2->setText(QApplication::translate("MainWindow", "0", nullptr));
        lb_zona3->setText(QApplication::translate("MainWindow", "0", nullptr));
        lb_zona4->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "09 - 19 \320\272\320\274:    ", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "\320\223\320\224\320\220-1/\342\204\226 \320\246\320\225001", nullptr));
        lb_zona1->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\321\200\321\217\320\264\321\213", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265:", nullptr));
        lb_infoGroz->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\321\216\321\207\320\265\320\275", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "\342\204\226 \320\246\320\225001", nullptr));
        pushButton_connect_groz->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214", nullptr));
        groupBox_3->setTitle(QString());
        label_22->setText(QApplication::translate("MainWindow", "\320\224\320\260\320\275\320\275\321\213\320\265", nullptr));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\320\236\321\210\320\270\320\261\320\272\320\270", nullptr));
        groupBox_5->setTitle(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\265\320\275\320\275\321\213\320\265 \321\201 \320\264\320\260\321\202\321\207\320\270\320\272\320\260 ", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\277\320\276\321\200\320\276\320\263\320\276\320\262\321\213\321\205 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\223\321\200\320\276\320\267\320\276\320\277\320\265\320\273\320\265\320\275\320\263\320\260\321\202\320\276\321\200 - \320\264\320\260\320\273\321\214\320\275\320\276\320\274\320\265\321\200 \320\223\320\224\320\220-1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
