FLAGS = -Wall -Wextra -Werror -pedantic

pp2: prize.o box.o CinReader.o pp2.o
	g++ $(FLAGS) pp2.o CinReader.o prize.o box.o -o pp2

pp2.o: pp2.cpp
	g++ $(FLAGS) -c pp2.cpp -o pp2.o
	
CinReader.o: CinReader.h CinReader.cpp
	g++ $(Flag) -c CinReader.cpp -o CinReader.o

box.o: box.h box.cpp
	g++ $(FLAGS) -c box.cpp -o box.o

prize.o: prize.h prize.cpp
	g++ $(FLAGS) -c prize.cpp  -o prize.o

clean:
	rm -f *.o

cleanall: clean
	rm -f pp2