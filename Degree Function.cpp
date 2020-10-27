// Степень. Разработайте функцию, котора возводит x в степень n

#include <iostream>
#include <cmath>
#define RESET   "\033[0m"
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define YELLOW  "\033[33m"      /* Yellow */
#define GREEN   "\033[32m"      /* Green */

using namespace std;

double getDegree (double x, double n);
double getCheck (double x, double n);

int main() {

	//initialization
	cout << endl << BOLDWHITE << "Program for raising x to the degree of N." << RESET << endl;
	int nInt = 0;
	double x = 0.0, n = 0.0;

	//input
	cout << "Input X: " << YELLOW;
	cin >> x;
	cout << RESET << "Input N: " << YELLOW;
	cin >> n;

	//input processing
	nInt = n;
	if (nInt - n !=0) {
		cout << "Error! Program works with integer N. Try again" << endl;
		return 1;
	}

	//logic-output
	cout << RESET << "Result = " << GREEN << getDegree(x, n) << RESET << endl;
	cout << RESET << "PowCheck = " << GREEN << getCheck(x, n) << RESET << endl;

	return 0; 
}

double getDegree (double x, double n) {

	double local = x;

	if (n == 0) {
		x = 1;
	} else if (n > 0) {
		for (int i = 2; i <= n; i++) {
			x = x * local;
	} 
	} else {
		n = abs(n);
		for (int i = 2; i <= n; i++) {
			x = x * local;
		}
		x = 1 / x;
	}

	return x;
}

double getCheck (double x, double n) {
	return pow(x, n);
}

