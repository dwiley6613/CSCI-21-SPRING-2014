/*
 * Programming Challenge29
 * Donald Wiley
 * treasurechest.cpp
 * created 5/16/2014
 * modified 5/21/2014
 * cplusplus.com
 */

#include "treasurechest.h" 
#include <algorithm> // for sort
#include <cstdlib> // for NULL
#include <iostream> // for operator<<
#include <string>
#include <vector>
 
void TreasureChest::addItem (const Item& newItem){
	chest.push_back(newItem);
}

void TreasureChest::insertItem (const Item& newItem, unsigned int position){
	if(position < chest.size()){
		vector<Item>::iterator it;
		it = chest.begin() + position;
		chest.insert(it, newItem);
	}
	else{
		chest.push_back(newItem);
	}
}

const Item* TreasureChest::getItem (unsigned int position){
	if(position < chest.size()){
		Item* tmpItemPtr;
		tmpItemPtr = &chest[position];
		return tmpItemPtr;
	}
	else{
		return NULL;
	}
}

Item TreasureChest::removeItem (unsigned int position) throw (string){
	Item tmpItem;	
	if(position < chest.size()){
		vector<Item>::iterator it;
		it = chest.begin() + position;
		tmpItem = chest[position];
		chest.erase(it);
	}
	else
		throw string("ERROR: attempting remove at invalid position");
	return tmpItem;
}

void TreasureChest::clear (){
	chest.clear();
}

bool TreasureChest::empty () const{
	return chest.empty();
}

unsigned int TreasureChest::getSize () const{
	return chest.size();
}

void TreasureChest::sortByName (){
	std::sort (chest.begin(), chest.end(), compareItemsByName);
}

void TreasureChest::sortByValue (){
	std::sort (chest.begin(), chest.end(), compareItemsByValue);
}

void TreasureChest::sortByQuantity (){
	std::sort (chest.begin(), chest.end(), compareItemsByQuantity);
}

ostream& operator<< (ostream& outs, const TreasureChest& src){
	for (unsigned int i=0; i < src.chest.size(); i++){
		outs << src.chest[i].name;
		if(src.chest.size() > 1 && i < src.chest.size() - 1){
			outs << ",";
		}
	}
	return outs;
}
 
bool compareItemsByName (const Item& lsrc, const Item& rsrc){
	return (lsrc.name < rsrc.name);
}

bool compareItemsByValue (const Item& lsrc, const Item& rsrc){
	return (lsrc.value < rsrc.value);
}

bool compareItemsByQuantity (const Item& lsrc, const Item& rsrc){
	return (lsrc.quantity < rsrc.quantity);
}