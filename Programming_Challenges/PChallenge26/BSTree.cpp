/*
 * Donald Wiley
 * Demonstrates the use of binary search tree 
 * Programming Challenge 26 - UNIT TEST
 * BSTree.cpp
 * created 4/19/2014
 * modified 4/19/2014
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

void BSTree::clear(){
	clear(root);
}

unsigned int BSTree::getSize() const{
	return size;
}
		  
void BSTree::inOrder(){
	inOrder(root);
}
	
bool BSTree::insert(int newContents, BSTNode*& newNode){
	newNode = new BSTNode(newContents);
	root = newNode;
	return false;
}
		 
void BSTree::clear(BSTNode*& root){
	delete root;
	root = NULL;
}
		 
 void BSTree::inOrder(BSTNode* rootNode){
	cout << rootNode->getContents();
 }
 