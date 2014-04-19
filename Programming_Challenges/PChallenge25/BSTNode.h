/*
 * Donald Wiley
 * Demonstrates the use of binary search tree 
 * Programming Challenge 25 - UNIT TEST
 * BSTNode.h
 * created 4/19/2014
 * modified 4/19/2014
 * 
 */
 #pragma once
 #include<cstdlib>
 #include<string>
 
 using namespace std;
 
 class BSTNode
 {
	public:
	
		/*
         * default constructor, sets values left and right child to (NULL) and contents(0)
         */
		BSTNode();
		
		/*
         * overloaded constructor, int parameter assigned to contents
		 * @param int newcontents
         */
        BSTNode (int newContents);
        
        /* 
         * destructor, sets left and right child to (NULL)
         */
	    virtual ~BSTNode();
		
		/*
		 * set contents of node to newContents
		 * @param int newContents
		 * @return void
		 */
		void setContents(int newContents);
		
		/*
		 * get the value of contents
		 * @return int contents
		 */
		 int getContents() const;
		 
		 /*
		 * get the value of contents
		 * @return int& contents
		 */
		 int& getContents();
		 
		 /*
		  * set the left child pointer
		  * @param BTNode* leftChild
		  */
		void setLeftChild(BSTNode* newLeftChild);
		
		/*
		  * set the right child pointer
		  * @param BTNode* rightChild
		  */
		void setRightChild(BSTNode* newRightChild);
		
		/*
		 * get the pointer from left child
		 * @return BSTNode* leftChild
		 */
		 BSTNode* getLeftChild() const;
		 
		 /*
		 * get the pointer from left child
		 * @return BSTNode*& leftChild
		 */
		 BSTNode*& getLeftChild();
		 
		 /*
		 * get the pointer from right child
		 * @return BSTNode* rightChild
		 */
		 BSTNode* getRightChild() const;
		 
		 /*
		 * get the pointer from right child
		 * @return BSTNode*& rightChild
		 */
		 BSTNode*& getRightChild();
		
	private:
		BSTNode* leftChild;
		BSTNode* rightChild;
		int contents;
 };