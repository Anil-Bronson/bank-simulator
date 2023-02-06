/* PriorityQueue.cpp


 * 
 * Description: 
 * 
 * Author: Kiarash Zamani Anil Bronson
 * Date of last modification: March 20th, 2022
 *

*/
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

// Description:  Constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(){
    
    elementCount= 0;
} 


        // Description: Returns "true" if this Priority Queue is empty, otherwise "false".
        // Postcondition: This Priority Queue is unchanged by this operation.
        // Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const{
    if(elementCount == 0){
        return true;
    } else {
        return false;
    }
}

        // Description: Inserts newElement in this Priority Queue and 
        //              returns "true" if successful, otherwise "false".
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType& newElement) { ///////////////have to change inside
    
    if(theLine.insert(newElement)){
        elementCount++;
        return true;
    }

    else 
        return false;
    

}  


        // Description: Removes (but does not return) the element with the next
        //              "highest" priority value from the Priority Queue.
        // Precondition: This Priority Queue is not empty.
        // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
template <class ElementType>
void PriorityQueue<ElementType>::dequeue() {                //////////////have to change  inside

    theLine.remove();
    elementCount--;
} 


   
// Description: Returns (but does not remove) the element with the next 
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
template <class ElementType>
ElementType PriorityQueue<ElementType>::peek() const {//////////////have to change inside

    return theLine.retrieve();
} 



