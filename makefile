all: graphs

graphs: driver.o
	g++ -o graphs driver.o

driver.o: driver.o Graph.h
	g++ -c driver.cpp

clean:
	rm *.o graphs