
#ifndef NEWGAME_H
#define NEWGAME_H
#include <QApplication> //for app
#include <QWidget> //for widgets
#include <QVBoxLayout> //for layout
#include <QSpacerItem> //for spacer item
#include <QList> //for list
#include <QDateTime>  //to set random
#include "mytimer.h"
#include "colorbutton.h"
#include "mygridlayout.h"


//creates the game and new game button
class newgame : public QPushButton
{    Q_OBJECT

 public:
     newgame(QApplication *app, QWidget *parent=0);
     QApplication *app;


 public slots:
      //restart the game if the new game button is clicked.
     void restart();
};

#endif // NEWGAME_H
