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
	static int trySet = 3;
	cout << "\nВведите часы -> ";
	cin >> h;
	try {
		if (h < 0 || h > 23) throw exception("Неверный ввод. Интервал значения часов от 0 до 23.\n");
		if (cin.fail())	throw exception("Неверный ввод. Введены не цифры.");
		*hours = h;
	}
	catch (exception&e) {
		trySet--;
		cin.clear();
		cin.ignore(32767, '\n');
		cout << e.what() << endl;
		if (trySet)
			setHours();
		else cout << "\nЗначение не изменено!\n\n";
	}
}
void Clock::setMinutes()
{
	int m;
	static int trySet = 3;
	cout << "\nВведите минуты -> ";
	cin >> m;

	try {
		if (m < 0 || m > 59) throw exception("Неверный ввод. Интервал значения минут от 0 до 59.\n");
		if (cin.fail())	throw exception("Неверный ввод. Введены не цифры.");
		*minutes = m;
	}
	catch (exception&e) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << e.what() << endl;
		if (trySet)
			setMinutes();
		else cout << "\nЗначение не изменено!\n\n";
	}
}
void Clock::setSeconds()
{
	int s;
	static int trySet = 3;
	cout << "\nВведите секунды -> ";
	cin >> s;
	try {
		if (s < 0 || s > 59) throw exception("Неверный ввод. Интервал значения секунд от 0 до 59.\n");
		if (cin.fail())	throw exception("Неверный ввод. Введены не цифры.");
		*seconds = s;
	}
	catch (exception&e) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << e.what() << endl;
		if (trySet)
			setMinutes();
		else cout << "\nЗначение не изменено!\n\n";
	}
}

int Clock::getHours() { return *hours; };
int Clock::getMinutes() { return *minutes; };
int Clock::getSeconds() { return *seconds; };

void Clock::printClock()
{
	cout << "\n\nФормат времени HH:MM:SS \n"
		<< "Текущие установки - " << *hours << ":" << *minutes << ":" << *seconds << "\n\n";
}

Clock::~Clock()
{
	delete hours, minutes, seconds;
}

