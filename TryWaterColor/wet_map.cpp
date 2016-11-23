#include "wet_map.h"
#include <omp.h>

WetMap::WetMap(int width, int height) : m_width(width), m_height(height)
{
    this->m_wetMap = new unsigned char[width * height];
}

void WetMap::UpdateMap()
{
    int i;
    uchar w;
    prepareGeometryChange();
#pragma omp parallel num_threads(1)
{
    #pragma omp for
    for (int y = 0; y < m_height; y++)
        for (int x = 0; x < m_width; x++) {
            i = x + y * m_width;
            w = m_wetMap[i];
            if (w > 0)
                m_wetMap[i]--;
        }
}
    this->update(this->boundingRect());
}

void WetMap::Fill(int* xs, int* ys, int xOffset, int yOffset)
{
    prepareGeometryChange();
    int length = sizeof xs / sizeof xs[0];
    for (int i = 0; i < length; i++) {
        int x = xs[i] + xOffset;
        int y = ys[i] + yOffset;
        if (x < 0 || m_width <= x || y < 0 || m_height <= y)
            continue;
        int pixIndex = x + y * m_width;
        m_wetMap[pixIndex] = 255;
    }
    this->update(this->boundingRect());
}

char WetMap::GetWater(int x, int y)
{
    if (x < 0 || m_width <= x || y < 0 || m_height <= y)
                    return 0;
    int pixelIndex = x + y * m_width;
    return m_wetMap[pixelIndex];
}

void WetMap::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    int i;
    uchar w;
    QImage image(m_width, m_height, QImage::Format_ARGB32_Premultiplied);
    painter->setBackground(Qt::white);

    #pragma omp parallel num_threads(1)
    {
        #pragma omp for
        for (int y = 0; y < m_height; y++)
            for (int x = 0; x < m_width; x++) {
                i = x + y * m_width;
                w = this->m_wetMap[i];
                image.setPixelColor(x, y, QColor(0, 0, 255, (int) w));
            }
    }
    painter->drawImage(0, 0, image);
}

