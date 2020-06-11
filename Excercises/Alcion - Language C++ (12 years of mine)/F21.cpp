#include <iostream.h>
#include <exception.h>

using namespace std;
using std::cout;

void Func()
{
// Function generate exception;
}

main()
{
	try
	{
		Func();
		return 0;
	}
	catch (const char*)
	{
		cout <<"const char* Exception\n";
		return 1;
	}
	catch(...)
	{
		cout <<"Any Exception";
		return 1;
	}
};