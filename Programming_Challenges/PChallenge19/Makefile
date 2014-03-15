Flag = -Wall -Wextra -Werror -pedantic

pc19: SLNode.o SList pc19.o
    g++ $(Flag) pc19.o SList.o SLNode.o -pc19

pc19.0: pc19.cpp
    g++ $(Flag) -c pc19.cpp -pc19.o

SList.0: SList.h SList.cpp
    g++ $(Flag) -c SList.cpp -SList.o

SLNode.o: SLNode.h SLNode.cpp
    g++ $(Flag) -c SLNode.cpp -o SLNode.o

clean:
    rm *.o