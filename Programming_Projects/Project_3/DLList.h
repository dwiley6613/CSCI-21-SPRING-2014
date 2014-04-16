/*
 *
 * Programming Project 3
 * This program demonstrates the initialization and use of templated dynamically link lists
 * using classes
 * DLList.h
 * Donald Wiley
 * created 04/04/2014
 * modified 04/07/2014
 */
 
#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "DLNode.h"

using namespace std;

template <typename T>
class DLList
{
    public:
        /*
         * default constructor, sets values head(NULL) and count(0)
         */
        DLList()
		:head(NULL), tail(NULL),count(0){}

        /* 
         * destructor, calls the clear function
         */
	    virtual ~DLList(){
			clear();
		}
	    
		/*
		 * Function "newNode" create a new DLNode with newContents and return pointer
		 * @param T typename
		 * @return SLNode<T>* pointer
		 */
		DLNode<T>* newNode(T newContents){
			return new DLNode<T>(newContents);
		}
		
	    /*
	     * Function "pushFront" create a new DLNode with newContents and attach as head of list
		 * @param typename newContents
	     * @return void
	     */
	    void pushFront(T newContents){
			DLNode<T>* tmpHead = head;
			head = newNode(newContents);
			if (count == 0){
				head->setNext(NULL);
				head->setPrevious(NULL);
				tail = head;
			}
			else{
				head->setPrevious(NULL);
				head->setNext(tmpHead);
				tmpHead->setPrevious(head);
			}	
			tmpHead = NULL;
			count++;
		}  		
	    
	    /* 
	     * Function "popFront" remove the head node from the list
	     * @return void
	     */
	    void popFront(){
			if(count > 1){
				DLNode<T>* tmpHead = head;
				head = tmpHead->getNext();
				head->setPrevious(NULL);
				delete tmpHead;
				tmpHead = NULL;
				count--;
			}
			else if(count == 1){
				delete head;
				head = NULL;
				tail = NULL;
				count--;
			}
		}		
	    
	    /*
	     * Function "pushBack" create a new DLNode with newContents and attach at the end of list
	     * @param int newContents
	     * @returun void
	     */
	     void pushBack(T newContents){
			if (count == 0){
				pushFront(newContents);
			}
			else{
				tail->setNext(newNode(newContents));  //create new node and set tail node with pointer of new node
				(tail->getNext())->setPrevious(tail);  //set previousNode* of new tail node to old tail pointer
				tail = tail->getNext();
				tail->setNext(NULL);
				count++;
			}
		}		 
	     
	    /*
	     * Function "popBack" remove the tail node from the list
	     * @return void
	     */
        void popBack(){
			if(count == 1){
				popFront();
			}
			else if(count > 1){
				DLNode<T>* tmpNode = tail;
				tail->getPrevious()->setNext(NULL); //set nextNode of node in front of tail node to NULL
				tail = tail->getPrevious();
				delete tmpNode;
				tmpNode = NULL;
				count--;
			}
		}		

		/*
		 * Function "insert" create a new DLNode and insert it in the correct position
	     * in the list so that the values in the nodes are in 
	     * ascending order from head node to tail node
		 * @param typename newContencts
		 * @return void
		 */
		void insert(T newContents){
			
			if(head == NULL){
				pushFront(newContents);
			}
			else if(newContents <= head->getContents()){
				pushFront(newContents);
			}
			else if(newContents >= tail->getContents()){
				pushBack(newContents);
			}
			else{
				DLNode<T>* theNewNode = newNode(newContents);//create the new node
				DLNode<T>* beforeNode = head->getNext();// set insertBeforeNode to the second node
				DLNode<T>* afterNode = NULL;
				bool inserted = false;
				do{
					if((newContents < beforeNode->getContents()) and (newContents < beforeNode->getNext()->getContents())){//check contents of next two nodes
						afterNode = beforeNode->getPrevious();//assign afterNode to beforeNode's previousNode
						afterNode->setNext(theNewNode);//set afterNode's nextNode to theNewNode
						theNewNode->setPrevious(afterNode);//set theNewNode's previousNode to afterNode
						theNewNode->setNext(beforeNode);//set theNewNode's nextNode to beforeNode
						beforeNode->setPrevious(theNewNode);//set beforeNode's previousNode to theNewNode
						inserted = true;
						count++;
					}
					beforeNode = beforeNode->getNext();
				} while(! inserted);
				theNewNode = NULL;
				beforeNode = NULL;
				afterNode = NULL;
			}
		}		
		
