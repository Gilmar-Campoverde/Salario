#include "acerca.h"
#include "ui_acerca.h"

Acerca::Acerca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acerca)
{
    ui->setupUi(this);
}

Acerca::~Acerca()
{
    delete ui;
}

void Acerca::setVersion(const QString &value)
{
    version = value;
    ui->outVer->setText("VERSION: " + value);
}

