/*
 * Programming Programming Project 3 - UNIT TEST
 * Demonstrates the use of a templated doubly  linked list implemented in classes
 * Donald Wiley
 * DLNode.h
 * Created 4/4/2014
 * Modified 4/4/2014
 */
 
# pragma once
#include <string>
using namespace std;

template <typename T>
class DLNode
{
    public:

        /*
         * default constructor, set value nextNode(NULL)
         */
        DLNode()
		:previousNode(NULL), nextNode(NULL){}
        
        /*
         * overloaded constructor, typename parameter assigned to contents
         */
        DLNode(T newContents)
		:contents(newContents), previousNode(NULL), nextNode(NULL){}
        
        /* 
         * destructor, sets nextNode to NULL
         */
	    virtual ~DLNode()
		{
			previousNode = NULL;
			nextNode = NULL;
		}
	    
	    /*
	     * Set the value of contents in this DLNode.
	     * @param int newContents 
	     * @return void
	     */
        void setContents (T newContents)
		{
			contents = newContents;
		}
        
        /*
         * Get the value in contents in this DLNode.
         * @return a typename containing the value
         * in contents of this DLNode
		 * @return typename T
         */
        T getContents () const
		{
			return contents;
		}
		
		/*
	     * Set the value of the previous DLNode in this DLNode.
	     * @param DLNode* newPreviousNode 
	     * @return void
	     */
        void setPrevious (DLNode* newPrevious)
		{
			previousNode = newPrevious; 
		}
		
	    /*
	     * Set the value of the next DLNode in this DLNode.
	     * @param DLNode* newNextNode 
	     * @return void
	     */
        void setNext (DLNode* newNext)
		{
			nextNode = newNext; 
		}
        
	    /*
         * Get the address of the next node.
         * @return a pointer with address of the next node
         */
        
		DLNode<T>* getNext() const
		{
			return nextNode;   
		}

		/*
         * Get the address of the previous node.
         * @return a pointer with address of the previous node
         */
        
		DLNode<T>* getPrevious() const
		{
			return previousNode;   
		}
		
    private:
        T contents;
		DLNode* previousNode;
        DLNode* nextNode;
};