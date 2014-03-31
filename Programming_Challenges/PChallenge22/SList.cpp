/*
 *
 * Programming Challenge 22
 * This program demonstrates the initialization and use of templated dynamically link lists
 * using classes
 * SList.cpp
 * Donald Wiley
 * created 03/29/2014
 * modified 03/29/2014
 */
 
#include "SList.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

template<typename T>
SList<T>::SList()
    :head (NULL), size(0){}
    
template<typename T>
SList<T>::~SList()
{
    SList::clear();
}

template<typename T>
void SList<T>::insertHead(T newContents)
{
    SLNode<T>* tmpHead = NULL;
    tmpHead = head;
    head = new SLNode<T>(newContents);
    if (size == 0)
        head->setNextNode(NULL);
    else
        head->setNextNode(tmpHead);
    tmpHead = NULL;
    size++;
}   

template<typename T>	    
void SList<T>::removeHead()
{
    if(size > 0)
    {
        SLNode<T>* tmpHead;
        tmpHead = head;
        head = tmpHead->getNextNode();
        delete tmpHead;
        tmpHead = NULL;
        size--;
    }
}

template<typename T>
void SList<T>::insertTail(T newContents)
{
    if (size == 0)
        SList::insertHead(newContents);
    else
    {
        SLNode<T>* hereNode = head;
        while(hereNode->getNextNode() != NULL)
            hereNode = hereNode->getNextNode();
        hereNode->setNextNode(new SLNode<T>(newContents));  //set nextNode* of hereNode to new node
        (hereNode->getNextNode())->setNextNode(NULL);  //set nextNode* of new tail node to NULL
		size++;
    }
}

template<typename T>
void SList<T>::removeTail()
{
    if(size == 1)
    {
        removeHead() ;
    }
        
    else if(size > 1)
    {
        SLNode<T>* hereNode = head;
        SLNode<T>* preNode;
        while(hereNode->getNextNode() != NULL)
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

template<typename T>
void SList<T>::insert(T newContents)
{
	insertHead(newContents);
	bubbleSort();
}

template<typename T>
bool SList<T>::removeFirst(T valToRemove)
{
	SLNode<T>* tmpNode = NULL;
	SLNode<T>* previousNode = NULL;
	if(findValue(valToRemove) == NULL)
	{
		return false;
	}
	else
	{
		previousNode = findValue(valToRemove);
		tmpNode =(previousNode->getNextNode())->getNextNode(); // save the nextNode of the node to be removed
		delete previousNode->getNextNode(); //remove the node
		previousNode->setNextNode(tmpNode);  //store next node from removed node to previous node		
		size--;
		return true;
	}
}

template<typename T>
void SList<T>::clear()
{  
    unsigned int lmt = size;
    for(unsigned int cnt = 0; cnt < lmt; cnt++)
        removeHead();
}
	    

template<typename T>
unsigned int SList<T>::getSize() const
{
    return size;    
}

template<typename T>
string SList<T>::toString() const
{
    SLNode<T>* here;
    stringstream outString;
    
    here = head;
    
    if(size == 0)
        return "";
    else
        for(unsigned int cnt = 0; cnt < size; cnt++)
        {
            if(cnt == 0)
                outString << here->getContents();
            else 
                outString << "," << here->getContents();
            here = here->getNextNode();
        }
           
        return outString.str();
}

template<typename T>
void SList<T>::bubbleSort ()
{
	SLNode<T>* hereNode = head;
    bool swapped = true;
	while(swapped)
	{
        swapped = false;
		while(hereNode->getNextNode() != NULL)
		{
			if(hereNode->getContents() > (hereNode->getNextNode())->getContents())
			{
		        swapped = swapValues(hereNode);
			}
			hereNode = hereNode->getNextNode();
		}

	}
}

template<typename T>
bool SList<T>::swapValues(SLNode<T>* hereNode)
{
    int tmpVal = hereNode->getContents ();
    hereNode->setContents((hereNode->getNextNode())->getContents());
    (hereNode->getNextNode())->setContents(tmpVal);
 
    return true;
}
template<typename T>
SLNode<T>* SList<T>::findValue(T valToFind)
{
	SLNode<T>* previousNode = head;
	SLNode<T>* hereNode = head;
	for(unsigned int cnt=0; cnt < size; cnt++)
		if(hereNode->getContents() == valToFind)
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

template<typename T>
bool SList<T>::removeAll(T valueToRemove)
{
	bool removed = false;
	for(int cnt = 0; cnt < size; cnt++)
		if(removeFirst(valueToRemove))
			removed = true;
	return removed;
}