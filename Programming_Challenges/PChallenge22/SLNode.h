/*
 *
 * Programming Challenge 22
 * This program demonstrates the initialization and use of templated dynamically link lists
 * using classes
 * SLNode.h
 * Donald Wiley
 * created 03/29/2014
 * modified 03/29/2014
 */
 
# pragma once
#include <string>
using namespace std;

template <typename T>
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
        SLNode (T newContents);
        
        /* 
         * destructor, sets nextNode to NULL
         */
	    virtual ~SLNode();
	    
	    /*
	     * Set the value of contents in this SLNode.
	     * @param int newContents 
	     * @return void
	     */
        void setContents (T newContent);
        
        /*
         * Get the value in contents in this SLNode.
         * @return an integer containing the value
         * in contents of this SLNode
         */
        T getContents () const;
	
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
        SLNode* getNextNode() const;
         
    private:
        T contents;
        SLNode* nextNode;
};