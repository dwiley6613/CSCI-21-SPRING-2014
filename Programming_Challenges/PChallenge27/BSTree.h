/*
 * Donald Wiley
 * Demonstrates the use of binary search tree 
 * Programming Challenge 27 - UNIT TEST
 * BSTree.h
 * created 4/19/2014
 * modified 4/19/2014
 * 
 */
 
#pragma once
#include"BSTNode.h"
#include<cstdlib>
#include<string>
 
using namespace std;
 
class BSTree
{
	public:
		/*
         * default constructor, sets values root(NULL) and size(0)
         */
		BSTree();
		
        /* 
         * destructor, sets left and right child to (NULL)
         */
	    virtual ~BSTree();
	
		/*
		 * function bool insert (int), calls private function insert(int, root)
		 * @param int root
		 * @return bool
		 */
		 bool insert(int newContents);

		/*
		 * function bool remove (int), return value returned by private function remove(int, root)
		 * @param int value
		 * @return bool
		 */
		bool remove(int value);
		
		 /*
		  * function void clear (), call private function clear(root)
		  * @return void
		  */
		 void clear();
		 
		 /*
		  * function unsigned int getSize () const
		  * @return int size
		  */
		  unsigned int getSize() const;
		  
		  /*
		   * function void inOrder (), call private function inOrder(root)
		   * @return Void
		   */
		   void inOrder();
	
	private:
		BSTNode* root;
		unsigned int size;
		
		/*
		 * bool insert (int, BSTNode*&), create a new BSTNode and insert it into the tree, returns 
	     * 	true; if integer is already in the true, does not insert, returns false
		 * @param int BSTNode*&
		 * @return bool
		 */
		 bool insert(int newContents, BSTNode*& newNode);

		/*
		 * function bool remove (int, BSTNode*&), traverse the tree and remove the node containing the target 
	     * 	integer if present, return true; return false if target integer is not in tree
		 * @param int value DSTNode*& root
		 * @return bool
		 */
		bool remove(int value, BSTNode*& tmpRoot);
		
		/*
		 * function void removeMax (int&, BSTNode*&), helper function for private remove
		 * @param int& value BSTNode*& tmpRoot
		 * @return BSTNode*& tmpRoot
		 */
		void removeMax(int& value, BSTNode*& tmpRoot);

		/* 
		 * void clear (BSTNode*&), clear the entire contents of the tree, freeing all memory
	     * 	associated with all nodes
		 * @param BSTNode*& cNode
		 * @return void
		 */
		 void clear(BSTNode*& cNode);
		 
		 /*
		  * void inOrder (BSTNode*), print the data in all nodes in the tree, in ascending order, 
	      * 	separate by spaces (there should be a space after the last output value)
		  * @param BSTNode* rootNode
		  * @return void
		  */
		  void inOrder(BSTNode* rootNode);
};