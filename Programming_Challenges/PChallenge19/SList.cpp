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

void SList::insertHead (int newContents)
{
    SLNode* tmpHead = NULL;
    tmpHead = head;
    head = new SLNode(newContents);
    if (size == 0)
        head->setNextNode(NULL);
    else
        head->setNextNode(tmpHead);
    tmpHead = NULL;
    size++;
}   
	    
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

void SList::insertTail (int newContents)
{
    if (size == 0)
        SList::insertHead (newContents);
    else
    {
        SLNode* hereNode = head;
        while (hereNode->getNextNode() != NULL)
            hereNode = hereNode->getNextNode();
        hereNode->setNextNode(new SLNode(newContents));  //set nextNode* of hereNode to new node
        (hereNode->getNextNode())->setNextNode(NULL);  //set nextNode* of new tail node to NULL
    }
}

void SList::removeTail ()
{
    if (size == 1)
    {
        removeHead() ;
    }
        
    else if (size > 1)
    {
        SLNode* hereNode = head;
        SLNode* preNode;
        cout << "here we are" << endl;
        while (hereNode->getNextNode() != NULL)
        {
            preNode = hereNode;
            hereNode = hereNode->getNextNode();
        }
        preNode->setNextNode(NULL);
        delete hereNode;
        hereNode = NULL;
        preNode = NULL;
        size--;
    }
}

void SList::clear ()
{  
    unsigned int lmt = size;
    for (unsigned int cnt = 0; cnt < lmt; cnt++)
        removeHead();
}
	    

unsigned int SList::getSize () const
{
    return size;    
}

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