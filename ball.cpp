#include "ball.h"

Ball::Ball(int x, int y, int r, QColor color)
{
    m_x = x;
    m_y = y;
    m_r = r;
    m_color = color;

    for (int i = 0; i < 4; i ++)
        m_children[i] = NULL;

    setAcceptHoverEvents(true);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(QBrush(m_color));
    painter->setPen(m_color.lighter());
    painter->drawEllipse(boundingRect());
}

QRectF Ball::boundingRect() const
{
    return QRectF(m_x - m_r, m_y - m_r, 2 * m_r, 2 * m_r);
}

void Ball::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    // position with respect to ball's center
    QPointF pos = event->pos() - QPointF(m_x, m_y);

    // clicked inside the ball and ball is not too small
    if (sqrt(pow(pos.x(), 2) + pow(pos.y(), 2)) <= m_r && m_r > 5)
        slice();
}

void Ball::slice()
{
    const QColor colors[4] = {Qt::red, Qt::darkGreen, Qt::darkCyan, Qt::darkYellow};

    for (int i = 0; i < 4; i ++)
    {
        int hmul = -1 + 2 * ((i >> 1) & 1);
        int vmul = -1 + 2 * (i & 1);

        m_children[i] = new Ball(m_x + hmul * m_r/2, m_y + vmul * m_r/2, m_r/2, colors[i]);
        scene()->addItem(m_children[i]);
    }

    scene()->removeItem(this);
}
