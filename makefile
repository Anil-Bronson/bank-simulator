all: td

td: BankSimApp.o Event.o EmptyDataCollectionException.o PriorityQueue.h Queue.h BinaryHeap.h
	g++ -Wall -o td BankSimApp.o EmptyDataCollectionException.o Event.o

BankSimApp.o: BankSimApp.cpp
	g++ -Wall -c BankSimApp.cpp

Event.o: Event.h Event.cpp
	g++ -Wall -c Event.cpp
				
EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f td *.o
