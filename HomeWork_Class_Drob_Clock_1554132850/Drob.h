#pragma once
#include<iostream>

using namespace std;

class Drob
{
private:
	int *numerator;
	int *denominator;

public:
	Drob(int a = 0, int b = 0);	// ����������� � �����������
	Drob(const Drob & obj); // ����������� �����������
	void setNomDenom(int a, int b);	// ������
	int getNom() const;	// ������
	int getDenom() const;	// ������
	void fractionReduction(); // ����� ���������� �����
	void printDrob() const;
	double getFraction() const;
	Drob operator+=(const Drob & b);
	~Drob(); // ����������
};

// ���������� ���������� ������� �������� ��� �������
Drob operator+(const Drob& a, const Drob& b);
