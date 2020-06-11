#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

char* Animals[12] = {
					  "Rat", "Bull", "Tiger",
					  "Rabbit", "Dragon", "Snake",
					  "Horse", "Sheep", "Monkey",
					  "Petuh", "Dog", "Pig"
					};

int
main()
{
	int year;
	int age;
	int answer;
	char* answerAnm;

	clrscr();

	for (;;)
	{
		cout << "Enter flow year : ";
		cin >> year;

		if (year == 0) { clrscr(); break; }
		if (year == 1 || year < 0 || year > 3000) { clrscr(); continue; }

		cout << "Ok, How old are you : ";
		cin >> age;

		answer = year - age;

		for (int i=1901, gode=0; i <= year-age; ++i)
		{
			if (++gode==12) gode = 0;
			answerAnm = Animals[gode];
		}

		cout << "You born in " << answer << " Year of " << answerAnm << endl;
	}

	return 0;
}