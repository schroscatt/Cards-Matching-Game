#include "mytimer.h"
//MyTimer object executes timer, label and after 180 seconds, it stops

MyTimer::MyTimer() : QObject()
{
    this->counter =0;
    //timer label
    this->label = new QLabel("Time(secs):0");
    this->timer = new QTimer();
    //connect timer to measure the time
    QObject::connect(this->timer,SIGNAL(timeout()),this,SLOT(MyTimerSlot()));


    this->timer ->start(1000);


}

void MyTimer::MyTimerSlot(){
    //checks if it took 180 secs and stops it.
    this->counter +=1;
    this->label->setText("Time(secs):"+QString::number(this->counter));
    if(this->counter>=180) {

        this->timer->stop();

        //gives message
        QMessageBox *qn = new QMessageBox();
        qn->setText("You failed!");
        qn-> setStandardButtons(QMessageBox::Cancel);
        qn->exec();

    }
}
void MyTimer::stop(){
    //stops the timer.
    this->timer->stop();
}
