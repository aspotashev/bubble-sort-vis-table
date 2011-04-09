#ifndef BALL_H
#define BALL_H

#include <QtGui>

class Ball : public QGraphicsItem
{
public:
    Ball(int x, int y, int r, QColor color);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    void slice();

private:
    int m_x;
    int m_y;
    int m_r;
    QColor m_color;
    Ball *m_children[4];
};

#endif // BALL_H
