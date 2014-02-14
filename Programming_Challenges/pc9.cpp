/*
 * Programming Challenge 9
 *pc9.cpp
 *Donald Wiley
 *created 2/14/2014
 *modified 2/14/2014
 */
 
#include <cassert>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


/*
 * Class Spaceship.
 * A class to model a simple spaceship for a science fiction
 * game or story.
 */
class Spaceship
{
	public:
	
		/*
		 * Set the name of this Spaceship.
		 * @param newName a string containing a name for this Spaceship
		 */
		void setName (string newName)
		{
		    name = newName;
		}
		
		/*
		 * Set the top speed of this Spaceship.
		 * @param newTopSpeed a float containing a top speed for this Spaceship
		 *        in warp
		 */
		void setTopSpeed (float newTopSpeed)
		{
		    topSpeed = newTopSpeed;
		}
		
		/*
		 * Set the fuel source of this Spaceship.
		 * @param newFuelSource a string containing a fuel source for this Spaceship
		 */
		void setFuelSource (string newFuelSource)
		{
		    fuelSource = newFuelSource;
		}
		
		/*
		 * Set the crew capacity of this Spaceship.
		 * @param newCrewCapacity an int containing a crew capacity for this Spaceship
		 */
		void setCrewCapacity (int newCrewCapacity)
		{
		    crewCapacity = newCrewCapacity;
		}
		
		/*
		 * Get the name of this Spaceship.
		 * @return a string containing the name of this Spaceship
		 */
		string getName () const
		{
		    return name;
		}
		
		/*
		 * Get the top speed of this Spaceship.
		 * @return a float containing the top speed of this Spaceship
		 */
		float getTopSpeed () const
		{
		    return topSpeed;
		}
		
		/*
		 * Get the fuel source of this Spaceship.
		 * @return a string containing the fuel source of this Spaceship
		 */
		string getFuelSource () const
		{
		    return fuelSource;
		}
		
		/*
		 * Get the crew capacity of this Spaceship.
		 * @return an int containing the crew capacity of this Spaceship
		 */
		int getCrewCapacity () const
		{
		    return crewCapacity;
		}
		
		/*
		 * Get a string representation of this Spaceship's specifications.
		 * The string will be formatted as
		 * "NAME, top speed: warp TOP_SPEED, fuel source: FUEL_SOURCE, crew capacity: CREW_CAPACITY"
		 * where NAME, TOP_SPEED (to two decimal places), FUEL_SOURCE, and CREW_CAPACITY
		 * contain the values of the associated member variables.
		 * @return a string representation of this Spaceship's specifications
		 */
		string toString () const
		{
		    stringstream tempStr, temp2;
		    string temp;
		    cout.setf (ios::fixed);
		    cout.setf (ios::showpoint);
		    cout.precision (2);
		    cout << topSpeed << endl;
		    tempStr << name << ", top speed: warp " << topSpeed <<  ", fuel source: " << fuelSource << ", crew capacity: " << crewCapacity;
		    return tempStr.str();
		}
		
	private:
	
		string name;
		float topSpeed;
		string fuelSource;
		int crewCapacity;
};

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main (int argc, char* argv[])
{
	unittest();
	
	return 0;
}

// CODE HERE -- FUNCTION DEFINITIONS


/*
 * Unit testing functions. Do not alter.
 */

void unittest ()
{
	cout << "\nSTARTING UNIT TEST\n\n";
	
	Spaceship enterprise;
	
	enterprise.setName("USS Enterprise");
	try {
		btassert<bool>(enterprise.getName() == "USS Enterprise");
		cout << "Passed TEST 1: setName/getName\n";
	} catch (bool b) {
		cout << "# FAILED TEST 1 setName/getName #\n";
	}
	
	enterprise.setTopSpeed(9.6);
	try {
		btassert<bool>(enterprise.getTopSpeed() >= 9.59 && enterprise.getTopSpeed() <= 9.61);
		cout << "Passed TEST 2: setTopSpeed/getTopSpeed\n";
	} catch (bool b) {
		cout << "# FAILED TEST 2 setTopSpeed/getTopSpeed #\n";
	}
	
	enterprise.setFuelSource("plasma");
	try {
		btassert<bool>(enterprise.getFuelSource() == "plasma");
		cout << "Passed TEST 3: setFuelSource/getFuelSource\n";
	} catch (bool b) {
		cout << "# FAILED TEST 3 setFuelSource/getFuelSource #\n";
	}
	
	enterprise.setCrewCapacity(5000);
	try {
		btassert<bool>(enterprise.getCrewCapacity() == 5000);
		cout << "Passed TEST 4: setCrewCapacity/getCrewCapacity\n";
	} catch (bool b) {
		cout << "# FAILED TEST 4 setCrewCapacity/getCrewCapacity #\n";
	}
	
	try {
		btassert<bool>(enterprise.toString() == 
							"USS Enterprise, top speed: warp 9.60, fuel source: plasma, crew capacity: 5000");
		cout << "Passed TEST 5: toString\n";
	} catch (bool b) {
		cout << "# FAILED TEST 5 toString #\n";
	}
		
	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}