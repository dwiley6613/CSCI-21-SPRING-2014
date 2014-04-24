/*
 * Programming Programming Project 3 - UNIT TEST
 * Demonstrates the use of a templated doubly  linked list implemented in classes
 * Donald Wiley
 * pp3.cpp
 * Created 4/4/2014
 * Modified 4/7/2014
 */

#include "DLNode.h"
#include "DLList.h"
#include <cassert>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();
bool processIntFile(string filename);
bool processStringFile(string filename);
bool processDoubleFile(string filename);

int main (int argc, char* argv[])
{
	//unittest();
	if(argc != 3){
		cout << "Usage: " << argv[0] << " <FILE> <DATATYPE>\n";
	}
	else if(string(argv[2]) == "int"){
		processIntFile(argv[1]);
	}
	else if(string(argv[2]) == "string"){
		processStringFile(argv[1]);
	}
	else if(string(argv[2]) == "double"){
		processStringFile(argv[1]);
	}
	else{
		cout << "Invalid data type please use int double string\n";
	}
	return 0;
}

bool processIntFile(string filename)
{
	
    ifstream infile(filename.c_str());
    if (infile.is_open()){
		string str;

		DLList<int>* list = NULL;
		bool listAlive = false;
        while (! infile.eof()){
			getline(infile, str);
			int data = 0;
            if (str[0] == '#'){
			}
			else if (str[0] == 'C'){
				if(listAlive){
					delete list;
					list = new DLList<int>;
				}
				else{
					list = new DLList<int>;
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
				if(list != NULL){
					stringstream ss(str.substr(2));
					ss >> data;
					list->pushFront(data);
					cout << "VALUE " << data << " ADDED TO HEAD" << endl;
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
			}
			else if (str[0] == 'B'){
				if(list != NULL){
					stringstream ss(str.substr(2));
					ss >> data;
					list->pushBack(data);
					cout << "VALUE " << data << " ADDED TO TAIL" << endl;
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
			}
			else if (str[0] == 'A'){
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
			}
			else if (str[0] == 'T'){
				if(listAlive && list->getSize() != 0){
					list->popFront();
					cout << "REMOVED HEAD" << endl;
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
				
			}
			else if (str[0] == 'K'){
				if(listAlive && list->getSize() != 0){
					list->popBack();
					cout << "REMOVED TAIL" << endl;
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
			}
			else if (str[0] == 'E'){
				if(listAlive){
					stringstream ss(str.substr(2));
					ss >> data;
					if(list->removeAll(data)){
						cout << "VALUE " << data << " ELIMINATED" << endl;
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
			else if (str[0] == 'R'){
				if(listAlive){
					stringstream ss(str.substr(2));
					ss >> data;
					if(list->removeFirst(data)){
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
			else if (str[0] == 'P'){
				if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else if(listAlive && list != NULL && list->getSize() > 0){
					cout << *list << endl;
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
bool processStringFile (string filename){
	ifstream infile(filename.c_str());
    if (infile.is_open()){
		string str;
		string data;

		DLList<string>* list = NULL;
		bool listAlive = false;
        while (! infile.eof()){
			getline(infile, str);
			
            if (str[0] == '#'){
			}
			else if (str[0] == 'C'){
				if(listAlive){
					delete list;
					list = new DLList<string>;
				}
				else{
					list = new DLList<string>;
				}
				listAlive = true;
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
					data = str.substr(2);
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
				if(list != NULL){
					stringstream ss(str.substr(2));
					//ss >> data;
					list->pushFront(ss.str());
					cout << "VALUE " << ss.str() << " ADDED TO HEAD" << endl;
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
			}
			else if (str[0] == 'B'){
				if(list != NULL){
					data = str.substr(2);
					list->pushBack(data);
					cout << "VALUE " << data << " ADDED TO TAIL" << endl;
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
			}
			else if (str[0] == 'A'){
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
						cout << "VALUE " << list->getBack() << " AT HEAD" << endl;
					}catch(string str){
						cout << str <<endl;
					}
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
			}
			else if (str[0] == 'T'){
				if(listAlive && list->getSize() != 0){
					list->popFront();
					cout << "REMOVED HEAD" << endl;
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
				
			}
			else if (str[0] == 'K'){
				if(listAlive && list->getSize() != 0){
					list->popBack();
					cout << "REMOVED TAIL" << endl;
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
			}
			else if (str[0] == 'E'){
				if(listAlive){
					data = str.substr(2);
					if(list->removeAll(data)){
						cout << "VALUE " << data << " ELIMINATED" << endl;
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
			else if (str[0] == 'R'){
				if(listAlive){
					data = str.substr(2);
					if(list->removeFirst(data)){
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
					data = str.substr(2);
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
			else if (str[0] == 'P'){
				if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else if(listAlive && list != NULL && list->getSize() > 0){
					cout << *list << endl;
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

bool processDoubleFile (string filename){
	ifstream infile(filename.c_str());
    if (infile.is_open()){
		string str;

		DLList<double>* list = NULL;
		bool listAlive = false;
        while (! infile.eof()){
			getline(infile, str);
			double data =0;
            if (str[0] == '#'){
			}
			else if (str[0] == 'C'){
				if(listAlive){
					delete list;
					list = new DLList<double>;
				}
				else{
					list = new DLList<double>;
				}
				listAlive = true;
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
				if(list != NULL){
					stringstream ss(str.substr(2));
					ss >> data;
					list->pushFront(data);
					cout << "VALUE " << data << " ADDED TO HEAD" << endl;
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
			}
			else if (str[0] == 'B'){
				if(list != NULL){
					stringstream ss(str.substr(2));
					ss >> data;
					list->pushBack(data);
					cout << "VALUE " << data << " ADDED TO TAIL" << endl;
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
			}
			else if (str[0] == 'A'){
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
						cout << "VALUE " << list->getBack() << " AT HEAD" << endl;
					}catch(string str){
						cout << str <<endl;
					}
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
			}
			else if (str[0] == 'T'){
				if(listAlive && list->getSize() != 0){
					list->popFront();
					cout << "REMOVED HEAD" << endl;
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
				
			}
			else if (str[0] == 'K'){
				if(listAlive && list->getSize() != 0){
					list->popBack();
					cout << "REMOVED TAIL" << endl;
				}
				else if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else{
					cout << "LIST EMPTY\n";
				}
			}
			else if (str[0] == 'E'){
				if(listAlive){
					stringstream ss(str.substr(2));
					ss >> data;
					if(list->removeAll(data)){
						cout << "VALUE " << data << " ELIMINATED" << endl;
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
			else if (str[0] == 'R'){
				if(listAlive){
					stringstream ss(str.substr(2));
					ss >> data;
					if(list->removeFirst(data)){
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
			else if (str[0] == 'P'){
				if(!listAlive){
					cout << "MUST CREATE LIST INSTANCE\n";
				}
				else if(listAlive && list != NULL && list->getSize() > 0){
					cout << *list << endl;
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
	
	DLList<int> intList;
	
	cout << "INTEGER LIST TEST\n\n";
	
	try {
		btassert<bool>(intList.getSize() == 0);
		cout << "Passed TEST 1: default constructor (size) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 1: default constructor (size) #\n";
	}
	
	try {
		btassert<bool>(intList.toString() == "");
		cout << "Passed TEST 2: toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 2: toString #\n";
	}
	
	intList.insert(10);
	try {
		btassert<bool>(intList.getSize() == 1 && intList.toString() == "10");
		cout << "Passed TEST 3: insert(10)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 3: insert(10)/getSize/toString #\n";
	}
	intList.insert(10);
	try {
		btassert<bool>(intList.getSize() == 2 && intList.toString() == "10,10");
		cout << "Passed TEST 3: insert(10)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 3: insert(10)/getSize/toString #\n";
	}	
	
	intList.insert(10);
	try {
		btassert<bool>(intList.getSize() == 3 && intList.toString() == "10,10,10");
		cout << "Passed TEST 4: insert(10)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 4: insert(10)/getSize/toString #\n";
	}
	
	intList.insert(30);
	try {
		btassert<bool>(intList.getSize() == 4 && intList.toString() == "10,10,10,30");
		cout << "Passed TEST 5: insert(30)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 5: insert(30)/getSize/toString #\n";
	}
	
	intList.insert(30);
	try {
		btassert<bool>(intList.getSize() == 5 && intList.toString() == "10,10,10,30,30");
		cout << "Passed TEST 6: insert(30)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 6: insert(30)/getSize/toString #\n";
	}
	
	intList.insert(15);
	try {
		btassert<bool>(intList.getSize() == 6 && intList.toString() == "10,10,10,15,30,30");
		cout << "Passed TEST 7: insert(15)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 7: insert(15)/getSize/toString #\n";
	}
	
	intList.pushFront(5);
	try {
		btassert<bool>(intList.getSize() == 7 && intList.toString() == "5,10,10,10,15,30,30");
		cout << "Passed TEST 8: pushFront(5)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 8: pushFront(5)/getSize/toString #\n";
	}
	
	intList.pushBack(50);
	try {
		btassert<bool>(intList.getSize() == 8 && intList.toString() == "5,10,10,10,15,30,30,50");
		cout << "Passed TEST 9: pushBack(50)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 9: pushBack(50)/getSize/toString #\n";
	}
	
	try {
		btassert<bool>(intList.removeFirst(1) == false);
		cout << "Passed TEST 10: removeFirst(1) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 10: removeFirst(1) #\n";
	}
	
	try {
		btassert<bool>(intList.removeAll(100) == false);
		cout << "Passed TEST 11: removeAll(1) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 11: removeAll(1) #\n";
	}
	try {
		btassert<bool>(intList.removeFirst(10) == true && intList.getSize() == 7 && intList.toString() == "5,10,10,15,30,30,50");
		cout << "Passed TEST 12: removeFirst(10)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 12: removeFirst(10)/getSize/toString #\n";
	}
	
	try {
		btassert<bool>(intList.removeAll(30) == true && intList.getSize() == 5 && intList.toString() == "5,10,10,15,50");
		cout << "Passed TEST 13: removeAll(30)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 13: removeAll(30)/getSize/toString #\n";
	}
	
	intList.popFront();
	try {
		btassert<bool>(intList.getSize() == 4 && intList.toString() == "10,10,15,50");
		cout << "Passed TEST 14: popFront/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 14: popFront/getSize/toString #\n";
	}
	
	intList.popBack();
	try {
		btassert<bool>(intList.getSize() == 3 && intList.toString() == "10,10,15");
		cout << "Passed TEST 15: popBack/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 15: popBack/getSize/toString #\n";
	}
	
	intList.clear();
	try {
		btassert<bool>(intList.getSize() == 0 && intList.toString() == "");
		cout << "Passed TEST 16: clear/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 16: clear/getSize/toString #\n";
	}
	
	cout << "\nSTRING LIST TEST\n\n";
	
	DLList<string> stringList;
	
	try {
		btassert<bool>(stringList.getSize() == 0);

		cout << "Passed TEST 17: default constructor (size) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 17: default constructor (size) #\n";
	}
	
	try {
		btassert<bool>(stringList.toString() == "");
		cout << "Passed TEST 18: toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 18: toString #\n";
	}
	
	stringList.insert("hello");
	try {
		btassert<bool>(stringList.getSize() == 1 && stringList.toString() == "hello");
		cout << "Passed TEST 19: insert(\"hello\")/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 19: insert(\"hello\")/getSize/toString #\n";
	}
	
	stringList.insert("hello");
	try {
		btassert<bool>(stringList.getSize() == 2 && stringList.toString() == "hello,hello");
		cout << "Passed TEST 20: insert(\"hello\")/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 20: insert(\"hello\")/getSize/toString #\n";
	}
	
	stringList.insert("mellow");
	
	try {
		btassert<bool>(stringList.getSize() == 3 && stringList.toString() == "hello,hello,mellow");
		cout << "Passed TEST 21: insert(\"mellow\")/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 21: insert(\"mellow\")/getSize/toString #\n";
	}
	
	stringList.insert("mellow");
	try {
		btassert<bool>(stringList.getSize() == 4 && stringList.toString() == "hello,hello,mellow,mellow");
		cout << "Passed TEST 22: insert(\"mellow\")/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 22: insert(\"mellow\")/getSize/toString #\n";
	}
	
	stringList.insert("jello");
	try {
		btassert<bool>(stringList.getSize() == 5 && stringList.toString() == "hello,hello,jello,mellow,mellow");
		cout << "Passed TEST 23: insert(\"jello\")/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 23: insert(\"jello\")/getSize/toString #\n";
	}
	
	stringList.pushFront("cello");
	try {
		btassert<bool>(stringList.getSize() == 6 && stringList.toString() == "cello,hello,hello,jello,mellow,mellow");
		cout << "Passed TEST 24: pushFront(\"cello\")/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 24: pushFront(\"cello\")/getSize/toString #\n";
	}
	
	stringList.pushBack("yellow");
	try {
		btassert<bool>(stringList.getSize() == 7 && stringList.toString() == "cello,hello,hello,jello,mellow,mellow,yellow");
		cout << "Passed TEST 25: pushBack(\"yellow\")/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 25: pushBack(\"yellow\")/getSize/toString #\n";
	}
	
	try {
		btassert<bool>(stringList.removeFirst("fellow") == false);
		cout << "Passed TEST 26: removeFirst(\"fellow\") \n";
	} catch (bool b) {
		cout << "# FAILED TEST 26: removeFirst(\"fellow\") #\n";
	}
	
	try {
		btassert<bool>(stringList.removeAll("bellow") == false);
		cout << "Passed TEST 27: removeAll(\"bellow\") \n";
	} catch (bool b) {
		cout << "# FAILED TEST 27: removeAll(\"bellow\") #\n";
	}
	
	try {
		btassert<bool>(stringList.removeFirst("hello") == true && stringList.getSize() == 6 && stringList.toString() == "cello,hello,jello,mellow,mellow,yellow");
		cout << "Passed TEST 28: removeFirst(\"hello\")/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 28: removeFirst(\"hello\")/getSize/toString #\n";
	}
	
	try {
		btassert<bool>(stringList.removeAll("mellow") == true && stringList.getSize() == 4 && stringList.toString() == "cello,hello,jello,yellow");
		cout << "Passed TEST 29: removeAll(30)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 29: removeAll(30)/getSize/toString #\n";
	}
	
	stringList.popFront();
	try {
		btassert<bool>(stringList.getSize() == 3 && stringList.toString() == "hello,jello,yellow");
		cout << "Passed TEST 30: popFront/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 30: popFront/getSize/toString #\n";
	}
	
	stringList.popBack();
	try {
		btassert<bool>(stringList.getSize() == 2 && stringList.toString() == "hello,jello");
		cout << "Passed TEST 31: popBack/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 31: popBack/getSize/toString #\n";
	}
	
	stringList.clear();
	try {
		btassert<bool>(stringList.getSize() == 0 && stringList.toString() == "");
		cout << "Passed TEST 32: clear/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 32: clear/getSize/toString #\n";
	}
	
	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}