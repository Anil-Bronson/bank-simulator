/*
 * SimulationApp.cpp
 * 
 * Class Description: Simulates a line up with one teller.
 *					  Calculates the average wait time for each Event.
 *					  Also outputs the number of Events and the time of each
 *					  Event's arrival/departure in order.
 *
 * Last modified on: June 30, 2017
 * Author: Jacky Tse, Vicky Lau
 */

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"

using namespace std;

int main(int argc, char *argv[]){

    cout << "Simulation Begins" << endl;
    
    PriorityQueue<Event> *EventQueue = new PriorityQueue<Event>();
    
    Queue<Event> *bankline = new Queue<Event>();

    bool tellerAvailable = true;
    unsigned int current_time = 0;
    int customers = 0;
    int departure_time = 0;
    int length = 0;
    int time = 0;
    float totalWaitTime= 0.0;
    
	string aline = "";
	
	Event newEvent;
    Event newArrivalEvent;

    while( getline(cin >> ws, aline) ){
        stringstream ss(aline);
        ss >> time >> length;

        newArrivalEvent = Event();
        newArrivalEvent.setTime(time);
        newArrivalEvent.setLength(length);

        EventQueue->enqueue(newArrivalEvent);
        customers++;
    }

    // Event loop
    while(!EventQueue->isEmpty()){
      	
		newEvent = EventQueue->peek();

      	current_time = newEvent.getTime();

      	// Process an Arrival Event
      	if(newEvent.isArrival()){
      		cout << "Processing an arrival event at time:     "<< current_time << endl;

      		EventQueue->dequeue();
      		
      		// Event line goes directly to teller
			if(bankline->isEmpty() && tellerAvailable){

				departure_time = current_time + newEvent.getLength();

				// Departing Event 
				newEvent = Event();
				newEvent.setTime(departure_time);
                newEvent.setType(Event::DEPARTURE);
				newEvent.setLength(0);
               

				// Departure Event 
				if(!EventQueue->enqueue(newEvent)){
					return(1);
				}

				tellerAvailable = false;
			}
				else{
					bankline->enqueue(newEvent);
				}
		}
		
		
		// Process a Departure Event
      	else{	
			newEvent = EventQueue->peek();
      		cout << "Processing a departure event at time:    " << current_time << endl; //newEvent.getTime()

      		// Dequeuing a departure event 
      		EventQueue->dequeue();
		  }
      		// Enqueues the leaving Event into a delete queue
      		// since deleting here causes a segmentation fault

      		if(!bankline->isEmpty()){
      			// Event at front of line 
			
				newEvent = bankline->peek();

      			totalWaitTime = (current_time - newEvent.getTime());
				// cout << "CURRENT: " << current_time << endl;
				// cout << "TIME: " << newEvent.getTime() << endl;
				// cout << "TOTAL :" << totalWaitTime << endl;
      			bankline->dequeue();
      			
      			departure_time = current_time + newEvent.getLength();

				// Next departing event
      			newEvent = Event();
				newEvent.setTime(departure_time);
				newEvent.setLength(0);
				newEvent.setType(Event::DEPARTURE);

      			if(!EventQueue->enqueue(newEvent)){
      				return (1);
				}
      		else{
      			tellerAvailable = true;
      		}
			}
    
	}
	cout << "Simulation Ends" << endl << endl;


	int averageWaitTime = totalWaitTime / customers;

	cout << "Final Statistics:" << endl;
	cout << "	Total number of people processed:  " << customers << endl;
	cout << "	Average amount of time spent waiting: " << averageWaitTime << endl;
	delete bankline;
	delete EventQueue;
}