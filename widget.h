#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "Trie.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_button1_clicked();

    void on_button2_clicked();

    void on_button3_clicked();

    void on_button4_clicked();

    void on_button5_clicked();

private:
    Ui::Widget *ui;
    Trie trie;
};
#endif // WIDGET_H
