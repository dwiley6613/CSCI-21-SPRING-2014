/*
 * Programming Challenge29
 * Donald Wiley
 * treasurechest.cpp
 */

#include "treasurechest.h" 
#include <algorithm> // for sort
#include <cstdlib> // for NULL
#include <iostream> // for operator<<
#include <string>
#include <vector>
 
/*
 * Add an item to the end of the chest.
 * @param newItem the item to be added to the end of the chest
 */
void TreasureChest::addItem (const Item& newItem){
	chest.push_back(newItem);
}

/*
 * Insert an item at the specified zero-indexed position in the chest.
 * If position is not valid for the chest, add the item to 
 * the end of the chest.
 * @param newItem the item to be inserted into the chest
 * @param position the zero-indexed position where the insertion
 *        is to take place
 */
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

/*
 * Get a pointer to an item at a specified zero-indexed position in the chest.
 * @param position the zero-indexed position of the item
 * @return a pointer to the item if position is valid, else NULL
 */
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

/*
 * Remove an item from the chest at a specified zero-indexed position.
 * @param position the zero-indexed position of the item
 * @return a copy of the Item removed from the chest
 * @throw string("ERROR: attempting remove at invalid position") if
 *        position is not valid
 */
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

/*
 * Clear the chest of all items.
 */
void TreasureChest::clear (){
	chest.clear();
}

/*
 * Check to see if the chest is empty.
 * @return true if the chest is empty, else false
 */
bool TreasureChest::empty () const{
	return chest.empty();
}

/*
 * Get the size/number of items currently in the chest.
 * @return an unsigned integer containing the current size of the chest
 */
unsigned int TreasureChest::getSize () const{
	return chest.size();
}

/*
 * Sort the items in the chest by name, using the sort function 
 * from the C++ standard algorithm library.
 */
void TreasureChest::sortByName (){
	std::sort (chest.begin(), chest.end(), compareItemsByName);
}

/*
 * Sort the items in the chest by value, using the sort function 
 * from the C++ standard algorithm library.
 */
void TreasureChest::sortByValue (){
	std::sort (chest.begin(), chest.end(), compareItemsByValue);
}

/*
 * Sort the items in the chest by quantity, using the sort function 
 * from the C++ standard algorithm library.
 */
void TreasureChest::sortByQuantity (){
	std::sort (chest.begin(), chest.end(), compareItemsByQuantity);
}

/*
 * Place the names of the items in the chest on the specified stream,
 * formatted as ITEM_NAME,ITEM_NAME,...ITEM_NAME
 */
ostream& operator<< (ostream& outs, const TreasureChest& src){
	for (unsigned int i=0; i < src.chest.size(); i++){
		outs << src.chest[i].name;
		if(src.chest.size() > 1 && i < src.chest.size() - 1){
			outs << ",";
		}
	}
	return outs;
}
 
/*
 * Compare two items by name.
 * @return true if lsrc.name < rsrc.name, else false
 */
bool compareItemsByName (const Item& lsrc, const Item& rsrc){
	return (lsrc.name < rsrc.name);
}

/*
 * Compare two items by value.
 * @return true if lsrc.value < rsrc.value, else false
 */
bool compareItemsByValue (const Item& lsrc, const Item& rsrc){
	return (lsrc.value < rsrc.value);
}

/*
 * Compare two items by quantity.
 * @return true if lsrc.quantity < rsrc.quantity, else false
 */
bool compareItemsByQuantity (const Item& lsrc, const Item& rsrc){
	return (lsrc.quantity < rsrc.quantity);
}