		/*
		 * Function "removeFirst" remove the first appearance of the parameter value;
	     * return true on success or false if the value is not in the list
		 * @param int valToRemove
		 * @return bool
		 */
		bool removeFirst (T valToRemove){
			DLNode<T>* hereNode = findValue(valToRemove);
			if (hereNode == NULL){
				return false;
			}
			else if (hereNode == head){
				popFront();
				return true;
			}
			else if (hereNode == tail){
				popBack();
				return true;
			}
			else{
				hereNode->getPrevious()->setNext(hereNode->getNext());// save the nextNode of the hereNode to the previous node
				hereNode->getNext()->setPrevious(hereNode->getPrevious());//save  the previousNode of the hereNode to the next node
				delete hereNode; //remove the node
				hereNode = NULL;
				count--;
				return true;
			}
		}

		/*
		 * Function "removeAll" remove all instances of DLNode containing target
		 * @param typename valToRemove
		 * @return bool true if removed
		 */
		bool removeAll(T valToRemove){
			bool removed = false;
			while(removeFirst(valToRemove)){
				removed = true;
			}
		return removed;
		}
		
	    /*
	     * Function "clear" clear the entire contents of the list, freeing all memory
	     * associated with all nodes
	     * @return void
	     */						  
	    void clear(){  
			unsigned int lmt = count;
			for(unsigned int cnt = 0; cnt < lmt; cnt++){
				popFront();
			}
		}
		    
	    /*
	     * Function "getSize" Get the count of the list
	     * @return int 
	     */
	 	unsigned int getSize() const{
			return count;    
		}
		
		/*
		 * Function "getFront" return value of the contents of the head node
		 * @return typename contents
		 */
	 	T getFront(){
			if (count == 0)
				throw "LIST EMPTY";
			else{
				return head->getContents();
			}
		}
		
		/*
		 * Function "getBack" return value of the contents of the tail node
		 * @return typename contents
		 */
	 	T getBack(){
			if (count == 0)
				throw "LIST EMPTY";
			else{
				return tail->getContents();
			}
		}
		
		/*
		 * Function "get" return true if target is in list
		 * @param typename contents
		 * @return bool true if found
		 */
		bool get(T valToFind) const{
			if (findValue(valToFind) == NULL){
				return false;
			}
			else{
				return true;
			}
		}
		
        /*
	     * Function return a string representation of the contents
	     * of all nodes in the list, in the format
	     * NUM1,NUM2,...,LASTNUM; return empty string on 
	     * empty list
	     * @return string
	 	 */
        string toString() const{
			if(head == NULL){
				return "";
			}
			else{
				stringstream ss;
				for(DLNode<T>* cnt = head; cnt != NULL; cnt = cnt->getNext()){
					ss << cnt->getContents();
					if(cnt->getNext() != NULL){
						ss << ',';
					}
				}
				return ss.str();
			}
		}
		/*
		 * Friend overloaded operator function "<<"
		 * @param ostream& out
		 * @param DLList<T>& src
		 * @return ostream& out
		 */
		friend ostream& operator << (ostream& out, const DLList<T>& src)
		{
			return out << src.toString();
		}
		
		/*
		 *
		 */
		void bubbleSort(){
			DLNode<T>* hereNode = head;
			bool swapped = true;
			while(swapped){
				swapped = false;
				while(hereNode->getNext() != NULL){
					if(hereNode->getContents() > (hereNode->getNext())->getContents()){
						swapped = swapValues(hereNode);
					}
					hereNode = hereNode->getNext();
				}
			}
		}

		/*
		 *
		 */
		bool swapValues(DLNode<T>* hereNode){
			T tmpVal = hereNode->getContents ();
			hereNode->setContents((hereNode->getNext())->getContents());
			(hereNode->getNext())->setContents(tmpVal);
			return true;
		}
		
		/*
		 * Function "findValue" find the first given occurrence of a value
		 * in a linked list
		 * @return node pointer
		 */
		DLNode<T>* findValue(T valToFind)const{
			DLNode<T>* hereNode = head;
			for(unsigned int cnt=0; cnt < count; cnt++){
				if(hereNode->getContents() == valToFind){
					return hereNode;
				}
				else{
					hereNode = hereNode->getNext();
				}
			}
			return NULL;
		}
		
		/*
		 * F"unction removeAll" remove all occurrences of the parameter value fromthe list
		 * return true on success or false if the value is not in the list
		 * @param typename variable
		 */
		/*bool removeAll(T valueToRemove){
			bool removed = false;
			for(int cnt = 0; cnt < count; cnt++){
				if(removeFirst(valueToRemove)){
					removed = true;
				}
			}
			return removed;
		}*/
	    
    /*
     * head, DLNode* that points to the first node in a doubly-linked list
	 * tail, DLNode* that points to the last node in the doubly-linked list
	 * count, unsigned int the count of the number of nodes in the list
     */
     private:
        DLNode<T>* head;
		DLNode<T>* tail;
        unsigned int count;
};
