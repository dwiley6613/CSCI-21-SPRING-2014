/*
 * Programming Challenge 11
 *pc11.cpp
 *Donald Wiley
 *created 2/15/2014
 *modified 2/15/2015
 */
#include <cassert>
#include <iomanip>
#include <iostream>
using namespace std;

/*
 * Class Prize. A class representing a simple prize, such as for a gameshow.
 */
class Prize
{
	public:
	
		// CODE HERE -- DECLARE FUNCTIONS
		//
		// Grader comments 2014.03.06
		//
		// Boyd wants function implementations outside the class declaration.
		// Minus 10%. Also, strange indentation lines 79 - 82. Usually costs
		// another 10% but I think Boyd will let me leave you alone just this once. --Rob
		//
	
		/*
		 * Constructor.
		 * @param newName string containing a name for this Prize; default argument is "no name!";
		 *        if newValue is > 100, converts name to all capital letters and concatenates a '!'
		 *        at the end of name
		 * @param newValue unsigned int containing a value for this Prize; default argument is 0
		 */
	    Prize(string newName = "no name!", unsigned int newValue = 0)
	    {
	        name = newName;
	        value = newValue;
	        if (newValue > 100)
	        {
	            for (unsigned int cnt = 0; cnt < name.length(); cnt++)
	                name[cnt] = static_cast<char> (toupper(name[cnt]));
	            name = name + "!";
	        
	        }
	    }
		/*
		 * Get this Prize's name
		 * @return a string containing this Prize's name
		 */
	    string getName();
		/*
		 * Get this Prize's value
		 * @return an unsigned int containing this Prize's value
		 */
		unsigned int getValue();
	private:
	
		string name;
		unsigned int value;
};

/*
 * Class SecretDoor. A class representing a "secret door" such as might be used on a game show.
 * Contains a Prize.
 */
class SecretDoor
{
	public:
	
		// CODE HERE -- DECLARE FUNCTIONS
	
		/*
		 * Constructor.
		 * @param newNumber unsigned int containing a value for this SecretDoor's number; default argument is 1
		 * @param newPrize Prize containing a Prize that is "hidden" behind this secret door; default argument 
		 *        is Prize()
		 */
	    SecretDoor (unsigned int newNumber = 1, Prize newPrize = Prize())
	        {
	            number = newNumber;
	            prize = newPrize;
	        }
		/*
		 * Get this SecretDoor's number.
		 * @return an unsigned int containing this SecretDoor's number
	   	 */
	    unsigned int getNumber();	
		/*
		 * Get this SecretDoor's Prize.
		 * @return the Prize, by reference, "hidden behind" this SecretDoor
		 */
		Prize getPrize();
	private:
	
		unsigned int number;
		Prize prize;
};

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main (int, char**)
{
	unittest();
	
	return 0;
}

// CODE HERE -- FUNCTION DEFINITIONS FOR PRIZE; USE INITIALIZER SECTION FOR CONSTRUCTOR

string Prize::getName()
{
    return Prize::name;
}
unsigned int Prize::getValue()
{
    return Prize::value;
}
// CODE HERE -- FUNCTION DEFINITIONS FOR SECRETDOOR; USE INITIALIZER SECTION FOR CONSTRUCTOR

unsigned int SecretDoor::getNumber()
{
    return SecretDoor::number;
}
Prize SecretDoor::getPrize()
{
    return SecretDoor::prize;
}

/*
 * Unit testing functions. Do not alter.
 */

void unittest ()
{
	cout << "\nSTARTING UNIT TEST\n\n";
	Prize * prizePointer;
	SecretDoor * doorPointer;
	try {
		prizePointer = new Prize();
		btassert<bool>(prizePointer->getName() == "no name!" && prizePointer->getValue() == 0);
		cout << "Passed TEST 1: CREATING A PRIZE () \n";
	} catch (bool b) {
		cout << "# FAILED TEST 1: CREATING A PRIZE () #\n";
	}
	delete prizePointer;
	try {
		prizePointer = new Prize("A Brand New Car");
		btassert<bool>(prizePointer->getName() == "A Brand New Car" && prizePointer->getValue() == 0);
		cout << "Passed TEST 2: CREATING A PRIZE (NAME) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 2: CREATING A PRIZE (NAME) #\n";
	}
	delete prizePointer;
	try {
		prizePointer = new Prize("A Couch",1000);
		btassert<bool>(prizePointer->getName() == "A COUCH!" && prizePointer->getValue() == 1000);
		cout << "Passed TEST 3: CREATING A PRIZE (NAME,VALUE) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 3: CREATING A PRIZE (NAME,VALUE) #\n";
	}

	try {
		doorPointer = new SecretDoor();
		btassert<bool>(doorPointer->getPrize().getName() == "no name!" && doorPointer->getNumber() == 1);
		cout << "Passed TEST 4: CREATING A SECRET DOOR () \n";
	} catch (bool b) {
		cout << "# FAILED TEST 4: CREATING A SECRET DOOR () #\n";
	}
	delete doorPointer;
	try {
		doorPointer = new SecretDoor(5);
		btassert<bool>(doorPointer->getPrize().getName() == "no name!" && doorPointer->getNumber() == 5);
		cout << "Passed TEST 5: CREATING A SECRET DOOR (NUMBER) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 5: CREATING A SECRET DOOR (NUMBER) #\n";
	}
	delete doorPointer;
	try {
		doorPointer = new SecretDoor(5,*prizePointer);
		btassert<bool>(doorPointer->getPrize().getName() == "A COUCH!" && doorPointer->getNumber() == 5);
		cout << "Passed TEST 6: CREATING A SECRET DOOR (NUMBER,PRIZE) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 6: CREATING A SECRET DOOR (NUMBER,PRIZE) #\n";
	}
	delete doorPointer;
	delete prizePointer;
		
	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}