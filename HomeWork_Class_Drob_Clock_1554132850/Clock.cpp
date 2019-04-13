#include "Clock.h"


	Clock::Clock(int h, int m, int s)	// конструктор с параметрами
	{
		this->hours = new int(h);
		this->minutes = new int(m);
		this->seconds = new int(s);
	}
	void Clock::setHours()
	{
		int h;
		cout << "Введите Часы -> ";
		cin >> h;

		if (h >= 0 && h <= 23)
			*hours = h;
		else
			*hours = 0;
	}
	void Clock::setMinutes()
	{
		int m;
		cout << "Введите Минуты -> ";
		cin >> m;

		if (m >= 0 && m <= 59)
			*minutes = m;
		else
			*minutes = 0;
	}
	void Clock::setSeconds()
	{
		int s;
		cout << "Введите секунды -> ";
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
		cout << "\n Формат времени HH:MM:SS \n";
		cout << "\n Текущие установки - " << *hours << ":" << *minutes << ":" << *seconds << "\n\n";
	}

	Clock::~Clock()
	{
		delete hours, minutes, seconds;
	}
