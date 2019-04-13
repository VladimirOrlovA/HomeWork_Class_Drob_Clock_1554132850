#pragma once
#include<iostream>

using namespace std;

class Drob
{
private:
	int *numerator;
	int *denominator;

public:
	Drob(int a = 0, int b = 0);	// конструктор с параметрами
	Drob(const Drob & obj); // конструктор копирования
	void setNomDenom(int a, int b);	// сеттер
	int getNom() const;	// геттер
	int getDenom() const;	// геттер
	void fractionReduction(); // метод сокращения дроби
	void printDrob() const;
	double getFraction() const;
	Drob operator+=(const Drob & b);
	~Drob(); // деструктор
};

// объявление глобальных функций операций над дробями
Drob operator+(const Drob& a, const Drob& b);
