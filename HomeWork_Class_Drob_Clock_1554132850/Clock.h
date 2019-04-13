#pragma once
#include<iostream>
#include<locale.h>

using namespace std;

class Clock
{
private:
	int *hours;
	int *minutes;
	int *seconds;

public:
	Clock(int h = 15, int m = 39, int s = 45);	// конструктор с параметрами
	void setHours();
	void setMinutes();
	void setSeconds();
	int getHours();
	int getMinutes();
	int getSeconds();
	void printClock();
	~Clock();
};

