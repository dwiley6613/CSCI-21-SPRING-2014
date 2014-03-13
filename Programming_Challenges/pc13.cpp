/*
 *
 * Programming Challenge 13
 *This program demostrates the use of functions that access and manipulate data
 *pc13.cpp
 *Donald Wiley
 *created 02/19/2014
 *modified 02/19/2014
 */
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
 * Allocate memory for a dynamic string with specified contents.
 * @param contents the desired contents of the dynamic string
 * @return a pointer to the newly allocated string
 */
string* makeDynoString (string contents);

/*
 * Free the memory associated with a dynamic string and NULL out its pointer.
 * @param theString a pointer (passed by reference) to a dynamic string
 */
void clearDynoString (string*& theString);

/*
 * Count the number of alphabetic and numeric characters in a string and return its length.
 * @param theString a pointer to the string in which characters will be counted
 * @param alpha an unsigned int (passed by reference) that will contain the count
 *        of alphabetic characters in the string on return
 * @param num an unsigned int (passed by reference) that will contain the count
 *        of numeric characters in the string on return
 * @return an unsigned integer containined the length of theString
 * @throw ArrayException with the message "NULL STRING REFERENCE" if theString is NULL
 */
unsigned int countChars (string* theString, unsigned int& alpha, unsigned int& num);

/*
 * Find a word inside of a string.
 * @param theString the string in which the search for a word will take place
 * @param theWord the word to look for inside of theString
 * @return true if theWord is found in theString, else false
 * @throw ArrayException with the message "NULL STRING REFERENCE" if theString is NULL
 */
bool findWord (string* theString, string theWord);

/*
 * Replace one word in a string with another word.
 * @param theString a pointer to the string that will have a word replaced
 * @param oldWord the word inside of theString being replaced
 * @param newWord the word that will be used to replace oldWord in theString
 * @return true if oldWord was found and replaced, else return false
 * @throw ArrayException with the message "NULL STRING REFERENCE" if theString is NULL
 */
bool replaceWord (string* theString, string oldWord, string newWord);

/* for unit testing -- do not alter */
struct ArrayException
{
	ArrayException (string newMessage="error")
	: message(newMessage)
	{
	}
	
	string message;
};

template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main (int , char**)
{
	unittest();
	
	return 0;
}

// CODE HERE -- FUNCTION DEFINITIONS
string* makeDynoString (string contents)
{
    string* stringPtr;
    stringPtr = new string;
    *stringPtr = contents;
    return stringPtr;
}

void clearDynoString (string*& theString)
{
    delete theString;
    theString = NULL;
}

unsigned int countChars (string* theString, unsigned int& alpha, unsigned int& num)
{
    unsigned int charCnt = 0;
    alpha = 0;
    num = 0;
    
    if (theString == NULL)
        throw ArrayException ("NULL STRING REFERENCE");
    else
    {
        string tmpString = *theString;
        for (unsigned int cnt = 0; cnt < tmpString.length(); cnt++)
        {
            if (isalpha(tmpString[cnt]))
                {
                    alpha++;
                    charCnt++;
                }
            else if (isdigit(tmpString[cnt]))
            {
                num++;
                charCnt++;
            }
                else
                    charCnt++;
        }
    }
    return charCnt;    
}

bool findWord (string* theString, string theWord)
{
    bool test = false;    
    
    if (theString == NULL)
        throw ArrayException ("NULL STRING REFERENCE");
    else
        {
            string tmpString = *theString;
            for (unsigned int cnt = 0; cnt < tmpString.length(); cnt++)
            {
                if (tmpString.substr(cnt, theWord.length()) == theWord)
                {
                    test = true;
                    break;
                }
            }
                
        }
    return test;    
}

bool replaceWord (string* theString, string oldWord, string newWord)
{
bool test = false;    
    
    if (theString == NULL)
        throw ArrayException ("NULL STRING REFERENCE");
    else
        {
            string tmpString = *theString;
            for (unsigned int cnt = 0; cnt < tmpString.length(); cnt++)
            {
             if (tmpString.substr(cnt, oldWord.length()) == oldWord)
                {
                    tmpString.erase(cnt, oldWord.length());
                    tmpString.insert(cnt, newWord);
                    *theString = tmpString;
                    break;
                }   
            }
                
        }
    return test;    
}


