/* ФИБОНАЧЧИ. Исследуйте в интернете, как строится ряд чисел Фибоначчи.
Попробуйте самостоятельно разработать алгоритм, печатающий n первых чисел */

#include <iostream>
#include <cmath>
#define BOLDWHITE "\033[1m\033[37m"      /* Bold White */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define RESET "\033[0m"

using namespace std;

int main() {

	//initialization
	cout << endl << BOLDWHITE << "Fibonacci's generator" << RESET << endl << endl;
	int n = 0, fibonaccisNumber = 0, fibonaccisCounter = 0, sequenceCounter = 0;
	double nDouble = 0.0;

	//input
	cout << "Input how much of Fibonacci's sequence " << BOLDBLUE <<  "first digits" << RESET << " you want to see: ";
	cin >> nDouble;


	//inputs processing
	n = nDouble;
	if (n == 1) {
		cout << endl << BOLDRED << "Important! First element of Fibonacci's sequence have 2 numbers" << RESET << endl;
	} else if (n == 0) {
		cout << endl << "There is no elements, coz your input " << BOLDCYAN << n << RESET << "." <<endl;
		return 0;
	} else if (n < 0) {
		cout << endl << BOLDRED "Error! input number can't be less then 0" << RESET << endl;
		return 1;
	} else if (n - nDouble !=0) {
		cout << "There is integer values must be entered according to the conditions" << endl;
		return 2;
	}	

	//logic-output
	cout << endl << "First " << BOLDCYAN << n << RESET << " element(s) of Fibonacci's sequence: " << endl;
	while (true) {
		fibonaccisNumber = (pow((1 + sqrt(5)) / 2, sequenceCounter) - pow((1 - sqrt(5)) / 2, sequenceCounter)) / sqrt(5);
		cout << fibonaccisNumber << " ";
		if (fibonaccisCounter == n) {
			break;
		}
		sequenceCounter++;
		fibonaccisCounter++;
	}

	return 0;
}