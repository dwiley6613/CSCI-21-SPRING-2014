/*
 * Donald Wiley
 * Demonstrates the use of binary search tree 
 * Programming Project 4
 * Word.h
 * created 5/2/2014
 * modified 5/2/2014
 * 
 */
 
#pragma once
#include<cstdlib>
#include<string>
#include<iostream>
#include<algorithm>
 
using namespace std;

class Word
{
	public:
	
		/*
         * default constructor, sets word to "word and count to 1
         */	
		Word();
			
		/*
         * overloaded constructor, string parameter assigned to word
		 * @param string word
         */
        Word(string newWord);

        /* 
         * destructor
         */
	    virtual ~Word();

		/*
		 * set word to newWord
		 * @param string newWord
		 * @return void
		 */
		void setWord(string newWord);
		
		/*
		 * get the contents of word
		 * @return string word
		 */
		string getWord() const;
		
		/*
		 * function incCount increment the count of words
		 * @return void
		 */
		void incCount();

		/*
		 * Friend function that overloads the comparison operator
		 * @param Word& wordName_1
		 * @param Word& wordName2
		 * @return bool
		 */
    
        friend bool operator == (const Word& wordName_1, const Word& wordName_2);
		
		/*
		 * Friend function that overloads the less than operator
		 * @param Word& wordName_1
		 * @param Word& wordName_2
		 * @return bool
		 */
    
        friend bool operator < (const Word& wordName_1, const Word& wordName_2);

		/*
		 * Friend function that overloads the greater than operator
		 * @param Word& wordName_1
		 * @param Word& wordName_2
		 * @return bool
		 */
    
        friend bool operator > (const Word& wordName_1, const Word& wordName_2);

		/*
		 * Friend overloaded operator function "<<"
		 * @param ostream& out
		 * @param Word& src
		 * @return ostream& out
		 */
		friend ostream& operator << (ostream& out, const Word& src);
		
	private:
		string word;
		unsigned int count;

};