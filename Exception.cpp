

//Exception class implimentation
//Raymond Berry
//10/1/2015





/************************************************************************
* Class: Exception.
*
* Constructors:
*	Exception()
*		length initialized to 0
*		msg initizlized to an array of 1



Exception(char* msg)
	length set to the number of characters in msg
	m_msg is set to msg


Exception(const Exception& originalException)
	length initilized to originalException's length
	m_msg set to the message in originalException
*
* Mutators:
*	setMessage(char* msg)
*		This mutator initializes the member varable m_msg to the parameter that was passed in
*
*
*operator=(const Exception& rhs)
*	this mutator sets all the member varables of the class, to the rhs's member variables
*
* Methods:
*	void getLength()
*		This method returns the number of characters in a string that is passed into it
*
*
* &operator<<(ostream &os, const Exception& except)
		//sends to the os m_msg
*
*************************************************************************/


#include "Exception.h"

/**************************************************************
*   Entry:  a character array
*    Exit:  the length of the character arry
*
* Purpose:  Allows the user to get the length of a character array
*
***************************************************************/
int getLength(char* msg)
{
	int length = 0;

	for (int i = 0; msg[i] != 0; i++)
	{
		length++;
	}

	return length;
}

//constructor
Exception::Exception()
{
	m_length = 0;
	m_msg = new char[m_length + 1];
}

//constructor overloaded with perameters
Exception::Exception(char* msg)
{
	m_length = getLength(msg);
	m_msg = new char [m_length+1];

	for (int i = 0; i < m_length; i++)
	{
		m_msg[i] = msg[i];
	}

	m_msg[m_length] = 0;
}

/**************************************************************
*   Entry:  An exception objcet
*
*    Exit:  a copy of the exceptoin object passedin
*
* Purpose:  To allow the user to copy their arrays with out losing their data due the default copy constructor
*
***************************************************************/

Exception::Exception(const Exception& originalException)
{
	m_length = originalException.m_length;
	m_msg = new char[m_length+1];

	for (int i = 0; originalException.m_msg[i] != 0; i++)
	{
		m_msg[i] = originalException.m_msg[i];
	}
	
	m_msg[m_length] = 0;
}


/**************************************************************
*   Entry:  nothing
*    Exit:  nothing
*
* Purpose:  To clean up alowcated memory
*
***************************************************************/
//destructor
Exception::~Exception()
{
	delete[] m_msg;
}



/**************************************************************
*   Entry:  nothing
*    Exit:  the msg saved inside of the objcect
*
* Purpose:  To allow the user to get accses to the message inside of the objcet
*
***************************************************************/
const char* Exception::getMessage()
{
	return m_msg;
}



/**************************************************************
*   Entry:  A message
*    Exit:  nothing
*
* Purpose:  To allow the user to change the what is the message
*
***************************************************************/
void Exception::setMessage(char* msg)
{
	m_length = getLength(msg);
	
	for (int i = 0; i < m_length; i++)
	{
		m_msg[i] = msg[i];
	}

	m_msg[m_length] = 0;
}


/**************************************************************
*   Entry:  An exceptiong object
*    Exit:  the message array
*
* Purpose:  To allow the user to display the message with the << operator
*
***************************************************************/
ostream &operator<<(ostream &os, const Exception& except)
{
	return os << except.m_msg;
}



/**************************************************************
*   Entry:  An exception object
*    Exit:  this objcet
*
* Purpose:  To allow the user to use the = to set one exceptiong to another
*
***************************************************************/
Exception& Exception::operator=(const Exception& rhs)
{
	m_length = rhs.m_length;
	m_msg = new char[m_length + 1];

	for (int i = 0; rhs.m_msg[i] != 0; i++)
	{
		m_msg[i] = rhs.m_msg[i];
	}

	m_msg[m_length] = 0;
	
	return *this;
}

