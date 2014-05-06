/*
 * Donald Wiley
 * Demonstrates the use of binary search tree 
 * Programming Project 4
 * Word.cpp
 * created 5/2/2014
 * modified 5/2/2014
 * 
 */

#include"Word.h"
#include<cstdlib>
#include<string>
#include<iostream>
 
using namespace std;


Word::Word()
	:word("word"), count(1){}

Word::Word(string newWord)
	:word(newWord), count(1){}

Word::~Word(){
}			

void Word::setWord(string newWord){
	word = newWord;
}

string Word::getWord() const{
	return word;
}

void Word::incCount(){
	count++;
}

bool operator == (const Word& wordName_1, const Word& wordName_2){
	if(wordName_1.word == wordName_2.word){
		return true;
	}
	else{
		return false;
	}
}

bool operator < (const Word& wordName_1, const Word& wordName_2){
	if(wordName_1.word < wordName_2.word){
		return true;
	}
	else{
		return false;
	}
}

bool operator > (const Word& wordName_1, const Word& wordName_2){
	if(wordName_1.word > wordName_2.word){
		return true;
	}
	else{
		return false;
	}
}

ostream& operator << (ostream& out, const Word& src){
	return out << src.word;
}