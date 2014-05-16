Flag = -Wall -Wextra -Werror -pedantic

pp4: pp4.o word.o
	g++ $(Flag) pp4.o word.o -o pp4

pp4.o: pp4.cpp bstnode.h bstree.h word.h
	g++ $(Flag) -c pp4.cpp -o pp4.o

word.o: word.cpp word.h
	g++ $(Flag) -c word.cpp -o word.o

clean:
	rm *.o

cleanall:
	rm *.o
	rm *.exe*