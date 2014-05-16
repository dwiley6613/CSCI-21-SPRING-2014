/*
 *Donald Wiley
 *Programming Challenge 28
 *Demonstrates the usage of inheritance
 *Item.h
 *created 5/8/2014
 *modified 5/8/2014
 *
 */
 
#pragma once
#include<string>

using std::string;

namespace BaseItem
{
	class Item
	{
		public:
			/*
			 * default constructor, sets name to "item" and value to 0
			 */	
			Item(string newName = "item", unsigned int newValue = 0);
			
			/* 
			 * destructor
			 */
			virtual ~Item();
			
			/*
			 * function setName sets the name of the item
			 * @param string newName
			 * @return void
			 */
			void setName(string newName);
			
			/*
			 * function setValue sets the value of the item
			 * @param unsigned int newValue
			 * @return void
			 */
			void setValue(unsigned int newValue);
			
			/*
			 * function getName gets the name of the item
			 * @return string
			 */
			string getName();
			
			/*
			 * function getValue gets the value of the item
			 * @return unsigned int
			 */
			unsigned int getValue();
			
			/*
			 * function toString returns string with name and value of item output format NAME, $VALUE
			 * @return string
			 */
			string toString();
			
		private:
			string name;
			unsigned int value;
	};
}//BaseItem