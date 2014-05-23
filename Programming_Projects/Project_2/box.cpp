#include "box.h"
#include <iostream>

Box::Box ()
{
    boxNumber = 0;
    boxColor = "NO COLOR";
    prizeCapacity = 5;
    prizeCount = 0;
    prizes = new Prize [prizeCapacity];
}

Box::Box (unsigned int newBoxNumber, string newBoxColor, unsigned int newPrizeCapacity)
{
    boxNumber = newBoxNumber;
    boxColor = newBoxColor;
    prizeCapacity = newPrizeCapacity;
    prizeCount = 0;
    prizes = new Prize [prizeCapacity];
}

Box::~Box()
{
    delete [] prizes;
    prizes = NULL;
}

unsigned int Box::getBoxNumber() const
{
    return boxNumber;  
}

string Box::getBoxColor() const
{
    return boxColor;
}
void Box::setBoxNumber(unsigned int newNumber)
{
    boxNumber = newNumber;  
}

void Box::setBoxColor(string newColor)
{
    boxColor = newColor;
}

unsigned int Box::getPrizeCapacity() const
{
    return prizeCapacity;   
}
unsigned int Box::getPrizeCount() const
{
    return prizeCount;    
}

//
// Grader comments 2014.04.11
// 1. Don't duplicate comments
// 2. Need blank lines between function implementations
// 3. Formatting in this function inconsistent with the
//		formatting throughout the rest of the code.
//
// See also prize.cpp
//
// Deducted 10 points
//

//addPrize: parameters prize (Prize), return value (bool); place prize in prizes array if there is space and return true, else return false
bool Box::addPrize (Prize newPrize)
{
    if (prizeCount < prizeCapacity)  
        {
            prizes [prizeCount] = newPrize;
            prizeCount++;
            return true;   
        }
    else return false;
}

Prize& Box::getPrize(unsigned int index)
{
    if (index < prizeCount)
        return prizes [index];
    else
        return scratch;
            
}
//removePrize: parameters index (unsigned int), return value Prize; remove and return Prize if index is valid, else return scratch (data member declared in class header)
Prize Box::removePrize (unsigned int index)
{
    if (index < prizeCount)
    {
        Prize tmpPrize = prizes [index];
        for (unsigned int cnt = index; cnt < prizeCount; cnt++)
            if (index < prizeCount-1)
                prizes [cnt] = prizes [cnt + 1];
        prizeCount--;
        return tmpPrize;
    }    
    else
        return scratch;    
}
