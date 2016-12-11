all: Driver.o Calculate.o
	g++ -Wall Driver.o Calculate.o -o driver.out

Driver.o: Driver.cpp
	g++ -Wall -c Driver.cpp
	
Calculate.o: Calculate.cpp
	g++ -Wall -c Calculate.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~*.h.gch *#[

run:
	./driver.out $(FILE)