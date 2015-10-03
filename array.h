

//Array Class
//Raymond Berry
//9/30/2015



/************************************************************************
* Class: Exception.
*

Description: This is a template array class, that alows a user to specify
a starting position and a length. The user can specify a -starting position.
This array class has overloaded [] operators, and overloaded = operator.
this array can be of any type specified.



* Constructors:
*	Array()
*		length initialized to 0
*		msg initizlized to an array of 1



Array(int length, int start_index = 0)
	length the number of ellements in the array specified by the user
	start_index the starting possing of the array (can be negitive)


Array(const Array& originalArray)
	originalArray the array that is going to be coppied
*
* Mutators:
*	setMessage(char* msg)
*		This mutator initializes the member varable m_msg to the parameter that was passed in
*
*
*operator=(const Exception& rhs)
*	this mutator sets all the member varables of the class, to the rhs's member variables
*

setLength(int length);
	Changes the length of the array to the specified perameter

setStartIndex(int start_index);
	Changes the starting position of the array to what is passed in

&operator[](int index) const;
	Returns by reference the ellement at the position specified in the []. throws an exceptiong if the position is out of bounds of the array

&operator[](int index);
	Returns by reference the ellement at the position specified in the []. throws an exceptiong if the position is out of bounds of the array

&operator=(const Array &rhs);
	Allows one array to be set to the parameter passed in

Inspectors:
int getLength()
	Returns the length of the array
	
int getStartIndex() const;
	returns the starting index of the array

*************************************************************************/

#include "Exception.h"


template <class  Type> class Array
{
public:
	//constructor
	Array();

	//constructor
	Array(int length, int start_index = 0 );

	//copy contructor
	Array(const Array& originalArray);

	//destructor
	~Array();

	//operator overloading
	Array &operator=(const Array &rhs);
	Type &operator[](int index);
	Type &operator[](int index) const;

	//getting and setting start index
	int getStartIndex() const;
	void setStartIndex(int start_index);

	//getting and setting the length
	int getLength() const;
	void setLength(int length);

private:
	Type *m_array;
	int m_length;
	int m_start_index;
};

//Array implimination
/**************************************************************
*   Entry:  nothing
*
*    Exit:  nothing
*
*
* Purpose: Allows the user to create an array class
**************************************************************/

template<class Type> Array<Type>::Array()
{
	m_length = 0;
	m_start_index = 0;
	m_array = new Type[m_length];
}

/**************************************************************
*   Entry:  length, the length of the array, start_index the starting position of the array
*
*    Exit:  nothing
*
*
* Purpose: Allows the user to create an array class
**************************************************************/
template<class Type> Array<Type>::Array(int length, int start_index)
{
	m_length = length;
	m_start_index = start_index;
	m_array = new Type[m_length];
}

/**************************************************************
*   Entry:  A class object
*
*    Exit:  nothing
*
*
* Purpose: Allows the user to copy an array
**************************************************************/
template<class Type> Array<Type>::Array(const Array& originalArray):
m_length(originalArray.getLength()),
m_start_index(originalArray.getStartIndex())
{
	//realocate the array
	m_array = new Type[m_length];

	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = originalArray[i];
	}
}

/**************************************************************
*   Entry:  nothing
*
*    Exit:  nothing
*
*
* Purpose: cleans up allowcating memory
**************************************************************/
template<class Type> Array<Type>::~Array()
{
	//cleanup allowcated memor
	delete[] m_array;
}

//operator overloading

/**************************************************************
*   Entry:  the array object that the user wants to copy
*
*    Exit:  the modified array
*
*
* Purpose: allows the user to assing one array to another array
**************************************************************/
template<class Type> Array<Type> &Array<Type>::operator=(const Array &rhs)
{
	//Array<Type> returnArray(rhs);
	m_length = rhs.getLength();
	m_start_index = rhs.getStartIndex();
	m_array = new Type[m_length];

	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = rhs[i];
	}
	return *this;

}


/**************************************************************
*   Entry:  The index
*
*    Exit:  the element at that index
*
*
* Purpose: allows the user to use the [] to get accses and change elements at
the specified index
**************************************************************/
template<class Type> Type &Array<Type>::operator[](int index)
{
	//check for index being <  the lower bound
	//int m_length;
	//int m_start_index;
		if (index < m_start_index)
		{
			throw Exception("index below start index");
		}

		if (index > m_start_index + m_length-1)
		{
			throw Exception("index above max index");
		}

	return m_array[index - m_start_index];
}

/**************************************************************
*   Entry:  The index
*
*    Exit:  the element at that index
*
*
* Purpose: allows the user to use the [] to get accses and change elements at
the specified index
**************************************************************/
template<class Type> Type &Array<Type>::operator[](int index) const
{
	if (index < m_start_index)
	{
		throw Exception("index below start index");
	}

	if (index > m_start_index + m_length - 1)
	{
		throw Exception("index above max index");
	}

	//check for index being > uper bound
	return m_array[index - m_start_index];
}

/**************************************************************
*   Entry:  nothing
*
*    Exit:  the starting index
*
*
* Purpose: alows the user to get the current start Index
**************************************************************/
template<class Type> int Array<Type>::getStartIndex() const
{
	return m_start_index;
}

/**************************************************************
*   Entry:  New start index
*
*    Exit:  nothing
*
* Purpose: alows the user to set the  start Index
**************************************************************/
template<class Type> void Array<Type>::setStartIndex(int start_index)
{
	if (start_index < m_start_index)
	{
		throw Exception("index below start index");
	}

	if (start_index > m_start_index + m_length - 1)
	{
		throw Exception("index above max index");
	}

	m_start_index = start_index;
}

//getting and setting the length

//getLength
/**************************************************************
*   Entry:  nothing
*
*    Exit:  the length of the array
*
* Purpose: alows the user to get the  length of the array
**************************************************************/
template<class Type> int Array<Type>::getLength() const
{
	return m_length;
}

//set Length
/**************************************************************
*   Entry:  the length
*
*    Exit:  nothing
*
* Purpose: alows the user to set the  length of the array
**************************************************************/
template<class Type> void Array<Type>::setLength(int length)
{
	m_length = length;
	m_array = new Type[m_length];
}