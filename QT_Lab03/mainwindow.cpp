#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <fstream>
#include <string.h>
using namespace std;

vector<Customer> customers;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->zipBox->addItem("");
    ifstream myFile("data.txt", ios::in);
    string person = "";
    QStringList attr;
    while (getline(myFile, person))
    {
        attr = QString::fromStdString(person).split( "," );

        Customer temp(attr.value(0), attr.value(1), attr.value(2), attr.value(3), attr.value(4), attr.value(5),
                attr.value(6), attr.value(7), attr.value(8), attr.value(9).toInt());
        customers.push_back(temp);
        ui->zipBox->addItem(attr.value(6));
    }
    ui->id->setText(QString::number(attr.value(0).toInt() + 1));

    QString states[] = {"Alabama",
                        "Alaska",
                        "Arizona",
                        "Arkansas",
                        "California",
                        "Colorado",
                        "Connecticut",
                        "Delaware",
                        "Florida",
                        "Georgia",
                        "Hawaii",
                        "Idaho",
                        "Illinois",
                        "Indiana",
                        "Iowa",
                        "Kansas",
                        "Kentucky",
                        "Louisiana",
                        "Maine",
                        "Maryland",
                        "Massachusetts",
                        "Michigan",
                        "Minnesota",
                        "Mississippi",
                        "Missouri",
                        "Montana",
                        "Nebraska",
                        "Nevada",
                        "New Hampshire",
                        "New Jersey",
                        "New Mexico",
                        "New York",
                        "North Carolina",
                        "Northui->id->setText(QString::number(attr.value(0).toInt() + 1)); Dakota",
                        "Ohio",
                        "Oklahoma",
                        "Oregon",
                        "Pennsylvania",
                        "Rhode Island",
                        "South Carolina",
                        "South Dakota",
                        "Tennessee",
                        "Texas",
                        "Utah",
                        "Vermont",
                        "Virginia",
                        "Washington",
                        "West Virginia",
                        "Wisconsin",
                        "Wyoming"};
    for(int i = 0; i < 50; i++)
    {
        ui->stateDrop->addItem(states[i]);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    ofstream myFile;
    myFile.open("data.txt", ios::out);
    QString fileDrop = "";
    for (int i = 0; i < sizeof(customers); i++)
    {
        fileDrop += customers[i].stringulate();
    }
    myFile << fileDrop.toStdString();
    myFile.close();
}

void MainWindow::on_submitBttn_pressed()
{
    Customer temp(ui->id->text(),
                  ui->firstNameEdit->text(),
                  ui->lastNameEdit->text(),
                  ui->addressEdit->text(),
                  ui->cityEdit->text(),
                  ui->stateDrop->currentText(),
                  ui->zipBox->currentText(),
                  ui->phoneEdit->text(),
                  ui->emailEdit->text(),
                  ui->textCheck->isChecked());

    customers.push_back(temp);
    ui->zipBox->addItem(ui->zipBox->currentText());
    ui->id->setText(QString::number(ui->id->text().toInt() + 1));
    ui->firstNameEdit->setText("");
    ui->lastNameEdit->setText("");
    ui->addressEdit->setText("");
    ui->cityEdit->setText("");
    ui->stateDrop->setCurrentIndex(0);
    ui->zipBox->setCurrentIndex(0);
    ui->phoneEdit->setText("");
    ui->emailEdit->setText("");
    ui->textCheck->setChecked(false);
}
