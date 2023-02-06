/* PriorityQueue.cpp
March 23, 2022

A queue with FIFO/LILO class invariants but based on key values within fields of the elements

*/

#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"
#include <cstddef> // For NULL
#include <iostream>
#include <stdlib.h>

using namespace std;

template <class ElementType>
PriorityQueue<ElementType>:: PriorityQueue()
{
    elementCount = 0;
}

template <class ElementType>
bool PriorityQueue<ElementType>:: isEmpty() const
{
    bool IsItEmpty = false;

    if(elementCount == 0)
    {
        IsItEmpty = true;
    }

    return IsItEmpty;
}

template <class ElementType>
bool PriorityQueue<ElementType>:: enqueue(const ElementType& newElement)
{
    bool SuccessfulInsertion = false;

    if(BiasedLineup.insert(newElement))
    {
        SuccessfulInsertion = true;
    }
    elementCount++;

    return SuccessfulInsertion;
}

template <class ElementType>
void PriorityQueue<ElementType>:: dequeue()
{
    BiasedLineup.remove();
    elementCount--;
}

template <class ElementType>
ElementType PriorityQueue<ElementType>:: peek() const  // Might be ElementType no &
{  
    return BiasedLineup.retrieve();
}

template <class ElementType>
void PriorityQueue<ElementType>:: PrintPriorityQueue()
{
    BiasedLineup.printBinaryHeap();
}