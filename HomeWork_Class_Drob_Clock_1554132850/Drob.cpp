#include "Drob.h"



// ����������� � �����������	
Drob::Drob(int a, int b)
{
	this->numerator = new int;
	this->denominator = new int;
}

// ����������� �����������
Drob::Drob(const Drob & obj)
{
	this->numerator = obj.numerator;
	this->denominator = obj.denominator;
}

// ������ ��� ���������� ��������� � �����������
void Drob::setNomDenom(int a, int b)	// ������
{
	/*cout << "������� ��������� ����� ->";
	cin >> a;
	cout << "������� ����������� ����� -> ";
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

// ������ ��� ��������� numerator, �����������, ����� ��������� ��������� ��������� numerator
int Drob::getNom() const
{
	return *numerator;
}

// ������ ��� ��������� denomerator, �����������, ����� ��������� ��������� ��������� denomerator
int Drob::getDenom() const
{
	return *denominator;
}

// ����� ���������� �����
void Drob::fractionReduction()
{
	int divider;
	divider = *numerator;

	while (divider > 1)
	{
		if ((*numerator%divider) == 0 && (*denominator%divider) == 0)
		{
			if ((*numerator > *denominator || *numerator == *denominator) && *numerator % *denominator == 0)
				cout << "����������� �����: " << *numerator / *denominator << endl;
			else if (*numerator > *denominator)
			{
				cout << "����������� �����: " << *numerator / *denominator
					<< (*numerator / divider) - (*denominator / divider) << "/"
					<< *denominator / divider << ")" << endl;
			}
			else
				cout << "����������� �����: " << *numerator / divider << "/" << *denominator / divider << endl;
			break;
		}
		--divider;
	}
	if (divider == 1)
		cout << "���������� ��������� �����" << endl << endl;
}

// ����� ������ ����� � �������, �����������
void Drob::printDrob() const
{
	cout << "\n ��������� ����� -> " << *numerator << "/" << *denominator << "\n\n";
}

// ����� ����������� ����� ����� ���������� ����� � �������, �����������
double Drob::getFraction() const
{
	int n = *numerator;
	int d = *denominator;
	return double(n) / d;
}

// ����� - "+" ������
Drob Drob::operator+=(const Drob & b)
{
	*this->numerator = *this->numerator * *b.denominator + *this->denominator* *b.numerator;
	*this->denominator = *this->denominator * *b.denominator;
	return *this;
}


Drob::~Drob() // ����������
{
	//delete numerator, denominator; // ����������� ������ - ����������� ������� ������ � ��� 
} // ������� �����������

// ���������� ������� ��������� "+" ��� ���� ������ drob
Drob operator+(const Drob & a, const Drob & b)
{
	Drob c = a;
	c += b;
	//drob c;
	//c.setX(a.getY()*b.getX() + a.getX()*b.getY());
	//c.setY(a.getY()*b.getY());
	return c;
}
