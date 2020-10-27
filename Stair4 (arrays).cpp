// Массив из 7 элементов:
// 1) Функция, которая печатает этот массив (+);
// 2) Функция, которая печатает этот массив в обратном порядке (+);
// 3) Функция, которая вычисляет сумму элементов массива (+);
// 4) Функция, которая вычисляет произведение элементов массива (+);
// 5) Функция, которая определяет, какой элемент самый средний (ближе всего к среднему арифметическому) (+);
// 6) Функция поиска (содержит ли массив заданный ключ) (+).
// 7) Функция, которая меняет местами минимальный и максимальный элемент (+).
// 8)* "Колокол" - самый большой элемент печатаем первым, 2 последнием , 3 вторым, 4 предпоследним и т.д. (по центру будет минимальный элемент) ().

#include <iostream>
#include <cmath>

//colors
#define RESET   "\033[0m"
#define YELLOW  "\033[33m"      /* Yellow */
#define GREEN   "\033[32m"      /* Green */
#define CYAN    "\033[36m"      /* Cyan */
#define RED     "\033[31m"      /* Red */

#define SIZE 7

using namespace std;

void printArray(int array[]); //Task1
void printArrayRevert(int array[]); //Task2
int getArraySum(int array[]); //Task3
int getArrayMult(int array[]); //Task4
int averageArrayDeterm (int array[]); //Task5
bool elementMassiveFinder (int array[], int number); //Task6
void maxAndMinElementsSwitcher (int massive[]); //Task7
void bellMaker (int array[]); //Task8

int main() {

	//init
	cout << endl << endl << CYAN << "Ladder" << RESET;
	int array[SIZE] = {1, 2, 3, 4, 5, 6, 7};


	//Task1 (+)
	cout << endl << endl << "Task 1 (print default array):" << endl << GREEN;
	printArray(array);

	//Task2 (+)
	cout << endl << endl << RESET <<  "Task 2 (print revert array): " << endl << YELLOW;
	printArrayRevert(array);

	
	//Task3 (+)
	int sum = 0;
	cout << endl << endl << RESET << "Task 3 (get sum of array elements):" << endl;
	sum = getArraySum(array);
	cout << "Sum of array = " << YELLOW << sum;
	
		
	//Task4 (+)
	int mult = 0;
	cout << endl << endl << RESET << "Task 4 (get multiply of array elements):" << endl;
	mult = getArrayMult(array);
	cout << "Multiply of array = " << YELLOW << mult;
	
	//Task5 (+)
	int averageElement = 0;
	cout << endl << endl << RESET << "Task 5 (get average element of array):" << endl;
	averageElement = averageArrayDeterm (array);
	cout << "array[" << YELLOW << averageElement << RESET << "] = " << GREEN << array[averageElement];

	
	//Task6 (+)
	int numberToFind = 0;
	cout << endl << endl << RESET << "Task 6 (number checker): " << endl;
	cout << "Input a number, which you need to find: " << YELLOW;
	cin >> numberToFind;
	if (elementMassiveFinder (array, numberToFind) == true) {
		cout << GREEN << "Good! Massive contains this number!";
	} else {
		cout << RED << "Sorry! Massive doesn't contains this number!";
	}

	
	//Task7 (+)
	cout << endl << endl << RESET << "Task 7 (switch Max and Min element):" << endl << YELLOW;
	maxAndMinElementsSwitcher(array);
	printArray(array);

	//Task8
	cout << endl << endl << RESET << "Task 8 (do a bell):" << YELLOW << endl;
	bellMaker(array);

	//ending
	return 0;
}

//Task1 (print default array)
void printArray (int array[]) {

	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << " ";
	}
}


//Task2 (print revert array)
void printArrayRevert (int array[]) {

	for (int i = SIZE - 1; i >= 0; i--) {
		cout << array[i] << " ";
	}
}


//Task3
int getArraySum(int array[]) {
	
	int sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum = sum + array[i];
	}

	return sum;
}


//Task4
int getArrayMult(int array[]) {

	int mult = 1;
	for (int i = 0; i < SIZE; i++) {
		mult = mult * array[i];
	}

	return mult;
}



//Task5
int averageArrayDeterm (int array[]) {

	double average = 0.0;
	double sum = 0.0;

	sum = getArraySum(array);
	average = sum / SIZE;

	int indexOfElement = 0;
	for (int i = 0; i < SIZE; i++) {
		if (abs(average - array[i]) <= abs(average - array[indexOfElement])) {
			indexOfElement = i;
		}
	}

	return indexOfElement;
}


//Task6
bool elementMassiveFinder (int array[], int number) {

	for (int i = 0; i < SIZE; i++) {
		if (array[i] == number) {
			return true;
		}
	}
	return false;
}


//Task7
void maxAndMinElementsSwitcher (int array[]) {
	
	int max = 0;
	int min = 0;
	int buffer;

	for (int i = 0; i < SIZE; i++) {
		if (array[i] > array[max]){
			max = i;
		}
		if (array[i] < array[min]) {
			min = i;
		}
	}

	buffer = array[min];
	array[min] = array[max];
	array[max] = buffer;
}


//Task8
void bellMaker (int array[]) {

	int newArray[SIZE] = {0};
	int idOdd = 0;
	int idEven = 0;
	int maxIndex = 0;
	int minIndex = 0;
	int whilecounter = 0;

	while (whilecounter < SIZE) {

		for (int i = 0; i < SIZE; i++) {
			if (array[i] > array[maxIndex]) {
				maxIndex = i;
			} else if (array[i] < array[minIndex]) {
				minIndex = i;
			}
		}
	
		if (whilecounter % 2 == 0) {
			newArray[idOdd] = array[maxIndex];
			idOdd++;
		} else {
			newArray[SIZE - 1 - idEven] = array[maxIndex];
			idEven++;
		}
		
		array[maxIndex] = array[minIndex];
		whilecounter++;
	}	

	printArray(newArray);
}