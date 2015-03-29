#include "Timer.h"


#define getElapsedTimeMs() getElapsedTime().asMilliseconds()

Timer::Timer() {
    m_clock = ClockPtr(new sf::Clock());

    m_started = false;
    m_paused = false;

    m_startTicks = 0;
    m_pausedTicks = 0;
    m_stopMark=0;
}

void Timer::start() {
    if (!isStarted()) {
        m_started = true;
        m_paused = false;
    }

    reset();
}

void Timer::reset() {
    if (isStarted()) {
        m_startTicks = m_clock->getElapsedTimeMs() - m_pausedTicks;
    }
}

void Timer::pause() {
    if (isStarted() && !isPaused()) {
        m_paused = true;
        m_pausedTicks = m_clock->getElapsedTimeMs() - m_startTicks;
    }
}

void Timer::resume() {
    if (isPaused()) {
        m_paused = false;

        reset();
    }
}

void Timer::stop() {
    if (isStarted()) {
        m_started = false;
        m_paused = false;
    }
}

unsigned int Timer::getTicks() {
    if (isStarted()) {
        if (isPaused()) {
            return m_pausedTicks;
        } else {
            return m_clock->getElapsedTimeMs() - m_startTicks;
        }
    }

    return 0;
}

int Timer::delta() {
    if (this->isRunning())
        return this->currentTime();

    if (this->m_paused)
        return this->m_pausedTicks;

    // Something went wrong here
    if (this->m_startTicks == 0)
        return 0;

    return (this->m_stopMark) - (this->m_startTicks);
}

int Timer::delta_ms() {
    return this->delta() % 1000;
}

int Timer::delta_s() {
    return this->delta() / 1000;
}

bool Timer::isStarted() {
    return m_started;
}

bool Timer::isPaused() {
    return m_paused;
}

bool Timer::isRunning(){
    return this->isStarted() && !this->isPaused();
}

unsigned int Timer::currentTime(){
    return (m_clock->getElapsedTimeMs()) - (this->m_startTicks);
}