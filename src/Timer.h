#ifndef TIMER_H_DEFINED
#define TIMER_H_DEFINED

#include <SFML/System.hpp>
#include <memory>

namespace sf{
	class Clock;
}

typedef std::shared_ptr<sf::Clock> ClockPtr;

class Timer
{
	public:
		Timer();
		~Timer() {}

		void start();
		void reset();
		void pause();
		void resume();
		void stop();
		bool isStarted();
		bool isPaused();
                bool isRunning();
		unsigned int getTicks();
                
                int delta();
                int delta_ms();
                int delta_s();
                unsigned int currentTime();

	private:
		ClockPtr m_clock;
		unsigned int m_startTicks;
		unsigned int m_pausedTicks;
                unsigned int m_stopMark;
		bool m_paused;
		bool m_started;
};

#endif /* TIMER_H_DEFINED */

