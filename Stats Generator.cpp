#include <iostream>
#define N 13
#define TEST 1000000

using namespace std;

int rollDice();

int main() {

	//initialization
	int stat[N]= {0};
	int i = 0;

	//logic
	for (i = 0; i < TEST; i++) {
		stat[rollDice()]++;
	}

	for (i = 2; i < N; i++) {
		cout.width(2);
		cout << i << ": ";
		cout.width(6);
		cout << stat[i];
		cout.width(6);
		cout.precision(3);
		cout << 100.0 * stat[i] / TEST << " %" << endl;
	}
	

	//ending
	return 0;
}

int rollDice() {
	return (1 + rand() % 6) + (1 + rand() % 6);
}