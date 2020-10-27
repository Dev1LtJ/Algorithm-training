//1.Самое длинное слово в тексте - longest word (вывести и напечатать кол-во символов)
#include <iostream>
#define N 1000

//colors
#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define CYAN    "\033[36m"      /* Cyan */

using namespace std;

bool isSeparator (char symbol);
void scanText (char text[], char word[], char wordMax[], int &maxSymbolCounter);
void replaceText (char word[], char wordMax[]);

int main() {
	
	//init
	cout << endl << endl << CYAN << "Program for determine the longest word of the text v.1" << RESET;
	char text[N], word[N], wordMax[N];
	int maxSymbolCounter = 0;
	cout << endl << endl << "Input the text: " << endl << YELLOW;
	cin.getline(text, N);
	cout << endl << RESET << "Entered text: " << endl << YELLOW << text << RESET;

	//logic
	cout << endl << endl << "The longest word of the entered text: " << GREEN << endl;
	scanText (text, word, wordMax, maxSymbolCounter);
	cout << GREEN << wordMax << RESET << " with " << GREEN << maxSymbolCounter << RESET << " symbols.";


	//end
	return 0;
}


void scanText (char text[], char word[], char wordMax[], int &maxSymbolCounter) {

	int iw = 0;

	for (int i = 0; text[i] != '\0'; i++) {

		word[iw++] = text[i];

		if (isSeparator (text[i+1]) == true) {
			if (iw > maxSymbolCounter) {
				word[iw] = '\0';
				replaceText(word, wordMax);
				maxSymbolCounter = iw;
			}
			iw = 0;
			i++;
		}
		
	}

	wordMax[maxSymbolCounter+1] = '\0';
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

void replaceText (char word[], char wordMax[]) {

	for (int i = 0; word[i] != '\0'; i++) {
		wordMax[i] = word[i];
	}
}