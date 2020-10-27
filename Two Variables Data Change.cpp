/* Есть две переменные. Заставьте их поменяться значениями(т.е. a = 5, b = 10 => a = 10, b = 5).
Решите задачу 2 способами (1-ый с использование буфера, 2-ой с использованием математических операций) */

#include <iostream>

using namespace std;

int main() {
  
	//initialize
	int a = 0, b = 0, buff = 0, c = 0, d = 0;

	//input
	cout << "Введите число а: " << endl;
	cin >> a;
	cout << "Введите число b: " << endl;
	cin >> b;

	//logic_1
	c = a;
	d = b; 
	buff = a;
	a = b;
	b = buff;

	//logic_2
	c = d + c;
	d = c - d;
	c = c - d;

	//output
	cout << "По методу буфера: a = " << a << ", b = " << b << endl;
	cout << "По методу мат. операций: a = " << c << ", b = " << d;
	return 0;
}