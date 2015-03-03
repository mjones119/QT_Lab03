#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
namespace Ui {
class MainWindow;
class Customer;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
class Customer{
private:
    QString cn;
    QString firstname;
    QString lastname;
    QString street;
    QString city;
    QString state;
    QString zip;
    QString phone;
    QString email;
    bool texting;

public:
    Customer(){
        cn = "0";
        firstname = "";
        lastname = "";
        street = "";
        city = "";
        state = "";
        zip = "";
        phone = "";
        email = "";
        texting = false;
}
    void set_cn(QString c){cn = c;}
    void set_first(QString fn){firstname = fn;}
     void set_last(QString ln){lastname = ln;}
     void set_street(QString str){street = str;}
     void set_city(QString cit){city = cit;}
     void set_state(QString sta){state = sta;}
     void set_zip(QString zi){zip = zi;}
     void set_phone(QString ph){phone = ph;}
     void set_email(QString em){email = em;}
     void set_texting(bool te){texting = te;}
     QString getcn(){return cn;}
     QString getFirstname(){return firstname;}
     QString getLastname(){return lastname;}
     QString getStreet(){return street;}
     QString getCity(){return city;}
     QString getState(){return state;}
     QString getZip(){return zip;}
     QString getPhone(){return phone;}
     QString getEmail(){return email;}
     bool getTexting(){return texting;}



};

#endif // MAINWINDOW_H
