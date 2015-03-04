#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_submitBttn_pressed();

private:
    Ui::MainWindow *ui;
};

class Customer
{
private:
    QString ID;
    QString fName;
    QString lName;
    QString address;
    QString city;
    QString state;
    QString zip;
    QString phone;
    QString email;
    int text;
public:
    Customer(QString pID, QString pFName, QString pLName, QString pAddress, QString pCity,
             QString pState, QString pZip, QString pPhone, QString pEmail, bool pText)
    {
        ID = pID;
        fName = pFName;
        lName = pLName;
        address = pAddress;
        city = pCity;
        state = pState;
        zip = pZip;
        phone = pPhone;
        email = pEmail;
        text = pText;
    }
    QString stringulate()
    {
        return ID + "," + fName + "," + lName + "," + address + "," + city + "," + state + ","
                + zip + "," + phone + "," + email + "," + QString::number(text) + "\n";
    }
    QString get_ID()
    {
        return ID;
    }

};

#endif // MAINWINDOW_H
