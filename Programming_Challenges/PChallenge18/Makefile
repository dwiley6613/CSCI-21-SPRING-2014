Flag = -Wall -Wextra -Werror -pedantic

pc18: SLNode.o SList.o pc18.o
	g++  $(Flag) pc18.o SList.o SLNode.o -o pc18

pc18.o: pc18.cpp
	g++ $(Flag) -c pc18.cpp -o pc18.o

SList.o: SList.h SList.cpp
	g++ $(Flag) -c SList.cpp -o SList.o

SLNode.o: SLNode.h SLNode.cpp
	g++ $(Flag) -c SLNode.cpp -o SLNode.o

clean:
	rm *.o