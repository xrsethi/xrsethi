#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public slots:
    void movestr()
    {
        le1->setText(le->text());
    }
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QPushButton *pb;
    QLineEdit *le;
    QLineEdit *le1;
};
#endif // WIDGET_H
