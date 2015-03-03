#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
static vector <Customer> customers;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    }


MainWindow::~MainWindow()
{
    QString qs;
    ofstream file;
    file.open("result.txt");
    for(int i = 0; i < customers.size(); i++){
        file << (customers[i].getcn()+"\n").toStdString();
        QString file1 = customers[i].getFirstname();
        file << (file1+"\n").toStdString();

        file << (customers[i].getLastname()+"\n").toStdString();
        file << (customers[i].getStreet()+"\n").toStdString();
        file << (customers[i].getCity()+"\n").toStdString();
        file <<(customers[i].getState()+"\n").toStdString();
        file <<(customers[i].getZip()+"\n").toStdString();
        file <<(customers[i].getPhone()+"\n").toStdString();
        file <<(customers[i].getEmail()+"\n").toStdString();
        if (customers[i].getTexting()){
            file << "user can receive texts\n\n\n";
            }
        else{
            file << "User can not receive texts\n\n";
               }
        file << "---------------------------------------\n\n";
        }

    file.close();
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{

    Customer temp;
    temp.set_cn(ui->label_10->text());
    temp.set_first(ui->lineEdit->text());
    temp.set_last(ui->lineEdit_2->text());
    temp.set_street(ui->lineEdit_3->text());
    temp.set_city(ui->lineEdit_4->text());
    temp.set_state(ui->comboBox->currentText());
    temp.set_phone(ui->lineEdit_6->text());
    temp.set_email(ui->lineEdit_7->text());
    temp.set_zip(ui->comboBox_2->currentText());
    QString text = ui->comboBox_2->currentText();
    ui->comboBox_2->addItem(text);
    temp.set_texting(ui->checkBox->isChecked());
    customers.push_back(temp);
    QString mystring = ui->label_10->text();
    int num = mystring.toInt();
    num++;
    mystring = QString::number(num);
    ui->label_10->setText(mystring);
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->comboBox->setCurrentIndex(0);
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->comboBox_2->setEditText("");
    ui->checkBox->setChecked(false);


}

void MainWindow::on_pushButton_2_clicked(){
    ui->textEdit->setText("");
    for(int i = 0; i < customers.size(); i++){
        ui->textEdit->insertPlainText(customers[i].getcn());
        ui->textEdit->insertPlainText("\n" + customers[i].getFirstname()+"\n");
        ui->textEdit->insertPlainText(customers[i].getLastname()+"\n");
        ui->textEdit->insertPlainText(customers[i].getStreet()+"\n");
        ui->textEdit->insertPlainText(customers[i].getCity()+"\n");
        ui->textEdit->insertPlainText(customers[i].getState()+"\n");
        ui->textEdit->insertPlainText(customers[i].getZip()+"\n");
        ui->textEdit->insertPlainText(customers[i].getPhone()+"\n");
        ui->textEdit->insertPlainText(customers[i].getEmail()+"\n");
        if (customers[i].getTexting()){
            ui->textEdit->insertPlainText("user can receive texts\n\n");}
        else{
            ui->textEdit->insertPlainText("User can not receive texts\n\n");}

}
}
