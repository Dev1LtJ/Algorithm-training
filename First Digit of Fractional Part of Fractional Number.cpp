/*Распечатайте первую цифру из дробной части вещественного числа.
(С помощью арифметических операторов и совета из занятия:))*/

#include <iostream>

using namespace std;

int main() {

	//initialize
	double var1 = 0.0;
	int var2 = 0, var3 = 0;
	
	//input
	cout << "Введите вещественное число: " << endl;
	cin >> var1;
	
	//There must be an input processing

	//logic
	var2 = var1;
	var1 = (var1 - var2)*10;
	var3 = var1;
	//output
	cout << "Первое число дробной части: " << var3;

	return 0;
}