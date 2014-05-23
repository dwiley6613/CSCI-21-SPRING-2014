//
// Grader comments 2014.05.14
// Full marks on DLList.h. Nice work.
// I added const to all of your get... functions, but that was
// just to get my test harness to work.
//
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
			if (head == NULL){
				head = newNode(newContents);
				tail = head;
				count++;
			}
			else{
				DLNode<T>* temp = newNode(newContents);
				head->setPrevious(temp);
				temp->setNext(head);
				head = temp;
				count++;
			}	
		}  		
	    
	    /* 
	     * Function "popFront" remove the head node from the list
	     * @return void
	     */
	    void popFront(){
			if(head != NULL && head->getNext() == NULL){
				delete head;
				head = NULL;
				tail = NULL;
				count--;
			}
			else if(head != NULL && head->getNext() != NULL ){
				DLNode<T>* temp = head;
				head = head->getNext();
				head->setPrevious(NULL);
				delete temp;
				count--;
			}
		}		
	    
	    /*
	     * Function "pushBack" create a new DLNode with newContents and attach at the end of list
	     * @param int newContents
	     * @returun void
	     */
	     void pushBack(T newContents){
			if (tail == NULL){
				tail = newNode(newContents);
				head = tail;
				count++;
			}
			else{
				DLNode<T>* temp = newNode(newContents);
				tail->setNext(temp);
				temp->setPrevious(tail);
				tail = temp;
				count++;
			}
		}		 
	     
	    /*
	     * Function "popBack" remove the tail node from the list
	     * @return void
	     */
        void popBack(){
			if(tail != NULL && tail->getPrevious() == NULL){
				delete tail;
				head = NULL;
				tail = NULL;
				count--;
			}
			else if(tail != NULL && tail->getPrevious() != NULL ){
				DLNode<T>* temp = tail;
				tail = tail->getPrevious();
				tail->setNext(NULL);
				delete temp;
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
				DLNode<T>* here = head;
				
				while(here->getNext() != NULL && here->getContents() < newContents){
					here = here->getNext();
				}
				if(here->getNext() == NULL && here->getContents() <= newContents){
					pushBack(newContents);
				}
				else{
					DLNode<T>* theNewNode = newNode(newContents);//create new node to insert
					DLNode<T>* before = here->getPrevious();//name the previous node so it's easier to use
					before->setNext(theNewNode);//link before node to new node
					theNewNode->setPrevious(before);//link new node to before node
					theNewNode->setNext(here);//link new node to here node
					here->setPrevious(theNewNode);//link here node to new node
					count++;

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
			while(head != NULL){
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
	 	T getFront() const {
			if (head == NULL)
				throw string("LIST EMPTY");
			else{
				return head->getContents();
			}
		}
		
		/*
		 * Function "getBack" return value of the contents of the tail node
		 * @return typename contents
		 */
	 	T getBack() const {
			if (tail == NULL)
				throw string("LIST EMPTY");
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
				return string("");
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
			out << src.toString();
			return out;
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
     * head, DLNode* that points to the first node in a doubly-linked list
	 * tail, DLNode* that points to the last node in the doubly-linked list
	 * count, unsigned int the count of the number of nodes in the list
     */
     private:
        DLNode<T>* head;
		DLNode<T>* tail;
        unsigned int count;
};
