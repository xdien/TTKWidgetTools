#ifndef TTKBARRULERLABEL_H
#define TTKBARRULERLABEL_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2023 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include <QWidget>
#include "ttkmoduleexport.h"

/*!
* @author Greedysky <greedysky@163.com>
*         feiyangqingyun <feiyangqingyun@163.com>
*/
class TTK_MODULE_EXPORT TTKBarRulerLabel : public QWidget
{
    Q_OBJECT    
    TTK_DECLARE_MODULE(TTKBarRulerLabel)
public:
    explicit TTKBarRulerLabel(QWidget *parent = nullptr);
    ~TTKBarRulerLabel();

    void setRange(double minValue, double maxValue);

    void setMinValue(double minValue);
    void setMaxValue(double maxValue);

    void setValue(double value);

    void setPrecision(int precision);

    void setLongStep(int longStep);
    void setShortStep(int shortStep);

    void setSpace(int space);

    void setAnimation(bool animation);
    void setAnimationStep(double animationStep);

    void setBackgroundColorStart(const QColor &backgroundColorStart);
    void setBackgroundColorEnd(const QColor &backgroundColorEnd);

    void setLineColor(const QColor &lineColor);

    void setBarBackgroundColor(const QColor &barBackgroundColor);
    void setBarColor(const QColor &barColor);

    virtual QSize sizeHint() const override final;

private Q_SLOTS:
    void updateValue();

private:
    virtual void paintEvent(QPaintEvent *event) override final;

    void drawBackground(QPainter *painter);
    void drawRuler(QPainter *painter);
    void drawBarBackground(QPainter *painter);
    void drawBar(QPainter *painter);

    double m_minValue;
    double m_maxValue;
    double m_value;
    int m_precision;

    int m_longStep;
    int m_shortStep;
    int m_space;

    bool m_animation;
    double m_animationStep;

    QColor m_backgroundColorStart;
    QColor m_backgroundColorEnd;
    QColor m_lineColor;
    QColor m_barBackgroundColor;
    QColor m_barColor;

    bool m_reverse;
    double m_currentValue;
    QTimer *m_timer;
    QRectF m_barRect;

};

#endif // TTKBARRULERLABEL_H
