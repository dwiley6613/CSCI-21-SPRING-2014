Flag = -Wall -Wextra -Werror -pedantic

pp4: pp4.o Word.o
	g++ $(Flag) pp4.o Word.o -o pp4

pp4.o: pp4.cpp BSTNode.h BSTree.h Word.h
	g++ $(Flag) -c pp4.cpp -o pp4.o

Word.o: Word.cpp Word.h
	g++ $(Flag) -c Word.cpp -o Word.o

clean:
	rm *.o
	rm *.exe*