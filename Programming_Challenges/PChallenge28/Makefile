Flag = -Werror -Wall -Wextra -pedantic

pc28: pc28.o MagicItem.o FoodItem.o Item.o
	g++ $(Flag) pc28.o MagicItem.o FoodItem.o Item.o -o pc28

pc28.o: pc28.cpp Item.h foodItem.h magicItem.h
	g++ $(Flag) -c pc28.cpp -o pc28.o

MagicItem.o: MagicItem.cpp MagicItem.h
	g++ $(Flag) -c MagicItem.cpp -o MagicItem.o

FoodItem.o: FoodItem.cpp FoodItem.h
	g++ $(Flag) -c FoodItem.cpp -o FoodItem.o

Item.o: Item.cpp Item.h
	g++ $(Flag) -c Item.cpp -o Item.o

clean:
	rm *.o
	rm *.exe