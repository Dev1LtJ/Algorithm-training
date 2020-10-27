/* 3. КРЕСТИКИ-НОЛИКИ.  Запрограммируйте и сыграйте с компьютером в игру "Крестики-нолики"! */

#include <iostream>

//colors
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define CYAN    "\033[36m"      /* Cyan */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

using namespace std;

void printBoard (char array[], int n);
void printCleanBoard (char array[], int n);
bool checkTurn (char array[], int n, int turn);
void printBoardAfterTurn (char array[], int n, int turn, char symbol);
bool checkWin (char array[], int n, int turn, char symbol);
bool checkDraw (int counter);
int doAITurn(char array[], int n, char huSymbol, char aiSymbol);

int main() {

	//initialization
	cout << endl << CYAN << "Tic-Tac-Toe game v.1!" << RESET << endl << endl;
	int n = 9;
	char board[n];

	//filling board & output
	for (int i = 1; i <= n; i++) {
		board[i] = ' ';
	}
	cout << MAGENTA << "Board and cells adress look like this: " << RESET << endl << endl;
	printBoard(board, n);
	
	//Clean (start) board output
	cout << endl << GREEN << "Let's start the game!" << RESET << endl << endl;
	printCleanBoard(board, n);

	//logic
	int huPlayer = 0;
	int aiPlayer = 0;
	int counter = 0;
	while (true) {

		//PlayerTurn
		while (true) {
			cout << endl << YELLOW << " Your turn: " << RESET;
			cin >> huPlayer;
			if (checkTurn(board, n, huPlayer) == true) {
				printBoardAfterTurn (board, n, huPlayer, 'X');
				break;
			}
		}
		counter++;
		
		//CheckWin
		if (checkWin(board, n, huPlayer, 'X') == true) {
			cout << endl << GREEN << "---You win!---" << RESET;
			break;
		}
		if (checkDraw(counter) == true) {
			break;
		}
		
		//AiTurn
		aiPlayer = doAITurn (board, n, 'X', 'O');
		cout << endl << BLUE << " AI turn: " << RESET << aiPlayer << endl;
		printBoardAfterTurn (board, n, aiPlayer, 'O');
		
		counter++;

		//CheckWin
		if (checkWin(board, n, aiPlayer, 'O') == true) {
		cout << endl << GREEN << "---AI wins!---" << RESET;
		break;
		}

		if (checkDraw(counter) == true) {
			break;
		}
	}
	
	//ending
	return 0;
}

void printBoard (char array[], int n) {
	
	for (int i = 1; i <= n; i++) {
	
		cout << BOLDWHITE << "| " << RESET << i << " ";
		if (i % 3 == 0) {
			cout << BOLDWHITE << "|" << RESET << endl;
			if (i != n) {
				cout << BOLDWHITE << " ———————————" << RESET << endl;
			}
		}
	}
}

void printCleanBoard (char array[], int n) {
	
	for (int i = 1; i <= n; i++) {
	
		cout << BOLDWHITE << "| " << RESET << array[i] << " ";
		if (i % 3 == 0) {
			cout << BOLDWHITE << "|" << RESET << endl;
			if (i != n) {
				cout << BOLDWHITE << " ———————————" << RESET << endl;
			}
		}
	}
}

bool checkTurn(char array[], int n, int turn) {

	while (true) {
		if (turn > 0 && turn < 10) {
			if (array[turn] != ' ') {
				cout << RED << "Error! The cell is already filled! Try again." << RESET << endl;
				return false;
			} else {
				return true;
			}
		} else {
			cout << RED << "Error! You must input a number from 1 to 9! Try again." << RESET << endl;
			return false;
		}
	}
}



void printBoardAfterTurn (char array[], int n, int turn, char symbol) {

	array[turn] = symbol;

	for (int i = 1; i <= n; i++) {
		cout << BOLDWHITE << "| " << RESET << array[i] << " ";
			if (i % 3 == 0) {
				cout << BOLDWHITE << "|" << RESET << endl;
			if (i != n) {
				cout << BOLDWHITE << " ———————————" << RESET << endl;
			}
		}
	}
}


bool checkWin (char array[], int n, int turn, char symbol) {

	int counter = 0;

	for (int i = 1; i <= 3; i++) {

		//columns
		if (array[i] == symbol && array[i + 3] == symbol && array [i + 6] == symbol) {
			return true;
		//rows
		} else if (array[i + (counter * 2)] == symbol && array[i + 1 + (counter * 2)] == symbol && array [i + 2 + (counter * 2)] == symbol){
			return true;
		}
		counter++;
	}

	//diagonals
	if (array[1] == symbol && array[5] == symbol && array[9] == symbol) {
		return true;
	} else if (array[3] == symbol && array[5] == symbol && array[7] == symbol) {
		return true;
	}
	return false;
}


