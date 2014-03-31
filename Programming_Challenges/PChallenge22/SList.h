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
#include "SLNode.h"

template <typename T>
class SList
{
    public:
        /*
         * default constructor, sets values head(NULL) and size(0)
         */
        SList ();

        /* 
         * destructor, calls the clear function
         */
	    virtual ~SList();
	    
	    /*
	     * Function "insertHead" create a new SLNode and attach as head of list
	     * @return void
	     */
	    void insertHead (T newContents);
	    
	    /* 
	     * Function "removeHead" remove the head node from the list
	     * @return void
	     */
	    void removeHead ();
	    
	    /*
	     * Function "insertTail" create a new SLNode and attach at the end of list
	     * @param int newContents
	     * @returun void
	     */
	     void insertTail (T newContents);
	     
	    /*
	     * Function "removeTail" remove the tail node from the list
	     * @return void
	     */
        void removeTail ();	      
	    

		/*
		 * Function "insert" create a new SLNode and insert it in the correct position
	     * in the list so that the values in the nodes are in 
	     * ascending order from head node to tail node
		 * @param int newContencts
		 * @return void
		 */
		void insert (T newContents);
		
		/*
		 * Function "removeFirst" remove the first appearance of the parameter value;
	     * return true on success or false if the value is not in the list
		 * @param int valToRemove
		 * @return bool
		 */
		bool removeFirst (T valToRemove);
						  
	    /*
	     * Function "clear" clear the entire contents of the list, freeing all memory
	     * associated with all nodes
	     * @return void
	     */						  
	    void clear ();
	    
	    /*
	     * Function "getSize" Get the size of the list
	     * @return int 
	     */
	 	unsigned int getSize () const;
	 	
        /*
	     * Function return a string representation of the contents
	     * of all nodes in the list, in the format
	     * NUM1,NUM2,...,LASTNUM; return empty string on 
	     * empty list
	     * @return string
	 	 */
        string toString () const;

		/*
		 *
		 */
		void bubbleSort ();

		/*
		 *
		 */
		bool swapValues (SLNode<T>* hereNode);
		
		/*
		 * Function "findValue" find the first given occurrence of a value
		 * in a linked list
		 * @return node pointer
		 */
		SLNode<T>* findValue(T valToFind);
		
		/*
		 * F"unction removeAll" remove all occurrences of the parameter value fromthe list
		 * return true on success or false if the value is not in the list
		 * @param typename variable
		 */
		bool removeAll(T valueToRemove);
	    
    /*
     * head, SLNode* that points to the first node in a singly-linked list
	 * size, unsigned int the count of the number of nodes in the list
     */
     private:
        SLNode<T>* head;
        unsigned int size;
};


	
	
	
	
	
	

	
	