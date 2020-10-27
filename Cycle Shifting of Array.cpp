/* 1. СДВИГ. Сделайте циклический сдвиг массива из n элементов на m позиций влево.*/

#include <iostream>
#include <cmath>

//colors
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define CYAN    "\033[36m"      /* Cyan */
#define YELLOW  "\033[33m"      /* Yellow */

using namespace std;

bool checkInput (double n);
void printArray (int array[], int n);
void doShift (int array[], int n, int m);
int getTrueShiftNumber (int n, int m);
void returnArray (int array[], int newArray[], int n);

int main() {

	//initialization
	cout << endl << CYAN << "Program for cycle shifting array of " << YELLOW << "N" << CYAN << " elements for " << GREEN << "M" << CYAN << " positions left." << RESET;
	double n = 0;
	int nInt = 0;
	double m = 0;
	int mInt = 0;

	//input processing
	while (true) {

		cout << endl << endl << "Input N: " << YELLOW;
		cin >> n;
		n = abs(n);
		if (checkInput (n) == true) {
			nInt = n;
			break;
		}
	}
	
	int array[nInt];

	//original array filling and output
	for (int i = 0; i < nInt; i++) {
		array[i] = i + 1;
	}
	cout << RESET << "Original Array: " << YELLOW;
	printArray (array, nInt);

	//logic
	while (true) {
		cout << endl << endl << RESET << "Input M: " << GREEN;
		cin >> m;
		m = abs(m);
		if (checkInput (m) == true) {
			mInt = m;
			break;
		} 
	}
	doShift (array, nInt, mInt);
	cout << RESET << "Shift Array: " << GREEN;
	printArray (array, n);

	//ending
	return 0;
}

bool checkInput (double n) {

	int nInt = n;
	
	if (n - nInt == 0) {
		return true;
	} else {
		cout << RED << "Error! You must enter an integer value! Try  again." << RESET;
		return false;
	}
}


void printArray (int array[], int n) {

	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
}


void doShift (int array[], int n, int m) {

	int counter = 0;
	int newArray[n];

	m = getTrueShiftNumber (n, m);

	for (int i = 0; i < n; i++) {
		if (i + m >= n) {
			newArray[i] = array[counter];
			counter++;
		} else {
			newArray[i] = array[i + m];
		}
	}
	
	returnArray (array, newArray, n);
}


int getTrueShiftNumber (int n, int m) {
	
	if (m > n) {
		m = m % n;
	}
	return m;
}

void returnArray (int array[], int newArray[], int n) {

	for (int i = 0; i < n; i++) {
		array[i] = newArray[i];
	}
}