Flag = -Wall -Wextra -Werror -pedantic

pc19: SLNode.o SList.o pc19.o
	g++ $(Flag) pc19.o SList.o SLNode.o -o pc19

pc19.o: pc19.cpp
	g++ $(Flag) -c pc19.cpp -o pc19.o

SList.o: SList.h SList.cpp
	g++ $(Flag) -c SList.cpp -o SList.o

SLNode.o: SLNode.h SLNode.cpp
	g++ $(Flag) -c SLNode.cpp -o SLNode.o

clean:
	rm *.o