/*
 * Donald Wiley
 * Demonstrates the use of binary search tree 
 * Programming Project 4
 * BSTNode.h
 * created 4/19/2014
 * modified 5/2/2014
 * 
 */
 #pragma once
 #include<cstdlib>
 #include<string>
 
 using namespace std;
 
 template<typename T>
 class BSTNode
 {
	public:
	
		/*
         * default constructor, sets values left and right child to (NULL) and contents(0)
         */
		BSTNode()
			:leftChild(NULL), rightChild(NULL){}
		
		/*
         * overloaded constructor, int parameter assigned to contents
		 * @param T newcontents
         */
        BSTNode(T newContents)
			:leftChild(NULL), rightChild(NULL), contents(newContents){}
        
        /* 
         * destructor
         */
	    ~BSTNode(){
		}
		
		/*
		 * set contents of node to newContents
		 * @param T newContents
		 * @return void
		 */
		void setContents(T newContents){
			contents = newContents;
		}
		
		/*
		 * get the value of contents
		 * @return T contents
		 */
		T getContents() const{
			return contents;
		}
		 /*
		 * get the value of contents
		 * @return T& contents
		 */
		T& getContents(){
			return contents;
		}
		 
		 /*
		  * set the left child pointer
		  * @param BTNode* leftChild
		  */
		void setLeftChild(BSTNode* newLeftChild){
			leftChild = newLeftChild;
		}
		
		/*
		  * set the right child pointer
		  * @param BTNode* rightChild
		  */
		void setRightChild(BSTNode* newRightChild){
			rightChild = newRightChild;
		}
		
		/*
		 * get the pointer from left child
		 * @return BSTNode* leftChild
		 */
		BSTNode* getLeftChild() const{
			return leftChild;
		}
		 
		 /*
		 * get the pointer from left child
		 * @return BSTNode*& leftChild
		 */
		BSTNode*& getLeftChild(){
			return leftChild;
		}
		 
		 /*
		 * get the pointer from right child
		 * @return BSTNode* rightChild
		 */
		BSTNode* getRightChild() const{
			return rightChild;
		}
		 
		 /*
		 * get the pointer from right child
		 * @return BSTNode*& rightChild
		 */
		BSTNode*& getRightChild(){
			return rightChild;
		}
		
	private:
		BSTNode* leftChild;
		BSTNode* rightChild;
		T contents;
 };