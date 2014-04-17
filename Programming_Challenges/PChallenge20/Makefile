Flag = -Wall -Wextra -Werror -pedantic

pc20: SLNode.o SList.o pc20.o
	g++ $(Flag) pc20.o SList.o SLNode.o -o pc20

pc20.o: pc20.cpp
	g++ $(Flag) -c pc20.cpp -o pc20.o

SList.o: SList.h SList.cpp
	g++ $(Flag) -c SList.cpp -o SList.o

SLNode.o: SLNode.h SLNode.cpp
	g++ $(Flag) -c SLNode.cpp -o SLNode.o

clean:
	rm *.o