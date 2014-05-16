/*
 * Donald Wiley
 * Demonstrates the use of binary search tree 
 * Programming Challenge 27 - UNIT TEST
 * BSTree.cpp
 * created 4/19/2014
 * modified 4/30/2014
 * 
 */
 
#include"BSTree.h"
#include"BSTNode.h"
#include<cstdlib>
#include<string>
#include<iostream>

using namespace std;

BSTree::BSTree()
	:root(NULL), size(0){}
		
BSTree::~BSTree(){
	clear();
}
	
bool BSTree::insert(int newContents){
	return insert(newContents, root);
}

bool BSTree::remove(int value){
	return remove(value, root);
}

void BSTree::clear(){
	clear(root);
}

unsigned int BSTree::getSize() const{
	return size;
}
		  
void BSTree::inOrder(){
	inOrder(root);
}
	
bool BSTree::insert(int newContents, BSTNode*& tmpRoot){
	if(tmpRoot == NULL){
		tmpRoot = new BSTNode(newContents);
		size++;
		return true;
	}
	else if(newContents < tmpRoot->getContents()){
		return insert(newContents, tmpRoot->getLeftChild());
	}
	else if(newContents > tmpRoot->getContents()){
		return insert(newContents, tmpRoot->getRightChild());
	}
	else{
		return false;
	}
}
bool BSTree::remove(const int& value, BSTNode*& tmpRoot){
	BSTNode* tmpNode = tmpRoot;
	if(tmpRoot == NULL){
		return false;
	}
	else if(value < tmpRoot->getContents()){
		return remove(value, tmpRoot->getLeftChild());
	}
	else if(value > tmpRoot->getContents()){
		return remove(value, tmpRoot->getRightChild());
	}
	else{
		if(tmpRoot->getLeftChild() == NULL){
			tmpNode = tmpRoot;
			tmpRoot = tmpRoot->getRightChild();
			delete tmpNode;
			size--;
		}
		else{
			removeMax(tmpRoot->getContents(), tmpRoot->getLeftChild());
		}
		return true;
	}
}

void BSTree::removeMax(int& value, BSTNode*& tmpRoot){
	BSTNode* maxNode = tmpRoot;
	if(tmpRoot->getRightChild() == NULL){
		value = maxNode->getContents();
		tmpRoot = maxNode->getLeftChild();
		delete maxNode;
		size--;
	}
	else{
		removeMax(value, tmpRoot->getRightChild());
	}
}
		 
void BSTree::clear(BSTNode*& tmpRoot){
	if(tmpRoot != NULL){
		clear(tmpRoot->getLeftChild());
		clear(tmpRoot->getRightChild());
		delete tmpRoot;
		tmpRoot = NULL;
		size--;
	}
}
		 
void BSTree::inOrder(BSTNode* rootNode){
	if(rootNode != NULL){

		inOrder(rootNode->getLeftChild());
		cout << rootNode->getContents() << " ";
		inOrder(rootNode->getRightChild());
	}
}
 