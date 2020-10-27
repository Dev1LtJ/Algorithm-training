// a (int): Y, if odd; N, if even;  (+)
// a, b: Y if both odd, N if even in all (+)
// a, b: Y same odd or same even (+)
// n: Y - prime (простое, которое делится только на себя и на единицу) (+)
// a, b: НОД (+)
// a, b: НОК (+)

#include <iostream>
#define RESET   "\033[0m"
#define BLUE    "\033[34m"      /* Blue */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define CYAN    "\033[36m"      /* Cyan */
#define MAGENTA "\033[35m"      /* Magenta */
#define RED     "\033[31m"      /* Red */

using namespace std;

void Task1 (int a);
void Task2 (int a, int b);
void Task3 (int a, int b);
int Task4 (int a);
void Task5 (int a, int b);
void Task6 (int a, int b);

int main() {
	
	//initialization
	int a = 0, b = 0;

	
	//task1
	cout << BLUE << "Task 1." << RESET << " Input A: ";
	cin >> a;
	Task1 (a);

	//task2
	cout << GREEN << "Task 2." << RESET << " Input A: ";
	cin >> a;
	cout << GREEN << "Task 2." << RESET << " Input B: ";
	cin >> b;
	Task2 (a, b);

	//task3
	cout << YELLOW << "Task 3." << RESET << " Input A: ";
	cin >> a;
	cout << YELLOW << "Task 3." << RESET << " Input B: ";
	cin >> b;
	Task3 (a, b);

	//task4
	cout << CYAN << "Task 4." << RESET << " Input A: ";
	cin >> a;
	Task4 (a);

	//task5
	cout << MAGENTA << "Task 5." << RESET << "Input A: ";
	cin >> a;
	cout << MAGENTA << "Task 5." << RESET << "Input B: ";
	cin >> b;
	Task5 (a, b);


	//task6
	cout << RED << "Task 6." << RESET << " Input A: ";
	cin >> a;
	cout << RED << "Task 6." << RESET << " Input B: ";
	cin >> b;
	Task6 (a, b);

	return 0;
}

void Task1 (int a) {

	if (a % 2 == 0) {
		cout << GREEN << "Answer: Y" << RESET << endl;
	} else {
		cout << RED << "Answer: N" << RESET << endl;
	}
}

void Task2 (int a, int b) {

	if (a % 2 == 0 && b % 2 == 0) {
		cout << GREEN << "Answer: Y" << RESET << endl;
	} else {
		cout << RED << "Answer: N" << RESET << endl;
	}
}

void Task3 (int a, int b) {

	if ((a % 2 == 0 && b % 2 == 0) || (a % 2 !=0 && b % 2 !=0)) {
		cout << GREEN << "Answer: Y" << RESET << endl;
	} else {
		cout << RED << "Answer: N" << RESET << endl;
	}
}

int Task4 (int a) {

	//local var
	int c = 2;

	while (c < a){
		if (a % c == 0) {
			cout << YELLOW << a << RED << " is not a prime number!" << RESET << endl;
			return 0;
		}
		c++;
	}
	cout << YELLOW << a << GREEN << " is a prime number!" << RESET << endl;
	return 0;
}

void Task5 (int a, int b) {

	//local var
	int c = 0;

	if (a > b) {
		c = a;
	} else {
		c = b;
	}

	while (true) {
		if ((a % c == 0) && (b % c == 0)) {
			cout << "НОД: " << GREEN << c << endl;
			break;
		}
		c--;
	}
}

void Task6 (int a, int b){

	//local var
	int c = 0;

	if (a > b) {
		c = a;
	} else {
		c = b;
	}

	while (true) {
		if ((c % a == 0) && (c % b == 0)){
			cout << "НОД: " << GREEN << c << endl;
			break;
		}
		c++;
	}
}