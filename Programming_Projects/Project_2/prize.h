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

/*
		 * Constructor.
		 * creates an instance of type Prize class
		 * prizeName string initialized to "NO NAME"
		 * prizeVal unsigned int initialized to 0
		 */        
        Prize ();
 /*
		 * Overloaded constructor.
		 * creates an instance of type Prize class
		 * @param prizeName string 
		 * @param prizeVal unsigned int
		 */       
        Prize (string newName, unsigned int newVal);

/*
		 * Destructor.
		 */        
        ~Prize ();
        


            //Accessors/gets AND Mutators/sets for prizeName, prizeValue//
            
/*
         * Set function named "setPrizeName" with parameter newName
         * @param newName string
         * @return void
         */           
        void setPrizeName (string newName);       
 
 /*
         * Set function named "setPrizeVale" with parameter newValue
         * @param newValue unsigned int
         * @return void
         */       
        void setPrizeValue (unsigned int newVal);
        
/*
         * Get function named "getPrizeName" no parameters and set to const
         * @return a string contianing prize name
         */
        string getPrizeName () const;

/*
         * Get function named "getPrizeVale" no parameters and set to const
         * @return an unsigned int containing the prize value
         */        
        unsigned int getPrizeValue () const;
        

    
        friend bool operator == (const Prize& prizeName_1, const Prize& prizeName_2);
        
    private:
    
        string prizeName;
        unsigned int prizeVal;
};
 