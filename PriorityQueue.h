/* PriorityQueue.h


 * 
 * Description: 
 * 
 * Author: Kiarash Zamani Anil Bronson
 * Date of last modification: March 20th, 2022
 *


*/


#pragma once

using namespace std;
#include "BinaryHeap.h"

template <class ElementType>
class PriorityQueue {
	
    private:

        BinaryHeap<ElementType> theLine = BinaryHeap<ElementType>();
        unsigned int elementCount;

    public:
        // Description:  Constructor
        PriorityQueue();
        
        // Description: Returns "true" if this Priority Queue is empty, otherwise "false".
        // Postcondition: This Priority Queue is unchanged by this operation.
        // Time Efficiency: O(1)
        bool isEmpty() const;

        // Description: Inserts newElement in this Priority Queue and 
        //              returns "true" if successful, otherwise "false".
        bool enqueue(ElementType& newElement);


        // Description: Removes (but does not return) the element with the next
        //              "highest" priority value from the Priority Queue.
        // Precondition: This Priority Queue is not empty.
        // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
        void dequeue(); 


        // Description: Returns (but does not remove) the element with the next 
        //              "highest" priority from the Priority Queue.
        // Precondition: This Priority Queue is not empty.
        // Postcondition: This Priority Queue is unchanged by this operation.
        // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
        ElementType peek() const;  



};

#include "PriorityQueue.cpp"