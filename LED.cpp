// #include "led.h"

// LED::LED(QPushButton *button, QObject *parent) :
//     QObject(parent),
//     m_button(button),
//     m_state(false)
// {
//     connect(m_button, &QPushButton::clicked, this, &LED::toggleState);

//     m_timer = new QTimer(this);
//     connect(m_timer, &QTimer::timeout, this, &LED::toggleState);
// }

// void LED::toggleState()
// {
//     m_state = !m_state;
//     updateState();
// }

// void LED::startBlinking()
// {
//     m_timer->start(500); // Blink interval of 500 milliseconds
// }

// void LED::stopBlinking()
// {
//     m_timer->stop();
// }

// void LED::updateState()
// {
//     if (m_state)
//         m_button->setStyleSheet("background-color: red");
//     else
//         m_button->setStyleSheet("background-color: none");
// }
