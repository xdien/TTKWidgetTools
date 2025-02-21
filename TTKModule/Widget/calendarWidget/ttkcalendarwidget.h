#ifndef TTKCALENDARWIDGET_H
#define TTKCALENDARWIDGET_H

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

#include <QLabel>
#include <QPushButton>
#include <QCalendarWidget>
#include "ttkmoduleexport.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKCalendarWidget : public QCalendarWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKCalendarWidget)
public:
    explicit TTKCalendarWidget(QWidget *parent = nullptr);

    virtual QSize sizeHint() const override final;

private Q_SLOTS:
    void buttonClicked();
    void setDataLabelTimeText(int year, int month);

private:
#if TTK_QT_VERSION_CHECK(6,0,0)
    virtual void paintCell(QPainter *painter, const QRect &rect, QDate date) const override final;
#else
    virtual void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const override final;
#endif

    void initControl();
    void initTopWidget();
    void initBottomWidget();

    QPushButton *m_leftYearButton, *m_leftMonthButton;
    QPushButton *m_rightYearButton, *m_rightMonthButton;
    QLabel *m_dataLabel;

};

#endif // TTKCALENDARWIDGET_H
