#ifndef CONFIG_FORM_H
#define CONFIG_FORM_H

#include <QWidget>

namespace Ui {
class config_form;
}

class config_form : public QWidget
{
    Q_OBJECT

public:
    explicit config_form(QWidget *parent = 0);
    ~config_form();

private:
    Ui::config_form *ui;
};

#endif // CONFIG_FORM_H
