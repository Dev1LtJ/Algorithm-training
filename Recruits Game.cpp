/*2. НОВОБРАНЦЫ. Новобранцы выстроены в шеренгу. По команде НАЛЕ–ВО! одни из них поворачиваются налево, а другие – направо. Это есть начальное положение шеренги. Далее каждый новобранец действует следующим образом: увидев перед собой лицо соседа, он ровно через секунду поворачивается кругом. В конце концов повороты прекратятся. Тогда сержант подает звуковой сигнал. */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

//colors
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define CYAN    "\033[36m"      /* Cyan */

using namespace std;

bool checkInput (char n);
void arrayOutput (char array[], int n);
void doRound (char array[], int n);

int main() {

	//initialization
	cout << endl << CYAN << "Recruits command program." << RESET;
	double recruitsNumber = 0;
	int recruitsNumberInt = 0;
	srand (time(NULL));

	//input
	while (true) {
		cout << endl << endl << "Enter a quantity of recruits: " << YELLOW;
		cin >> recruitsNumber;

		if (checkInput (recruitsNumber) == true) {
			recruitsNumberInt = recruitsNumber;
			break;
		}
	}
	char squad[recruitsNumberInt];
	

	//Squad filling before command 'Left!' and output
	for (int i = 0; i < recruitsNumber; i++) {
		squad[i] = '^';
	}
	cout << endl << RESET << "Position of recruits before command 'Left!': " << GREEN << endl;
	arrayOutput (squad, recruitsNumber);

	//Squad random filling after command 'Left!' and output
	int randomNumber = 0;
	for (int i = 0; i < recruitsNumber; i++) {
		randomNumber = rand() % 2;
		if (randomNumber == 1) {
			squad[i] = '<';
		} else {
			squad[i] = '>';
		}
	}
	cout << endl << RESET << "Sergeant: " << YELLOW << "Left!" << RESET << endl;
	cout << endl << "Position of recruits after command 'Left!': " << endl << GREEN;
	arrayOutput (squad, recruitsNumber);
	

	//logic
	doRound (squad, recruitsNumber);
	cout << endl << endl << RESET << "Sergeant: " << YELLOW << "\aStop!" << RESET << endl;

	//ending
	return 0;
}

bool checkInput (char n) {

	int recruitsNumberInt = n;

	if (n - recruitsNumberInt == 0) {
		return true;
	} else {
		cout << RED << "Error! You must enter an integer value! Try  again." << RESET;
		return false;
	} 
}

void arrayOutput (char array[], int n) {

	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
}

void doRound (char array[], int n) {

	int counter = 0;

	//testcycle
	while (true) {
		
		bool doBreak = true;

		for (int i = 0; i < n; i++) {
			if (array[i] == '>' && array[i + 1] == '<') {
				array[i] = '<';
				array[i + 1] = '>';
				doBreak = false;
			} 
		}

		counter++;

		//break conditions
		if (doBreak == true) {
			break;
		}

		cout << endl << endl << RESET << "Position after " << YELLOW << counter << RESET << " rotation:" << GREEN << endl;
		arrayOutput (array, n);
	}
}

