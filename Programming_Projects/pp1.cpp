/*
 *Programming Project 
 * pp1.cpp
 *This program
 *Donald Wiley
 *date created 2/12/2014
 *date modified 2/12/2014
 */
 
#include <cassert>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

/*
count the number of alphabetic characters and the number of numeric characters in a string
    (function name: countCharacters; parameters: string, int&, int&; return value: void)
    
capitalize/lowercase every other character in a string -- first character of the string should be capitalized, the second character lowercase, etc.
    (function name: upAndDown; parameter: string; return value: string)
    
count the number of words--delimited by space characters--in a string;
assume that the parameter will never have multiple spaces back-to-back, and will never begin or end with spaces
    (function name: countWords; parameter: string; return value: int)
    
compute the average of the values in an array; assume the function will never receive an array of size 0
    (function name: computeAverage; parameters: int[], int; return value: int)
    
identify the smallest value in an array; assume the function will never receive an array of size 0
    (function name: findMinValue; parameters: int[], int; return value: int)
    
identify the largest value in an array; assume the function will never receive an array of size 0
    (function name: findMaxValue; parameters: int[], int; return value: int)
*/

// CODE HERE -- FUNCTION DEFINITIONS

void countCharacters( string inputStr, int& alphaCnt, int& numCnt);
string upAndDown(string inputStr);
int countWords(string inputStr);
int computeAverage(int inputArray[], int arraySize);
int findMinValue(int inputArray[], int arraySize);
int findMaxValue(int inputArray[], int arraySize);



/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main (int argc, char* argv[])
{
	unittest();
	
	return 0;
}

/*
 * Function coding here
 */

/*
 *count the number of alphabetic characters and the number of numeric characters in a string
 *@parameter inputStr sting passed to function
 *@parameter alphaCnt integer count of alpha charaters in the string
 *@parameter NumCnt integer count of numeric characters
 *@return void
 */  
void countCharacters (string inputStr, int& alphaCnt, int& numCnt)
{
    alphaCnt = 0;
    numCnt = 0;
    for (unsigned int cnt = 0; cnt < inputStr.length(); cnt++)
    {
        if (isalpha(inputStr[cnt]))
            alphaCnt++;
        else if (isdigit(inputStr[cnt]))
            numCnt++;
    }
}

/*
 *capitalize/lowercase every other character in a string -- first character of the string will be capitalized, the second character lowercase, etc.
 *@parameter inputStr sting passed to function
 *@return string that has alternating upper case lower case letters
 */  
string upAndDown(string inputStr)
{
    for (unsigned int cnt = 0; cnt < inputStr.length(); cnt++)
        if (cnt % 2 == 0)
            inputStr[cnt] = toupper (inputStr[cnt]);
        else
            inputStr[cnt] = tolower (inputStr[cnt]);
    return inputStr;
}

/*
 *count the number of words--delimited by space characters--in a string;
 *assumes that the parameter will never have multiple spaces back-to-back, and will never begin or end with spaces
 *@parameter inputStr sting passed to function
 *@returns the integer number of words in the string
 */  
int countWords(string inputStr)
{
    int wordCnt = 0;
    if (inputStr.length() == 0)
        return 0;
    else
    {   for (unsigned int cnt = 0; cnt < inputStr.length(); cnt++)
            if (isspace(inputStr[cnt]))
                wordCnt++;
        return wordCnt + 1;
    }
}

/*compute the average of the values in an array; assume the function will never receive an array of size 0
 *@parameter inputArray[] an array of integers
 *@parameter arraySize the size of the array of integers
 *@returns the average of the numbers in the array
 */
 int computeAverage(int inputArray[], int arraySize)
{
    int sum = 0;
    for (int cnt = 0; cnt < arraySize; cnt++)
        sum = sum + inputArray[cnt];
    return sum/arraySize;
}

/*identify the smallest value in an array; assumes the function will never receive an array of size 0
 *@parameter inputArray[] an array of integers
 *@parameter arraySize the size of the array of integers
 *@returns the average of the numbers in the array
 */
int findMinValue(int inputArray[], int arraySize)
{
    
}

/*identify the largest value in an array; assumes the function will never receive an array of size 0
 *@parameter inputArray[] an array of integers
 *@parameter arraySize the size of the array of integers
 *@returns the average of the numbers in the array
 */
int findMaxValue(int inputArray[], int arraySize)
{
    
}

/*
 * Unit testing functions. Do not alter.
 */
