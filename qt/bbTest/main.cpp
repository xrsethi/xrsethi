#include "mywidget.h"
#include <QApplication> //包含应用程序的头文件

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //窗口对象
    myWidget w;
    //窗口对象默认不会显示，必须调用show方法显示对象
    w.show();
    //让应用程序对象进入消息循环
    return a.exec();
}
