/*Programming Project 2
 *Donald Wiley
 *prize.cpp
 */
 
#include <string>
#include "prize.h"

Prize::Prize()
{
    prizeName = "NO NAME";
    prizeVal = 0;
}

Prize::Prize (string newName, unsigned int newVal)
{
    prizeName = newName;
    prizeVal = newVal;
}

Prize::~Prize ()
{
    
}
string Prize::getPrizeName () const
{
    return prizeName;
}

void Prize::setPrizeName (string newName)
{
    prizeName = newName;
}

unsigned int Prize::getPrizeValue () const
{
    return prizeVal;   
}
void Prize::setPrizeValue (unsigned int newVal)
{
    prizeVal = newVal;
}
//friend overloaded operator==: returns true if the prizeName and prizeValue of the two Prizes being compared are equivalent, else return false
bool operator == (const Prize& prizeName_1, const Prize& prizeName_2)
{
    if ((prizeName_1.getPrizeName() == prizeName_2.getPrizeName()) && (prizeName_1.getPrizeValue() == prizeName_2.getPrizeValue()))
        return true;
    else return false;
}
