#include<iostream>

using namespace std;

template <class T>
// Класс функции
class Print
{
public:
	void operator() (const T& t)
	{
		cout <<t <<" ";
	}
};

int
main()
{
	Print<int> DoPrint;		// обьект - функция
	for(int i=0; i<5; i++)
		DoPrint(i);			// Использование обьекта как функции

/*
		На самом деле используется
		перегруженный оператор вызова функции:

		void operator() (...)
*/

	return 0;