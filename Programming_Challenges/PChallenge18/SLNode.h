/*
 *
 * Programming Challenge 18
 * This program demonstrates the initialization and use of dynamically link lists
 * using classes
 * SLNode.h
 * Donald Wiley
 * created 03/12/2014
 * modified 03/12/2014
 */
 
# pragma once
#include <string>
using namespace std;

class SLNode
{
    public:

        /*
         * default constructor, sets values nextNode(NULL) and contents(0)
         */
        SLNode ();
        
        /*
         * overloaded constructor, int parameter assigned to contents
         */
        SLNode (int newContents);
        
        /* 
         * destructor, sets nextNode to NULL
         */
	    virtual ~SLNode();
	    
	    /*
	     * Set the value of contents in this SLNode.
	     * @param int newContents 
	     * @return void
	     */
        void setContents (int newContent);
        
        /*
         * Get the value in contents in this SLNode.
         * @return an integer containing the value
         * in contents of this SLNode
         */
        int getContents () const;
	
	    /*
	     * Set the value of the next SLNode in this SLNode.
	     * @param SLNode* newNextNode 
	     * @return void
	     */
        void setNextNode (SLNode* newNextNode);
        
	    /*
         * Get the address of the next node.
         * @return a pointer with address of the next node
         */
        SLNode* getNextNode () const;
         
    private:
        int contents;
        SLNode* nextNode;
};