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
  // You should change the data types for your clocks based upon what timer you use and include the right .h file
  beginTime = 0;
  stopTime = 0;
  duration = 0;
}

///start() function - Marks the beginning of a time interval (starts the timer). Requires the clock function is working correctly.
void Timer::start() throw (runtime_error)
{
  timeval tmp;
  gettimeofday(&tmp, NULL);
  beginTime = tmp.tv_sec+(tmp.tv_usec/1000000.0);
  timerWasStarted = true;
}

///stop() function - Marks the end of a timer interval (stops the timer). Requires the beginning of a time interval has been marked.
void Timer::stop() throw (logic_error)
{
  if (!timerWasStarted)
  {
    throw logic_error("stop() timer wasn't started");
  }

  timeval tmp;
  gettimeofday(&tmp, NULL);
  stopTime = tmp.tv_sec+(tmp.tv_usec/1000000.0);
  duration = stopTime - beginTime;
}

///getElapsedTime() function - Returns the length of the time interval in seconds.
double Timer::getElapsedTime() const throw (logic_error)
{  
  return duration;
}
