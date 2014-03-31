/*
 *
 * Programming Challenge 22
 * This program demonstrates the initialization and use of templated dynamically link lists
 * using classes
 * SLNode.cpp
 * Donald Wiley
 * created 03/29/2014
 * modified 03/29/2014
 */
 
#include <string>
#include "SLNode.h"


/*
 * default constructor, sets value nextNode(NULL)
 */
template <typename T>
SLNode<T>::SLNode ()
:nextNode(NULL){}
        
/*
 * overloaded constructor, typename parameter assigned to contents
 */
template <typename T>
SLNode<T>::SLNode (T newContents)
    : contents (newContents), nextNode (NULL){}
        
/* 
 * destructor, sets nextNode to NULL
 */
template <typename T>
SLNode<T>::~SLNode()
{
    nextNode = NULL;
}
	    
/*
 * Set the value of contents in this SLNode.
 * @param typename newContents 
 * @return void
 */
template <typename T>
void SLNode<T>::setContents (T newContents)
{
    contents = newContents;
}
        
/*
 * Get the value in contents in this SLNode.
 * @return a typename parameter containing the value
 * in contents of this SLNode
 */
template <typename T>
T SLNode<T>::getContents () const
{
    return contents;
}
	
/*
 * Set the value of the next node in this SLNode.
 * @param SLNode* newNextNode 
 * @return void
 */
template <typename T>
void SLNode<T>::setNextNode (SLNode* newNextNode)
{
   nextNode = newNextNode; 
}
        
/*
 * Get the address of the next node.
 * @return a pointer with address of the next node
 */
template <typename T>
SLNode<T>* SLNode<T>::getNextNode() const
{
	return nextNode;   
}
