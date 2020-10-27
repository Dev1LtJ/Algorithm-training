//5. Доработать задачу 4. (укоротить) и вернуть 0 если они равны (любое отрицательное, если они не равны (их разность) или положительное (тоже разность) - в зависимости от веса).

#include <iostream>

using namespace std;

int doCompare (char str1[], char str2[]);
int getLen (char str[]);

int main() {

	//init
	cout << endl << "Program for comparing 2 strings..." << endl << endl;
	char string1[128];
	char string2[128];
	cout << "Enter 1st string: ";
	cin >> string1;
	cout << "Enter 2nd string: ";
	cin >> string2;

	//logic
	int cmpRslt = doCompare (string1, string2);
	cout << endl << "Decimal difference = " << cmpRslt;

	//end	
	return 0;

}

int doCompare (char str1[], char str2[]) {

	int str1Sum = 0;
	int str2Sum = 0;
	bool isFirstlonger = getLen(str1) > getLen(str2);

	for (int i = 0; isFirstlonger ? str1[i] : str2[i] != '\0'; i++) {
		
		str1Sum = str1Sum + str1[i];
		str2Sum = str2Sum + str2[i];
	}

	return str1Sum - str2Sum;
}

int getLen (char str[]) {

	int i = 0;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}