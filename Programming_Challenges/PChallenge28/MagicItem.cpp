/*
 *Donald Wiley
 *Programming Challenge 28
 *Demonstrates the usage of inheritance
 *MagicItem.cpp
 *created 5/9/2014
 *modified 5/9/2014
 *
 */
 
#include<string>
#include<sstream>
#include<iostream>
#include"Item.h"
#include"MagicItem.h"

using namespace std;

namespace BaseItem
{
			MagicItem::MagicItem(string newName, unsigned int newValue, string newDescription, unsigned int newManaRequired)
				: Item(newName, newValue), description(newDescription), manaRequired(newManaRequired){}

			MagicItem::~MagicItem(){
			}

			void MagicItem::setDescription(string newDescription){
				description = newDescription;
			}
			
			void MagicItem::setManaRequired(unsigned int newMana){
				manaRequired = newMana;
			}

			string MagicItem::getDescription(){
				return description;
			}

			float MagicItem::getManaRequired(){
				return manaRequired;
			}
			
			string MagicItem::toString(){
				stringstream ss;
				ss << Item::toString() << ", " << description << ", requires " << manaRequired << " mana";
				return ss.str();
			}
}//BaseItem		  