/*
 * Unit testing functions. Do not alter.
 */

void unittest ()
{
	cout << "\nSTARTING UNIT TEST\n\n";
	
	string* myString = 0;
	unsigned int alpha, num;
	
	try {
		countChars(myString, alpha, num);
	} catch (ArrayException e) {
		try {
			btassert<bool>(e.message == "NULL STRING REFERENCE");
			cout << "Passed TEST 1: countChars EXCEPTION HANDLING (STRING*) () \n";
		} catch (bool b) {
			cout << "# FAILED TEST 1: countChars EXCEPTION HANDLING (STRING*) () #\n";
		}
	}
	
	try {
		findWord(myString, "hello");
	} catch (ArrayException e) {
		try {
			btassert<bool>(e.message == "NULL STRING REFERENCE");
			cout << "Passed TEST 2: findWord EXCEPTION HANDLING (STRING*) () \n";
		} catch (bool b) {
			cout << "# FAILED TEST 2: findWord EXCEPTION HANDLING (STRING*) () #\n";
		}
	}
	
	try {
		replaceWord(myString, "hello", "goodbye");
	} catch (ArrayException e) {
		try {
			btassert<bool>(e.message == "NULL STRING REFERENCE");
			cout << "Passed TEST 3: replaceWord EXCEPTION HANDLING (STRING*) () \n";
		} catch (bool b) {
			cout << "# FAILED TEST 3: replaceWord EXCEPTION HANDLING (STRING*) () #\n";
		}
	}
	
	myString = makeDynoString("123, abc; 456: hello. 0!");
	
	try {
		btassert<bool>(myString != 0);
		cout << "Passed TEST 4: STRING INITIALIZATION () \n";
	} catch (bool b) {
		cout << "# FAILED TEST 4: STRING INITIALIZATION () #\n";
	}
	
	try {
		btassert<bool>(countChars(myString, alpha, num) == 24);
		cout << "Passed TEST 5: countChars (myString) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 5: countChars (myString) #\n";
	}
	
	try {
		btassert<bool>(alpha == 8);
		cout << "Passed TEST 6: countChars (alphabetic) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 6: countChars (alphabetic) #\n";
	}
	
	try {
		btassert<bool>(num == 7);
		cout << "Passed TEST 7: countChars (numeric) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 7: countChars (numeric) #\n";
	}
	
	try {
		btassert<bool>(findWord(myString, "HELLO") == false);
		cout << "Passed TEST 8: findWord (\"HELLO\") \n";
	} catch (bool b) {
		cout << "# FAILED TEST 8: findWord (\"HELLO\") #\n";
	}
	
	try {
		btassert<bool>(findWord(myString, "abc") == true);
		cout << "Passed TEST 9: findWord (\"abc\") \n";
	} catch (bool b) {
		cout << "# FAILED TEST 9: findWord (\"abc\") #\n";
	}
	
	replaceWord(myString, "hello", "goodbye");
	try {
		btassert<bool>(*myString == "123, abc; 456: goodbye. 0!");
		cout << "Passed TEST 10: replaceWord (myString, \"hello\", \"goodbye\") \n";
	} catch (bool b) {
		cout << "# FAILED TEST 10: replaceWord (myString, \"hello\", \"goodbye\") #\n";
	}
	
	try {
		btassert<bool>(replaceWord(myString, "HELLO", "GOODBYE") == false);
		cout << "Passed TEST 11: replaceWord (myString, \"HELLO\", \"GOODBYE\") \n";
	} catch (bool b) {
		cout << "# FAILED TEST 11: replaceWord (myString, \"HELLO\", \"GOODBYE\") #\n";
	}
	
	clearDynoString(myString);
	
	try {
		btassert<bool>(myString == 0);
		cout << "Passed TEST 12: clearDynoString () \n";
	} catch (bool b) {
		cout << "# FAILED TEST 12: clearDynoString () #\n";
	}
		
	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}