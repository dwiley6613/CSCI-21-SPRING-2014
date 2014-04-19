Flag = -Wall -Wextra -Werror -pedantic

pc25: pc25.o BSTNode.o
	g++ $(Flag) pc25.o BSTNode.o -o pc25

pc25.o: pc25.cpp BSTNode.h
	g++ $(Flag) -c pc25.cpp -o pc25.o

BSTNode.o: BSTNode.h BSTNode.cpp
	g++ $(Flag) -c BSTNode.cpp -o BSTNode.o

clean:
	rm *.o
	rm *.exe*