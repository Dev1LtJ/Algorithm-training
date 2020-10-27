/* РАЗРЯДЫ. Напишите программу, которая из введенного натурального числа формирует второе,
с "перевернутыми" разрядами и печатает его. Ввели 1234, вывелось 4321. */

#include <iostream>
#define RED     "\033[31m"      /* Red */
#define YELLOW  "\033[33m"      /* Yellow */
#define GREEN   "\033[32m"      /* Green */
#define BOLDWHITE "\033[1m\033[37m"      /* Bold White */
#define RESET "\033[0m"

using namespace std;

int main() {
	
	//initialization
	cout << endl << BOLDWHITE << "Program for flipping the digits" << RESET << endl << endl;
	int number = 0, digit = 0, reverseNumberSumm = 0;
	double numberDouble = 0.0;


	//input
	cout << "Input a number: " << YELLOW;
	cin >> numberDouble;
	number = numberDouble;

	//input processing
	if (number <= 0){
		cout << RED << "Error! Input number must be in range [1 ... 2 147 483 647]." << RESET << endl;
		return 1;
	} else if (numberDouble != number) {
		cout << RED << "Error! Input number must be an integer value." << RESET << endl;
		return 2;
	}

	//logic
	while (number > 0) {
		digit = number % 10;
		reverseNumberSumm = reverseNumberSumm * 10 + digit;
		number = number / 10;
	}

	//output
	cout << RESET << "Reverse number: " << GREEN << reverseNumberSumm << endl;
	return 0;
}