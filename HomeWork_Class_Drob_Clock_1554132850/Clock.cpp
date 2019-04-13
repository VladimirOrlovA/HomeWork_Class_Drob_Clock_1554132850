#include "Clock.h"


	Clock::Clock(int h, int m, int s)	// ����������� � �����������
	{
		this->hours = new int(h);
		this->minutes = new int(m);
		this->seconds = new int(s);
	}
	void Clock::setHours()
	{
		int h;
		cout << "������� ���� -> ";
		cin >> h;

		if (h >= 0 && h <= 23)
			*hours = h;
		else
			*hours = 0;
	}
	void Clock::setMinutes()
	{
		int m;
		cout << "������� ������ -> ";
		cin >> m;

		if (m >= 0 && m <= 59)
			*minutes = m;
		else
			*minutes = 0;
	}
	void Clock::setSeconds()
	{
		int s;
		cout << "������� ������� -> ";
		cin >> s;

		if (s >= 0 && s <= 59)
			*seconds = s;
		else
			*seconds = 0;
	}
	int Clock::getHours() { return *hours; };
	int Clock::getMinutes() { return *minutes; };
	int Clock::getSeconds() { return *seconds; };

	void Clock::printClock()
	{
		cout << "\n ������ ������� HH:MM:SS \n";
		cout << "\n ������� ��������� - " << *hours << ":" << *minutes << ":" << *seconds << "\n\n";
	}

	Clock::~Clock()
	{
		delete hours, minutes, seconds;
	}
