/*
 * Donald Wiley
 * Demonstrates the use of binary search tree 
 * Programming Project 4 - UNIT TEST
 * pp4.cpp
 * created 4/19/2014
 * modified 5/15/2014
 * 
 */
#include "word.h"
#include "bstnode.h"
#include "bstree.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <streambuf>
#include <string>
#include <fstream>

using namespace std;

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest();
bool processFile(string filename);

int main (int argc, char* argv[])
{
	//unittest();
	if(argc != 2){
		cout << "Usage: " << argv[0] << " <FILE>\n";
	}
	else{
		processFile(argv[1]);
	}
	return 0;
}


bool processFile(string filename){
	
    ifstream infile(filename.c_str());
    if (infile.is_open()){
		string str;

		BSTree<Word>* list = NULL;
		bool listAlive = false;
        while (! infile.eof()){
			getline(infile, str);
			string data;
            if (str[0] == '#'){
			}
			else if (str[0] == 'C'){
				if(listAlive){
					delete list;
					list = new BSTree<Word>;
				}
				else{
					list = new BSTree<Word>;
					listAlive = true;
				}
				cout << "TREE CREATED" << endl;
			}
            else if (str[0] == 'X'){
				if(listAlive){
					list->clear();
					cout << "TREE CLEARED" << endl;
				}
				else if(!listAlive){
					cout << "MUST CREATE TREE INSTANCE\n";
				}
				else{
					cout << "TREE EMPTY\n";
				}
			}
            else if (str[0] == 'D'){
				if(listAlive){
					delete list;
					list = NULL;
					listAlive = false;
					cout << "TREE DELETED" << endl;
					
				}
				else{
					cout << "MUST CREATE TREE INSTANCE\n";
				}
			}
            else if (str[0] == 'I'){
				if(listAlive){
					stringstream ss(str.substr(2));
					ss >> data;
					if(!list->find(Word(data))){
						list->insert(Word(data));
						cout << "WORD " << data << " INSERTED" << endl;
					}
					else{
						list->get(Word(data))->incrementCount();
						cout << "WORD " << data << " INCREMENTED" << endl;
					}
					
				}
				else if(!listAlive){
					cout << "MUST CREATE TREE INSTANCE\n";
				}
				else{
					cout << "TREE EMPTY\n";
				}
			}
			else if (str[0] == 'F'){
				if(!listAlive){
					cout << "MUST CREATE TREE INSTANCE\n";
				}
				else if(list != NULL and list->getSize() != 0){
					stringstream ss(str.substr(2));
					ss >> data;
					if(list->find(Word(data))){
						cout << "FOUND " << data << endl;
					}
					else{
						cout << data << " NOT FOUND" << endl;
					}
				}
				else{
					cout << "TREE EMPTY\n";
				}
			}
			/*else if (str[0] == 'A'){
				if(list != NULL){
					try{
						cout << "VALUE " << list->getFront() << " AT HEAD" << endl;
					}catch(string str){
						cout << str <<endl;
					}
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
			}
			else if (str[0] == 'Z'){
				if(list != NULL){
					try{
						cout << "VALUE " << list->getBack() << " AT TAIL" << endl;
					}catch(string str){
						cout << str << endl;
					}
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
			}*/
			else if (str[0] == 'R'){
				if(!listAlive){
					cout << "MUST CREATE TREE INSTANCE\n";
				}
				else if(list != NULL and list->getSize() != 0){
					stringstream ss(str.substr(2));
					ss >> data;
					if(list->remove(Word(data))){
						cout << "REMOVED " << data << endl;
					}
					else{
						cout << data << " NOT FOUND\n";
					}
				}
				else{
					cout << "TREE EMPTY\n";
				}
			}
			else if (str[0] == 'G'){
				if(!listAlive){
					cout << "MUST CREATE TREE INSTANCE\n";
				}
				else if(list != NULL && list->getSize() != 0){
					stringstream ss(str.substr(2));
					ss >> data;
					Word* tmpWord;
					tmpWord = list->get(Word(data));
					if(tmpWord != NULL){
						cout << "GOT " << *tmpWord << endl;
					}
					else{
						cout << data << " NOT FOUND\n";
					}
				}
				else{
					cout << "TREE EMPTY\n";
				}
			}
			else if (str[0] == 'N'){
				if(listAlive){
					cout << "TREE SIZE IS " << list->getSize() << endl;
				}
				else if(!listAlive){
					cout << "MUST CREATE TREE INSTANCE\n";
				}
				else{
					cout << "TREE EMPTY\n";
				}
			}
			else if (str[0] == 'O'){
				if(!listAlive){
					cout << "MUST CREATE TREE INSTANCE\n";
				}
				else if(listAlive && list != NULL && list->getSize() > 0){
					list->inOrder();
				}
				else{
					cout << "TREE EMPTY\n";
				}
			}
			else if (str[0] == 'E'){
				if(!listAlive){
					cout << "MUST CREATE TREE INSTANCE\n";
				}
				else if(listAlive && list != NULL && list->getSize() > 0){
					list->reverseOrder();
				}
				else{
					cout << "TREE EMPTY\n";
				}
			}
            else{
				cout << "INVALID INPUT\n";
			}
        }		
        infile.close();
    }
	else{
		cout << "File not found please enter correct file name and path.\n";
	}
    return false; 
}


