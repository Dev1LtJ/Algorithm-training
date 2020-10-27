#include <iostream>

using namespace std;

int linearSearch(int array[], int n, int key);
void bubbleSort (int array[], int n);
void printArray (int array[], int n);

int main() {

	//initialization
	int n = 6;
	int array[6] = {3, 2, 9, 1, 8, 5};
	int key = 9;
	int indexKey = 0;

	//task1 (Linear search)
	cout << "Task 1. Linear Search: " << endl;
	indexKey = linearSearch(array, n, key);
	cout << "IndexKey = " << indexKey << endl << endl;

	//task2 (Bubble sort)
	cout << "Task 2. Bubble Sort: " << endl;
	bubbleSort (array, n);
	printArray(array, n);

	//ending
	return 0;
}

int linearSearch(int array[], int n, int key) {

	for (int i = 0; i < n; i++) {
		if (array[i] == key) {
			return i;
		}
	}
	return -1;
}

void bubbleSort (int array[], int n) {

	for (int j = 1; j < n; j++) {
		for (int i = 0; i < n - j; i++) {
			if (array[i] > array[i + 1]) {
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
}

void printArray (int array[], int n) {

	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
}