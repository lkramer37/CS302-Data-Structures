// Timer.h

#ifndef TIMER_H
#define TIMER_H

#include <ctime>
#include <stdexcept>
#include <iostream>

using namespace std;


class Timer {
  public:
    Timer();
    void start() throw (runtime_error);
    void stop() throw (logic_error);
    double getElapsedTime() const throw (logic_error);

  private:
    clock_t beginTime;
    clock_t duration;
    bool timerWasStarted;
};

#endif	// ifndef TIMER_H
