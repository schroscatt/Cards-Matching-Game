#include "mygridlayout.h"
#include "colorbutton.h"
mygridlayout::mygridlayout(QTimer *timer) : QGridLayout()
{
    //score label
    this->label = new QLabel("Score:0");
    //set timer
    this->timer = timer;
    //connect timer to the layout to disconnect the buttons when
    // the time is stopped.
    QObject::connect(this->timer,SIGNAL(timeout()),this,SLOT(dis()));


}
//to check if 2 open cards have the same name.
void mygridlayout::match(){

        ColorButton *a=nullptr;
        ColorButton *b=nullptr;
//travels the buttons in layout and checks open cards if the animal names
// are the same. If they are same set their text as empty. Otherwise, "?".
        for(int i=0; i< this->count(); i++){
            ColorButton *widget = qobject_cast<ColorButton*>(this->itemAt(i)->widget());

            if(widget->text()!="" && widget->text()!="?" && a==nullptr)
                a=widget;
            else if(widget->text()!="" && widget->text()!="?" && b==nullptr)
                b=widget;
            if(a!=nullptr && b!=nullptr) break;
        }



       if(a!=nullptr && b!=nullptr){
//singleShot to wait 500 ms after 2 cards opened.
        QEventLoop loop;
        QTimer::singleShot(500, &loop, &QEventLoop::quit);
        loop.exec();
        if(a->text()==b->text()) {
            a->setText("");
            b->setText("");
        }else {
            a->setText("?");
            b->setText("?");
        }
        }

        update();


}

//checks all layout if the game is finished.
void mygridlayout:: check(){
    bool all_same = true;
    int total=0;

    //check if the game is finished.
    for(int i=0; i< this->count(); i++){
        ColorButton *widget = qobject_cast<ColorButton*>(this->itemAt(i)->widget());
        if(widget->text()!="")
            all_same = false;
        if(widget->text()==""){
            total++;
            widget->disconnect();
        }

    }
    //calculate the score and change the label
    this->score= total/2;
    this->label->setText("Score:"+QString::number(this->score));
    //if the game is finished, stop the timer and give message.
    if (all_same) {
        this->timer->stop();
        QMessageBox *qm = new QMessageBox();
        qm->setText("You won!");
        qm->exec();
        qm->setStandardButtons(QMessageBox::Cancel);
    }

}
//when time is stopped, disable all card buttons.
void mygridlayout::dis(){
    if(!this->timer->isActive()) {
    for(int i=0; i< this->count(); i++){
        ColorButton *widget = qobject_cast<ColorButton*>(this->itemAt(i)->widget());
        widget->disconnect();
    }
    }
}
