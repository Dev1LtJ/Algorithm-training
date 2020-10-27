//ПОЛЕ ЧУДЕЕС. Запрограммируйте игру: открывает буквы, угадывает слово, в конце - шутка Якубовича.

#include <iostream>
#include <cstring>

//colors
#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */
#define CYAN    "\033[36m"      /* Cyan */
#define YELLOW  "\033[33m"      /* Yellow */
#define RED     "\033[31m"      /* Red */
#define BOLDWHITE   "\033[1m\033[37m" 

using namespace std;

void printBoard (char board[], int len);
bool checkInput (char board[], int len, char letter[]);
void doUpperLetter (char letter[]);
void doUpperWord (char word[]);
int searchNumber (char boardWithwinWord[], char letter[]);
bool tryToGuessWholeWord (char boardWithGuessWord[], char boardWithwinWord[]);
bool checkWin (char board[], char boardWithwinWord[]);

int main() {

	//init
	cout << endl << CYAN << "Filed of Dreams Game v.1" << RESET << endl << endl;
	char letter[] = "";
	char user;
	int boardNumber = 0; 
	char winWord[] = "EYJAFJALLAJOKULL";
	int len = strlen(winWord);
	char board[128] = "";
	char boardWithGuessWord[128] = "";
	cout << "Initial clean board: " << endl;
	printBoard(board, len);

	while (true) {
		
		//input-letter cycle
		while (true) {
			cout << endl << endl << RESET << "Input letter: " << YELLOW;
			cin >> letter;
			if (checkInput (board, len, letter) == true) {
				break;
			}
		}
		//input a letter on board
		if (strstr(winWord, letter)) {
			boardNumber = searchNumber (winWord, letter);
			cout << GREEN << "Bingo! This word has this letter!" << RESET << endl << endl;
			board[boardNumber] = letter[0];
			printBoard(board, len);
			//check for win word
			if (checkWin (board, winWord) == true) {
				return 0;
			}
			//guess whole word
			cout << endl << endl << "Want to try to guess the whole word?" << endl;
			cout << "Press " << GREEN << 'Y' << RESET " - to " << GREEN << "yes." << RESET << endl;
			cout << "Press " << CYAN << "any symbol" << RESET << " to " <<  CYAN << "continue" << RESET << " the game." << endl;
			cout << "Your choice: " << YELLOW;
			cin >> user;		

			if (user == 'Y' || user == 'y') {
				cout << endl << GREEN << "OK!" << RESET << " Enter the whole word: " << YELLOW;
				cin >> boardWithGuessWord;
				doUpperWord(boardWithGuessWord);
				if (tryToGuessWholeWord (boardWithGuessWord, winWord)== true) {
					return 0;
				} else {
					printBoard(board, len);
				}
			} else {
				cout << endl << CYAN << "OK! Continue the game!" << RESET << endl;
			}
		} else {
			cout << endl << RED << "There is no this letter in this word. Try again:)" << RESET << endl;
		}
	}
}

void printBoard (char board[], int len) {

	for (int i = 0; i < len; i++) {
		cout << BOLDWHITE "| " << RESET << board[i] << " ";
	}
	cout << BOLDWHITE "|" << RESET;
}

bool checkInput (char board[], int len, char letter[]) {

	//check for one-symbol input
	if (strlen(letter) != 1) {
		cout << "Error! You can input only one letter per turn! Try again.";
		return false;
	}

	doUpperLetter(letter);

	//check for already entered values
	for (int i = 0; i < len; i++) {
		if (board[i] == letter[0]) {
			cout << RED << "Error! You already input this letter! Try again." << RESET;
			return false;
		}
	}

	return true;
}

void doUpperLetter (char letter[]) {

	char lowerLetter = 'a';
	char upperLetter = 'A';
	do {
		if (letter [0] == lowerLetter) {
			letter [0] = upperLetter;
			break;
		}
		lowerLetter++;
		upperLetter++;
	} while (lowerLetter <= 'z');
}

int searchNumber (char boardWithwinWord[], char letter[]) {

	for (int i = 0; boardWithwinWord[i] != '\0'; i++) {
		if (boardWithwinWord[i] == letter[0]) {
			return i;
		}
	}
}

bool tryToGuessWholeWord (char boardWithGuessWord[], char boardWithwinWord[]) {
	
	if (strlen(boardWithGuessWord) == strlen(boardWithwinWord) && checkWin (boardWithGuessWord, boardWithwinWord) == true) {
		return true;
	} else {
		cout << RED << endl << "Sorry! This is incorrect word! Continue the game." << RESET << endl << endl;
		return false;
	}
}

bool checkWin (char board[], char boardWithwinWord[]) {

	for (int i = 0; boardWithwinWord[i] != '\0'; i++) {
		if (boardWithwinWord[i] != board[i]){
			return false;
		}
	}
	cout << endl << GREEN << "Correct word! Congratulations, you win!" << RESET;
	cout << endl << CYAN << "Leonid Yakubovich's washing machine broke down and he forced his wife to spin the drum:))" << RESET;
	return true;
}

void doUpperWord (char word[]) {

	int i = 0;
	char lowerLetter = 'a';
	char upperLetter = 'A';

	for ( i = 0; word[i] != '\0'; i++) {

		lowerLetter = 'a';
		upperLetter = 'A';
		do {
			if (word [i] == lowerLetter) {
				word [i] = upperLetter;
				break;
			}
			lowerLetter++;
			upperLetter++;
		} while (lowerLetter <= 'z');
	}
	
}