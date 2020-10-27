/* Макс. из трех переменных */

#include <iostream>

using namespace std;

int main() {

	//initialize
	cout << "Program for calculation of max of three variables" << endl;
	int a = 0, b = 0, c = 0, max = 0;

	//input
	cout << "Enter a = ";
	cin >> a;
	cout << "Enter b = ";
	cin >> b;
	cout << "Enter c = ";
	cin >> c;

	//there must be an input processing

	//logic
	max = a;
	if (b > max) {
		max = b;
	};
	if (c > max) {
		max = c;
	};

	//output
	cout << "Max from a, b, c is " << max;
	
	return 0;
}