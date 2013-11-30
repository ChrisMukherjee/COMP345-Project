#ifndef CLICKLABEL_H
#define CLICKLABEL_H

#include <QLabel>

class ClickLabel : public QLabel
{
    Q_OBJECT

public:
    explicit ClickLabel(QWidget *parent = 0);
    explicit ClickLabel(const QString &text, QWidget *parent = 0);
    ~ClickLabel();

signals:
    void clicked();

public slots:
    void slotClicked();

protected:
    void mousePressEvent(QMouseEvent *ev);
};

#endif // CLICKLABEL_H
