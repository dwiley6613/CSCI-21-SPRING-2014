/*Programming Project 2
 *Donald Wiley
 */
 
class Prize
{
 
    public:
        //default constructor: initial values itemName ("NO NAME"), itemValue (0)
        Prize(string itemName = "NO Name", unsigned int itemValue = 0)
	    {
	        prizeName = itemName;
	        prizeValue = itemValue;
	    }
        //public overloaded constructor: parameters for all data members
        Prize (string itemName);
        
        Prize (unsigned int itemValue);
        
        //public destructor: empty
        ~Prize ();
        
        //friend overloaded operator==: returns true if the prizeName and prizeValue of the two Prizes being compared are equivalent, else return false
        friend bool operator == (const Prize& prizeName_1, const Prize& prizeName_2);
        
        //public accessors/gets and mutators/sets for all data members
        string getPrizeName ();
        void setPrizeName();
        
        unsigned int getPrizeVal();
        void setPrizeVal();

    private:
    string prizeName;
    unsigned int prizeValue;

}