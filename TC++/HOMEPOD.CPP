#include <iostream.h>
#include <assert.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

/////////////////////////////////////////////////////////////////


class House
{
public:
	// constructors

	House();
	House(int, int, int);
   ~House(){	}

	void SetCurPodyezd(int z){ CurPodyezd = z; }

	void SetSumEtage(int z){ SumEtage = z; }
	void SetCurEtage(int z){ CurEtage = z; }

	void SetCvartOnEtage(int z){ CvartOnEtage = z; }

	void SetCvart(int z){ Cvart = z; }

	int GetCurPodyezd() const{ return CurPodyezd; }

	int GetSumEtage() const{ return SumEtage; }
	int GetCurEtage() const{ return CurEtage; }

	int GetCvartOnEtage() const{ return CvartOnEtage; }

	int GetCvart() const{ return Cvart; }

	friend int Find(int, int, int);

private:

	int SumEtage;

	int CvartOnEtage;

	int CurPodyezd;
	int CurEtage;
	int Cvart;

};

/////////////////////////

House::House():
CurPodyezd(1),
SumEtage(9),
CurEtage(1),
CvartOnEtage(4),
Cvart(1)
{	}

House::House(int Cv, int ConE, int Se):
CurPodyezd(1),
SumEtage(Se),
CurEtage(1),
CvartOnEtage(ConE),
Cvart(Cv)
{	}


/////////////////////////////////////////////////////////////////

enum { NError = 10 };

int A[1000];

int Find(int, int, int);

int Digit(int);

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////

int
main()
{
	int C, CbE, E;

	clrscr();

	for (int i=0; i<1000; ++i)
		A[i] = i;

	while (1)
	{
		clrscr();

		cout << "Enter number of KVARTIRA : ";
		cin >> C;
		if (Digit(C) != NError) abort();

		cout << "Enter number of KVARTIRAS ON ETAGES : ";
		cin >> CbE;
		if (Digit(CbE) != NError) abort();

		cout << "Enter number of ETAGES : ";
		cin >> E;
		if (Digit(E) != NError) abort();

		Find(C, CbE, E);
	}
	return 0;
}

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

int
Digit(int _c)
{
	for (int i=0; i<1000; ++i)
		if (_c == A[i])
			return NError;
		else if (_c == 0)
			return 0;
}


int
Find(int NumCvr, int CvOnEt, int ColEt)
{
	clrscr();

	House Home(NumCvr, CvOnEt, ColEt);

	for (int i=1, i_cvNet=1; i!=Home.Cvart; i++)
	{
		if (++i_cvNet > Home.CvartOnEtage)
		{
			Home.CurEtage++;
			i_cvNet = 1;
		}
		if (Home.CurEtage > Home.SumEtage)
		{
			Home.CurPodyezd++;
			Home.CurEtage = 1;
		}
	}
	cout << "KVARTIRA - " << Home.Cvart << endl << endl;
	cout << "Podyezd - " << Home.CurPodyezd << endl;
	cout << "Etage - " << Home.CurEtage << endl;

	getch();

	return Home.Cvart;
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////