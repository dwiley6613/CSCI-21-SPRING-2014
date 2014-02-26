/*Programming Project 2
 *Donald Wiley
 */
 # include <string>
 using namespace std;
 
class Prize
{
 
    public:
        //default constructor: initial values itemName ("NO NAME"), itemValue (0)
        Prize()

        //public overloaded constructor: parameters for all data members
        Prize (string itemName, unsigned int itemValue)

        //public destructor: empty
        ~Prize ();
        
        //public accessors/gets and mutators/sets for all data members
        string getPrizeName ();
        void setPrizeName();
        
        unsigned int getPrizeVal();
        void setPrizeVal();
        
        //friend overloaded operator==: returns true if the prizeName and prizeValue of the two Prizes being compared are equivalent, else return false
        friend: 
            bool operator == (const Prize& prizeName_1, const Prize& prizeName_2);
        
        

    private:
        string prizeName;
        unsigned int prizeValue;

};