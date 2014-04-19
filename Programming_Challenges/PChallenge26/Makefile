Flag = -Wall -Wextra -Werror -pedantic

pc26: pc26.o BSTNode.o BSTNode.o
	g++ $(Flag) pc26.o BSTNode.o BSTree.o -o pc26

pc26.o: pc26.cpp BSTNode.o BSTree.o
	g++ $(Flag) -c pc26.cpp -o pc26.o

BSTree.o: BSTree.h BSTree.cpp
	g++ $(Flag) -c BSTree.cpp -o BSTree.o

BSTNode.o: BSTNode.h BSTNode.cpp
	g++ $(Flag) -c BSTNode.cpp -o BSTNode.o

clean:
	rm *.o
	rm *.exe*