bool checkDraw (int counter) {
	if (counter == 9) {
		cout << endl << CYAN << "---Draw! Nobody won!---" << RESET << endl;
		return true;
	}
	return false;
}


int doAITurn(char array[], int n, char huSymbol, char aiSymbol) {

	//init
	int counter = 0;
	int i = 1;

	//check columns for two AI's
	for (int i = 1; i <= 3; i++) {
		if (array[i] == aiSymbol && array[i + 3] == aiSymbol && array[i + 6] != huSymbol) {
			i = i + 6;
			return i;
		} else if (array[i] == aiSymbol && array[i + 6] == aiSymbol && array[i + 3] != huSymbol) {
			i = i + 3;
			return i;
		} else if (array[i + 3] == aiSymbol && array[i + 6] == aiSymbol && array[i] != huSymbol) {
			return i;
		}
	}

	//check rows for two AI's
	for (int i = 1; i <= 3; i++) {
		if (array[i + (counter * 2)] == aiSymbol && array[i + 1 + (counter * 2)] == aiSymbol && array[i + 2 + (counter * 2)] != huSymbol) {
			i = i + 2 + (counter * 2);
			return i;
		} else if (array[i + (counter * 2)] == aiSymbol && array [i + 2 + (counter * 2)] == aiSymbol && array[i + 1 + (counter * 2)] != huSymbol) {
			i= i + 1 + (counter * 2);
			return i;
		} else if (array[i + 1 + (counter * 2)] == aiSymbol && array [i + 2 + (counter * 2)] == aiSymbol && array[i + (counter * 2)] != huSymbol) {
			i = i + (counter * 2);
			return i;
		}
		counter++;
	}

	//check diagonals for two AI's
	if (array[1] == aiSymbol && array[5] == aiSymbol && array[9] != huSymbol) {
		return i = 9;
	} else if (array[1] == aiSymbol && array[9] == aiSymbol && array[5] != huSymbol) {
		return i = 5;
	} else if (array[5] == aiSymbol && array[9] == aiSymbol && array[1] != huSymbol) {
		return i = 1;
	} else if (array[3] == aiSymbol && array[5] == aiSymbol && array[7] != huSymbol) {
		return i = 7;
	} else if (array[3] == aiSymbol && array[7] == aiSymbol && array[5] != huSymbol) {
		return i = 5;
	} else if (array[7] == aiSymbol && array[5] == aiSymbol && array[3] != huSymbol) {
		return i = 3;
	}

	//check columns for two HU's
	for (int i = 1; i <= 3; i++) {
		if (array[i] == huSymbol && array[i + 3] == huSymbol && array [i + 6] != aiSymbol) {
			i = i + 6;
			return i;
		} else if (array[i] == huSymbol && array[i + 6] == huSymbol && array[i + 3] != aiSymbol) {
			i = i + 3;
			return i;
		} else if (array[i + 3] == huSymbol && array[i + 6] == huSymbol && array[i] != aiSymbol) {
			return i;
		}
	}
	
	//check rows for two HU's
	counter = 0;
	for (int i = 1; i <= 3; i++) {
		if (array[i + (counter * 2)] == huSymbol && array[i + 1 + (counter * 2)] == huSymbol && array[i + 2 + (counter * 2)] != aiSymbol) {
			i = i + 2 + (counter * 2);
			return i;
		} else if (array[i + (counter * 2)] == huSymbol && array [i + 2 + (counter * 2)] == huSymbol && array[i + 1 + (counter * 2)] != aiSymbol) {
			i= i + 1 + (counter * 2);
			return i;
		} else if (array[i + 1 + (counter * 2)] == huSymbol && array [i + 2 + (counter * 2)] == huSymbol && array[i + (counter * 2)] != aiSymbol) {
			i = i + (counter * 2);
			return i;
		}
		counter++;
	}

		//check diagonals for two HU's
	if (array[1] == huSymbol && array[5] == huSymbol && array[9] != aiSymbol) {
		return i = 9;
	} else if (array[1] == huSymbol && array[9] == huSymbol && array[5] != aiSymbol) {
		return i = 5;
	} else if (array[5] == huSymbol && array[9] == huSymbol && array[1] != aiSymbol) {
		return i = 1;
	} else if (array[3] == huSymbol && array[5] == huSymbol && array[7] != aiSymbol) {
		return i = 7;
	} else if (array[3] == huSymbol && array[7] == huSymbol && array[5] != aiSymbol) {
		return i = 5;
	} else if (array[7] == huSymbol && array[5] == huSymbol && array[3] != aiSymbol) {
		return i = 3;
	}

	//check mid
	if (array[5] != aiSymbol && array[5] != huSymbol) {
		return i = 5;
	}

	//check others
	for (int i = 1; i <= n; i++) {
		if (array[i] != huSymbol && array[i] != aiSymbol) {
			return i;
		}
	}
	
}