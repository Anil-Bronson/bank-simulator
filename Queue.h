/* Queue.h


 * 
 * Description: 
 * 
 * Author: Kiarash Zamani
 * Date of last modification: March 20th, 2022
 *


*/

#pragma once

using namespace std;

template <class ElementType>
class Queue {
	
    private:
        static unsigned const INITIAL_CAPACITY = 10; // Constant INITIAL_CAPACITY
        ElementType *elements; //changed to pointer    

        unsigned elementCount;                      // Number of elements in the Queue
        unsigned capacity;                          // Actual capacity of the data structure (number of cells in the array)
                

    public:
        // Description:  Constructor
        Queue();

        //Description:  Destructor
        ~Queue();

        
        // Description: Returns "true" if this Queue is empty, otherwise "false".
        // Postcondition: This Queue is unchanged by this operation.
        // Time Efficiency: O(1)
        bool isEmpty() const;

        // Description: Inserts newElement at the "back" of this Queue 
        //              (not necessarily the "back" of its data structure) and 
        //              returns "true" if successful, otherwise "false".
        // Time Efficiency: O(1)
        bool enqueue(ElementType& newElement);


        // Description: Removes (but does not return) the element at the "front" of this Queue 
        //              (not necessarily the "front" of its data structure).
        // Precondition: This Queue is not empty.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
        // Time Efficiency: O(1)
        void dequeue(); 


        // Description: Returns (but does not remove) the element at the "front" of this Queue
        //              (not necessarily the "front" of its data structure).
        // Precondition: This Queue is not empty.
        // Postcondition: This Queue is unchanged by this operation.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.
        // Time Efficiency: O(1)
        ElementType& peek() const;  



};

#include "Queue.cpp"