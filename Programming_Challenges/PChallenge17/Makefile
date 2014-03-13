Flag = -Wall -Wextra -Werror -pedantic

pc17: SLNode.o pc17.o
	g++  $(Flag) pc17.o SLNode.o -o pc17

pc17.o: pc17.cpp
	g++ $(Flag) -c pc17.cpp -o pc17.o

SLNode.o:  SLNode.h SLNode.cpp
	g++ $(Flag) -c SLNode.cpp -o SLNode.o

clean:
	rm *.o