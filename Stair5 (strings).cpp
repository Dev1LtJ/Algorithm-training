#include <iostream>

using namespace std;

int strLength(char str[]);
void strCopy (char line[], char newLine[]);
void strCont (char cat1[], char cat2[]);
int strComp (char cmp1[], char cmp2[]);

int main() {

	//Task1 (+)
	cout << endl << "Task1: Length: " << endl;
	int length = 0;
	char str[] = "Hello World!1";
	length = strLength(str);
	cout << "Length = " << length;

	//task2 (+)
	cout << endl << endl << "Task2. Copy: " << endl;
	char line[] = "Sherlok";
	char newLine[128];
	strCopy (line, newLine);
	cout << "Text is " << newLine;

	//task3 (+)
	cout << endl << endl << "Task3. Concatenation: " << endl;
	char cat1[128] = "Sherlok ";
	char cat2[128] = "Holms";
	strCont (cat1, cat2);
	cout << "Common text is " << cat1;

	//task4 (+)
	int compResult = 4;
	cout << endl << endl << "Task4. Comparison: " << endl;
	char cmp1[] = "Hellow";
	char cmp2[] = "Hellov";
	compResult = strComp(cmp1, cmp2);
	cout << compResult;

	//ending
	return 0;
}

int strLength(char str[]) {

	int counter = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		counter++;
	}
	return counter;
}

void strCopy (char line[], char newLine[]) {

	int counter = 0;

	for (int i = 0; line[i] != '\0'; i++) {
		newLine[i] = line[i];
		counter++;
	}
	newLine[counter + 1] = '\0';
}

void strCont (char cat1[], char cat2[]) {

	int cat1Counter = 0;
	int cat2Counter = 0;
	int catCounter = 0;
	int lastCounter = 0;

	for (int i = 0; cat1[i] != '\0'; i++) {
		cat1Counter++;
	}

	for (int i = 0; cat2[i] != '\0'; i++) {
		cat2Counter++;
	}

	catCounter = cat1Counter + cat2Counter;

	for (int i = cat1Counter; i < catCounter; i++) {

		cat1[i] = cat2[lastCounter++];
	}

	cat1[catCounter + 1] = '\0';
}

int strComp (char cmp1[], char cmp2[]) {

	int cmp1Length = strLength(cmp1);
	int cmp2Length = strLength(cmp2);
	int cmpMaxLength = 0;

	if (cmp1Length > cmp2Length) {
		cmpMaxLength = cmp1Length;
	} else {
		cmpMaxLength = cmp2Length;
	}

	for (int i = 0; i < cmpMaxLength; i++) {

		if (cmp1[i] < cmp2[i]) {
			return 1;
		}
		if (cmp1[i] > cmp2[i]) {
			return -1;
		}
	}

	return 0;
}