/*
 *Donald Wiley
 *Programming Challenge 28
 *Demonstrates the usage of inheritance
 *Item.cpp
 *created 5/8/2014
 *modified 5/9/2014
 *
 */
 

#include<cstdlib>
#include<string>
#include<iostream>
#include<sstream>
#include"Item.h"
using std::string;
using std::cout;
using std::endl;
using std::stringstream;


namespace BaseItem
{
	Item::Item(string newName, unsigned int newValue) : name(newName), value(newValue){
	}
		
	Item::~Item(){
	}
	void Item::setName(string newName){
		name = newName;
	}
	void Item::setValue(unsigned int newValue){
		value = newValue;
	}
	string Item::getName(){
		return name;
	}
	unsigned int Item::getValue(){
		return value;
	}
	string Item::toString(){
		stringstream ss;
		ss << name << ", $" << value;
		return ss.str();
	}
}//BaseItem