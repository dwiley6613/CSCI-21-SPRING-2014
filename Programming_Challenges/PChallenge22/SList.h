/*
 *
 * Programming Challenge 22
 * This program demonstrates the initialization and use of templated dynamically link lists
 * using classes
 * SList.h
 * Donald Wiley
 * created 03/29/2014
 * modified 03/29/2014
 */
 
#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "SLNode.h"

using namespace std;

template <typename T>
class SList{
    public:
        /*
         * default constructor, sets values head(NULL) and size(0)
         */
        SList ()
		:head (NULL), size(0){}

        /* 
         * destructor, calls the clear function
         */
	    virtual ~SList(){
			SList::clear();
		}
	    
	    /*
	     * Function "insertHead" create a new SLNode and attach as head of list
	     * @return void
	     */
	    void insertHead (T newContents){
			SLNode<T>* tmpHead = NULL;
			tmpHead = head;
			head = new SLNode<T>(newContents);
			if (size == 0){
				head->setNextNode(NULL);
			}
			else{
				head->setNextNode(tmpHead);
			}
			tmpHead = NULL;
			size++;
		}  		
	    
	    /* 
	     * Function "removeHead" remove the head node from the list
	     * @return void
	     */
	    void removeHead (){
			if(size > 0){
				SLNode<T>* tmpHead;
				tmpHead = head;
				head = tmpHead->getNextNode();
				delete tmpHead;
				tmpHead = NULL;
				size--;
			}
		}		
	    
	    /*
	     * Function "insertTail" create a new SLNode and attach at the end of list
	     * @param int newContents
	     * @returun void
	     */
	     void insertTail (T newContents){
			if (size == 0){
				SList::insertHead(newContents);
			}
			else{
				SLNode<T>* hereNode = head;
				while(hereNode->getNextNode() != NULL){
					hereNode = hereNode->getNextNode();
				}
				hereNode->setNextNode(new SLNode<T>(newContents));  //set nextNode* of hereNode to new node
				(hereNode->getNextNode())->setNextNode(NULL);  //set nextNode* of new tail node to NULL
				size++;
			}
		}		 
	     
	    /*
	     * Function "removeTail" remove the tail node from the list
	     * @return void
	     */
        void removeTail (){
			if(size == 1){
				removeHead() ;
			}
			else if(size > 1){
				SLNode<T>* hereNode = head;
				SLNode<T>* preNode;
				while(hereNode->getNextNode() != NULL){
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
	    
		/*
		 * Function "insert" create a new SLNode and insert it in the correct position
	     * in the list so that the values in the nodes are in 
	     * ascending order from head node to tail node
		 * @param typename newContencts
		 * @return void
		 */
		void insert (T newContents){
			if(head == NULL){
				insertHead(newContents);
			}
			else if(newContents <= head->getContents()){
				insertHead(newContents);
			}
			else if(head->getNextNode() == NULL && newContents > head->getContents()){
				insertTail(newContents);
			}
			else{
				SLNode<T>* here = head;// set insertBeforeNode to the second node
				SLNode<T>* previous = NULL;
		
				while(here->getNextNode() != NULL && here->getContents() < newContents){
					previous = here;
					here = here->getNextNode();
				}
				if(here->getNextNode() == NULL && here->getContents() < newContents){
					insertTail(newContents);
				}
				else{
					previous->setNextNode(new SLNode<T>(newContents));//create new node and set previous nextNode to new node
					previous->getNextNode()->setNextNode(here);//set new node's nextNode to here node
					size++;
				}
			}
		}
		
		/*
		 * Function "removeFirst" remove the first appearance of the parameter value;
	     * return true on success or false if the value is not in the list
		 * @param int valToRemove
		 * @return bool
		 */
		bool removeFirst (T valToRemove)
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
						  
	    /*
	     * Function "clear" clear the entire contents of the list, freeing all memory
	     * associated with all nodes
	     * @return void
	     */						  
	    void clear ()
		{  
			unsigned int lmt = size;
			for(unsigned int cnt = 0; cnt < lmt; cnt++)
				removeHead();
		}		
	    
	    /*
	     * Function "getSize" Get the size of the list
	     * @return int 
	     */
	 	unsigned int getSize () const
		{
			return size;    
		}
	 	
        /*
	     * Function return a string representation of the contents
	     * of all nodes in the list, in the format
	     * NUM1,NUM2,...,LASTNUM; return empty string on 
	     * empty list
	     * @return string
	 	 */
        string toString () const
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

		/*
		 *
		 */
		void bubbleSort ()
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

		/*
		 *
		 */
		bool swapValues (SLNode<T>* hereNode)
		{
			T tmpVal = hereNode->getContents ();
			hereNode->setContents((hereNode->getNextNode())->getContents());
			(hereNode->getNextNode())->setContents(tmpVal);
		 
			return true;
		}
		
		/*
		 * Function "findValue" find the first given occurrence of a value
		 * in a linked list
		 * @return node pointer
		 */
		SLNode<T>* findValue(T valToFind)
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
		
		/*
		 * F"unction removeAll" remove all occurrences of the parameter value fromthe list
		 * return true on success or false if the value is not in the list
		 * @param typename variable
		 */
		bool removeAll(T valueToRemove)
		{
			bool removed = false;
			for(int cnt = 0; cnt < size; cnt++)
				if(removeFirst(valueToRemove))
					removed = true;
			return removed;
		}
	    
    /*
     * head, SLNode* that points to the first node in a singly-linked list
	 * size, unsigned int the count of the number of nodes in the list
     */
     private:
        SLNode<T>* head;
        unsigned int size;
};


	
	
	
	
	
	

	
	