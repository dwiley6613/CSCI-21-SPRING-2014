/*
 *
 * Programming Challenge 18
 * This program demostrates the initialization and use of dynamicly link lists
 * using classes
 * SList.cpp
 * Donald Wiley
 * created 03/12/2014
 * modified 03/12/2014
 */
 
#include "SList.h"
#include <string>

SList::SList ()
    :head (NULL), size(0){}
    

SList::~SList()
{
    SList::clear();
}
	    
/*
 * create a new SLNode and attach as head of list
 */
void SList::insertHead (int newContents)
{
    head = new SLNode(newContents);
    size++;
}   
	    
/* 
 * remove the head node from the list
 * @return void
 */
void SList::removeHead ()
{
    
}
	    
/*
 * clear the entire contents of the list, freeing all memory
 * associated with all nodes
 */
void SList::clear ()
{
    
}
	    
/*
 * Get the size of the list
 * @return int 
 */
unsigned int SList::getSize () const
{
    return size;    
}
	 	
/*
 * @return a string representation of the contents
 * of all nodes in the list, in the format
 * NUM1,NUM2,...,LASTNUM; return empty string on 
 * empty list 
 */
string SList::toString () const
{
    if (size == 0)
        return "";
    else
        return "test";
}