/*
 * Unit testing functions. Do not alter.
 */
void unittest ()
{
	cout << "\nSTARTING UNIT TEST\n\n";

	stringstream ss;

	cout << "WORD CLASS TEST\n\n";
	unsigned int totalWordTests = 10;
	unsigned int passedWordTests = 0;

	Word word1;
	Word word2("apple");
	
	try {
		btassert<bool>(word1.getWord() == "" && word1.getCount() == 1);
		cout << "Passed TEST  1: default constructor/getWord/getSize \n";
		++passedWordTests;
	} catch (bool b) {
		cout << "# FAILED TEST  1: default constructor/getWord/getSize #\n";
	}

	try {
		btassert<bool>((word2.getWord() == "APPLE" || word2.getWord() == "apple") && word2.getCount() == 1);
		cout << "Passed TEST  2: overloaded constructor/getWord/getCount \n";
		++passedWordTests;
	} catch (bool b) {
		cout << "# FAILED TEST  2: overloaded constructor/getWord/getCount #\n";
	}

	word1.setWord("banana");
	word2.setWord("orange");

	try {
		btassert<bool>((word1.getWord() == "BANANA" || word1.getWord() == "banana") && 
			           (word2.getWord() == "ORANGE" || word2.getWord() == "orange"));
		cout << "Passed TEST  3: setWord/getWord \n";
		++passedWordTests;
	} catch (bool b) {
		cout << "# FAILED TEST  3: setWord/getWord #\n";
	}

	word1.incrementCount();
	word2.incrementCount();
	word2.incrementCount();

	try {
		btassert<bool>(word1.getCount() == 2 && word2.getCount() == 3);
		cout << "Passed TEST  4: getCount \n";
		++passedWordTests;
	} catch (bool b) {
		cout << "# FAILED TEST  4: getCount #\n";
	}

	try {
		btassert<bool>(word1 < word2);
		cout << "Passed TEST  5: operator< \n";
		++passedWordTests;
	} catch (bool b) {
		cout << "# FAILED TEST  5: operator< #\n";
	}

	try {
		btassert<bool>(word2 > word1);
		cout << "Passed TEST  6: operator> \n";
		++passedWordTests;
	} catch (bool b) {
		cout << "# FAILED TEST  6: operator> #\n";
	}

	try {
		btassert<bool>(!(word1 == word2));
		cout << "Passed TEST  7: operator== \n";
		++passedWordTests;
	} catch (bool b) {
		cout << "# FAILED TEST  7: operator== #\n";
	}

	word2.setWord("banana");

	try {
		btassert<bool>(word1 == word2);
		cout << "Passed TEST  8: operator== \n";
		++passedWordTests;
	} catch (bool b) {
		cout << "# FAILED TEST  8: operator== #\n";
	}

	ss << word1;

	try {
		btassert<bool>(ss.str() == "BANANA 2" || ss.str() == "banana 2");
		cout << "Passed TEST  9: operator<< \n";
		++passedWordTests;
	} catch (bool b) {
		cout << "# FAILED TEST  9: operator<< #\n";
	}

	ss.str("");
	word2.setWord("orange");
	ss << word2;	

	try {
		btassert<bool>(ss.str() == "ORANGE 3" || ss.str() == "orange 3");
		cout << "Passed TEST 10: operator<< \n";
		++passedWordTests;
	} catch (bool b) {
		cout << "# FAILED TEST 10: operator<< #\n";
	}

	cout << "\n>> COMPLETED WORD CLASS TEST: PASSED " << passedWordTests 
	     << " OF " << totalWordTests << " TESTS\n\n";
	
	cout << "BSTNODE CLASS TEST\n\n";
	unsigned int totalNodeTests = 10;
	unsigned int passedNodeTests = 0;

	BSTNode<int> inode(1);
	BSTNode<string> snode("shoe");
	BSTNode<Word> wnode(Word("tree"));

	try {
		btassert<bool>(inode.getData() == 1 && inode.getLeftChild() == NULL &&
			           inode.getRightChild() == NULL);
		cout << "Passed TEST 11: constructor<int>/getData/getLeftChild/getRightChild \n";
		++passedNodeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 11: constructor<int>/getData/getLeftChild/getRightChild #\n";
	}

	try {
		btassert<bool>(snode.getData() == "shoe" && snode.getLeftChild() == NULL &&
			           snode.getRightChild() == NULL);
		cout << "Passed TEST 12: constructor<string>/getData/getLeftChild/getRightChild \n";
		++passedNodeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 12: constructor<string>/getData/getLeftChild/getRightChild #\n";
	}

	try {
		btassert<bool>(wnode.getData() == Word("tree") && wnode.getLeftChild() == NULL &&
			           wnode.getRightChild() == NULL);
		cout << "Passed TEST 13: constructor<Word>/getData/getLeftChild/getRightChild \n";
		++passedNodeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 13: constructor<Word>/getData/getLeftChild/getRightChild #\n";
	}

	inode.setData(10);

	try {
		btassert<bool>(inode.getData() == 10);
		cout << "Passed TEST 14: <int> setData/getData \n";
		++passedNodeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 14: <int> setData/getData #\n";
	}

	snode.setData("leaf");

	try {
		btassert<bool>(snode.getData() == "leaf");
		cout << "Passed TEST 15: <string> setData/getData \n";
		++passedNodeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 15: <string> setData/getData #\n";
	}

	wnode.setData(Word("cloud"));

	try {
		btassert<bool>(wnode.getData() == Word("cloud"));
		cout << "Passed TEST 16: <Word> setData/getData \n";
		++passedNodeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 16: <Word> setData/getData #\n";
	}

	BSTNode<int>* tinode1 = new BSTNode<int>(0);
	BSTNode<int>* tinode2 = new BSTNode<int>(2);
	inode.setLeftChild(tinode1);
	tinode1->setRightChild(&inode);
	inode.setRightChild(tinode2);
	tinode2->setLeftChild(&inode);

	try {
		btassert<bool>(inode.getLeftChild() == tinode1 && tinode2->getLeftChild() == &inode);
		cout << "Passed TEST 17: setLeftChild/getLeftChild \n";
		++passedNodeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 17: setLeftChild/getLeftChild #\n";
	}

	try {
		btassert<bool>(inode.getRightChild() == tinode2 && tinode1->getRightChild() == &inode);
		cout << "Passed TEST 18: setRightChild/getRightChild \n";
		++passedNodeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 18: setRightChild/getRightChild #\n";
	}

	delete tinode1;
	delete tinode2;

	inode.setLeftChild(NULL);
	inode.setRightChild(NULL);

	try {
		btassert<bool>(inode.getLeftChild() == NULL);
		cout << "Passed TEST 19: setLeftChild/getLeftChild \n";
		++passedNodeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 19: setLeftChild/getLeftChild #\n";
	}

	try {
		btassert<bool>(inode.getRightChild() == NULL);
		cout << "Passed TEST 20: setRightChild/getRightChild \n";
		++passedNodeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 20: setRightChild/getRightChild #\n";
	}

	cout << "\n>> COMPLETED BSTNODE CLASS TEST: PASSED " << passedNodeTests 
	     << " OF " << totalNodeTests << " TESTS\n\n";

	cout << "BSTREE CLASS TEST\n\n";
	unsigned int totalTreeTests = 35;
	unsigned int passedTreeTests = 0;

	streambuf* oldCout = cout.rdbuf();
	ostringstream captureCout;

	BSTree<int> itree;

	try {
		btassert<bool>(itree.getSize() == 0);
		cout << "Passed TEST 21: constructor/getCount \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 21: constructor/getCount #\n";
	}

	try {
		btassert<bool>(!itree.find(1));
		cout << "Passed TEST 22: find (empty tree) \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 22: find (empty tree) #\n";
	}

	try {
		btassert<bool>(!itree.get(1));
		cout << "Passed TEST 23: get (empty tree) \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 23: get (empty tree) #\n";
	}

	try {
		btassert<bool>(!itree.remove(1));
		cout << "Passed TEST 24: remove (empty tree) \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 24: remove (empty tree) #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	itree.inOrder();
	cout.rdbuf(oldCout);

	try {
		btassert<bool>(captureCout.str() == "");
		cout << "Passed TEST 25: inOrder (empty tree) \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 25: inOrder (empty tree) #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	itree.reverseOrder();
	cout.rdbuf(oldCout);

	try {
		btassert<bool>(captureCout.str() == "");
		cout << "Passed TEST 26: reverseOrder (empty tree) \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 26: reverseOrder (empty tree) #\n";
	}

	try {
		btassert<bool>(itree.insert(100) && itree.getSize() == 1);
		cout << "Passed TEST 27: insert(100) \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 27: insert(100) #\n";
	}

	try {
		btassert<bool>(!itree.insert(100) && itree.getSize() == 1);
		cout << "Passed TEST 28: insert(duplicate) \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 28: insert(duplicate) #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	itree.reverseOrder();
	cout.rdbuf(oldCout);

	try {
		btassert<bool>(captureCout.str() == "100\n");
		cout << "Passed TEST 29: inOrder \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 29: inOrder #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	itree.reverseOrder();
	cout.rdbuf(oldCout);

	try {
		btassert<bool>(captureCout.str() == "100\n");
		cout << "Passed TEST 30: reverseOrder \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 30: reverseOrder #\n";
	}

	try {
		btassert<bool>(itree.find(100));
		cout << "Passed TEST 31: find \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 31: find #\n";
	}

	try {
		btassert<bool>(*itree.get(100) == 100);
		cout << "Passed TEST 32: get \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 32: get #\n";
	}

	try {
		btassert<bool>(itree.remove(100) && itree.getSize() == 0);
		cout << "Passed TEST 33: remove/getSize \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 33: remove/getSize #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	itree.inOrder();
	cout.rdbuf(oldCout);

	try {
		btassert<bool>(captureCout.str() == "");
		cout << "Passed TEST 34: inOrder (empty tree) \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 34: inOrder (empty tree) #\n";
	}

	itree.insert(100);
	itree.insert(50);
	itree.insert(150);
	itree.insert(25);
	itree.insert(75);
	itree.insert(125);
	itree.insert(175);

	try {
		btassert<bool>(itree.getSize() == 7);
		cout << "Passed TEST 35: multiple inserts/getSize \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 35: multiple inserts/getSize #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	itree.inOrder();
	cout.rdbuf(oldCout);

	try {
		btassert<bool>(captureCout.str() == "25\n50\n75\n100\n125\n150\n175\n");
		cout << "Passed TEST 36: inOrder \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 36: inOrder #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	itree.reverseOrder();
	cout.rdbuf(oldCout);

	try {
		btassert<bool>(captureCout.str() == "175\n150\n125\n100\n75\n50\n25\n");
		cout << "Passed TEST 37: reverseOrder \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 37: reverseOrder #\n";
	}

	try {
		btassert<bool>(!itree.insert(25) && !itree.insert(50) && 
			           !itree.insert(75) && !itree.insert(100) && 
			           !itree.insert(125) && !itree.insert(150) && 
			           !itree.insert(175) && itree.getSize() == 7);
		cout << "Passed TEST 38: multiple duplicate inserts/getSize \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 38: multiple duplicate inserts/getSize #\n";
	}

	try {
		btassert<bool>(itree.remove(25) && itree.getSize() == 6);
		cout << "Passed TEST 39: remove (no left child)/getSize \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 39: remove (no left child)/getSize #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	itree.inOrder();
	cout.rdbuf(oldCout);

	try {
		btassert<bool>(captureCout.str() == "50\n75\n100\n125\n150\n175\n");
		cout << "Passed TEST 40: inOrder \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 40: inOrder #\n";
	}

	try {
		btassert<bool>(itree.remove(125) && itree.getSize() == 5);
		cout << "Passed TEST 41: remove (no left child)/getSize \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 41: remove (no left child)/getSize #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	itree.reverseOrder();
	cout.rdbuf(oldCout);

	try {
		btassert<bool>(captureCout.str() == "175\n150\n100\n75\n50\n");
		cout << "Passed TEST 42: reverseOrder \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 42: reverseOrder #\n";
	}

	try {
		btassert<bool>(itree.remove(100) && itree.getSize() == 4);
		cout << "Passed TEST 43: remove (trigger removeMax)/getSize \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 43: remove (trigger removeMax)/getSize #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	itree.inOrder();
	cout.rdbuf(oldCout);

	try {
		btassert<bool>(captureCout.str() == "50\n75\n150\n175\n");
		cout << "Passed TEST 44: inOrder \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 44: inOrder #\n";
	}

	try {
		btassert<bool>(itree.remove(75) && itree.getSize() == 3);
		cout << "Passed TEST 45: remove (trigger removeMax)/getSize \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 45: remove (trigger removeMax)/getSize #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	itree.reverseOrder();
	cout.rdbuf(oldCout);

	try {
		btassert<bool>(captureCout.str() == "175\n150\n50\n");
		cout << "Passed TEST 46: reverseOrder \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 46: reverseOrder #\n";
	}

	try {
		btassert<bool>(itree.remove(150) && itree.getSize() == 2);
		cout << "Passed TEST 47: remove/getSize \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 47: remove/getSize #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	itree.inOrder();
	cout.rdbuf(oldCout);

	try {
		btassert<bool>(captureCout.str() == "50\n175\n");
		cout << "Passed TEST 48: inOrder \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 48: inOrder #\n";
	}

	try {
		btassert<bool>(itree.remove(50) && itree.getSize() == 1);
		cout << "Passed TEST 49: remove/getSize \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 49: remove/getSize #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	itree.reverseOrder();
	cout.rdbuf(oldCout);

	try {
		btassert<bool>(captureCout.str() == "175\n");
		cout << "Passed TEST 50: reverseOrder \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 50: reverseOrder #\n";
	}

	try {
		btassert<bool>(!itree.remove(50) && itree.getSize() == 1);
		cout << "Passed TEST 51: remove (non-existent item)/getSize \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 51: remove (non-existent item)/getSize #\n";
	}

	try {
		btassert<bool>(!itree.find(50));
		cout << "Passed TEST 52: find (non-existent item) \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 52: find (non-existent item) #\n";
	}

	try {
		btassert<bool>(!itree.get(50));
		cout << "Passed TEST 53: get (non-existent item) \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 53: get (non-existent item) #\n";
	}

	try {
		btassert<bool>(itree.remove(175) && itree.getSize() == 0);
		cout << "Passed TEST 54: remove (last item)/getSize \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 54: remove (last item)/getSize #\n";
	}

	itree.insert(100);
	itree.insert(50);
	itree.insert(150);
	itree.insert(25);
	itree.insert(75);
	itree.insert(125);
	itree.insert(175);
	itree.clear();

	try {
		btassert<bool>(itree.getSize() == 0);
		cout << "Passed TEST 55: multiple inserts/clear/getSize \n";
		++passedTreeTests;
	} catch (bool b) {
		cout << "# FAILED TEST 55: multiple inserts/clear/getSize #\n";
	}

	cout << "\n>> COMPLETED BSTREE CLASS TEST: PASSED " << passedTreeTests 
	     << " OF " << totalTreeTests << " TESTS\n\n";

	cout << "UNIT TEST COMPLETE\n\n";
}
	
template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}