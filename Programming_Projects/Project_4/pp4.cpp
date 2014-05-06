/*
 * Donald Wiley
 * Demonstrates the use of binary search tree 
 * Programming Project 4 - UNIT TEST
 * pp4.cpp
 * created 4/19/2014
 * modified 5/2/2014
 * 
 */
#include"Word.h"
#include"BSTree.h"
#include<cassert>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<streambuf>
#include<fstream>
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

/*int main ()
{
	//unittest();
	Word red;
	red.setWord("red");
	
	Word blue("blue");
	Word green("green");
	
	BSTree<Word> list;
	
	list.insert(red);
	list.insert(blue);
	list.insert(green);
	list.insert("blue");
	list.insert("orange");
	list.insert("white");
	list.insert("black");
	list.insert("brown");
	list.inOrder();
	cout <<endl;
	list.reverseOrder();
	cout << list.getSize() << endl;
	
	return 0;
}*/

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
				cout << "LIST CREATED" << endl;
			}
            else if (str[0] == 'X'){
				if(listAlive){
					list->clear();
					cout << "LIST CLEARED" << endl;
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
			}
            else if (str[0] == 'D'){
				if(listAlive){
					delete list;
					list = NULL;
					listAlive = false;
					cout << "LIST DELETED" << endl;
					
				}
				else{
					cout << "MUST CREATE LIST INSTANCE\n";
				}
			}
            else if (str[0] == 'I'){
				if(listAlive){
					stringstream ss(str.substr(2));
					ss >> data;
					list->insert(data);
					cout << "VALUE " << data << " INSERTED" << endl;
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
			}
			else if (str[0] == 'F'){
				if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else if(list != NULL and list->getSize() != 0){
					stringstream ss(str.substr(2));
					ss >> data;
					if(list->find(data)){
						cout << "FOUND " << data << endl;
					}
					else{
						cout << data << " NOT FOUND" << endl;
					}
				}
				else{
					cout << "LIST EMPTY\n";
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
				if(listAlive){
					stringstream ss(str.substr(2));
					ss >> data;
					if(list->remove(data)){
						cout << "VALUE " << data << " REMOVED" << endl;
					}
					else{
						cout << "VALUE " << data << " NOT FOUND\n";
					}
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
			}
			else if (str[0] == 'G'){
				if(listAlive){
					stringstream ss(str.substr(2));
					ss >> data;
					if(list->get(data)){
						cout << "VALUE " << data << " FOUND" << endl;
					}
					else{
						cout << "VALUE " << data << " NOT FOUND\n";
					}
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
			}
			else if (str[0] == 'N'){
				if(listAlive){
					cout << "LIST SIZE IS " << list->getSize() << endl;
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
			}
			else if (str[0] == 'O'){
				if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else if(listAlive && list != NULL && list->getSize() > 0){
					list->inOrder();
					cout << endl;
				}
				else{
					cout << "LIST EMPTY\n";
				}
			}
			else if (str[0] == 'E'){
				if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else if(listAlive && list != NULL && list->getSize() > 0){
					list->reverseOrder();
					cout << endl;
				}
				else{
					cout << "LIST EMPTY\n";
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

	BSTree<int> tree;
	
	streambuf* oldCout = cout.rdbuf();
	ostringstream captureCout;
	
	try {
		btassert<bool>(!tree.remove(1));
		cout << "Passed TEST 1: empty tree/remove \n";
	} catch (bool b) {
		cout << "# FAILED TEST 1: empty tree/remove #\n";
	}
	
	cout << "\nINSERT STRESS TEST\n\n";
	try {
		btassert<bool>(tree.insert(50) == true && tree.insert(50) == false && 
							tree.insert(25) == true && tree.insert(25) == false && 
							tree.insert(75) == true && tree.insert(75) == false && 
							tree.insert(30) == true && tree.insert(30) == false && 
							tree.insert(29) == true && tree.insert(29) == false && 
							tree.insert(31) == true && tree.insert(31) == false && 
							tree.insert(32) == true && tree.insert(32) == false && 
							tree.insert(33) == true && tree.insert(33) == false && 
							tree.insert(34) == true && tree.insert(34) == false);
		cout << "Passed TEST 2: insert stress test \n";
	} catch (bool b) {
		cout << "# FAILED TEST 2: insert stress test #\n";
	}
	
	tree.clear();
	
	cout << "\nREGULAR TESTS\n\n";
	
	cout.rdbuf(captureCout.rdbuf());
	tree.insert(10);
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(captureCout.str() == "10 " && tree.getSize() == 1 && tree.remove(10) && tree.getSize() == 0);
		cout << "Passed TEST 3: single node/remove/getSize \n";
	} catch (bool b) {
		cout << "# FAILED TEST 3: single node/remove/getSize #\n";
	}
	
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(captureCout.str() == "5 10 15 " && tree.getSize() == 3 && !tree.remove(1));
		cout << "Passed TEST 4: remove non-existent target \n";
	} catch (bool b) {
		cout << "# FAILED TEST 4: remove non-existent target #\n";
	}
	
	try {
		btassert<bool>(tree.remove(5) && tree.getSize() == 2);
		cout << "Passed TEST 5: remove left child \n";
	} catch (bool b) {
		cout << "# FAILED TEST 5: remove left child #\n";
	}
	
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.inOrder();
	cout.rdbuf(oldCout);
	tree.insert(5);
	try {
		btassert<bool>(captureCout.str() == "10 15 " && tree.getSize() == 3 && tree.remove(15) && tree.getSize() == 2);
		cout << "Passed TEST 6: remove right child \n";
	} catch (bool b) {
		cout << "# FAILED TEST 6: remove right child #\n";
	}
	
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.inOrder();
	cout.rdbuf(oldCout);
	tree.insert(15);
	try {
		btassert<bool>(captureCout.str() == "5 10 " && tree.getSize() == 3 && tree.remove(10) && tree.getSize() == 2);
		cout << "Passed TEST 7: remove root (has left child) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 7: remove root (has left child) #\n";
	}
	
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.inOrder();
	cout.rdbuf(oldCout);
	tree.insert(20);
	try {
		btassert<bool>(captureCout.str() == "5 15 " && tree.getSize() == 3 && tree.remove(5) && tree.getSize() == 2);
		cout << "Passed TEST 8: remove root (no left child) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 8: remove root (no left child) #\n";
	}
	
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.insert(10);
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(captureCout.str() == "10 15 20 " && tree.getSize() == 3);
		cout << "Passed TEST 9: size and in order output \n";
	} catch (bool b) {
		cout << "# FAILED TEST 9: size and in order output #\n";
	}
	
	try {
		btassert<bool>(!tree.remove(1));
		cout << "Passed TEST 10: remove non existent value \n";
	} catch (bool b) {
		cout << "# FAILED TEST 10: remove non existent value #\n";
	}
	
	try {
		btassert<bool>(!tree.remove(100));
		cout << "Passed TEST 11: remove non existent value \n";
	} catch (bool b) {
		cout << "# FAILED TEST 11: remove non existent value #\n";
	}
	
	try {
		btassert<bool>(!tree.remove(11));
		cout << "Passed TEST 12: remove non existent value \n";
	} catch (bool b) {
		cout << "# FAILED TEST 12: remove non existent value #\n";
	}
	
	try {
		btassert<bool>(!tree.remove(19));
		cout << "Passed TEST 13: remove non existent value \n";
	} catch (bool b) {
		cout << "# FAILED TEST 13: remove non existent value #\n";
	}
	
	bool removed = tree.remove(15);
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(removed && captureCout.str() == "10 20 " && tree.getSize() == 2);
		cout << "Passed TEST 14: remove \n";
	} catch (bool b) {
		cout << "# FAILED TEST 14: remove #\n";
	}
	
	removed = tree.remove(10);
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(removed && captureCout.str() == "20 " && tree.getSize() == 1);
		cout << "Passed TEST 15: remove \n";
	} catch (bool b) {
		cout << "# FAILED TEST 15: remove #\n";
	}
	
	removed = tree.remove(20);
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(removed && captureCout.str() == "" && tree.getSize() == 0);
		cout << "Passed TEST 16: remove \n";
	} catch (bool b) {
		cout << "# FAILED TEST 16: remove #\n";
	}
	
	cout << "\nUNIT TEST COMPLETE\n\n";
}
	
template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}