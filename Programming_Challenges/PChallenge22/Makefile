Flag = -Wall -Wextra -Werror -pedantic

pc22: pc22.o
	g++ $(Flag) pc22.o -o pc22

pc22.o: pc22.cpp SList.h SLNode.h
	g++ $(Flag) -c pc22.cpp -o pc22.o

clean:
	rm *.o