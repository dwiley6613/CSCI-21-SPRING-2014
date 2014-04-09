/*
 *
 * Programming Challenge 18
 * This program demonstrates the initialization and use of dynamically link lists
 * using classes
 * SList.cpp
 * Donald Wiley
 * created 03/12/2014
 * modified 03/12/2014
 */
 
#include "SList.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

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
    SLNode* tmpHead = head;
    head = new SLNode(newContents);
    if (size == 0)
        head->setNextNode(NULL);
    else
        head->setNextNode(tmpHead);
    size++;
	tmpHead = NULL;
}   
	    
/* 
 * remove the head node from the list
 * @return void
 */
void SList::removeHead ()
{
    if (size > 0)
    {
        SLNode* tmpHead;
        tmpHead = head;
        head = tmpHead->getNextNode();
        delete tmpHead;
        tmpHead = NULL;
        size--;
    }
}
	    
/*
 * clear the entire contents of the list, freeing all memory
 * associated with all nodes
 */
void SList::clear ()
{  
    unsigned int lmt = size;
    for (unsigned int cnt = 0; cnt < lmt; cnt++)
        removeHead();
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
    SLNode* here;
    stringstream outString;
    
    here = head;
    
    if (size == 0)
        return "";
    else
        for (unsigned int cnt = 0; cnt < size; cnt++)
        {
            if (cnt == 0)
                outString << here->getContents();
            else 
                outString << "," << here->getContents();
            here = here->getNextNode();
        }
           
        return outString.str();
}