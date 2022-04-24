#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QTimeEdit>
#include <QDial>
#include <QSlider>          /* 滑动条 */
#include <QScrollBar>       /* 滚动条 */

#include <QLabel>           /* 图片等标签 */
#include <QLCDNumber>       /* 类似数码管 */
#include <QProgressBar>     /* 进度条 */

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    //input
    QLineEdit *le;
    QTextEdit *te;
    QComboBox *cb;
    QTimeEdit *timee;
    QDial *dl;
    QSlider *sd;
    QScrollBar *sb;
    //output
    QLabel *lb;
    QLabel *lb1;
    QLCDNumber *lcd;
    QProgressBar *pgb;
};
#endif // WIDGET_H
