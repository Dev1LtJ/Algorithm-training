//Tasks

#include <iostream>

using namespace std;

void getFactorial();

int main() {

	getFactorial();
	return 0;
}

void getFactorial() {

	int n = 0;
	double f = 1.0;

	cout << "Input natural n, please: ";
	cin >> n;
	for (int i = 2; i <= n; i++) {
		f = f * i;
	}
	cout << f;
}