/*
 * Donald Wiley
 * Demonstrates the use of binary search tree 
 * Programming Project 4
 * BSTree.h
 * created 4/19/2014
 * modified 5/15/2014
 * stackoverflow.com
 */
 
#pragma once
#include"bstnode.h"
#include<cstdlib>
#include<string>
#include<iostream>
 
using namespace std;
 
template<typename T>
class BSTree
{
	public:
		/*
         * default constructor, sets values root(NULL) and size(0)
         */
		BSTree()
			:root(NULL), size(0){}
		
        /* 
         * destructor, sets left and right child to (NULL)
         */
	    ~BSTree(){
			clear();
		}
	
		/*
		 * function bool insert (T), calls private function insert(int, root)
		 * @param int root
		 * @return bool
		 */
		bool insert(T newContents){
			return insert(newContents, root);
		}
		
		/*
		 * function bool remove (T), return value returned by private function remove(T, root)
		 * @param T value
		 * @return bool
		 */
		bool remove(T value){
			return remove(value, root);
		}
		
		 /*
		  * function void clear (), call private function clear(root)
		  * @return void
		  */
		void clear(){
			clear(root);
		}
		 
		 /*
		  * function unsigned int getSize () const
		  * @return int size
		  */
		unsigned int getSize() const{
			return size;
		}
		  
		  /*
		   * function void inOrder (), call private function inOrder(root)
		   * @return Void
		   */
		void inOrder(){
			inOrder(root);
		}
		
		/*
		 * function void reverseOrder (), call private function reverse-order(root)
		 * @return Void
		 */
		void reverseOrder(){
			reverseOrder(root);
		}		
	
		/*
		 * function find data return true if data found, else false on failure
		 * @param T data
		 * @return bool
		 */
		bool find(T data){
			return find(data, root);
		}
		
		/*
		 * function get data return pointer if data found, else NULL on not found;
		 * @param T data
		 * @return pointer
		 */
		T* get(T data){
			return get(data, root);
		}
		
	private:
		BSTNode<T>* root;
		unsigned int size;
		
		/*
		 * bool insert (T, BSTNode<T>*&), create a new BSTNode and insert it into the tree, returns 
	     * 	true; if integer is already in the true, does not insert, returns false
		 * @param int BSTNode*&
		 * @return bool
		 */
		bool insert(T newWord, BSTNode<T>*& tmpRoot){
			if(tmpRoot == NULL){
				tmpRoot = new BSTNode<T>(newWord);
				size++;
				return true;
			}
			else if(newWord < tmpRoot->getData()){
				return insert(newWord, tmpRoot->getLeftChild());
			}
			else if(newWord > tmpRoot->getData()){
				return insert(newWord, tmpRoot->getRightChild());
			}
			else{
				return false;
			}
		}
		
		/*
		 * function bool remove (T, BSTNode<T>*&), traverse the tree and remove the node containing the target 
	     * 	integer if present, return true; return false if target integer is not in tree
		 * @param T value DSTNode*& root
		 * @return bool
		 */
		bool remove(const T& word, BSTNode<T>*& tmpRoot){
			BSTNode<T>* tmpNode = tmpRoot;
			if(tmpRoot == NULL){
				return false;
			}
			else if(word < tmpRoot->getData()){
				return remove(word, tmpRoot->getLeftChild());
			}
			else if(word > tmpRoot->getData()){
				return remove(word, tmpRoot->getRightChild());
			}
			else{
				if(tmpRoot->getLeftChild() == NULL){
					tmpNode = tmpRoot;
					tmpRoot = tmpRoot->getRightChild();
					delete tmpNode;
					size--;
				}
				else{
					removeMax(tmpRoot->getData(), tmpRoot->getLeftChild());
				}
				return true;
			}
		}

		/*
		 * function void removeMax (T&, BSTNode<T>*&), helper function for private remove
		 * @param T& value BSTNode*& tmpRoot
		 * @return BSTNode<T>*& tmpRoot
		 */
		void removeMax(T& value, BSTNode<T>*& tmpRoot){
			BSTNode<T>* maxNode = tmpRoot;
			if(tmpRoot->getRightChild() == NULL){
				value = maxNode->getData();
				tmpRoot = maxNode->getLeftChild();
				delete maxNode;
				size--;
			}
			else{
				removeMax(value, tmpRoot->getRightChild());
			}
		}
		
		/* 
		 * void clear (BSTNode<T>*&), clear the entire contents of the tree, freeing all memory
	     * 	associated with all nodes
		 * @param BSTNode<T>*& cNode
		 * @return void
		 */
		void clear(BSTNode<T>*& tmpRoot){
			if(tmpRoot != NULL){
				clear(tmpRoot->getLeftChild());
				clear(tmpRoot->getRightChild());
				delete tmpRoot;
				tmpRoot = NULL;
				size--;
			}
		}
		 
		 /*
		  * void inOrder (BSTNode<T>*), print the data in all nodes in the tree, in ascending order, 
	      * 	separate by spaces (there should be a space after the last output value)
		  * @param BSTNode* rootNode
		  * @return void
		  */
		void inOrder(BSTNode<T>* rootNode){
			if(rootNode != NULL){
				inOrder(rootNode->getLeftChild());
				cout << rootNode->getData() << endl;
				inOrder(rootNode->getRightChild());
			}
		}
		
		 /*
		  * void reverseOrder (BSTNode<T>*), print the data in all nodes in the tree, in descending order, 
	      * 	separate by spaces (there should be a space after the last output value)
		  * @param BSTNode<T>* rootNode
		  * @return void
		  */
		void reverseOrder(BSTNode<T>* rootNode){
			if(rootNode != NULL){
				reverseOrder(rootNode->getRightChild());
				cout << rootNode->getData() << endl;
				reverseOrder(rootNode->getLeftChild());
			}
		}
		
		/*
		 * function find data return true if data found, else false on failure
		 * @param T data
		 * @return bool
		 */
		bool find(T data, BSTNode<T>* tmpRoot){
			if(tmpRoot == NULL){
				return false;
			}
			else if(tmpRoot->getData() == data){
				return true;
			}
			else if(data < tmpRoot->getData()){
				return find(data, tmpRoot->getLeftChild());
			}
			else{
				return find(data, tmpRoot->getRightChild());
			}
		}

		/*
		 * function get data return pointer if data found, else NULL on not found;
		 * @param T data
		 * @return pointer
		 */
		T* get(T data, BSTNode<T>* tmpRoot){
			if(tmpRoot == NULL){
				return NULL;
			}
			else if(tmpRoot->getData() == data){
				return &tmpRoot->getData();
			}
			else if(data < tmpRoot->getData()){
				return get(data, tmpRoot->getLeftChild());
			}
			else{
				return get(data, tmpRoot->getRightChild());
			}
		}			
};