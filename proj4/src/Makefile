all: Driver.o IntervalHeap.o
	g++ -ansi -Wall Driver.o IntervalHeap.o -o driver.out

Driver.o: Driver.cpp
	g++ -ansi -Wall -c Driver.cpp
	
IntervalHeap.o: IntervalHeap.cpp
	g++ -ansi -Wall -c IntervalHeap.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~*.h.gch *#[

run:
	./driver.out $(MIN) $(MAX) $(SIZE) $(SEED)