//#include "ledindicator.h"

//LedIndicator::LedIndicator(QWidget *parent) : QWidget(parent), m_color(Qt::blue) {
//    setFixedSize(100, 100); // Set the fixed size of the widget
//}

//void LedIndicator::setColor(const QColor &color) {
//    m_color = color;
//    update(); // Trigger a repaint
//}

//void LedIndicator::changeToRed() {
//    setColor(Qt::red);
//}

//void LedIndicator::changeToGreen() {
//    setColor(Qt::green);
//}

//void LedIndicator::paintEvent(QPaintEvent *event) {
//    Q_UNUSED(event);

//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing, true); // Enable antialiasing
//    painter.setBrush(m_color);
//    painter.drawEllipse(rect()); // Draw a circle that fits the widget's rectangle
//}
