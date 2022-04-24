#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    pb = new QPushButton("ok", this);
    le = new QLineEdit(this);
    le1 = new QLineEdit(this);
#if 0
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(le);
    vbox->addWidget(le1);
    vbox->addWidget(pb);

    this->setLayout(vbox);
#endif
#if 0
    QHBoxLayout *vhox = new QHBoxLayout;
    vhox->addWidget(le);
    vhox->addWidget(le1);
    vhox->addWidget(pb);

    this->setLayout(vhox);
#endif
#if 0
    QGridLayout *vhox = new QGridLayout;
    vhox->addWidget(le,0,0);
    vhox->addWidget(le1,1,1);
    vhox->addWidget(pb,2,2);

    this->setLayout(vhox);
#endif
    QFormLayout *fbox = new QFormLayout;
    fbox->addRow("user",le);
    fbox->addRow("pawd",le1);
    fbox->addRow("",pb);
    this->setLayout(fbox);
    connect(pb,SIGNAL(clicked(bool)), this,SLOT(movestr()));
}

Widget::~Widget()
{
    delete ui;
}