void unittest ()
{
	cout << "\nSTARTING UNIT TEST\n\n";

	int n1=0, n2=0;

	try {
		countCharacters("", n1, n2);
		btassert<bool>((n1 == 0) && (n2 == 0));
		cout << "Passed TEST 1: countCharacters(empty string)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 1 #\n";
	}

	try {
		countCharacters("hello", n1, n2);
		btassert<bool>((n1 == 5) && (n2 == 0));
		cout << "Passed TEST 2: countCharacters(\"hello\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 2 #\n";
	}

	try {
		countCharacters("12345", n1, n2);
		btassert<bool>((n1 == 0) && (n2 == 5));
		cout << "Passed TEST 3: countCharacters(\"12345\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 3 #\n";
	}

	try {
		countCharacters("hello 12345", n1, n2);
		btassert<bool>((n1 == 5) && (n2 == 5));
		cout << "Passed TEST 4: countCharacters(\"hello 12345\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 4 #\n";
	}

	try {
		countCharacters("&,.", n1, n2);
		btassert<bool>((n1 == 0) && (n2 == 0));
		cout << "Passed TEST 5: countCharacters(\"&,.\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 5 #\n";
	}

	string s;

	try {
		s = upAndDown("hello");
		btassert<bool>(s == "HeLlO");
		cout << "Passed TEST 6: upAndDown(\"hello\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 6 #\n";
	}

	try {
		s = upAndDown("HeLlO");
		btassert<bool>(s == "HeLlO");
		cout << "Passed TEST 7: upAndDown(\"HeLlO\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 7 #\n";
	}

	try {
		s = upAndDown("hElLo");
		btassert<bool>(s == "HeLlO");
		cout << "Passed TEST 8: upAndDown(\"hElLo\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 8 #\n";
	}

	try {
		s = upAndDown("");
		btassert<bool>(s == "");
		cout << "Passed TEST 9: upAndDown(empty string)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 9 #\n";
	}

	try {
		s = upAndDown("a");
		btassert<bool>(s == "A");
		cout << "Passed TEST 10: upAndDown(\"a\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 10 #\n";
	}

	try {
		btassert<bool>(countWords("") == 0);
		cout << "Passed TEST 11: countWords(empty string)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 11 #\n";
	}

	try {
		btassert<bool>(countWords("hello") == 1);
		cout << "Passed TEST 12: countWords(\"hello\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 12 #\n";
	}

	try {
		btassert<bool>(countWords("hello,world") == 1);
		cout << "Passed TEST 13: countWords(\"hello world\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 13 #\n";
	}

	try {
		btassert<bool>(countWords("hello world") == 2);
		cout << "Passed TEST 14: countWords(\"hello world\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 14 #\n";
	}

	try {
		btassert<bool>(countWords("hello, world") == 2);
		cout << "Passed TEST 15: countWords(\"hello, world\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 15 #\n";
	}

	int values [] = {10, 20, 30};
	try {
		btassert<bool>(computeAverage(values, 3) == 20);
		cout << "Passed TEST 16: computeAverage([10,20,30])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 16 #\n";
	}

	values[0] = 0, values[1] = 0, values[2] = 0;
	try {
		btassert<bool>(computeAverage(values, 3) == 0);
		cout << "Passed TEST 17: computeAverage([0,0,0])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 17 #\n";
	}

	values[0] = 5, values[1] = 7, values[2] = 11;
	try {
		btassert<bool>(computeAverage(values, 3) == 7);
		cout << "Passed TEST 18: computeAverages([5,7,11])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 18 #\n";
	}

	values[0] = -10, values[1] = -20, values[2] = -30;
	try {
		btassert<bool>(computeAverage(values, 3) == -20);
		cout << "Passed TEST 19: computeAverages([-10,-20,-30])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 19 #\n";
	}

	values[0] = -5, values[1] = 0, values[2] = 5;
	try {
		btassert<bool>(computeAverage(values, 3) == 0);
		cout << "Passed TEST 20: computeAverages([-5,0,5])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 20 #\n";
	}

	values[0] = -1, values[1] = 0, values[2] = 1;
	try {
		btassert<bool>(findMinValue(values, 3) == -1);
		cout << "Passed TEST 21: findMinValue([-1,0,1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 21 #\n";
	}

	values[0] = -3, values[1] = -2, values[2] = -1;
	try {
		btassert<bool>(findMinValue(values, 3) == -3);
		cout << "Passed TEST 22: findMinValue([-3,-2,-1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 22 #\n";
	}

	values[0] = 0, values[1] = 1, values[2] = 2;
	try {
		btassert<bool>(findMinValue(values, 3) == 0);
		cout << "Passed TEST 23: findMinValue([0,1,2])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 23 #\n";
	}

	values[0] = 1, values[1] = 1, values[2] = 1;
	try {
		btassert<bool>(findMinValue(values, 3) == 1);
		cout << "Passed TEST 24: findMinValue([1,1,1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 24 #\n";
	}

	values[0] = INT_MAX, values[1] = INT_MAX, values[2] = INT_MAX;
	try {
		btassert<bool>(findMinValue(values, 3) == INT_MAX);
		cout << "Passed TEST 25: findMinValue([INT_MAX,INT_MAX,INT_MAX])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 25 #\n";
	}

	values[0] = -1, values[1] = 0, values[2] = 1;
	try {
		btassert<bool>(findMaxValue(values, 3) == 1);
		cout << "Passed TEST 26: findMaxValue([-1,0,1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 26 #\n";
	}

	values[0] = -3, values[1] = -2, values[2] = -1;
	try {
		btassert<bool>(findMaxValue(values, 3) == -1);
		cout << "Passed TEST 27: findMaxValue([-3,-2,-1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 27 #\n";
	}

	values[0] = 0, values[1] = 1, values[2] = 2;
	try {
		btassert<bool>(findMaxValue(values, 3) == 2);
		cout << "Passed TEST 28: findMaxValue([0,1,2])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 28 #\n";
	}

	values[0] = 1, values[1] = 1, values[2] = 1;
	try {
		btassert<bool>(findMaxValue(values, 3) == 1);
		cout << "Passed TEST 29: findMaxValue([1,1,1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 29 #\n";
	}

	values[0] = INT_MIN, values[1] = INT_MIN, values[2] = INT_MIN;
	try {
		btassert<bool>(findMaxValue(values, 3) == INT_MIN);
		cout << "Passed TEST 30: findMaxValue([INT_MIN,INT_MIN,INT_MIN])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 30 #\n";
	}

	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
	if (!assertion)
		throw X();
}