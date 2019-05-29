#include "Drob.h"



// конструктор с параметрами	
Drob::Drob(int a, int b)
{
	this->numerator = new int;
	this->denominator = new int;
}

// конструктор копирования
Drob::Drob(const Drob & obj)
{
	this->numerator = obj.numerator;
	this->denominator = obj.denominator;
}

// сеттер для параметров числителя и знаменателя
void Drob::setNomDenom(int a, int b)	// сеттер
{
	/*cout << "Введите числитель дроби ->";
	cin >> a;
	cout << "Введите знаменатель дроби -> ";
	cin >> b;*/

	*numerator = a;
	try {
		if (b == 0)
			throw exception(" Division by zero denied");
	}
	catch (exception&e) {
		b = 1;
		cout << "Error: " << e.what() << "\nThe default denominator value is set to 1\n\n";
	}
	*denominator = b;
}

// геттер для параметра numerator, константный, чтобы исключить изменение параметра numerator
int Drob::getNom() const
{
	return *numerator;
}

// геттер для параметра denomerator, константный, чтобы исключить изменение параметра denomerator
int Drob::getDenom() const
{
	return *denominator;
}

// метод сокращения дроби
void Drob::fractionReduction()
{
	int divider;
	divider = *numerator;

	while (divider > 1)
	{
		if ((*numerator%divider) == 0 && (*denominator%divider) == 0)
		{
			if ((*numerator > *denominator || *numerator == *denominator) && *numerator % *denominator == 0)
				cout << "Сокращенная дробь: " << *numerator / *denominator << endl;
			else if (*numerator > *denominator)
			{
				cout << "Сокращенная дробь: " << *numerator / *denominator
					<< (*numerator / divider) - (*denominator / divider) << "/"
					<< *denominator / divider << ")" << endl;
			}
			else
				cout << "Сокращенная дробь: " << *numerator / divider << "/" << *denominator / divider << endl;
			break;
		}
		--divider;
	}
	if (divider == 1)
		cout << "Невозможно сократить дробь" << endl << endl;
}

// метод вывода дроби в консоль, константный
void Drob::printDrob() const
{
	cout << "\n Введенная дробь -> " << *numerator << "/" << *denominator << "\n\n";
}

// метод возвращения дроби ввиде десятичной дроби в консоль, константный
double Drob::getFraction() const
{
	int n = *numerator;
	int d = *denominator;
	return double(n) / d;
}

// метод - "+" дробей
Drob Drob::operator+=(const Drob & b)
{
	*this->numerator = *this->numerator * *b.denominator + *this->denominator* *b.numerator;
	*this->denominator = *this->denominator * *b.denominator;
	return *this;
}


Drob::~Drob() // деструктор
{
	//delete numerator, denominator; // освобождаем память - освобождаем занятые адреса в ОЗУ 
} // удаляем конструктор

// глобальная функция оператора "+" для типа данных drob
Drob operator+(const Drob & a, const Drob & b)
{
	Drob c = a;
	c += b;
	//drob c;
	//c.setX(a.getY()*b.getX() + a.getX()*b.getY());
	//c.setY(a.getY()*b.getY());
	return c;
}
