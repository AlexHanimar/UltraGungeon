#include <Helpers/Helpers.h>

QPointF normalize(QPointF vec)
{
    if(vec.manhattanLength() == 0)
        return vec;
    qreal mod = vec.x() * vec.x() + vec.y() * vec.y();
    mod = sqrt(mod);
    return vec / mod;
}

qreal module(QPointF vec)
{
    qreal mod = vec.x() * vec.x() + vec.y() * vec.y();
    mod = sqrt(mod);
    return mod;
}

QPointF rotate(QPointF vec, qreal angle)
{
    qreal nx = vec.x() * cos(angle) - vec.y() * sin(angle);
    qreal ny = vec.x() * sin(angle) + vec.y() * cos(angle);
    return QPointF(nx, ny);
}
