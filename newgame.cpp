#include "newgame.h"
//all game is created here, this objects creates new game button.
newgame::newgame(QApplication *app,QWidget *parent): QPushButton("New Game", parent)

{
    //set the app
    this->app = app;
    //set the color of the button.
    QPalette pal = palette();
    pal.setColor(QPalette::Button, QColor(Qt::cyan));

    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    // at first call creates the game
    restart();
    //connect new game button to the restart slot, to restart the game.
    QObject::connect(this,SIGNAL(clicked()),
                     this,SLOT(restart()));

    update();

}
//play game.
void newgame:: restart(){
    //main windows
    QWidget *cw = new QWidget();
    //vertical box layout
    QVBoxLayout *vb = new QVBoxLayout();
    //horizontal box layout
    QHBoxLayout *hl = new QHBoxLayout();
    //timer
    MyTimer *mt = new MyTimer();
    //create grid layout
    mygridlayout *gl = new mygridlayout(mt->timer);
    //anime name list
    QList<QString> list={"Tiger","Tiger","Cat","Cat","Monkey","Monkey","Donkey","Donkey","Bird","Bird","Dog","Dog","Sloth",
                        "Sloth","Lion","Lion","Horse","Horse","Panda","Panda","Turtle","Turtle","Hamster","Hamster",
                        "Rabbit","Rabbit","Deer","Deer","Bee","Bee"};
    //set the grid layout randomly with items in list.
    for(int row=0; row<5;row++) {
        for(int col=0; col<6; col++) {
            //get random element.
            qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
            int color_cd = qrand()%list.size();
            QString color = list.at(color_cd);
            list.removeAt(color_cd);
            //create the button and add it to the layout.
            ColorButton *randButton = new ColorButton("?",color);
            gl->addWidget(randButton, row, col, 1, 1);
            //connect button to the show() slot. So, when it is clicked, it will show the name.
            QObject::connect(randButton,SIGNAL(clicked()),
                             randButton,SLOT(show()));
            //connect button to the match() slot. So, when it is clicked, it will check if there are matched cards.
            QObject::connect(randButton, SIGNAL(clicked()),
                                         gl, SLOT(match()));
            //connect button to the check() slot. So, when it is clicked, it will check if the game is over.
            QObject::connect(randButton, SIGNAL(clicked()),
                                         gl, SLOT(check()));

        }
    }

    //add timer label
    hl->addWidget(mt->label);
    //add score label
    hl->addWidget(gl->label);


    //add quit button and connect it to quit the app.
    ColorButton *quitgame = new ColorButton("Quit","");
    QObject::connect(quitgame, SIGNAL(clicked()),
                                 this->app, SLOT(quit()));

    //connect the new game button, to close the current game and create new one.
    QObject::connect(this,SIGNAL(clicked()),cw,SLOT(close()));

    QObject::connect(this,SIGNAL(clicked()),mt,SLOT(stop()));

    //spacer item
    QSpacerItem *si = new QSpacerItem(0,10,
                                      QSizePolicy::Expanding,
                                      QSizePolicy::Expanding);
    //add spacer item to the horizontal layout.
    hl->addSpacerItem(si);

    //add new game and quit bottons.
    hl->addWidget(this);
    hl->addWidget(quitgame);

    //add horizontal layout to the vertical one.
    vb->addLayout(hl);
    //add spacer item
    vb -> addSpacerItem(si);
    //add the grid layout
    vb -> addLayout(gl);
    //set window title
    cw ->setWindowTitle("Card Match Game");
    //resize the game
    cw -> resize(640,240);
    //set the layout with vertical box
    cw -> setLayout(vb);
    cw ->show();
}
