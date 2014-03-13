Flag = -Wall -Wextra -Werror -pedantic

pc8: pc8.cpp
	g++ $(Flag) -o pc8 pc8.cpp

pc9: pc9.cpp
	g++ $(Flag) -o pc9 pc9.cpp

pc10: pc10.cpp
	g++ $(Flag) -o pc10 pc10.cpp

pc11: pc11.cpp
	g++ $(Flag) -o pc11 pc11.cpp

pc12: pc12.cpp
	g++ $(Flag) -o pc12 pc12.cpp

pc13:pc13.cpp
	g++ $(Flag) -o pc13 pc13.cpp

pc14:pc14.cpp
	g++ $(Flag) -o pc14 pc14.cpp
	
pc15:pc15.cpp
	g++ $(Flag) -o pc15 pc15.cpp

pc16:pc16.cpp
	g++ $(Flag) -o pc16 pc16.cpp

pc17: SLNode.o pc17.o
	g++  pc17.o SLNode.o -o pc17

pc17.o: pc17.cpp
	g++ -c pc17.cpp -o pc17.o

SLNode.o:  SLNode.h SLNode.cpp
	g++ -c SLNode.cpp -o SLNode.o

clean:
	rm *.o