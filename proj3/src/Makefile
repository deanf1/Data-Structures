all: Driver.o BinarySearchTree.h RandomizedBinarySearchTree.h
	g++ -ansi -Wall Driver.o BinarySearchTree.h RandomizedBinarySearchTree.h -o driver.out

Driver.o: Driver.cpp
	g++ -ansi -Wall -c Driver.cpp
	
#BinarySearchTree.o: BinarySearchTree.h
#	g++ -ansi -Wall -c BinarySearchTree.h

#RandomizedBinarySearchTree.o: RandomizedBinarySearchTree.h
#	g++ -ansi -Wall -c RandomizedBinarySearchTree.h

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~*.h.gch *#[
	rm -f *.gch
	rm -f *~

run:
	./driver.out $(FILE) $(L)