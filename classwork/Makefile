all: Driver.o 
	g++ -Wall Driver.o -o output.out

Driver.o: Driver.cpp
	g++ -Wall -c Driver.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~*.h.gch *#[

run:
	./output.out $(COUNT)