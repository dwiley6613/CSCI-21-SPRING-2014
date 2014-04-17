/*
 *
 * Programming Challenge 20
 * This program demonstrates the initialization and use of dynamically link lists
 * using classes
 * SLNode.cpp
 * Donald Wiley
 * created 03/17/2014
 * modified 03/17/2014
 */
 
#include <string>
# include "SLNode.h"


/*
 * default constructor, sets values nextNode(NULL) and contents(0)
 */
SLNode::SLNode ()
    :contents(0), nextNode (NULL){}
        
/*
 * overloaded constructor, int parameter assigned to contents
 */
SLNode::SLNode (int newContents)
    : contents (newContents), nextNode (NULL){}
        
/* 
 * destructor, sets nextNode to NULL
 */
SLNode::~SLNode()
{
    nextNode = NULL;
}
	    
/*
 * Set the value of contents in this SLNode.
 * @param int newContents 
 * @return void
 */
void SLNode::setContents (int newContents)
{
    contents = newContents;
}
        
/*
 * Get the value in contents in this SLNode.
 * @return an integer containing the value
 * in contents of this SLNode
 */
int SLNode::getContents () const
{
    return contents;
}
	
/*
 * Set the value of the next node in this SLNode.
 * @param SLNode* newNextNode 
 * @return void
 */
void SLNode::setNextNode (SLNode* newNextNode)
{
   nextNode = newNextNode; 
}
        
/*
 * Get the address of the next node.
 * @return a pointer with address of the next node
 */
SLNode* SLNode::getNextNode () const
{
    return nextNode;   
}
