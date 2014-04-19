Flag = -Wall -Wextra -Werror -pedantic

pp3: pp3.o
	g++ $(Flag) pp3.o -o pp3

pp3.o: pp3.cpp DLList.h DLNode.h
	g++ $(Flag) -c pp3.cpp -o pp3.o

clean:
	rm *.o

cleanall:
	rm *.o
	rm *.exe*