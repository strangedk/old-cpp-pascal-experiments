#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

int
main()
{
	const int ksize = 6;

	int a[ksize] = { 0, 0, 0, 0, 0, 0 };

	clrscr();
	randomize();

	int kk=0;

	for (int i=0, j=0, r=0; i<20000; ++i, ++j, ++r)
	{

		delay(2);

		for (double k=0; k<ksize-kk; ++k)
		{
			a[k] = random(j);
			cout << a[k];
		}

		switch(kk)
		{
			case 0: cout << " "; break;
			case 1: cout << "  "; break;
			case 2: cout << " - "; break;
			case 3: cout << " -- "; break;
			case 4: cout << " --- "; break;
			case 5: cout << " ---- "; break;
		}
		if (j > 10)
		{
			j = 0;
			cout << endl;
		}
		if (r > 1000)
		{
			r = 0;
			if (kk != 5)
				++kk;
			else
				kk = 0;
		}
	}

	getch();

	return 0;
}