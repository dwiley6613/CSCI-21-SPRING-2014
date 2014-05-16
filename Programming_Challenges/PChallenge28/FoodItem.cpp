/*
 *Donald Wiley
 *Programming Challenge 28
 *Demonstrates the usage of inheritance
 *FoodItem.cpp
 *created 5/9/2014
 *modified 5/9/2014
 *
 */
 

#include<cstdlib>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include"FoodItem.h"
using namespace std;


namespace BaseItem
{
	FoodItem::FoodItem(string newName, unsigned int newValue, unsigned int newCalories, string newUnitOfMeasure, float newUnits)
		: Item(newName, newValue), calories(newCalories), unitOfMeasure(newUnitOfMeasure), units(newUnits){}
			
	FoodItem::~FoodItem(){
	}

	void FoodItem::setCalories(unsigned int newCalories){
		calories = newCalories;
	}

	void FoodItem::setUnitOfMeasure(string newUOM){
		unitOfMeasure = newUOM;
	}
	
	void FoodItem::setUnits(float newUnits){
		units = newUnits;
	}
	
	unsigned int FoodItem::getCalories(){
		return calories;
	}
	
	string FoodItem::getUnitOfMeasure(){
		return unitOfMeasure;
	}

	float FoodItem::getUnits(){
		return units;
	}
	
	string FoodItem::toString(){
		stringstream ss;
		ss.setf(ios::fixed);
		ss.setf(ios::showpoint);
		ss << Item::toString() << ", " << setprecision(2) << units << " " << unitOfMeasure << ", " << calories << " calories";
		return ss.str();
	}
}//BaseItem