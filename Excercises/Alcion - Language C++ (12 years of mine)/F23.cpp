#include <iostream.h>

class SomeException{};

int
main()
{
	try
	{
		try
		{
			throw SomeException();
		}
		catch(...)
		{
			throw;
		}
	}
	catch(SomeException)
	{
		cout <<" SomeException ... Done.\n";
	}
	return 0;
};