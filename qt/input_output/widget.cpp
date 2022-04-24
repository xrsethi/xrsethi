#include "widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //input
    le = new QLineEdit(this);
    te = new QTextEdit;
    cb = new QComboBox;
    cb->addItem("read");
    cb->addItem("write");
    timee = new QTimeEdit;
    dl = new QDial;
    sd = new QSlider;
    sd->setOrientation(Qt::Horizontal);
    sb = new QScrollBar;
    sb->setOrientation(Qt::Horizontal);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(le);
    vbox->addWidget(te);
    vbox->addWidget(cb);
    vbox->addWidget(timee);
    vbox->addWidget(dl);
    vbox->addWidget(sd);
    vbox->addWidget(sb);
    //output
    lb = new QLabel("hello");
    lb1 = new QLabel ;
    lb1->setFixedSize(80,80);       /* 设置图片大小 */
    lb1->setScaledContents(true);   /* 设置图片自动缩放 */
    QPixmap pix("1.png");           /* 显示一张照片 */
    lb1->setPixmap( pix );          /* 放在影子目录下 */
    lcd = new QLCDNumber ;
    pgb  = new QProgressBar ;
    QVBoxLayout *vbox1 = new QVBoxLayout;
    vbox1->addWidget(lb);
    vbox1->addWidget(lb1);
    vbox1->addWidget(lcd);
    vbox1->addWidget(pgb);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addLayout(vbox);
    hbox->addLayout(vbox1);
    this->setLayout(hbox);

    connect(dl, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
    connect(dl, SIGNAL(valueChanged(int)), pgb, SLOT(setValue(int)));
    connect(dl, SIGNAL(valueChanged(int)), sd, SLOT(setValue(int)));
}

Widget::~Widget()
{
}

