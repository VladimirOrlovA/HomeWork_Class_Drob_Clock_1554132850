#include<iostream>
#include<locale.h>

using namespace std;

class Drob
{
private:
	int *numerator;
	int *denominator;

public:
	Drob(int a = 0, int b = 0)	// �����������
	{
		this->numerator = new int;
		this->denominator = new int;
	}

	void setNomDenom(int a, int b)	// ������
	{
		cout << "������� ��������� ����� ->";
		cin >> a;
		cout << "������� ����������� ����� -> ";
		cin >> b;

		*numerator = a;
		*denominator = b;
	}

	int getNom() const	// ������
	{
		return *numerator;
	}

	int getDenom() const	// ������
	{
		return *denominator;
	}

	void fractionReduction() // ����� ���������� �����
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

	void printDrob() const
	{
		cout << "\n ��������� ����� -> " << *numerator << "/" << *denominator << "\n\n";
	}

	~Drob() // ����������
	{
		delete numerator, denominator; // ����������� ������ - ����������� ������� ������ � ��� 
	} // ������� �����������
};

class Clock
{
private:
	int *hours;
	int *minutes;
	int *seconds;

public:
	Clock(int h = 15, int m = 39, int s = 45)	// ����������� � �����������
	{
		hours = new int;	minutes = new int;	seconds = new int;
		/*setHours(h);
		setMinutes(m);
		setSeconds(s);*/

		*hours = h;
		*minutes = m;
		*seconds = s;
	}
	void setHours()
	{
		int h;
		cout << "������� ���� -> ";
		cin >> h;

		if (h >= 0 && h <= 23)
			*hours = h;
		else
			*hours = 0;
	}
	void setMinutes()
	{
		int m;
		cout << "������� ������ -> ";
		cin >> m;

		if (m >= 0 && m <= 59)
			*minutes = m;
		else
			*minutes = 0;
	}
	void setSeconds()
	{
		int s;
		cout << "������� ������� -> ";
		cin >> s;

		if (s >= 0 && s <= 59)
			*seconds = s;
		else
			*seconds = 0;
	}
	int getHours() { return *hours; };
	int getMinutes() { return *minutes; };
	int getSeconds() { return *seconds; };

	void printClock()
	{
		cout << "\n ������ ������� HH:MM:SS \n";
		cout << "\n ������� ��������� - " << *hours << ":" << *minutes << ":" << *seconds << "\n\n";
	}

	~Clock()
	{
		delete hours, minutes, seconds;
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");

	Drob first;
	first.setNomDenom(15, 25);
	first.printDrob();
	first.fractionReduction();

	cout << "\n----------------------------------------------------------\n";

	Clock mytime;
	mytime.printClock();
	mytime.setHours();
	mytime.setMinutes();
	mytime.setSeconds();
	mytime.printClock();


	system("pause");
	return 0;
}