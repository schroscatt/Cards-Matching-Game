#include <QApplication>

#include "newgame.h"

int main(int argc, char *argv[])
{
    //create app
    QApplication app(argc,argv);
    //run newgame
    newgame *game = new newgame(&app);
    //execute app
    return app.exec();
}

