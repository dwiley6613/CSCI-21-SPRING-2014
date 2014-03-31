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
         * default constructor, set value nextNode(NULL)
         */
        SLNode()
		:nextNode(NULL){}
        
        /*
         * overloaded constructor, typename parameter assigned to contents
         */
        SLNode(T newContents)
		:contents(newContents), nextNode(NULL){}
        
        /* 
         * destructor, sets nextNode to NULL
         */
	    virtual ~SLNode()
		{
			nextNode = NULL;
		}
	    
	    /*
	     * Set the value of contents in this SLNode.
	     * @param int newContents 
	     * @return void
	     */
        void setContents (T newContents)
		{
			contents = newContents;
		}
        
        /*
         * Get the value in contents in this SLNode.
         * @return a typename containing the value
         * in contents of this SLNode
		 * @return typename T
         */
        T getContents () const
		{
			return contents;
		}
	
	    /*
	     * Set the value of the next SLNode in this SLNode.
	     * @param SLNode* newNextNode 
	     * @return void
	     */
        void setNextNode (SLNode* newNextNode)
		{
			nextNode = newNextNode; 
		}
        
	    /*
         * Get the address of the next node.
         * @return a pointer with address of the next node
         */
        
		SLNode<T>* getNextNode() const
		{
			return nextNode;   
		}
         
    private:
        T contents;
        SLNode* nextNode;
};