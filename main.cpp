
/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/2/2015
* Last Modification Date:	10/2/2015
* Lab Number:			CST 211 Assignment 1
* Filename:				main.cpp
*


Awnswers to questions:
1) I had to consider the fact that I needed to do a deep copy. This is because I was using dynamic 
memory so if I just coppied the array normaly, the pointer would end up getting deleated and the array would get errased when the destructor is called.
To fix this, I had to create a new array, and copy each ellement into it.


2) The similarity is that thye both have to copy the data in the same way. The difrense is the way the perameters are passed into the method.
the assignment operator has a rhs perameter, and the copy construcot has a perameter that is passed in through (). The two function are very simmilar, and
in some cases the assignment operator could call the copy constructor, if the array class is designed that way.

3)I made sure I used a deep copy on both the copy construcotr, and the assignment operator. That way the pointer to the array dosn't get deleated
when it's not supose to. Also running the program with the debugger, and testing the class.

4) In big O notation, when a user calls [] to get an ellement the noation is 0(46). This could be improved by changing the deep copy the instruction class does,
and indtead making it a showlow coppy that keeps track of the number of times the constructor is called, and only delete the memory when there is only 1 object pointer
to the string. That would reduce the O notation to 0(2). Another way to increase eficeny is to make the exception checking an if statement, and an else if statment. That would reduce the notation by 1. 
So the final notation with the improvements would be O(1). And the code inside the funciton call would look like this

if (index < m_start_index)
{
throw Exception("index below start index");
}

else if (index > m_start_index + m_length-1)
{
throw Exception("index above max index");
}


* Overview:
*	This program demonstrates the abilities of the array class, and the exception class.
*
* Input:
*	no input
*
* Output:
*	The output of this program will be several arrays along with some strings which are the exceptions
*	

An exception occrued. Exceptionindex below start index
An exception occrued. Exceptionindex below start index
An exception occrued. Exceptionindex above start index
My Array:
10
10
10
10
10
10
10
10
10
10

Copy of Array
10
10
10
10
10
10
10
10
10
10

My Array:
10
10
10
10
10
10
10
10
10
10

Copy of Array
10
10
10
10
10
10
10
10
10
10

My Array
-2
-2
-2
-2
-2
-2
-2
-2
-2
-2

Copy Array
-2
-2
-2
-2
-2
-2
-2
-2
-2
-2

hihi


*
*/
#include <iostream>
#include "array.h"




using namespace std;


#define DataType int
#define OUT_OF_BOUNDS_EXCEPTION Exception("index below start index")

//Functions



//Takes an inputed array and displays to the screen every element in that array
void displayArray(Array<DataType> &theArray)
{
	int theLength = (theArray.getLength());

	for (int i = 0; i < theLength; i++)
	{
		cout << theArray[i] << endl;
	}

}


//Demonstrates creating an array, the exception class, the overloaded operator [], 
void TestCreateArray(void)
{
	Array<DataType> my_array(10);

	for (int i = 0; i < 10; i++)
	{
		my_array[i] = 10;
	}


	const int x = -1;

	try
	{
		my_array[x] = 7;
	}
	catch (Exception boundException)
	{
		cout << "An exception occrued. Exception" << boundException << endl;

	}
	
	try
	{
		my_array[-1] = 7;
	}
	catch (Exception boundException)
	{
		cout << "An exception occrued. Exception" << boundException << endl;

	}


	try
	{
		my_array[20] = 7;
	}
	catch (Exception boundException)
	{
		cout << "An exception occrued. Exception" << boundException << endl;

	}



	

}

//Demonstrates the ability for an array to be coppied with a copy constructor
void TestCopyArray(void)
{
	Array<DataType> my_array(10);

	for (int i = 0; i < 10; i++)
	{
		my_array[i] = 10;
	}

	Array<DataType> my_array2(my_array);


	cout << "My Array: " << endl;
	displayArray(my_array);

	cout << endl << "Copy of Array: " << endl;
	displayArray(my_array2);

}


//Demonstrates the ability to assign an array to another array with the overloaded = sign
void TestAssignArray(void)
{
	Array<DataType> my_array(10);

	for (int i = 0; i < 10; i++)
	{
		my_array[i] = 10;
	}


	Array<DataType> my_array2(5);

	for (int i = 0; i < 5; i++)
	{
		my_array[i] = 10;
	}

	my_array2 = my_array;

	cout << "My Array: " << endl;
	displayArray(my_array);

	cout << endl << "Copy of Array: " << endl;
	displayArray(my_array2);



}




//demonstrates the ability to set - start indexes

void TestStartIndex(void)
{

	Array<DataType> my_array(10, -2);

	for (int i = -2; i < 8; i++)
	{
		try
		{
			my_array[i] = 10;

		}
		catch (Exception boundException)
		{
			cout << "An exception occrued. Exception" << boundException << endl;
		}

	}



}

//Demonstrates the ability to set and get the length and start index
void SetAndGetTester()
{





	Array<DataType> my_array(10, -2);

	int lengt = my_array.getLength();

	int startIndex = my_array.getStartIndex();

	my_array.setStartIndex(5);

	my_array.setLength(11);

	
	

	

}



//demonstrates the array construcotr without any perameters
void emptyArrayTester()
{
	Array<DataType> my_array();


}


//Demonstrates that arrays can be assigned with the overloaded = operaotr
void assignmentTester()
{
	Array<DataType> my_array(10);

	for (int i = 0; i < 10; i++)
	{
		my_array[i] = -2;
	}

	Array<DataType> my_array2 = my_array;


	cout << "My Array: " << endl;
	displayArray(my_array);

	cout << endl << "Copy of Array: " << endl;
	displayArray(my_array2);




}



//Demonstrates the abilities of the Exception class
//The ability to construc an exception
//the ability to ocpy an exception with a copy construcotr
//the ability to set and get the message in the exception
//the ability to assign exceptiong using the overloaded = operator
//the ability to use the << operator to display the exception
void exceptionTesting()
{
	Exception myException("bob");

	
	myException.setMessage("hi");

	Exception exception2(myException);


	exception2  = myException;

	cout << endl << myException.getMessage() << myException << endl;

	



}


//the main program that calls all the test functions
int main(void)
{
	TestCreateArray();
	
	TestCopyArray();

	TestAssignArray();

	TestStartIndex();



	SetAndGetTester();
	


	emptyArrayTester();



	assignmentTester();


	

	exceptionTesting();
	return 0;
}