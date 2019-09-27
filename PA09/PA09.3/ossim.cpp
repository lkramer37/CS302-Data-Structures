//--------------------------------------------------------------------
//
//  Laboratory 11, Programming Exercise 1                     ossim.cs
//  (Shell) Operating system task scheduling simulation
//--------------------------------------------------------------------

// Simulates an operating system's use of a priority queue to regulate
// access to a system resource (printer, disk, etc.).

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "PriorityQueue.cpp"

using namespace std;

//--------------------------------------------------------------------
//
// Declaration for the task data struct
//

struct TaskData
{
    int getPriority () const
        { return priority; }     // Returns the priority. Needed by the heap.

    int priority,                // Task's priority
        arrived;                 // Time when task was enqueued
};

//--------------------------------------------------------------------

int main ()
{
    PriorityQueue<TaskData, int, Less<int> > taskPQ;   // Priority queue of tasks
    TaskData task;                   // Task
    int simLength = 0,               // Length of simulation (minutes)
        minute = 0,                  // Current minute
        numPtyLevels = 0,            // Number of priority levels
        numArrivals = 0,             // Number of new tasks arriving
        j;                          // Loop counter
    int waitTime, // How long dequeued customer waited


    // Seed the random number generator
    srand(7);

    cout << endl << "Enter the number of priority levels : ";
    cin >> numPtyLevels;

    cout << "Enter the length of time to run the simulator : ";
    cin >> simLength;

    taskPQ.clear(); //Initialize the queue to empty

    for ( minute = 0 ; minute < simLength ; minute++ )
    {
        // Dequeue the first task in the queue (if any).
        if(!taskPQ.isEmpty()) //If not empty, remove customer at the front
        {
            task = taskPQ.dequeue();
            //waitTime = minute - task.arrived;
            cout << "At " << minute << " dequeued : ";
            cout << task.priority << " " << task.arrived << " " << minute - task.arrived << endl;
        }

        // Determine the number of new tasks and add them to the queue.
        
        //if(!taskPQ.isFull())
        //{
            numArrivals = rand() % 4; //Compute a random number k between 0 and 3
            if(numArrivals == 1) //if k is 1, then add one customer to the line
            {
                
                task.priority = rand() % numPtyLevels;
                /*
                task.arrived = minute;
                taskPQ.enqueue(task);
                */
                 cout << "Insert 1: " << task.priority << " " << task.arrived << " " << minute - task.arrived << endl;
            }

            if(numArrivals == 2) //if k is 2, then add two customers to the line
            {
               
                task.priority = rand() % numPtyLevels;
                /*               
                task.arrived = minute;
                taskPQ.enqueue(task);
                */
                cout << "Insert 2A : " << task.priority << " " << task.arrived << " " << minute - task.arrived << endl;
    
                task.priority = rand() % numPtyLevels;
                /*
                task.arrived = minute;
                taskPQ.enqueue(task);
                */
                cout << "Insert 2B : " << task.priority << " " << task.arrived << " " << minute - task.arrived << endl;
            }
        //}
    }

    return 0;
}

