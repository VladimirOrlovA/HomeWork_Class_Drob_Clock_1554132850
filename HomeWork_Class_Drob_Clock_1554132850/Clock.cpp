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
	static int trySet = 3;
	cout << "\n������� ���� -> ";
	cin >> h;
	try {
		if (h < 0 || h > 23) throw exception("�������� ����. �������� �������� ����� �� 0 �� 23.\n");
		if (cin.fail())	throw exception("�������� ����. ������� �� �����.");
		*hours = h;
	}
	catch (exception&e) {
		trySet--;
		cin.clear();
		cin.ignore(32767, '\n');
		cout << e.what() << endl;
		if (trySet)
			setHours();
		else cout << "\n�������� �� ��������!\n\n";
	}
}
void Clock::setMinutes()
{
	int m;
	static int trySet = 3;
	cout << "\n������� ������ -> ";
	cin >> m;

	try {
		if (m < 0 || m > 59) throw exception("�������� ����. �������� �������� ����� �� 0 �� 59.\n");
		if (cin.fail())	throw exception("�������� ����. ������� �� �����.");
		*minutes = m;
	}
	catch (exception&e) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << e.what() << endl;
		if (trySet)
			setMinutes();
		else cout << "\n�������� �� ��������!\n\n";
	}
}
void Clock::setSeconds()
{
	int s;
	static int trySet = 3;
	cout << "\n������� ������� -> ";
	cin >> s;
	try {
		if (s < 0 || s > 59) throw exception("�������� ����. �������� �������� ������ �� 0 �� 59.\n");
		if (cin.fail())	throw exception("�������� ����. ������� �� �����.");
		*seconds = s;
	}
	catch (exception&e) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << e.what() << endl;
		if (trySet)
			setMinutes();
		else cout << "\n�������� �� ��������!\n\n";
	}
}

int Clock::getHours() { return *hours; };
int Clock::getMinutes() { return *minutes; };
int Clock::getSeconds() { return *seconds; };

void Clock::printClock()
{
	cout << "\n\n������ ������� HH:MM:SS \n"
		<< "������� ��������� - " << *hours << ":" << *minutes << ":" << *seconds << "\n\n";
}

Clock::~Clock()
{
	delete hours, minutes, seconds;
}

