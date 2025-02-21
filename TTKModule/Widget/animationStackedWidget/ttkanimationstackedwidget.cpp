#include "ttkanimationstackedwidget.h"

#include <QPixmap>
#include <QPainter>
#include <QTransform>
#include <QPropertyAnimation>

TTKAnimationStackedWidget::TTKAnimationStackedWidget(QWidget *parent)
    : QStackedWidget(parent),
      m_isAnimating(false),
      m_currentValue(0),
      m_currentIndex(0),
      m_previousIndex(0),
      m_type(Module::LeftToRight)
{
    m_animation = new QPropertyAnimation(this, QByteArray());
    m_animation->setDuration(500);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    m_animation->setStartValue(0);
    m_animation->setEndValue(0);

    connect(m_animation, SIGNAL(valueChanged(QVariant)), SLOT(valueChanged(QVariant)));
    connect(m_animation, SIGNAL(finished()), SLOT(animationFinished()));

    setLength(200, m_type);
}

TTKAnimationStackedWidget::~TTKAnimationStackedWidget()
{
    delete m_animation;
}

void TTKAnimationStackedWidget::paintEvent(QPaintEvent *event)
{
    if(m_isAnimating)
    {
        QPainter painter(this);
        QTransform transform;

        renderCurrentWidget(&painter, transform);
        renderPreviousWidget(&painter, transform);
    }
    else
    {
        QWidget::paintEvent(event);
    }
}

void TTKAnimationStackedWidget::renderPreviousWidget(QPainter *painter, QTransform &transform)
{
    QWidget *w = widget(m_previousIndex);
    QPixmap pix(w->size());
    w->render(&pix);

    Q_UNUSED(transform);
    switch(m_type)
    {
        case Module::BottomToTop :
                {
                    painter->drawPixmap(0, height() / 2, pix);
                    break;
                }
        case Module::TopToBottom :
                {
                    painter->drawPixmap(0, -height() / 2, pix);
                    break;
                }
        case Module::LeftToRight :
                {
                    painter->drawPixmap(width() / 2, 0, pix);
                    break;
                }
        case Module::RightToLeft :
                {
                    painter->drawPixmap(-width() / 2, 0, pix);
                    break;
                }
        default: break;
    }
}

void TTKAnimationStackedWidget::renderCurrentWidget(QPainter *painter, QTransform &transform)
{
    QWidget *w = widget(m_currentIndex);
    QPixmap pix(w->size());
    w->render(&pix);

    switch(m_type)
    {
        case Module::BottomToTop :
                {
                    transform.translate(0, m_currentValue);
                    painter->setTransform(transform);
                    painter->drawPixmap(0, -height() / 2, pix);
                    break;
                }
        case Module::TopToBottom :
                {
                    transform.translate(0, m_currentValue);
                    painter->setTransform(transform);
                    painter->drawPixmap(0, height() / 2, pix);
                    break;
                }
        case Module::LeftToRight :
                {
                    transform.translate(m_currentValue, 0);
                    painter->setTransform(transform);
                    painter->drawPixmap(-width() / 2, 0, pix);
                    break;
                }
        case Module::RightToLeft :
                {
                    transform.translate(m_currentValue, 0);
                    painter->setTransform(transform);
                    painter->drawPixmap(width() / 2, 0, pix);
                    break;
                }
        default: break;
    }
}

void TTKAnimationStackedWidget::start(int index)
{
    if(m_isAnimating)
    {
        return;
    }

    m_previousIndex = m_currentIndex;
    m_currentIndex = index;

    QWidget *w = widget(m_currentIndex);
    if(!w)
    {
        return;
    }

    const int offsetx = frameRect().width();
    const int offsety = frameRect().height();
    w->setGeometry(0, 0, offsetx, offsety);

    currentWidget()->hide();
    m_isAnimating = true;
    m_animation->start();
}

void TTKAnimationStackedWidget::setLength(int length, Module type)
{
    switch(m_type = type)
    {
        case Module::BottomToTop :
        case Module::LeftToRight :
                {
                    m_animation->setStartValue(-length / 2);
                    m_animation->setEndValue(length / 2);
                    break;
                }
        case Module::TopToBottom :
        case Module::RightToLeft :
                {
                    m_animation->setStartValue(length / 2);
                    m_animation->setEndValue(-length / 2);
                    break;
                }
        default: break;
    }
}

void TTKAnimationStackedWidget::setDuration(int duration)
{
    m_animation->setDuration(duration);
}

int TTKAnimationStackedWidget::duration() const
{
    return m_animation->duration();
}

QSize TTKAnimationStackedWidget::sizeHint() const
{
    return QSize(200, 100);
}

void TTKAnimationStackedWidget::valueChanged(const QVariant &value)
{
    m_currentValue = value.toFloat();
    update();
}

void TTKAnimationStackedWidget::animationFinished()
{
    m_currentValue = 0;
    m_isAnimating = false;

    QWidget *w = widget(m_currentIndex);
    if(w != nullptr)
    {
        w->show();
        w->raise();
        QStackedWidget::setCurrentWidget(w);
    }

    update();
}
