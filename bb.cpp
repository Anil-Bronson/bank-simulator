
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>

#include "Event.h"
#include "BinaryHeap.h"
#include "Queue.h"
#include "PriorityQueue.h"

using namespace std;
//setw

// processArrival(Event arrivalEvent, PriorityQueue Queue, Queue queue){

// }

int main(int argc, char *argv[]){

    cout << "Simulation Begins" << endl;
    
    PriorityQueue<Event> eventQueue = PriorityQueue<Event>();
    
    Queue<Event> bankline = Queue<Event>();

    bool tellerAvailable = true;
    unsigned int current_time = 0;
    double total_time = 0.0;
    
    Event newEvent;
    
    int customers = 0;
    int departure_time = 0;
    int length = 0;
    int time = 0;

    float totalWaitTime= 0.0;
    string aline = "";

    Event newArrivalEvent;

    while( getline(cin >> ws, aline) ){
        stringstream ss(aline);
        ss >> time;
        ss >> length;

        newArrivalEvent = Event();
        newArrivalEvent.setTime(time);
        newArrivalEvent.setLength(length);


        eventQueue.enqueue(newArrivalEvent);
        customers++;
    }
    
   // input.close();
    
    //event loop
    while(!eventQueue.isEmpty()){

        newEvent = eventQueue.peek();
       
        eventQueue.dequeue();
        current_time = newEvent.getTime();
        
        //process arrival
        if(newEvent.isArrival()) {
            //Event customerA = newEvent;
            cout << "Processing an arrival event at time:     "<< current_time << endl;

            if(bankline.isEmpty() && tellerAvailable){
                departure_time = current_time + newEvent.getLength(); 
                //Event DepartureA = Event();                           
                newEvent = Event();
                newEvent.setLength(0);
                newEvent.setTime(departure_time);
                newEvent.setType(Event::DEPARTURE);
                eventQueue.enqueue(newEvent);
                
                tellerAvailable = false;

            } else {
                bankline.enqueue(newEvent);
            }
        //process departure
        } else {
            if(!bankline.isEmpty()){
                newEvent = bankline.peek();
                bankline.dequeue();
                departure_time = current_time + newEvent.getLength();
                cout << "Processing an departure event at time:     "<< departure_time << endl;
                totalWaitTime += current_time - newEvent.getTime();

                newEvent = Event();
                newEvent.setLength(0);
                newEvent.setTime(departure_time);
                newEvent.setType(Event::DEPARTURE);
                eventQueue.enqueue(newEvent);
            } else {
                tellerAvailable = true;
            }
        }
    }
	cout << "Simulation Ends" << endl << endl;


	float averageWaitTime = totalWaitTime / customers;

	cout << "Final Statistics:" << endl;
	cout << "	Total number of people processed:  " << customers << endl;
	cout << "	Average amount of time spent waiting: " 
		 << averageWaitTime << endl;
}
