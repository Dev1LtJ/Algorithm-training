#include <iostream>

using namespace std;

int main() {

	int i;

	for (i = 1; i <= 6; i++) { // 1 2 3 4 5 6
		cout << i << " ";
	}
	cout << endl;
	for (i=1; i <= 11; i = i + 2) { // 1 3 5 7 9 11
		cout << i << " ";
	}
	cout << endl;
	for (i = - 5; i <= 10; i = i + 3) { // -5 -2 1 4 7 10
		cout << i << " ";
	}
	cout << endl;
	for (i = 6; i > 0; i--) { // 6 5 4 3 2 1
		cout << i << " ";
	}
	cout << endl;
	for (i = 1; i <= 6; i++) { // 1 4 9 16 25 36
		cout << i * i << " ";
	}
	cout << endl;
	int c = 0;
	for (i = 1; i <= 16; i = i + c) { // 1 2 4 7 11 16
		cout << i << " ";
		c = c + 1;
	}

	return 0;
}