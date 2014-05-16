/*
 *Donald Wiley
 *Programming Challenge 28
 *Demonstrates the usage of inheritance
 *FoodItem.h
 *created 5/9/2014
 *modified 5/9/2014
 *
 */
 
#pragma once
#include<string>
#include"Item.h"

namespace BaseItem
{
	class FoodItem : public Item
	{
		public:

			/* Default constructor arguments for name("fooditem"), value(0), calories(0),
			 *	unitOfMeasure("nounits"), units(0); calls Item constructor
			 *  in its initialization section with name and value
			 */
			FoodItem(string newName = "fooditem", unsigned int newValue = 0, unsigned int newCalories = 0, string newUnitOfMeasure = "nounits", float newUnits = 0);
			
			/* 
			 * destructor
			 */
			virtual ~FoodItem();
			
			/*
			 * function setCalories sets the number of calories for the food item
			 * @param unsigned int calories
			 * @return void
			 */
			void setCalories(unsigned int newCalories);
			
			/*
			 * function setUnitOfMeasure sets the unit of measure for the food item
			 * @param string newUOM
			 * @return void
			 */
			void setUnitOfMeasure(string newUOM);
			
			/*
			 * function setUnits sets the nember of units for the food item
			 * @param float newUnits
			 * @return void
			 */
			void setUnits(float newUnits);
			
			/*
			 * function getCalories gets the amount of calories for a food item
			 * @return unsigned int
			 */
			unsigned int getCalories();
			
			/*
			 * function getUnitOfMeasure gets the type of units the food item is measure in
			 * @return string
			 */
			string getUnitOfMeasure();
			
			/*
			 * function getUnits gets the amount of the food item
			 * @return float
			 */
			float getUnits();
			
			/*
			 * function toString returns string with name and value, units, unit of measure and calories of item;
			 *  output format NAME, $VALUE, UNITS UNITOFMEASURE, CALORIES calories
			 *	EXAMPLE -- cookie, 1, 2.50 cookie(s), 250 calories
			 * @return string
			 */
			string toString();
		private:

			unsigned int calories;
			string unitOfMeasure;//  (such as "ounces")
			float units; 
	};
}//BaseItem		  