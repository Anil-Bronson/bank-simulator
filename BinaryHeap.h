/* BinaryHeap.h
Anil B, Kiarash Z
March 23, 2022

Header file for our binary heap data structure
*/



#pragma once

#include "Event.h"
#include <iostream>
#include "EmptyDataCollectionException.h"   
#include <math.h>   //for the floor function

using namespace std;

template <class ElementType>
class BinaryHeap {

private:

	unsigned int elementCount;
	unsigned const INITAL_CAPACITY = 10;
	unsigned int capacity = INITAL_CAPACITY;

	ElementType *elements;

    	// Utility method - Recursively put the array back into a __________ Binary Heap.
	void reHeapUp(unsigned int indexOfBottom);

	// Utility method - Recursively put the array back into a __________ Binary Heap.
	void reHeapDown(unsigned int indexOfRoot);  
   
public:
	// Default Constructor
	BinaryHeap(); 
	
	// To do: If it needs a copy constructor, add it!
	~BinaryHeap();
	
    // Description: Returns the number of elements in the Binary Heap.
    // Postcondition:  The Binary Heap is unchanged by this operation.
	// Time Efficiency: O(1)
    unsigned int getElementCount() const;

	// Description: Inserts newElement into the Binary Heap.
	//              It returns "true" if successful, otherwise "false".        
	// Postcondition: Remains a __________ Binary Heap after the insertion.
	// Time Efficiency: O(log2 n)
	bool insert(const ElementType& newElement);
	   
	// Description: Removes (but does not return) the element located at the root.
	// Precondition: This Binary Heap is not empty.
	// Postcondition: Remains a __________ Binary Heap after the removal.	
	// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
	// Time Efficiency: O(log2 n)
	void remove();

	// Description: Retrieves (but does not remove) the element located at the root.
	// Precondition: This Binary Heap is not empty.
	// Postcondition: This Binary Heap is unchanged.
	// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
	// Time Efficiency: O(1) 
	ElementType retrieve() const;

	// For Testing Purposes
	// Description: Prints the content of "this". 
	void printBinaryHeap();

}; // end BinaryHeap

#include "BinaryHeap.cpp"