/* Queue.cpp

 * 
 * Description: 
 * 
 * Author: Kiarash Zamani
 * Date of last modification: March 20th, 2022
 *



*/

 
#include "Queue.h"
#include "EmptyDataCollectionException.h"
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

// Description:  Constructor
template <class ElementType>
Queue<ElementType>::Queue() : elementCount(0), capacity(INITIAL_CAPACITY) {
} 

//destructor for heap allocated memory
template <class ElementType>
Queue<ElementType>::~Queue(){
    
    delete [] elements;
    elements = NULL;
    elementCount = 0;
    return;

}

        // Description: Returns "true" if this Queue is empty, otherwise "false".
        // Postcondition: This Queue is unchanged by this operation.
        // Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const{
    if (elementCount == 0)
    {
        return true;
    } 
    else 
    {
        return false;
    }
}

   // Description: Inserts newElement at the "back" of this Queue 
   //              (not necessarily the "back" of its data structure) and 
   //              returns "true" if successful, otherwise "false".
   // Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::enqueue(ElementType& newElement) { ///////////////should be done
    
    //dynamically creates array
    if(elementCount == 0)
        elements = new ElementType[capacity]; //////////////////check syntax

    //if array capacity is reach
    if(elementCount >= capacity){
        capacity = capacity*2;
        ElementType *newArr = new ElementType[capacity];
        
        //copy from elements to newArr
        for( int i = 0; i < elementCount; i++){
           newArr[i] = elements[i];
        } 

        newArr[elementCount] = elements[elementCount];      
        //change capacity
        //capacity = newSize;

        //copy the elementCount
        this->elementCount = elementCount;
       
        delete [] elements;
        elements = newArr;
        
        
        
    } else if(elementCount < capacity){
        elements[elementCount] = newElement;                                ////////////////////////////back of the data structure or not, explaination confusing
    }


  
    elementCount++;
    return true;

}  


   // Description: Removes (but does not return) the element at the "front" of this Queue 
   //              (not necessarily the "front" of its data structure).
   // Precondition: This Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
   // Time Efficiency: O(1)
template <class ElementType>
void Queue<ElementType>::dequeue() {                //////////////have to change  inside
    

    
    if(this->isEmpty() == false){                  //////////////not sure about this

        int minCapacity = (capacity/4) + INITIAL_CAPACITY;
    
    //check if array is 1/4 full
    if(elementCount <= capacity*(1/4)){ 
        
        int newSize = minCapacity;
       // frontindex = newSize;
        ElementType *newArr = new ElementType[newSize];
        if(newArr == NULL){
            ///////////////////////////return false or exception   , checking to see if th eheap has ran out
        }
        
        //copy from elements to newArr
        for( int i = 0; i < newSize; i++)
           newArr[i] = elements[i];
       
        //change capacity
        capacity = newSize;
       
        delete [] elements;
        elements = newArr;
        
    }
    
    this->elementCount--;

        
    } 
    else {
        throw EmptyDataCollectionException("Empty data collection.");
    }


} 


   
   // Description: Returns (but does not remove) the element at the "front" of this Queue
   //              (not necessarily the "front" of its data structure).
   // Precondition: This Queue is not empty.
   // Postcondition: This Queue is unchanged by this operation.
   // Exception: Throws EmptyDataCollectionException if this Queue is empty.
   // Time Efficiency: O(1)
template <class ElementType>
ElementType& Queue<ElementType>::peek() const {
    
    if(this->isEmpty() == false){
        return elements[0];
    
    } else {
        throw EmptyDataCollectionException("Empty data collection.");
    }
} 








