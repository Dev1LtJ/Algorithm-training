#include <iostream>
#include <cstring>

//colors
#define RESET   "\033[0m"
#define YELLOW  "\033[33m"      /* Yellow */
#define GREEN   "\033[32m"      /* Green */

using namespace std;

void doReplace (char str[], char tempStr[]);
void doStrCat (char tempStr[], int n);

int main() {
	
	//init
	cout << endl << "Program for replacement even numbers with pluses, odd numbers with minuses." << endl << endl;
	char tempStr[128] = "";
	char str[128] = "H4v3 y0u h4d 4 g00d d4y?";
	cout << "The string entered before replacement: " << endl;
	cout << YELLOW << str << RESET << endl << endl;
	cout << "The string after replecement: " << endl;
		
	//logic
	doReplace(str, tempStr);
	cout << GREEN << tempStr << RESET;

	//end
	return 0;
}

void doReplace (char str[], char tempStr[]) {

	char veryTempStr[2];

	for (int i = 0; str[i] != '\0'; i++) {
		
		if (str[i] > '0' && str[i] <= '9') {
			doStrCat (tempStr, str[i]);
		} else {
			veryTempStr[0] = str[i];
			strcat(tempStr, veryTempStr);
		}	
	}

	tempStr[(strlen(tempStr) + 1)] = '\0';
}


void doStrCat (char tempStr[], int n) {

	for (int i = 0; i < n - '0'; i++) {
		strcat(tempStr, n % 2 == 0 ? "+" : "-");
	}
}