


#include <iostream>
using namespace std;
//Exception class
//Raymond Berry
//9/20/15
//

class Exception
{
public:

	//constructor
	Exception();
	Exception(char* msg);

	//copy constructor
	Exception(const Exception&);

	//destructor
	~Exception();

	//operator overloading
	Exception& operator=(const Exception& rhs);

	//functions
	const char* getMessage();

	void setMessage(char* msg);

	//friend ostream  &operator<<(ostream  &os, const Complex   &rhs);
	friend ostream& operator<<(ostream& os, const Exception& except);




private:

	char *m_msg;
	int m_length;


};