/* BinaryHeap.cpp
Alen Mehmedbegovic :)
March 23, 2022

An array based implementation of a binary heap tree


*/

#include "BinaryHeap.h"

// Default Constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap() {

   capacity = INITAL_CAPACITY;	
   elements = new ElementType[capacity];
   elementCount = 0;
} // end of default constructor
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap()
{
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
}  // end getElementCount


// Description: Inserts newElement into the Binary Heap.
//              It returns "true" if successful, otherwise "false".        
// Postcondition: Remains a minimum Binary Heap after the insertion.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap


::insert(const ElementType& newElement) {

    bool ableToInsert = false;
	unsigned int indexOfRoot = 0;
	unsigned int indexOfBottom = this->elementCount;
    
	if(elementCount == capacity)	// We need to resize
	{
		ElementType *OriginalElements = elements; // Store the original elements to help overwrite

		capacity = capacity*2;      // Resize
        elements = new ElementType[capacity];

		for(unsigned int i = indexOfRoot; i <= indexOfBottom; i++)
        {
            elements[i] = OriginalElements[i]; 	// Overwrite
        }

    	delete[] OriginalElements;
	}

		elements[indexOfBottom] = newElement;
		elementCount++;
		ableToInsert = true;

		reHeapUp(indexOfBottom);


    return ableToInsert;

} // end insert


// Utility method - Recursively put the array back into a minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfBottom) {

	unsigned int indexOfRoot = 0;
	unsigned int indexOfParent;

	if(indexOfBottom == indexOfRoot) // Base case 
	{
		return;
	}

	else if(elementCount > 1 && (indexOfBottom > indexOfRoot))
	{
		indexOfParent = floor((indexOfBottom-1)/2);
			
		if(elements[indexOfParent] <= elements[indexOfBottom]) // CHAGED > <=
		{
			ElementType temp = elements[indexOfParent];
			elements[indexOfParent] = elements[indexOfBottom];
			elements[indexOfBottom] = temp;
		}

		indexOfBottom = indexOfParent;	// Moving up the tree
		reHeapUp(indexOfBottom);
	}

	return;
	
} // end reHeapUp


// Description: Removes (but does not return) the element located at the root.
// Precondition: This Binary Heap is not empty.
// Postcondition: Remains a Minimum Binary Heap after the removal.	
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {
      
   if(!(elementCount == 0))
   {
		unsigned int indexOfRoot = 0;
		// Overwrite the element at the root with the bottom 
		elements[indexOfRoot] = elements[elementCount-1]; 
		elementCount--;	
		reHeapDown(indexOfRoot);
   }
   else
   {
	   throw EmptyDataCollectionException("There are no events to remove");
   }

	return;
	
}  // end remove


// Utility method - Recursively put the array back into a minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

	unsigned int indexOfMinChild = indexOfRoot;
	
	// Find indices of children.
	unsigned int indexOfLeftChild = 2*indexOfRoot+1;
	unsigned int indexOfRightChild = 2*indexOfRoot+2;

    // Base case: elements[indexOfRoot] is a leaf as it has no children
	if (indexOfLeftChild > elementCount-1) return;

	// If we need to swap, select the smallest child
    if (elements[indexOfRoot] <= elements[indexOfLeftChild]) // CHANGED > -> <= --------------------------------------
    	indexOfMinChild = indexOfLeftChild;

    // Check if there is a right child, is it the smallest?
    if (indexOfRightChild <= elementCount) {
		if (elements[indexOfMinChild] <= elements[indexOfRightChild]) //CHANGED >= 
		    indexOfMinChild = indexOfRightChild;
	}

	// Swap parent with smallest of children.
	if (indexOfMinChild != indexOfRoot) {
		
	   ElementType temp = elements[indexOfRoot];
	   elements[indexOfRoot] = elements[indexOfMinChild];
	   elements[indexOfMinChild] = temp;
	   
	   // Recursively put the array back into a heap
	   reHeapDown(indexOfMinChild);
    }

	return;
	
} // end reHeapDown


// Description: Retrieves (but does not remove) the element located at the root.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1) 
template <class ElementType>
ElementType BinaryHeap<ElementType>::retrieve() const {
   
   // Enforce precondition
   if ( elementCount > 0 )
      return elements[0];
   else
      throw(EmptyDataCollectionException("retrieve() called with an empty BinaryHeap.")); 

}  // end retrieve


// For Testing Purposes
// Prints the content of binary heap
template <class ElementType>
void BinaryHeap<ElementType>::printBinaryHeap()
{
	for (unsigned int i = 0; i < this->elementCount; i++)
	{
		cout << "Time (keyvalue):" << this->elements[i].getTime() << "\n";
	}

}