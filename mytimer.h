#ifndef MYTIMER_H
#define MYTIMER_H

#include <QTimer>
#include <QLabel>
#include <QMessageBox>

//timer object to measure the time.
class MyTimer : public QObject
{
    Q_OBJECT

public:
    MyTimer();
    QTimer *timer;
    //timer label
    QLabel *label;
    int counter;

public slots:
    //check if it took 180 secs
    void MyTimerSlot();
    //stop the timer.
    void stop();
};

#endif // MYTIMER_H
