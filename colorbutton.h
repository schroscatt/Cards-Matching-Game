#ifndef COLORBUTTON_H
#define COLORBUTTON_H
#include <QPushButton>
#include <QPalette>
//push button
class ColorButton : public QPushButton
{
    Q_OBJECT
public:
  /*takes "?"as default sets it. word is the animal name
   written on the card.
    */
    ColorButton(const QString&text,
                const QString&word,
                QWidget*parent=0);
    QString word;
public slots:
    void show();
};

#endif // COLORBUTTON_H
