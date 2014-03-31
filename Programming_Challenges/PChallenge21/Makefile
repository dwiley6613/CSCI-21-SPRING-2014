Flag = -Wall -Werror -Wextra -pedantic

pc21: pc21.o box.h
	g++ $(Flag) pc21.o  -o pc21

pc21.o: pc21.cpp box.h
	g++ $(Flag) -c pc21.cpp -o pc21.o

clean:
	rm *.o