// void count() - считает (печатает) от 1 до 10
// void count(int n) - считает (печатает) от 1 до n
// void count (int n, int m) - считает (печатает) от n до m
// int getSum(int n, int m) - возвращает сумму чисел от n до m
// int getAverage(int n, int m) - возвращает среднее арифметическое, используя п. 4

#include <iostream>
#define RESET   "\033[0m"
#define YELLOW  "\033[33m"      /* Yellow */
#define CYAN    "\033[36m"      /* Cyan */
#define GREEN   "\033[32m"      /* Green */
#define MAGENTA "\033[35m"      /* Magenta */
#define RED     "\033[31m"      /* Red */
#define BLUE    "\033[34m"      /* Blue */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

using namespace std;

void count();
void count(int n);
void count(int n, int m);
int getSum(int n, int m);
double getAverage(int n, int m);

int main() {

	int n = 0, m = 0, sum = 0;

	//task1
	cout << endl << BOLDWHITE << "Task 1. Program for counting from 1 to 10." << RESET << endl;
	count();

	//task2
	cout << endl << endl << BOLDWHITE << "Task 2. Program for counting from 1 to N." << RESET << endl;
	cout << "Input N: ";
	cin >> n;
	count(n);

	//task3
	cout << endl << endl << BOLDWHITE << "Task 3. Program for counting from N to M." << RESET << endl;
	cout << "Input N: ";
	cin >> n;
	cout << "Input M: ";
	cin >> m;
	count(n, m);

	//task4
	cout << endl << endl << BOLDWHITE << "Task 4. Program for summ numbers from N to M." << RESET << endl;
	cout << "Input N: ";
	cin >> n;
	cout << "Input M: ";
	cin >> m;
	cout << "Result = " << MAGENTA << getSum(n, m) << RESET;

	//task5
	cout << endl << endl << BOLDWHITE << "Task 5. Program for calculation average of numbers from N to M." << RESET << endl;
	cout << "According to the task 4: N = " << RED << n << RESET << ", M = " << RED << m << RESET << "." << endl;
	cout << "Result = " << BLUE << getAverage(n, m) << RESET;

	return 0;
}

//task1
void count() {
	
	for (int i = 1; i < 11; i++) {
		cout << YELLOW << i << RESET << " ";
	}
}

//task2
void count(int n) {

	if (n > 1) {
		
		for (int i = 1; i <= n; i++) {
			cout << CYAN << i << RESET << " "; 
		}
	} else {
		for (int i = 1; i >= n; i--) {
			cout << CYAN << i << RESET << " ";	
		}
	}
}

//task3
void count(int n, int m) {

	if (n > m) {
		for (n; n >= m; n--) {
			cout << GREEN << n << RESET << " "; 
		}
	} else {
		for (n; n <= m; n++) {
			cout << GREEN << n << RESET << " "; 
		}
	}
}

//task4
int getSum(int n, int m) {

	int sum = 0;

	for (n; n <= m; n++) {
		sum = sum + n;
	}

	return sum; 
}

//task5
double getAverage(int n, int m) {

	int counterAverage = 0;
	double sum = 0;

	sum = getSum(n, m);

	for (n; n <= m; n++) {
		counterAverage++;
	}

	return sum / counterAverage;
}