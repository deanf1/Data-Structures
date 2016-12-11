all: Driver.o QuadraticProbing.o TextFile.o
	g++ -ansi -Wall Driver.o QuadraticProbing.o TextFile.o -o driver.out

Driver.o: Driver.cpp
	g++ -ansi -Wall -c -g Driver.cpp
	
QuadraticProbing.o: QuadraticProbing.cpp
	g++ -ansi -Wall -c -g QuadraticProbing.cpp
	
TextFile.o: TextFile.cpp
	g++ -ansi -Wall -c -g TextFile.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~*.h.gch *#[

run:
	./driver.out $(DIR)