/*
 * Donald Wiley
 * Demonstrates the use of binary search tree 
 * Programming Challenge 27 - UNIT TEST
 * BSTNode.cpp
 * created 4/19/2014
 * modified 4/19/2014
 * 
 */
#include "BSTNode.h"
#include<cstdlib>
#include<string>
 
using namespace std;
 
BSTNode::BSTNode()
	:leftChild(NULL), rightChild(NULL), contents(0){}
		
BSTNode::BSTNode (int newContents)
	:leftChild(NULL), rightChild(NULL), contents(newContents){}
        
BSTNode::~BSTNode(){
}
		
void BSTNode::setContents(int newContents){
	contents = newContents;
}
		
		
int BSTNode::getContents() const{
	return contents;
}
 		 
int& BSTNode::getContents(){
	return contents;
}
		 
void BSTNode::setLeftChild(BSTNode* newLeftChild){
	leftChild = newLeftChild;
}		
void BSTNode::setRightChild(BSTNode* newRightChild){
	rightChild = newRightChild;
}
	
BSTNode* BSTNode::getLeftChild() const{
	return leftChild;
}
		 
BSTNode*& BSTNode::getLeftChild(){
	return leftChild;
}

BSTNode* BSTNode::getRightChild() const{
	return rightChild;
}
		 
BSTNode*& BSTNode::getRightChild(){
	return rightChild;
}