/* BinaryHeap.cpp
Anil B, Kiarash Z
March 30, 2022

An array based implementation of a binary heap 

*/


#include "BinaryHeap.h"

// Default Constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap(){

   capacity = INITAL_CAPACITY;	
   elements = new ElementType[capacity];
   elementCount = 0;

} 
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap(){

	elementCount = 0;
	capacity = 0;
	delete[] this->elements;

}

// Description: Returns the number of elements in the Binary Heap.
// Postcondition:  The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const {
   
   return elementCount;
}

// Description: Inserts newElement into the Binary Heap.
//              It returns "true" if successful, otherwise "false".        
// Postcondition: Remains a minimum Binary Heap after the insertion.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert(const ElementType& newElement) {

    bool inserted = false;
	unsigned int indexOfRoot = 0;
	unsigned int indexOfBottom = this->elementCount;
    
	if(elementCount == capacity){       //resizing
		
        ElementType *OgElements = elements; // copying

		capacity = capacity*2;      // new size
        elements = new ElementType[capacity];

		for(unsigned int i = indexOfRoot; i <= indexOfBottom; i++){//transferring elements

            elements[i] = OgElements[i]; 	
        }

    	delete[] OgElements;
	}

		elements[indexOfBottom] = newElement;
		elementCount++;
		inserted = true;

		reHeapUp(indexOfBottom);


    return inserted;

}	

// Utility method - Recursively put the array back into a minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfBottom) {

	unsigned int indexOfRoot = 0;
	unsigned int indexOfParent;

	if(indexOfBottom == indexOfRoot){
		return;
	}

	else if(elementCount > 1 && (indexOfBottom > indexOfRoot)){

		indexOfParent = floor((indexOfBottom-1)/2);
			
		if(elements[indexOfBottom] <= elements[indexOfParent] ){  //comparing values in those indexs

			ElementType temp = elements[indexOfParent];
			elements[indexOfParent] = elements[indexOfBottom];
			elements[indexOfBottom] = temp;
		}

		indexOfBottom = indexOfParent;	
        //recursive call
		reHeapUp(indexOfBottom);
	}

	return;
	
}

// Utility method - Recursively put the array back into a minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

	unsigned int indexOfMinChild = indexOfRoot;
	
    //indices of children
	unsigned int indexOfLeftChild = 2*indexOfRoot+1;
	unsigned int indexOfRightChild = 2*indexOfRoot+2;

    
	if (indexOfLeftChild > elementCount-1){
        return;  //base case, return to break the recursive call (not sure why that works)
    }
	
    if (!(elements[indexOfRoot] <= elements[indexOfLeftChild])){
    	indexOfMinChild = indexOfLeftChild;
    }
 
    if (indexOfRightChild < elementCount) {
		if (!(elements[indexOfMinChild] <= elements[indexOfRightChild])){
		    indexOfMinChild = indexOfRightChild;
        }
	}

	
	if (indexOfMinChild != indexOfRoot) {       //swapping
		
	   ElementType temp = elements[indexOfRoot];
	   elements[indexOfRoot] = elements[indexOfMinChild];
	   elements[indexOfMinChild] = temp;
	   
        //recursive call
	   reHeapDown(indexOfMinChild);
    }

	return;
	
}

// Description: Removes (but does not return) the element located at the root.
// Precondition: This Binary Heap is not empty.
// Postcondition: Remains a Minimum Binary Heap after the removal.	
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {
      
   if(!(elementCount == 0)){
		unsigned int indexOfRoot = 0;
		
		elements[indexOfRoot] = elements[elementCount-1]; 
		elementCount--;	
		reHeapDown(indexOfRoot);

   } else {
	   throw EmptyDataCollectionException("There are no ElementTypes to remove");
   }

}

// Description: Retrieves (but does not remove) the element located at the root.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1) 
template <class ElementType>
ElementType BinaryHeap<ElementType>::retrieve() const {
   
    if ( elementCount > 0 ){
        return elements[0];
    } else {
      throw(EmptyDataCollectionException("retrieve() called with an empty BinaryHeap.")); 
    }

}