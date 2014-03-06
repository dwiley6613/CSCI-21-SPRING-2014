/*Programming Project 2
 *Donald Wiley
 */
#pragma once
#include "prize.h"

#include <string>
using namespace std;
 
class Box
{
public:

/*
		 * Constructor.
		 * creates an instance of type box class
		 * boxNumber unsigned int initial value 0
		 * boxColor string initial color "NO COLOR"
		 * prizeCapacity unsigned int initial value 5
		 * prizeCount unsigned int initial value 0
		 * prizes Prize (array initialized to match prizeCapacity)
		 */
Box ();

/*
		 * Overloaded constructor.
		 * creates an instance of type Box class
		 * @param boxNumber unsigned int
		 * @param boxColor string 
		 * @param prizeCapacity unsigned int
		 */
Box (unsigned int newBoxNumber, string newBoxColor, unsigned int newPrizeCapacity);

/*
		 * Destructor.
		 * free memory associated with prizes
		 */
~Box ();

            //Accessors/gets AND Mutators/sets for boxNumber, boxColor//
              
/*
         * Get function named "getBoxNumber" no parameters and set to const
         * @return an unsigned int containing the box number
         */
unsigned int getBoxNumber() const;

/*
         * Get function named "getBoxColor" no parameters and set to const
         * @return an string containing the box name
         */
string getBoxColor() const;

/*
         * Set function named "setBoxNumber" with parameter newNumber
         * @param newNumber unsigned int contains a new box number
         * @return void
         */
void setBoxNumber(unsigned int newNumber);

/*
         * Set function named "setBoxColor" with parameter newColor
         * @param newColor string containing a new box color
         * @return void
         */
void setBoxColor(string newColor);

            //accessor/get ONLY for data members prizeCapacity, prizeCount//
            
/*
         * Get function named "getPrizeCapacity" no parameters and set to const
         * @return an unsigned int containing the prize capacity value
         */          
unsigned int getPrizeCapacity() const;

/*
         * Get function named "getPrizeCount" no parameters and set to const
         * @return an unsigned int containing the prize count value
         */
unsigned int getPrizeCount() const;


/*
         * Function named "addPrize" place prize in prizes array if there is space and return true, else return false
         * @param newPrize Prize
         * @return bool if there is an empty space in the array
         */
bool addPrize (Prize newPrize);

/*
         * Function named "getPrize" return a Prize if index is valid, else return scratch (data member declared in class header)
         * @param index unsigned int
         * @return the value Prize&
         */
Prize& getPrize(unsigned int index);

//removePrize: parameters index (unsigned int), return value Prize; remove and return Prize if index is valid, else return scratch (data member declared in class header)
/*
         * Function named "removePrize" remove and return Prize if index is valid, else return scratch (data member declared in class header)
         * @param index unsigned int
         * @return value Prize
         */
Prize removePrize (unsigned int index);
 
private:
    unsigned int boxNumber;
    string boxColor;
    Prize scratch;
    Prize* prizes;
    unsigned int prizeCapacity;
    unsigned int prizeCount;
};
