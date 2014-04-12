#include "box.h"
#include "prize.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include "CinReader.h"
using namespace std;

CinReader reader;

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

/**************Function Declarations********************/

/*
 * Function "mainMenu"
 * @return int
 */
 void mainMenu();
 
 /*
  * Function "boxTest"
  * @return int
  */
 void boxTest();
 
 /*
  * Function "prizeTest"
  * @return int
  */
 void prizeTest();
/*
 * Function "enterToContinue" pause program until enter is pressed
 * @return void
 */
 void enterToContinue();
 
int main (int, char**)
{
    //unittest();
	
    // CODE HERE -- INTERACTIVE TEST
    //
    // add additional functions as needed to support interactive test
	mainMenu();
	
    return 0;
}

 
 
 /************Function Definitions**********************/
void mainMenu()
{
	system("clear");
	int choice=10;
	while(choice !=0)
	{
		cout << "Main Menu" << endl;
		cout << "[1] Box -- interactive test" << endl;
		cout << "[2] Prize -- interactive test" << endl;
		cout << "[3] Run official unit test" << endl;
		cout << "[0] Quit" << endl;
		cout << "your choice: ";
		choice = reader.readInt(0,3);
		cout << endl;
		switch(choice)
		{
			case 1:
				system("clear");
				boxTest();
				break;
			case 2:
				system("clear");
				prizeTest();
				break;
			case 3:
				enterToContinue();
				system("clear");
				unittest();
				enterToContinue();
				system("clear");
				break;
			case 0:
				system("clear");
				break;
		}
	}
}
 
void boxTest()
{
	int c2, choice=10;
	Box b1;
	string name;
	int value;
	string tmpString;
	char tmpChar;
	while (choice != 0)
	{
		cout << "Box Test" << endl << endl;
		cout << "Box info -> 0, NO COLOR" << endl;
		cout << "[1] Add prize" << endl;
		cout << "[2] View prizes (using getPrize)" << endl;
		cout << "[3] Remove prize" << endl;
		cout << "[4] Box number" << endl;
		cout << "[5] Box color" << endl;
		cout << "[6] View prize capacity" << endl;
		cout << "[7] View prize count" << endl;
		cout << "[0] Back to main menu" << endl;
		cout << "your choice: ";
		choice = reader.readInt(0,7);
		cout << endl;
		switch(choice)
		{
			case 1:
				cout << "Prize name (current= \"NO NAME\"): ";
				name = reader.readString();
				cout << "Prize value (current= 0): ";
				value = reader.readInt(0, 2000000);
				b1.addPrize(Prize(name, value));
				enterToContinue();
				system("clear");
				break;
			case 2:
				for(unsigned int cnt=0; cnt<b1.getPrizeCount(); cnt++)
					cout << cnt+1 << ": " << b1.getPrize(cnt).getPrizeName() << endl;
				enterToContinue();
				system("clear");
				break;
			case 3:
				for(unsigned int cnt=0; cnt<b1.getPrizeCount(); cnt++)
					cout << cnt+1 << ": " << b1.getPrize(cnt).getPrizeName() << endl;
				cout << "Remove which prize (0 to cancel)? ";
				c2 = reader.readInt(0,b1.getPrizeCount());
				if(c2 == 0)
				{
					enterToContinue();
					system("clear");
					break;
				}
				b1.removePrize(c2-1);
				cout << "Prize number " << c2 << " removed" << endl;
				enterToContinue();
				system("clear");
				break;
			case 4:
				cout << "Box number: " << b1.getBoxNumber() << endl;
				cout << "Update (y/n)? ";
				tmpChar = reader.readChar("yYnN");
				tmpChar = toupper(tmpChar);
				if(tmpChar == 'Y')
				{
					cout << "Enter new box number: ";
					c2 = reader.readInt();
					b1.setBoxNumber(c2);
				}
				enterToContinue();
				system("clear");
				break;
			case 5:
				cout << "Box color: " << b1.getBoxColor() << endl;
				cout << "Update (y/n)? ";
				tmpChar = reader.readChar("yYnN");
				tmpChar = toupper(tmpChar);
				if(tmpChar == 'Y')
				{
					cout << "Enter new box color: ";
					tmpString = reader.readString();
					b1.setBoxColor(tmpString);
				}
				enterToContinue();
				system("clear");
				break;
			case 6:
				cout << "Box prize capacity: " << b1.getPrizeCapacity() << endl;
				enterToContinue();
				system("clear");
				break;
			case 7:
				cout << "Box prize count: " << b1.getPrizeCount() << endl;
				enterToContinue();
				system("clear");
				break;
			case 0:
				enterToContinue();
				system("clear");
				break;
		}
	}
}
  
