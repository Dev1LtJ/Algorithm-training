// Слоны. Вводим 4 целых числа: это координаты двух слонов на шахматной доске. Бьют ли они друг друга?

#include <iostream>

using namespace std;

int main() {

	//initialize
	cout << "Program for chess board analysis: can one bishop beat second bishop with pre-input coordinates?" << endl;
	int firstBishopX = 0, firstBishopY = 0, secondBishopX = 0, secondBishopY = 0;

	//input
	cout << "Enter first bishop X coordinate: ";
	cin >> firstBishopX;
	cout << "Enter first bishop Y coordinate: ";
	cin >> firstBishopY;
	cout << "Enter second bishop X coordinate: ";
	cin >> secondBishopX;
	cout << "Enter second bishop Y coordinate: ";
	cin >> secondBishopY;

	//input proсessing
	if (firstBishopX > 8 || firstBishopX < 1 || firstBishopY > 8 || firstBishopY < 1 || secondBishopX > 8 || secondBishopX < 1 || secondBishopY > 8 || secondBishopY < 1) {
		cout << "Error! Coordinates must be in range [1...8]";
		return 1;
	} else {
		//logic-output
		if (((firstBishopX + firstBishopY) != (secondBishopX + secondBishopY)) && ((firstBishopX - firstBishopY) != (secondBishopX - secondBishopY))) {
			cout << "With these pre-input coordinates bishops don't beat each other!" << endl;
		} else {
			cout << "With these pre-input coordinates bishops beat each other!" << endl;
			return 0;
		}
	}
}