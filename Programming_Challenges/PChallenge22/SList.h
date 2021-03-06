/*
 *
 * Programming Challenge 22
 * This program demonstrates the initialization and use of templated dynamically link lists
 * using classes
 * SList.h
 * Donald Wiley
 * created 03/29/2014
 * modified 03/29/2014
 * modified 04/18/2014
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
			if (head == NULL){
				head = new SLNode<T>(newContents);
			}
			else{
				SLNode<T>* newNode = new SLNode<T>(newContents);
				newNode->setNextNode(head);
				head = newNode;
			}
			size++;
		}  		
	    
	    /* 
	     * Function "removeHead" remove the head node from the list
	     * @return void
	     */
	    void removeHead (){
			if(head != NULL && head->getNextNode() == NULL){
				delete head;
				head = NULL;
				size--;
			}
			else if(head != NULL){
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
			if (head == NULL){
				insertHead(newContents);
			}
			else if(head->getNextNode() == NULL){
				head->setNextNode(new SLNode<T>(newContents));
				size++;
			}
			else{
				SLNode<T>* here = head;
				while(here->getNextNode() != NULL){
					here = here->getNextNode();
				}
				here->setNextNode(new SLNode<T>(newContents));  //set nextNode* of hereNode to new node
				size++;
			}
		}		 
	     
	    /*
	     * Function "removeTail" remove the tail node from the list
	     * @return void
	     */
        void removeTail (){
			if(head != NULL){
				SLNode<T>* here = head;
				SLNode<T>* previous = NULL;
				while(here->getNextNode() != NULL){
					previous = here;
					here = here->getNextNode();
				}
				if(previous == NULL){
					removeHead();
				}
				else{
					previous->setNextNode(NULL);
					delete here;
				}
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
		bool removeFirst (T valToRemove){
			SLNode<T>* previous = findValue(valToRemove);//will be head or the pointer of previous node of the value found
			SLNode<T>* nodeToRemove = NULL;
			SLNode<T>* after = NULL;
			
			if(previous == head && head->getContents() == valToRemove){
				removeHead();
				return true;
			}
			else if(previous != NULL ){
				nodeToRemove = previous->getNextNode();// save node to be removed
				after = nodeToRemove->getNextNode();
				previous->setNextNode(after);
				delete nodeToRemove; //remove the node
				size--;
				return true;
			}
			else{
				return false;
			}
		}
						  
	    /*
	     * Function "clear" clear the entire contents of the list, freeing all memory
	     * associated with all nodes
	     * @return void
	     */						  
	    void clear (){
			while(head != NULL){
				removeHead();
			}
		}		
	    
	    /*
	     * Function "getSize" Get the size of the list
	     * @return int 
	     */
	 	unsigned int getSize () const{
			return size;    
		}
	 	
        /*
	     * Function return a string representation of the contents
	     * of all nodes in the list, in the format
	     * NUM1,NUM2,...,LASTNUM; return empty string on 
	     * empty list
	     * @return string
	 	 */
        string toString () const{
			if(head == NULL){
				return "";
			}
			else{
				stringstream ss;
				for(SLNode<T>* cnt = head; cnt != NULL; cnt = cnt->getNextNode()){
					ss << cnt->getContents();
					if(cnt->getNextNode() != NULL){
						ss << ',';
					}
				}
				return ss.str();
			}
		}

		/*
		 * Function "findValue" find the first given occurrence of a value
		 * in a linked list
		 * @return node pointer
		 */
		SLNode<T>* findValue(T valToFind){
			if(head != NULL && head->getContents() == valToFind){
				return head;//found value at head
			}
			else if(head != NULL){
				SLNode<T>* previous = NULL;
				SLNode<T>* here = head;
				while(here->getContents() != valToFind && here->getNextNode() != NULL){
					previous = here;
					here = here->getNextNode();
				}
				if(here->getContents() == valToFind){
					return previous;//found value
				}
				else{
					return NULL;//end of list and value not found
				}
			}
			else{
				return NULL;//empty list
			}
		}
		
		/*
		 * F"unction removeAll" remove all occurrences of the parameter value fromthe list
		 * return true on success or false if the value is not in the list
		 * @param typename variable
		 */
		bool removeAll(T valueToRemove)
		{
			bool removed = false;
			for(unsigned int cnt = 0; cnt < size; cnt++)
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


	
	
	
	
	
	

	
	