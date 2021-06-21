#include "config_form.h"
#include "ui_config_form.h"

config_form::config_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::config_form)
{
    ui->setupUi(this);
}

config_form::~config_form()
{
    delete ui;
}
