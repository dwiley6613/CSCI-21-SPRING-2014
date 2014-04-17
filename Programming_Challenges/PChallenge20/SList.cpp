/*
 *
 * Programming Challenge 20
 * This program demonstrates the initialization and use of dynamically link lists
 * using classes
 * SList.cpp
 * Donald Wiley
 * created 03/17/2014
 * modified 03/17/2014
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
		size++;
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

void SList::insert (int newContents)
{
	insertHead (newContents);
	bubbleSort();
}
	/*if(head == NULL){
		insertHead(newContents);
		return true;
	}
	else if(newContents <= head->getContents()){
		insertHead(newContents);
		return true;
	}
	else if(head->getNext == NULL && newContents > head->getContents()){
		insertTail(newContents);
		return true;
	}
	else{
		temp = new SLNode*(newContents);//create the new node
		SLNode* hear = head;// set insertBeforeNode to the second node
		
		while(newContents < here->getcontents()){
			if((newContents < beforeNode->getContents()) && (newContents < beforeNode->getNext()->getContents())){//check contents of next two nodes
				afterNode = beforeNode->getPrevious();//assign afterNode to beforeNode's previousNode
				afterNode->setNext(theNewNode);//set afterNode's nextNode to theNewNode
				theNewNode->setPrevious(afterNode);//set theNewNode's previousNode to afterNode
				theNewNode->setNext(beforeNode);//set theNewNode's nextNode to beforeNode
				beforeNode->setPrevious(theNewNode);//set beforeNode's previousNode to theNewNode
				inserted = true;
				count++;
			}
			beforeNode = beforeNode->getNext();
		}
		theNewNode = NULL;
		beforeNode = NULL;
		afterNode = NULL;
	}*/

bool SList::removeFirst (int valToRemove)
{
	SLNode* tmpNode = NULL;
	SLNode* previousNode = NULL;
	if(findValue(valToRemove) == NULL)
	{
		return false;
	}
	else
	{
		previousNode = findValue(valToRemove);
		tmpNode = (previousNode->getNextNode())->getNextNode(); // save the nextNode of the node to be removed
		delete previousNode->getNextNode(); //remove the node
		previousNode->setNextNode(tmpNode);  //store next node from removed node to previous node		
		size--;
		return true;
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

void SList::bubbleSort ()
{
	SLNode* hereNode = head;
    bool swapped = true;
	while (swapped)
	{
        swapped = false;
		while(hereNode->getNextNode() != NULL)
		{
			if (hereNode->getContents() > (hereNode->getNextNode())->getContents())
			{
		        swapped = swapValues(hereNode);
			}
			hereNode = hereNode->getNextNode();
		}

	}
}

bool SList::swapValues (SLNode* hereNode)
{
    int tmpVal = hereNode->getContents ();
    hereNode->setContents((hereNode->getNextNode())->getContents());
    (hereNode->getNextNode())->setContents(tmpVal);
 
    return true;
}

SLNode* SList::findValue(int valToFind)
{
	SLNode* previousNode = head;
	SLNode* hereNode = head;
	for(unsigned int cnt=0; cnt < size; cnt++)
		if (hereNode->getContents() == valToFind)
		{
			return previousNode;
		}
		else
		{
			previousNode = hereNode;
			hereNode = hereNode->getNextNode();
		}
	return NULL;
}