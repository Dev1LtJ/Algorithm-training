/*Вводим 4 целых числа. это координаты двух коней на шахматной доске. Бьют ли они друг друга? */

#include <iostream>
#include <cmath>

using namespace std;

int main() {

	//initialize
	cout << "Program for chess board analysis: can one horse beat second horse with pre-input coordinates?" << endl;
	int firstHorseX = 0, firstHorseY = 0, secondHorseX = 0, secondHorseY = 0;

	//input
	cout << "Enter first horse X coordinate: ";
	cin >> firstHorseX;
	cout << "Enter first horse Y coordinate: ";
	cin >> firstHorseY;
	cout << "Enter second horse X coordinate: ";
	cin >> secondHorseX;
	cout << "Enter second horse Y coordinate: ";
	cin >> secondHorseY;

	//input proсessing
	if (firstHorseX > 8 || firstHorseX <= 0 || firstHorseY > 8 || firstHorseY <= 0 || secondHorseX > 8 || secondHorseX <= 0 || secondHorseY > 8 || secondHorseY <= 0) {
		cout << "Error! Values must be in range [1...8]";
	} else {
		//logic-output
		if ( (abs(firstHorseX - secondHorseX) == 2) && (abs(firstHorseY - secondHorseY) == 1) ) {
			cout << "With these pre-input coordinates horses beat each other!";
		} else if ( (abs(secondHorseX - firstHorseX) == 2) && (abs(secondHorseY - firstHorseY) == 1) ){
			cout << "With these pre-input coordinates horses beat each other!";
		} else if ( (abs(firstHorseX - secondHorseX) == 1) && (abs(firstHorseY - secondHorseY) == 2) ) {
			cout << "With these pre-input coordinates horses beat each other!";
		} else if ( (abs(secondHorseX - firstHorseX) == 1) && (abs(secondHorseY - firstHorseY) == 2) ) {
			cout << "With these pre-input coordinates horses beat each other!";
		} else {
			cout << "With these pre-input coordinates horses don't beat each other!";
		};
	};
	return 0;
}