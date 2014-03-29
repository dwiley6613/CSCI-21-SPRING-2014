Flag = -Wall -Wextra -Werror -pedantic

pc22: SLNode.o SList.o pc22.o
	g++ $(Flag) pc22.o SList.o SLNode.o -o pc22

pc22.o: pc22.cpp
	g++ $(Flag) -c pc22.cpp -pc22.o

SList.o: SList.h SList.cpp
	g++ $(Flag) -c SList.cpp -SList.o

SLNode.o: SLNode.h SLNode.cpp
	g++ $(Flag) -c SLNode.cpp -o SLNode.o

clean:
	rm *.o