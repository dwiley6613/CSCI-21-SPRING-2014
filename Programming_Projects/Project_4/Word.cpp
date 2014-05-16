/*
 * Donald Wiley
 * Demonstrates the use of binary search tree 
 * Programming Project 4
 * Word.cpp
 * created 5/2/2014
 * modified 5/15/2014
 * 
 */

#include"word.h"
#include<cstdlib>
#include<string>
#include<iostream>
#include<cmath>
#include<algorithm>
 
using namespace std;


Word::Word()
	:word(""), count(1){}

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

void Word::incrementCount(){
	count++;
}

unsigned int Word::getCount() const{
	return count;
}

bool operator == (const Word& word1, const Word& word2){
	string str1(word1.word);
	string str2(word2.word);
	if(str1.size() != str2.size()){
		return false;
	}
	else{
		for(unsigned int cnt = 0; cnt < str1.size(); cnt++){
			if(toupper(str1[cnt]) != toupper(str2[cnt])){
				return false;
			}
		}
	}
	return true;
}

bool operator < (const Word& word1, const Word& word2){
	string str1(word1.word), str2(word2.word);
	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
	if(str1 < str2){
		return true;
	}
	else{
		return false;
	}
}

bool operator > (const Word& word1, const Word& word2){
	string str1(word1.word), str2(word2.word);
	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
	if(str1 > str2){
		return true;
	}
	else{
		return false;
	}
}

ostream& operator << (ostream& out, const Word& src){
	return out << src.word << " " << src.count;
}