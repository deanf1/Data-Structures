all: Driver.o
	g++ -ansi -Wall Driver.o -o driver.out

Driver.o: Driver.cpp
	g++ -ansi -Wall -c Driver.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~*.h.gch *#[

run:
	./driver.out