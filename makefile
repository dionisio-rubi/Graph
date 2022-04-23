all: graphs

graphs: driver.o
	g++ -o graphs driver.o

driver.o: driver.o Node.h LinkedStack.h AQueue.h PQueue.h Graph.h
	g++ -c driver.cpp

clean:
	rm *.o graphs