void prizeTest()
{ 
	int c2, choice=10;
	Prize p1;
	Prize p2;
	char tmpChar;
	string tmpString;
	
	while(choice != 0)
	{
		cout << "PRIZE TEST" << endl << endl;
		cout << "Prize info -> " << p1.getPrizeName() << ", $" << p1.getPrizeValue() << endl;
		cout << "[1] Prize name" << endl;
		cout << "[2] Prize value" << endl;
		cout << "[3] Compare two prizes" << endl;
		cout << "[0] Back to main menu" << endl;
		cout << "your choice: ";
		choice = reader.readInt(0,3);
		cout << endl;
		switch(choice)
		{
			case 1:
				cout << "Prize name: " << p1.getPrizeName() << endl;
				cout << "Update (y/n)? ";
				tmpChar = reader.readChar("yYnN");
				tmpChar = toupper(tmpChar);
				if(tmpChar == 'Y')
				{
					cout << "Enter new prize name: ";
					tmpString = reader.readString();
					p1.setPrizeName(tmpString);
					cout << "Prize name updated." <<endl;
				}
				enterToContinue();
				system("clear");
				break;
			case 2:
				cout << "Prize value: " << p1.getPrizeValue() << endl;
				cout << "Update (y/n)? ";
				tmpChar = reader.readChar("yYnN");
				tmpChar = toupper(tmpChar);
				if(tmpChar == 'Y')
				{
					cout << "Enter new prize value: ";
					c2 = reader.readInt();
					p1.setPrizeValue(c2);
					cout << "Prize value updated." << endl <<endl;
				}
				enterToContinue();
				system("clear");				
				break;
			case 3:
				cout << "First set the values for the data members of the two prizes." << endl << endl;
				cout << "Prize 1 ->" << endl;
				cout <<"Prize name (current=\"" << p1.getPrizeName() << "\"): ";
				tmpString = reader.readString();
				if(tmpString != "")
					p1.setPrizeName(tmpString);
				cout << "Prize value (current=" << p1.getPrizeValue() << "): ";
				c2 = reader.readInt(0, 2000000);
				p1.setPrizeValue(c2);
				cout << endl;
				cout << "Prize 2 ->" << endl;
				cout << "Prize name (current=\"" << p2.getPrizeName() << "\"): ";
				tmpString = reader.readString();
				if(tmpString != "")
					p2.setPrizeName(tmpString);
				cout << "Prize value (current=" << p2.getPrizeValue() << "): ";
				c2 = reader.readInt(0, 2000000);
				p2.setPrizeValue(c2);
				cout << endl;
				//
				// Grader comments 2014.04.11
				// One case says "yes" but they both say "not the same"
				// Deducted 3 points
				//
				if(p1 == p2)
					cout << "Yes. The two prizes are not the same." << endl;
				else
					cout << "No. The two prizes are not the same." << endl;
				cout << endl;
				enterToContinue();
				system("clear");
				break;
			case 0:
				enterToContinue();
				system("clear");				
				break;
		}
	}
}

void enterToContinue()
{
	cout << endl << "Press enter to continue";
	reader.readString();
	cout << endl;
}

/*
 * Unit testing functionb1. Do not alter.
 */

