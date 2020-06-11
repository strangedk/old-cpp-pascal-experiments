#include<iostream>

using namespace std;

class Dog // Собака
{
public:
	void Speak()   const {	cout<<"Woof!\n";			  } // Издать звук
	void Move()    const {	cout<<"Walking to heel...\n"; } // Идти/Бежать
	void Eat()     const {	cout<<"Gobbling food...\n";	  } // Кушать
	void Growl()   const {	cout<<"Grrrrr!";			  } // Злиться
	void Whimper() const {	cout<<"Whining noises...\n";  } // Нюхать
};

// Тип указателя на функцию класса Dog - PDF
typedef void(Dog::*PDF)() const;

int
main()
{
	const int MaxFuncs = 5; // Максимум Функций
	PDF DogFunctions[MaxFuncs] = 

	// Инициализация массива указателей на функции
	{
		Dog::Speak,
		Dog::Move,
		Dog::Eat,
		Dog::Growl,
		Dog::Whimper
	};

	Dog* pDog =0;	// Указатель pDog на обьект класса Dog
	int Method;		// Метод
	bool fQuit =false; // Проверка выхода

	while(!fQuit) // Пока не будет выбран выход
	{
		cout<<"(0)Quit (1)Speak (2)Move (3)Eat (4)Growl (5)Whimper: ";
		cin>>Method;
		if(Method==0 || Method>5)
			fQuit =true;
		else
		{
			pDog =new Dog;
			(pDog->*DogFunctions[Method-1])();
			delete pDog;
		}
	}
	return 0;
}