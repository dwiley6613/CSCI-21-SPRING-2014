/*
 *
 * Programming Challenge 18
 * This program demonstrates the initialization and use of dynamically link lists
 * using classes
 * SList.h
 * Donald Wiley
 * created 03/12/2014
 * modified 03/12/2014
 */
 
#pragma once
#include <string>
#include "SLNode.h"

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
	     * create a new SLNode and attach as head of list
	     */
	    void insertHead (int newSize);
	    
	    /*
	     * Function "insertTrail" create a new SLNode and attach at the end of list
	     * @param int newContents
	     * @return void
	     */
	    void insertTail (int newContents); 
	    
	    /* 
	     * remove the head node from the list
	     * @return void
	     */
	    void removeHead ();
	    
	    /*
	     * clear the entire contents of the list, freeing all memory
	     * associated with all nodes
	     */
	    void clear ();
	    
	    /*
	     * Get the size of the list
	     * @return int 
	     */
	 	unsigned int getSize () const;
	 	
        /*
	     * @return a string representation of the contents
	     * of all nodes in the list, in the format
	     * NUM1,NUM2,...,LASTNUM; return empty string on 
	     * empty list 
	 	 */
        string toString () const;	
	    
    /*
     * head, SLNode* that points to the first node in a singly-linked list
	 * size, unsigned int the count of the number of nodes in the list
     */
     private:
        SLNode* head;
        unsigned int size;
};


	
	
	
	
	
	

	
	