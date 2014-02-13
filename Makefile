Flag = -Wall -Wextra -Werror -pedantic

pc1:pc1.cpp
	g++ -o pc1 pc1.cpp

pc2:pc2.cpp
	g++ -o pc2 pc2.cpp
	
pc3:pc3.cpp
	g++ -o pc3 pc3.cpp
	
pc4:pc4.cpp
	g++ -o pc4 pc4.cpp
pc5:pc5.cpp
	g++ $(Flag) -o pc5 pc5.cpp

pc6:Programming_Challenges/pc6

Programming_Challenges/pc6:Programming_Challenges/pc6.cpp
	g++ $(Flag) -o Programming_Challenges/pc6 Programming_Challenges/pc6.cpp

pp1:Programming_Projects/pp1

Programming_Projects/pp1:Programming_Projects/pp1.cpp
	g++ -o Programming_Projects/pp1 Programming_Projects/pp1.cpp

pc7:Programming_Challenges/pc7

Programming_Challenges/pc7:Programming_Challenges/pc7.cpp
	g++ -o Programming_Challenges/pc7 Programming_Challenges/pc7.cpp