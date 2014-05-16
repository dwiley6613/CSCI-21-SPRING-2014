/*
 *Donald Wiley
 *Programming Challenge 28
 *Demonstrates the usage of inheritance
 *MagicItem.h
 *created 5/9/2014
 *modified 5/9/2014
 *
 */
 
#pragma once
#include<string>
#include"Item.h"

namespace BaseItem
{
	class MagicItem : public Item
	{
		public:

			/* Default constructor with default arguments for name("magicitem"), value(0),
	         *   description("no description"), manaRequired(0); 
			 *   calls Item constructor in its initialization section 
			 *   with name and value
			 */
			MagicItem(string newName = "magicitem", unsigned int newValue = 0, string newDescription = "no description", unsigned int newManaRequired = 0);
			
			/* 
			 * destructor
			 */
			virtual ~MagicItem();
			
			/*
			 * function setDescription sets the description of the magic item
			 * @param string newDescription
			 * @return void
			 */
			void setDescription(string newDescription);
			
			/*
			 * function setManaRequired sets the number required item
			 * @param unsigned int manaRequired
			 * @return void
			 */
			void setManaRequired(unsigned int newMana);
			
			/*
			 * function getDescription gets the of the magic item
			 * @return string
			 */
			string getDescription();
			
			/*
			 * function getManaRequired gets the amount of the magic item required
			 * @return unsigned int
			 */
			float getManaRequired();
			
			/*
			 * function toString returns string with name and value, description, mana required of magic item;
			 *  format -- NAME, $VALUE, DESCRIPTION, requires MANAREQUIRED mana
			 *	EXAMPLE -- hat, 10, made of felt, requires 2 mana
			 * @return string
			 */
			string toString();
			
		private:

			string description;
			unsigned int manaRequired;
	};
}//BaseItem		  