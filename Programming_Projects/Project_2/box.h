/*Programming Project 2
 *Donald Wiley
 */
#include "prize.h"

#include <string>
using namespace std;
 
class Box
{
public:

//default constructor: initial values boxNumber (0), boxColor ("NO COLOR"), prizeCapacity (5), prizeCount(0), prizes (array initialized to match prizeCapacity)
Box ();

//overloaded constructor: parameters for boxNumber, boxColor, prizeCapacity, prizes (array initialized to match prizeCapacity)
Box (unsigned int newBoxNumber, string newBoxColor, unsigned int newPrizeCapacity, Prize* newPrizes);

//destructor: free memory associated with prizes
~Box ();

//accessors/gets AND mutators/sets for boxNumber, boxColor
unsigned int getBoxNumber() const;

string getBoxColor() const;

void setBoxNumber(unsigned int newNumber);

void setBoxColor(string newColor);

//accessor/get ONLY for data members prizeCapacity, prizeCount
unsigned int getPrizeCapacity();
unsigned int getPrizeCount();

//addPrize: parameters prize (Prize), return value (bool); place prize in prizes array if there is space and return true, else return false
bool addPrize (Prize(string prizeName, unsigned int prizeValue));

//getPrize: parameters index (unsigned int), return value Prize&; return a Prize if index is valid, else return scratch (data member declared in class header)

//removePrize: parameters index (unsigned int), return value Prize; remove and return Prize if index is valid, else return scratch (data member declared in class header)
    
private:
    unsigned int boxNumber;
    string boxColor;
    Prize scratch;
    Prize* prizes;
    unsigned int prizeCapacity;
    unsigned int prizeCount;
};
