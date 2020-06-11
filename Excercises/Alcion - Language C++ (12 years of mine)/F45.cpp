#include<iostream>
#include<ctime>

using namespace std;

class Date
{
public:
	Date(int d, int m, int y)
	{
		tm_mday=d;
		tm_mon=m;
		tm_year=y;
	};
	Date(tm t){tm_date=t; };
	Date(){tm_mday=01; tm_mon=00; tm_year=00; }
private:
	tm tm_date;
	friend istream& operator>>(istream& is,Date& dat);
	friend ostream& operator<<(ostream& os,const Date& dat);
};

istream&
operator<<(istream& is,const Date& dat)
{
	is <<dat.tm_date.tm_mon <<'/';
	is <<dat.tm_date.tm_mday <<'/';
	is <<dat.tm_date.tm_year;
	return is;
}

ostream&
operator<<(ostream& os,const Date& dat)
{
	os <<dat.tm_date.tm_mon <<'/';
	os <<dat.tm_date.tm_mday <<'/';
	os <<dat.tm_date.tm_year;
	return os;
}

int
main()
{
	Date date;
	cout <<"Input date (day, month, year)\n";
	cin >>date;
	cout <<date <<'\n';

	return 0;
}