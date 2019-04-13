#include"Drob.h"
#include"Clock.h"

int main()
{
	setlocale(LC_ALL, "RUS");

	Drob first;
	first.setNomDenom(3, 5);
	first.printDrob();
	//first.fractionReduction();

	Drob second;
	second.setNomDenom(4, 5);
	second.printDrob();

	Drob plus = first + second;
	plus.fractionReduction();
	plus.printDrob();

	/*cout << "\n----------------------------------------------------------\n";

	Clock mytime;
	mytime.printClock();
	mytime.setHours();
	mytime.setMinutes();
	mytime.setSeconds();
	mytime.printClock();*/


	system("pause");
	return 0;
}