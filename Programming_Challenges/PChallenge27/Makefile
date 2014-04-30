Flag = -Wall -Wextra -Werror -pedantic

pc27: pc27.o BSTNode.o BSTNode.o
	g++ $(Flag) pc27.o BSTNode.o BSTree.o -o pc27

pc27.o: pc27.cpp BSTNode.o BSTree.o
	g++ $(Flag) -c pc27.cpp -o pc27.o

BSTree.o: BSTree.h BSTree.cpp
	g++ $(Flag) -c BSTree.cpp -o BSTree.o

BSTNode.o: BSTNode.h BSTNode.cpp
	g++ $(Flag) -c BSTNode.cpp -o BSTNode.o

clean:
	rm *.o
	rm *.exe*