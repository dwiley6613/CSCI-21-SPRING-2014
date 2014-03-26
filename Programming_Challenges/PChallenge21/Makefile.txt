Flag = -Wall -Werror -Wextra -pedantic

pc21: pc21.o box.o
	g++ $(Flag)