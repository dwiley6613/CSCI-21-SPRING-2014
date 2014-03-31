/*
 * Programming challenge 21
 * Demostrates the use of templates in a class
 * Donald Wiley
 * box.h
 * created 3/24/2014
 * modified 3/29/2014
 * Sebastian Brenton
 */
 //#pragma once
 #include <string>
 #include <iostream>
 #include <cstdlib>
 
 using namespace std;
 
 template <typename T>
 class Box
 {
	public:
	
		/*
         * overloaded constructor
		 * @param contentsDataType
         */
		Box(T newContents);
		
		/*
         * Get the contents in this Box.
         * @return contentsDataType
         */
		T getContents();
		
		/*
	     * Set the value of the contents in this box.
	     * @param contentsDataType newContents 
	     * @return void
		 */
		void setContents(T newContents);

		/*
		 * friend function that overloads the insertion operator
		 * @param contentsDataType outContents
		 * @return ostream
		 */
		friend ostream& operator << (ostream& out, Box in);
		
 	private:
		T contents;
 };
 
template <typename T>
Box <T>::Box(T newContents)
:contents(newContents)
{}

template <typename T>
T Box <T>::getContents()
{
	return contents;
}

template <typename T>
void Box<T>::setContents(T newContents)
{
	contents = newContents;
}

template <typename T>
ostream& operator << (ostream& out, Box in)
{
	out << in.getContents();
	return out;
}
