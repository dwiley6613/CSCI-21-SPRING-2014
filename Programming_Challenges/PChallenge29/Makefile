Flag = -Wall -Wextra -Werror -pedantic

pc29: pc29.o treasurechest.o
	g++ $(Flag) pc29.o treasurechest.o -o pc29

pc29.o: pc29.cpp treasurechest.h
	g++ $(Flag) -c pc29.cpp -o pc29.o

treasurechest.o: treasurechest.cpp treasurechest.h
	g++ $(Flag) -c treasurechest.cpp -o treasurechest.o

clean:
	rm *.o
	
cleanall:
	rm *.o
	rm *.exe