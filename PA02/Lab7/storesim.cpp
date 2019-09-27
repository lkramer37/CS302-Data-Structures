//--------------------------------------------------------------------
//
//  Laboratory 7, Programming Exercise 1                   storesim.cs
//
//  Program implementation shell.
//
//--------------------------------------------------------------------

// Simulates the flow of customers through a line in a store.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "config.h"

// Use which ever implementation is currently configured.
#if LAB7_TEST1
#   include "QueueLinked.cpp"
#else
#   include "QueueArray.cpp"
#endif

using namespace std;

int main ()
{
#if LAB7_TEST1
    QueueLinked<int> custQ;      // Line (queue) of customers containing the
#else
    QueueArray<int> custQ;       // Line (queue) of customers containing the
#endif 				 //   time that each customer arrived and
                                 //   joined the line
    int simLength, // Length of simulation (minutes)
        minute = 0, // Current minute
        timeArrived, // Time dequeued customer arrived
        waitTime, // How long dequeued customer waited
        totalServed = 0, // Total customers served
        totalWait   = 0, // Total waiting time
        maxWait     = 0,         // Longest wait
        numArrivals = 0; // Number of new arrivals

    // Seed the random number generator. Equally instructive to run the
    // simulation with the generator seeded and not seeded.
    srand(7);

    cout << endl << "Enter the length of time to run the simulator : ";
    cin >> simLength;

    // Put your code here to run this simulation. Use "rand()" to get
    // a pseudorandom number that you can use to calculate probabilities.

    custQ.clear(); //Initialize the queue to empty
    while(minute < simLength){//While the simulation is not done
      ++minute; //Increment simulated time by one minute
      if(!custQ.isEmpty()){ //If the queue is not empty, then remove the customer at the front of the queue
        int timeArrived = custQ.dequeue();
        ++totalServed;
        waitTime = minute - timeArrived;
        totalWait += waitTime;
        if(waitTime>maxWait){
          maxWait = waitTime;
        }
      }
      int k = (rand() % 4); //Compute a random number k between 0 and 3
        if(k == 1){ //if k is 1, then add one customer to the line
          custQ.enqueue(minute);
          ++numArrivals;
        }
        if(k == 2){ //if k is 2, then add two customers to the line
          custQ.enqueue(minute);
          ++numArrivals;
          custQ.enqueue(minute);
          ++numArrivals;
        }
    }
    // Print out simulation results
    cout << endl;
    cout << "Customers served : " << totalServed << endl;
    cout << "Average wait     : " << setprecision(2)
         << double(totalWait)/totalServed << endl;
    cout << "Longest wait     : " << maxWait << endl;

    return 0;
}
