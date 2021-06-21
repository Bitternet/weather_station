/********************************************************************************
** Form generated from reading UI file 'config_form.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_FORM_H
#define UI_CONFIG_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_config_form
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton_new;
    QPushButton *pushButton_read;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_write;
    QTableView *tableView;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *config_form)
    {
        if (config_form->objectName().isEmpty())
            config_form->setObjectName(QStringLiteral("config_form"));
        config_form->resize(721, 602);
        verticalLayout = new QVBoxLayout(config_form);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_new = new QPushButton(config_form);
        pushButton_new->setObjectName(QStringLiteral("pushButton_new"));
        pushButton_new->setMinimumSize(QSize(120, 40));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        pushButton_new->setFont(font);
        pushButton_new->setStyleSheet(QStringLiteral("background-color: dimgrey; color: white"));

        gridLayout->addWidget(pushButton_new, 1, 1, 1, 1);

        pushButton_read = new QPushButton(config_form);
        pushButton_read->setObjectName(QStringLiteral("pushButton_read"));
        pushButton_read->setMinimumSize(QSize(120, 40));
        pushButton_read->setFont(font);
        pushButton_read->setStyleSheet(QStringLiteral("background-color: dimgrey; color: white;"));

        gridLayout->addWidget(pushButton_read, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        pushButton_write = new QPushButton(config_form);
        pushButton_write->setObjectName(QStringLiteral("pushButton_write"));
        pushButton_write->setMinimumSize(QSize(120, 40));
        pushButton_write->setFont(font);
        pushButton_write->setStyleSheet(QStringLiteral("background-color: dimgrey; color: white;"));

        gridLayout->addWidget(pushButton_write, 2, 1, 1, 1);

        tableView = new QTableView(config_form);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setMinimumSize(QSize(0, 400));
        tableView->setLineWidth(1);

        gridLayout->addWidget(tableView, 0, 0, 4, 1);

        groupBox = new QGroupBox(config_form);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 130));
        groupBox->setFont(font);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout_2->addWidget(label_4, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        gridLayout_2->addWidget(label_5, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        gridLayout_2->addWidget(label_6, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        gridLayout->addWidget(groupBox, 4, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(config_form);

        QMetaObject::connectSlotsByName(config_form);
    } // setupUi

    void retranslateUi(QWidget *config_form)
    {
        config_form->setWindowTitle(QApplication::translate("config_form", "\320\247\321\202\320\265\320\275\320\270\320\265/\320\267\320\260\320\277\320\270\321\201\321\214 \320\262 \320\263\321\200\320\260\320\264\321\203\320\270\321\200\320\276\320\262\320\276\321\207\320\275\321\213\321\205 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\276\320\262 \320\262\320\276 \320\262\320\275\320\265\321\210\320\275\320\270\320\271 \320\277\321\203\320\273\321\214\321\202", nullptr));
        pushButton_new->setText(QApplication::translate("config_form", "\320\235\320\276\320\262\321\213\320\265", nullptr));
        pushButton_read->setText(QApplication::translate("config_form", "\320\247\321\202\320\265\320\275\320\270\320\265", nullptr));
        pushButton_write->setText(QApplication::translate("config_form", "\320\227\320\260\320\277\320\270\321\201\321\214", nullptr));
        groupBox->setTitle(QApplication::translate("config_form", "\320\224\320\270\320\260\320\263\320\275\320\276\321\201\321\202\320\270\320\272\320\260", nullptr));
        label->setText(QApplication::translate("config_form", "*0 - \321\203\321\201\320\277\320\265\321\210\320\275\320\260\321\217 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\321\217;", nullptr));
        label_3->setText(QApplication::translate("config_form", "*4 - \320\267\320\260\320\277\321\200\320\276\321\201 \320\276\321\202\320\262\320\265\321\200\320\263\320\275\321\203\321\202;", nullptr));
        label_2->setText(QApplication::translate("config_form", "*2 - \320\275\320\265 \321\201\320\276\320\262\320\277\320\260\320\264\320\260\320\265\321\202 \320\275\320\276\320\274\320\265\321\200 \320\277\320\260\321\200\320\274\320\265\321\202\321\200\320\260;", nullptr));
        label_4->setText(QApplication::translate("config_form", "*1 - \320\275\320\265 \321\201\320\276\320\262\320\277\320\260\320\264\320\260\320\265\321\202 \320\272\320\276\320\275\321\202\321\200\320\276\320\273\321\214\320\275\320\260\321\217 \321\201\321\203\320\274\320\274\320\260;", nullptr));
        label_5->setText(QApplication::translate("config_form", "*3 - \320\275\320\265 \321\201\320\276\320\262\320\277\320\260\320\264\320\260\320\265\321\202 \320\275\320\276\320\274\320\265\321\200 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\275\320\276\320\271 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270;", nullptr));
        label_6->setText(QApplication::translate("config_form", "*5 - \320\275\320\260\321\200\321\203\321\210\320\265\320\275\320\260 \321\201\321\202\321\200\321\203\320\272\321\202\321\203\321\200\320\260 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\276\320\275\320\275\320\276\320\263\320\276 \320\277\320\260\320\272\320\265\321\202\320\260;", nullptr));
    } // retranslateUi

};

namespace Ui {
    class config_form: public Ui_config_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_FORM_H
