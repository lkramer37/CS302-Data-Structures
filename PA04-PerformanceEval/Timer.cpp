// Timer.cpp

#include <ctime>
#include <stdexcept>
#include <iostream>
#include  <sys/time.h>

#include "Timer.h"

using namespace std;

///Constructor - Initializes the internal timer values so that the timer is ready to measure time.
Timer::Timer()
{
  timerWasStarted = 0;
}

///start() function - Marks the beginning of a time interval (starts the timer). Requires the clock function is working correctly.
void Timer::start() throw (runtime_error)
{
  if(gettimeofday(&beginTime, NULL) == -1)
  {
    throw runtime_error("Timer didn't start");
  }
  timerWasStarted = true;
}

///stop() function - Marks the end of a timer interval (stops the timer). Requires the beginning of a time interval has been marked.
void Timer::stop() throw (logic_error)
{
  if (!timerWasStarted)
  {
    throw logic_error("stop() timer wasn't started");
  }
  gettimeofday(&duration, NULL);
}

///getElapsedTime() function - Returns the length of the time interval in seconds.
double Timer::getElapsedTime() const throw (logic_error)
{
  timeval dTmp(duration);
  timeval bTmp(beginTime);

  double t1, t2;
  t1 = dTmp.tv_sec * 1000000 + dTmp.tv_usec;
  t2 = bTmp.tv_sec * 1000000 + bTmp.tv_usec;
  return (t1 - t2)/1000000;
}
