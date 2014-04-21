Flag = -Wall -Werror -Wextra -pedantic

pc23: pc23.o
	g++ $(Flag) pc23.o -o pc23

pc23.o: pc23.cpp
	g++ $(Flag) -c pc23.cpp -o pc23.o

clean:
	rm *.o
	rm *.exe