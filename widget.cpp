#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->definitionBox->setReadOnly(true);
    QString dictionary = ":/dictionary/ofd.txt";
    bool didWork = trie.createTrieFromQtFile(dictionary);
    if (!didWork) {
        ui->definitionBox->setPlainText("There was a loading error, please restart");
    }
    else {
        ui->definitionBox->setPlainText("Try typing a word in the box above!");
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_textChanged(const QString &updated_text)
{
    std::string searchResult = trie.findWord(updated_text.toStdString());
    if (searchResult == "-1") ui->definitionBox->setPlainText("No Matching Word for " + updated_text);
    else ui->definitionBox->setPlainText(QString::fromStdString(searchResult));

    trie.createSuggestionList(updated_text.toStdString());
    ui->button1->setText("");
    ui->button2->setText("");
    ui->button3->setText("");
    ui->button4->setText("");
    ui->button5->setText("");
    //1
    try {
        ui->button1->setText(QString::fromStdString(trie.suggestionList.at(0)));
    }
    catch(std::out_of_range) {
        return;
    }
    //2
    try {
        ui->button2->setText(QString::fromStdString(trie.suggestionList.at(1)));
    }
    catch(std::out_of_range) {
        return;
    }
    //3
    try {
        ui->button3->setText(QString::fromStdString(trie.suggestionList.at(2)));
    }
    catch(std::out_of_range) {
        return;
    }
    //4
    try {
        ui->button4->setText(QString::fromStdString(trie.suggestionList.at(3)));
    }
    catch(std::out_of_range) {
        return;
    }
    //5
    try {
        ui->button5->setText(QString::fromStdString(trie.suggestionList.at(4)));
    }
    catch(std::out_of_range) {
        return;
    }
}

void Widget::on_button1_clicked()
{
    ui->lineEdit->setText(ui->button1->text());
}

void Widget::on_button2_clicked()
{
    ui->lineEdit->setText(ui->button2->text());
}

void Widget::on_button3_clicked()
{
    ui->lineEdit->setText(ui->button3->text());
}

void Widget::on_button4_clicked()
{
    ui->lineEdit->setText(ui->button4->text());
}

void Widget::on_button5_clicked()
{
    ui->lineEdit->setText(ui->button5->text());
}
