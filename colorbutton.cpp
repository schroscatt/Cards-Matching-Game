#include "colorbutton.h"

ColorButton::ColorButton(const QString&text,
                         const QString&word,
                         QWidget*parent):
    QPushButton(text,parent)
{
    //set word
    this->word = word;

    //set the color of the button as cyan
    QPalette pal = palette();
    pal.setColor(QPalette::Button, QColor(Qt::cyan));

    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();

}

//slot to show the word hidden on the card
void ColorButton::show(){
    this->setText(this->word);
    update();
}

