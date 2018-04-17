//Source:
//https://stackoverflow.com/questions/282938/show-result-of-color-selection-in-qt?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa

#include "colorbutton.h"

ColorButton::ColorButton(QWidget *parent,const QColor & color) :
    QPushButton(parent)
{
    this->setMinimumWidth(50);
    currentColor = color;
    connect(this, SIGNAL(clicked()), this, SLOT(chooseColor()));
}

QColor ColorButton::getColor()
{
    return currentColor;
}

void ColorButton::setColor(const QColor color)
{
    currentColor = color;

}

void ColorButton::chooseColor()
{
    QColor color = QColorDialog::getColor(currentColor, this);
    if (color.isValid()){
         setColor(color);
         emit colorChanged(currentColor);
    }
}

void ColorButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);

    int colorPadding = 5;

    QRect rect = event->rect();
    QPainter painter( this );
    painter.setBrush( QBrush( currentColor ) );
    painter.setPen("#CECECE");
    rect.adjust(colorPadding, colorPadding, -1-colorPadding, -1-colorPadding);
    painter.drawRect(rect);
}