void unittest ()
{
    cout << "\nSTARTING UNIT TEST\n\n";
	
    Box b1;
    Box b2(42, "blue", 3);
	
    cout << "** TESTING DEFAULT BOX **\n\n";
	
    try {
        btassert<bool>(b1.getBoxNumber() == 0);
        cout << "Passed TEST 1: Box getBoxNumber()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 1 Box getBoxNumber() #\n";
    }
	
    try {
        btassert<bool>(b1.getBoxColor() == "NO COLOR");
        cout << "Passed TEST 2: Box getBoxColor()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 2 Box getBoxColor() #\n";
    }
    
    try {
        btassert<bool>(b1.getPrizeCapacity() == 5);
        cout << "Passed TEST 3: Box getPrizeCapacity()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 3 Box getPrizeCapacity() #\n";
    }
	
    try {
        btassert<bool>(b1.getPrizeCount() == 0);
        cout << "Passed TEST 4: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 4 Box getPrizeCount() #\n";
    }
	
    b1.setBoxNumber(99);
    try {
        btassert<bool>(b1.getBoxNumber() == 99);
        cout << "Passed TEST 5: Box setBoxNumber()/getBoxNumber()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 5 Box setBoxNumber()/getBoxNumber() #\n";
    }
	
    b1.setBoxColor("red");
    try {
        btassert<bool>(b1.getBoxColor() == "red");
        cout << "Passed TEST 6: Box setBoxColor()/getBoxColor()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 6 Box setBoxColor()/getBoxColor() #\n";
    }
    
    cout << "\n** TESTING CUSTOM BOX **\n\n";
	
    try {
        btassert<bool>(b2.getBoxNumber() == 42);
        cout << "Passed TEST 7: Box getBoxNumber()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 7 Box getBoxNumber() #\n";
    }
	
    try {
        btassert<bool>(b2.getBoxColor() == "blue");
        cout << "Passed TEST 8: Box getBoxColor()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 8 Box getBoxColor() #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCapacity() == 3);
        cout << "Passed TEST 9: Box getPrizeCapacity()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 9 Box getPrizeCapacity() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrizeCount() == 0);
        cout << "Passed TEST 10: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 10 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(0) == Prize());
        cout << "Passed TEST 11: Box getPrize(0)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 11 Box getPrize(0) #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(0) == Prize());
        cout << "Passed TEST 12: Box removePrize(0)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 12 Box removePrize(0) #\n";
    }
    
    b2.addPrize(Prize("BRONZE PRIZE", 1));
    try {
        btassert<bool>(b2.getPrizeCount() == 1);
        cout << "Passed TEST 13: Box addPrize()/getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 13 Box addPrize()/getPrizeCount() #\n";
    }
    
    b2.addPrize(Prize("SILVER PRIZE", 100));
    try {
        btassert<bool>(b2.getPrizeCount() == 2);
        cout << "Passed TEST 14: Box addPrize()/getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 14 Box addPrize()/getPrizeCount() #\n";
    }
        
    b2.addPrize(Prize("GOLD PRIZE", 1000));
    try {
        btassert<bool>(b2.getPrizeCount() == 3);
        cout << "Passed TEST 15: Box addPrize()/getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 15 Box addPrize()/getPrizeCount() #\n";
    }
    
    try {
        btassert<bool>(b2.addPrize(Prize("DIAMOND PRIZE", 999)) == false);
        cout << "Passed TEST 16: Box addPrize(ARRAY FULL)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 16 Box addPrize(ARRAY FULL) #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(1) == Prize("SILVER PRIZE", 100));
        cout << "Passed TEST 17: Box getPrize(1)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 17 Box getPrize(1) #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(2) == Prize("GOLD PRIZE", 1000));
        cout << "Passed TEST 18: Box removePrize(2)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 18 Box removePrize(2) #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCount() == 2);
        cout << "Passed TEST 19: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 19 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(2) == Prize());
        cout << "Passed TEST 20: Box removeCargo(2)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 20 Box removeCargo(2) #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(2) == Prize());
        cout << "Passed TEST 21: Box getPrize(2)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 21 Box getPrize(2) #\n";
    }
	
    try {
        btassert<bool>(b2.addPrize(Prize("RUBY PRIZE", 9999)) == true);
        cout << "Passed TEST 22: Box addPrize(\"RUBY PRIZE\", 9999)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 22 Box addPrize(\"RUBY PRIZE\", 9999) #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCount() == 3);
        cout << "Passed TEST 23: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 23 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrizeCapacity() == 3);
        cout << "Passed TEST 24: Box getPrizeCapacity()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 24 Box getPrizeCapacity() #\n";
    }
	
    cout << "\n** TESTING PRIZE **\n\n";
	
    Prize p1;
	
    try {
        btassert<bool>(p1.getPrizeName() == "NO NAME");
        cout << "Passed TEST 25: Prize getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 25 Prize getPrizeName() #\n";
    }
	
    try {
        btassert<bool>(p1.getPrizeValue() == 0);
        cout << "Passed TEST 26: Prize getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 26 Prize getPrizeValue() #\n";
    }
	
    p1.setPrizeName("FOOD PRIZE");
    try {
        btassert<bool>(p1.getPrizeName() == "FOOD PRIZE");
        cout << "Passed TEST 27: Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 27 Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName() #\n";
    }
	
    p1.setPrizeValue(17);
    try {
        btassert<bool>(p1.getPrizeValue() == 17);
        cout << "Passed TEST 28: Prize setPrizeValue(17)/getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 28 Prize setPrizeValue(17)/getPrizeValue() #\n";
    }
	
    Prize p2("HAT PRIZE", 50);
	
    try {
        btassert<bool>(p2.getPrizeName() == "HAT PRIZE");
        cout << "Passed TEST 29: Prize getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 29 Prize getPrizeName() #\n";
    }
	
    try {
        btassert<bool>(p2.getPrizeValue() == 50);
        cout << "Passed TEST 30: Prize getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 30 Prize getPrizeValue() #\n";
    }
    
    try {
        btassert<bool>(!(p1 == p2));
        cout << "Passed TEST 31: !(Prize == Prize)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 31 !(Prize == Prize) #\n";
    }
    
    p2.setPrizeName("FOOD PRIZE");
    try {
        btassert<bool>(p2.getPrizeName() == "FOOD PRIZE");
        cout << "Passed TEST 32: Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 32 Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName() #\n";
    }
	
    p2.setPrizeValue(17);
    try {
        btassert<bool>(p2.getPrizeValue() == 17);
        cout << "Passed TEST 33: Prize setPrizeValue(17)/getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 33 Prize setPrizeValue(17)/getPrizeValue() #\n";
    }
    
    try {
        btassert<bool>(p1 == p2);
        cout << "Passed TEST 34: (Prize == Prize)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 34 (Prize == Prize) #\n";
    }
    
    p2.setPrizeValue(1);
    try {
        btassert<bool>(!(p1 == p2));
        cout << "Passed TEST 35: !(Prize == Prize)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 35 !(Prize == Prize) #\n";
    }
	
    cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
        throw X();
}