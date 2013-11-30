#include "clicklabel.h"

ClickLabel::ClickLabel(QWidget *parent) : QLabel(parent)
{

}

ClickLabel::ClickLabel(const QString &text, QWidget *parent) : QLabel(parent)
{
    this->setText(text);
}

ClickLabel::~ClickLabel()
{
    delete this;
}

void ClickLabel::slotClicked()
{

}

void ClickLabel::mousePressEvent(QMouseEvent *ev)
{
    emit clicked();
}
