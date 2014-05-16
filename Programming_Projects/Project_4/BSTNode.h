/*
 * Donald Wiley
 * Demonstrates the use of binary search tree 
 * Programming Project 4
 * BSTNode.h
 * created 4/19/2014
 * modified 5/15/2014
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
         * default constructor, sets values left and right child to (NULL) and data(0)
         */
		BSTNode()
			:leftChild(NULL), rightChild(NULL){}
		
		/*
         * overloaded constructor, int parameter assigned to data
		 * @param T newData
         */
        BSTNode(T newData)
			:leftChild(NULL), rightChild(NULL), data(newData){}
        
        /* 
         * destructor
         */
	    ~BSTNode(){
		}
		
		/*
		 * set contents of node to newdata
		 * @param T newData
		 * @return void
		 */
		void setData(T newData){
			data = newData;
		}
		
		/*
		 * get the value of data
		 * @return T data
		 */
		T getData() const{
			return data;
		}
		 /*
		 * get the value of data
		 * @return T& data
		 */
		T& getData(){
			return data;
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
		T data;
 };