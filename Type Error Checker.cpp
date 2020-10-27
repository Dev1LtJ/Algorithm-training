// 2.Ошибка наборщика - typer error (повторяется ли слово два раза)
// Lorem ipsum ipsum dolor sit amet, consectetur adipiscing elit, sed sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo commodo consequat. Duis aute irure dolor dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum

// Можно 1
#include <iostream>
#include <cstring>
#define N 1000
//colors
#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define CYAN    "\033[36m"      /* Cyan */
#define RED     "\033[31m"      /* Red */

using namespace std;

void scanText (char text[], char word1[], char word2[], char clean[]);
bool isSeparator (char symbol);
bool compareWords (char word1[], char word2[]);
void replaceText (char word1[], char word2[]);
void cleanArray (char word[], char clean[]);
void trimText (char text[], char newText[]);
void doLowerLetters (char newText[]);

int main() {
	
	//init
	cout << endl << endl << CYAN << "Duplicate word program v.1";
	char text[N], word1[N], word2[N], clean[N];
	char newText[] = "";
	cout << endl << endl << RESET << "Input text: " << endl << YELLOW;
	cin.getline(text, N);
	//cout << RESET << endl << "Entered text: " << YELLOW << endl << text << RESET << endl;

	//logic
	//scanText(text, word1, word2, clean);
	trimText (text, newText);
	doLowerLetters (newText);
	cout << endl << endl << "Entered text only with spaces and lower letters:" << 
	endl << RED << newText << RESET << endl;
	scanText(newText, word1, word2, clean);

	//end
	return 0;
}

void scanText (char text[], char word1[], char word2[], char clean[]) {

	int iw = 0;
	int duplicate = 0;

	for (int i = 0; text[i] != '\0'; i++) {

		word1[iw++] = text[i];

		if (isSeparator(text[i+1]) == true) {
			word1[iw] = '\0';
			if (compareWords (word1, word2) == true) {
				cout << endl << "The word " << RED << word2 << RESET << " duplicates two or more times.";
				duplicate++;
			}
			cleanArray(word2, clean); //можно еще word2[0] = 0;
			replaceText(word1, word2);
			iw = 0;
			cleanArray(word1, clean); //можно еще word1[0] = 0;
			i++;
		}
	}
	if (duplicate == 0) {
		cout << endl << GREEN << "Good Job! The text doesn't contain duplicated words!" << RESET;
	}
}

bool isSeparator (char symbol) {

	char separator[] = " ,.;:!?";

	for (int i = 0; separator[i] != '\0'; i++) {

		if (symbol == separator[i] || symbol == '\0') {
			return true;
			
		}
	}

	return false;
}


bool compareWords (char word1[], char word2[]) {

	int w1 = strlen(word1);
	int w2 = strlen(word2);

	for (int i = 0; i <= (w1 >= w2 ? w1 : w2); i++) {
		if (word1[i] != word2[i]) {
			return false;
		}
	}

	return true;
}


void replaceText (char word1[], char word2[]) {

	int i = 0;

	for (i = 0; word1[i] != '\0'; i++) {

		word2[i] = word1[i];
	}
	word2[i] = '\0';
}

void cleanArray (char word[], char clean[]) {

	for (int i = 0; i <= N; i++) {

		word[i] = clean[i];
	}
}

void trimText (char text[], char newText[]) {

	char separator[] = ",.;:!?";
	int i = 0;
	int ni = 0;

	for (i = 0; text[i] != '\0'; i++) {

		for (int n = 0; separator[n] != '\0'; n++) {

			if (text[i] == separator[n]){
				i++;
			} else if (text[i] == ' ' && text[i+1] == ' ') {
				i++;
			}
		}
		newText[ni++] = text[i];
	}

	newText[ni] = '\0';
}

void doLowerLetters (char newText[]) {

	char upperLetter = 'A';
	char lowerLetter = 'a';

	for (int i = 0; newText[i] != '\0'; i++) {

		if (newText[i] != ' ') {
			while (lowerLetter != 'z') {
				if (newText[i] == upperLetter) {
					newText[i] = lowerLetter;
				}	
				upperLetter++;
				lowerLetter++;
			}
		}
		upperLetter = 'A';
		lowerLetter = 'a';
	}
}