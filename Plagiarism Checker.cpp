#include <iostream>
#include <cstring>
//colors
#define RESET   "\033[0m"
#define GREEN   "\033[32m"      // Green
#define YELLOW  "\033[33m"      // Yellow 
#define CYAN    "\033[36m"      // Cyan 
#define RED     "\033[31m"      // Red 
#define BLUE    "\033[34m"      // Blue
#define N 2000
using namespace std;

// text
#define TEXT "Lorem   kek dolor sit amet, consectetur   adipiscing elit, sed do eiusmod tempor incididunt ut labore et cheburek magna aliqua. Ut enim ad lol veniam, quis.  nostrud exercitation pizza laboris nisi ut aliquip ex ea commodo consequat. Duis coca-cola irure dolor in reprehenderit in voluptate velit esse shaverma eu fugiat nutella pariatur. Excepteur sint cat cupidatat non proident, sunt in culpa qui oficcial kek lol deserunt mollit anim id est laborum."
#define BASETEXT "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."

void convertText (char text[], char convText[]);
void trimText (char text[], char convText[]);
void doLowerLetters (char text[]);
double scanText (char text[], char baseText[]);
bool compareKeyWords (char keyWords[], char baseText[]);
bool checkLenght(char text[]);

int main() {

	//init
	cout << endl << endl << CYAN << "Plagiarism checker v.1 by " << BLUE << "Yako" << RESET << CYAN << " & " << RED << "Dev1LtJ" << RESET << endl << endl;
	char convText[N] = ""; // для переноса откорректированного текста
	char convBaseText[N] = ""; // для переноса откорректированного текста
	//logic
	convertText (TEXT, convText);
	cout << endl << YELLOW << convText << RESET;
	convertText (BASETEXT, convBaseText);
	cout << endl << endl << GREEN << convBaseText << RESET << endl << endl;

	if(checkLenght(convText) || checkLenght(convBaseText)){
	    cout << "Not enough words. At least 3 is required!";
	    return 0;
	}
	cout.precision(4);
	cout << "Match percentage = " << BLUE << scanText (convText, convBaseText) << " %" << endl;
	return 0; 
}
bool checkLenght(char text[]){
    int wordCounter = 0;
    for(int i = 0; text[i] != '\0'; i++){
        if (text[i] == ' ') wordCounter++;
    }
    if(wordCounter < 3){
        return true;
    }
    return false;
}

void convertText (char text[], char convText[]) {
	trimText (text, convText);
	doLowerLetters (convText);
}

void trimText (char text[], char convText[]) {
	char separator[] = ",.;:!?";
	int newIndex = 0, index = 0;

	while (true) {
		for (int n = 0; separator[n] != '\0'; n++) {
			if (text[index] == separator[n] || (text[index] == ' ' && text[index + 1] == ' ')) index++;  
		}
			if (text[index] == '\0') break;
		convText[newIndex++] = text[index++];
	}
	convText[newIndex] = ' ';
	convText[newIndex + 1] = '\0';	
}

void doLowerLetters (char text[]) {
	for (int i = 0; text[i] != '\0'; i++) {
		if (text[i] >= 'A' && text[i] <= 'Z' ){
			text[i] = text[i] + ('a' - 'A');
		}
	}
}

double scanText (char text[], char baseText[]) {
	int spaceCounter = 0, j = 0,checkCounter = 0;
	char keyWords[N];
	double result = 0;

	for (int i = 0; text[i] != '\0'; i++) { 	
		keyWords[j++] = text[i];
		if (text[i] == ' ' || text[i] == '\0') { 
			spaceCounter++;  
		}
		if (text[i] == '\0' || spaceCounter == 3) {
			keyWords[j] = '\0'; 
			j = 0; 	// keywords index
			for (; i >= 0; i--) {  
				if (text[i] == ' ') {
					spaceCounter--;
					if (spaceCounter == 0) break;
				}
			}
			checkCounter++; 
			result += compareKeyWords(keyWords, baseText);
		}
	}
	return (result  / checkCounter) * 100;
}

bool compareKeyWords (char keyWords[], char baseText[]) {
	return strstr(baseText, keyWords);
}