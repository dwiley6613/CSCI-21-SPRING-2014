/*
 * Programming challenge 21
 * box.h
 */
 //#progrma once
 #include <string>
 #include <iostream>
 
 using namespace std;
 
 template class Box<contentsDataType>
 {
	public
	
		/*
         * overloaded constructor
		 * @param contentsDataType
         */
		Box(contentsDataType newContents);
		
		/*
         * Get the contents in this Box.
         * @return contentsDataType
         */
		contentsDataType getcontents();
		
		/*
	     * Set the value of the contents in this box.
	     * @param contentsDataType newContents 
	     * @return void
		 */
		void setContents(contentsDataType newContents);
		
		/*
		 * friend function that overloads the insertion operator
		 * @param contentsDataType outContents
		 * @return ostream
		 */
		friend ostream operator << (contentsDataType outContents);
 
	private
		contentsDataType contents;
 };
 efine a "header only" template class named Box with:

- one data member -- contents (data type templated)
- overloaded constructor -- one parameter newContents to be assigned to contents
- getter (getContents) and setter (setContents)
- friend overloaded operator<<