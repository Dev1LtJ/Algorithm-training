/* Единицы. Распечатайте все натуральные числа до m, двоичная запись которых
состоит из единиц. Программу логично разбейте на функции */

#include <iostream>
#include <cmath>
#define RESET   "\033[0m"
#define CYAN  "\033[33m"      /* Yellow */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

using namespace std;

int getDecimalNumber (unsigned long long binaryNumber);
void getDecimalSequence (int m); 

int main() {

	//initialization
	cout << endl << BOLDWHITE << "Program for printing natural numbers from 1 to M, which binary notation consists of 1." << RESET << endl;
	int m = 0;
	double mDouble = 0.0;

	//input
	cout << "Input M: " << CYAN;
	cin >> mDouble;
	m = mDouble;

	//input processing
	if (m <= 0) {
		cout << RED << "Error! A naturnal [1 ... 2 147 483 647] value must be entered! Try again." << RESET << endl;
		return 1;
	}
	if (m - mDouble !=0) {
		cout << RED << "Error! An integer values must be entered according to tehe conditions! Try again." << RESET << endl;
		return 2;
	}
	
	//logic-output
	cout << RESET << "Result sequence = ";
	getDecimalSequence (m);

	return 0;
}

void getDecimalSequence (int m) {

	unsigned long long binaryNumber = 0;

	while (true) {
		binaryNumber = binaryNumber * 10 + 1;
		if (getDecimalNumber (binaryNumber) > m) {
			break;
		}
		cout << GREEN << getDecimalNumber (binaryNumber) << " ";	
	}
}

int getDecimalNumber (unsigned long long binaryNumber) {

	int decimalNumber = 0, digit = 0, decimalNumberSum = 0, digitCounter = 0;

	while (binaryNumber > 0) {
		digit = binaryNumber % 10;
		decimalNumber = pow(2, digitCounter);
		decimalNumberSum = decimalNumberSum + decimalNumber;
		digitCounter++;
		binaryNumber = binaryNumber / 10;
	}

	return decimalNumberSum;
}