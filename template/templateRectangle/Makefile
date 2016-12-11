all: Driver.o Rectangle.o
	g++ -Wall Driver.o Rectangle.o -o output.out

Driver.o: Driver.cpp
	g++ -Wall -c Driver.cpp

Rectangle.o: Rectangle.cpp
	g++ -Wall -c Rectangle.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~*.h.gch *#[

run:
	./output.out