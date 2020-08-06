#ifndef MYGRIDLAYOUT_H
#define MYGRIDLAYOUT_H
#include <QGridLayout>
#include <QTimer>
#include <QLabel>
#include <QMessageBox>
#include <QEventLoop>
#include "colorbutton.h"

//grid layout where the cards are placed.
class mygridlayout : public QGridLayout
{
    Q_OBJECT
public:
    //it takes timer object.
    mygridlayout(QTimer *timer);
    QTimer *timer;
    //label for score.
    QLabel *label;
    //keeps the total score
    int score=0;

public slots:
    //check the game is finished
    void check();
    //check if the cards are matched
    void match();
    //disable buttons.
    void dis();
};

#endif // MYGRIDLAYOUT_H
