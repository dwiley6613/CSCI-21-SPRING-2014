/*Programming Project 2
 *Donald Wiley
 */
include "prize.h"
 
class Box
{
public:
default constructor: initial values boxNumber (0), boxColor ("NO COLOR"), prizeCapacity (5), prizeCount(0), prizes (array initialized to match prizeCapacity)
overloaded constructor: parameters for boxNumber, boxColor, prizeCapacity, prizes (array initialized to match prizeCapacity)
destructor: free memory associated with prizes
accessors/gets AND mutators/sets for boxNumber, boxColor
accessor/get ONLY for data members prizeCapacity, prizeCount
addPrize: parameters prize (Prize), return value (bool); place prize in prizes array if there is space and return true, else return false
getPrize: parameters index (unsigned int), return value Prize&; return a Prize if index is valid, else return scratch (data member declared in class header)
removePrize: parameters index (unsigned int), return value Prize; remove and return Prize if index is valid, else return scratch (data member declared in class header)
    
private:
    unsigned int boxNumber;
    string boxColor;
    Prize scratch;
    Prize* prizes;
    unsigned int prizeCapacity;
    unsigned int prizeCount;
}
