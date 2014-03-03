/*Programming Project 2
 *Donald Wiley
 *prize.h
 */
#pragma once

#include <string>
using namespace std;

class Prize
{
    public:
        
        Prize ();
        
        Prize (string newName, unsigned int newVal);
        
        ~Prize ();
        
        string getName () const;
        void setName (string newName);
        
        unsigned int getVal () const;
        void setVal (unsigned int newVal);
    
        friend bool operator == (const Prize& prizeName_1, const Prize& prizeName_2);
        
    private:
    
        string prizeName;
        unsigned int prizeVal;
};
 
   