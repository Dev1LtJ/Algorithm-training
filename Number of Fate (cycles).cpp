#include <iostream>

using namespace std;

int main() {

	//initialize
	cout << "Program for calculating the number of fate" << endl;
	int date = 0, dateSum = 0, month = 0, monthSum = 0, year = 0, yearSum = 0, buff = 0, numberOfFate = 0, numberOfFateSum = 0;

	//input
	cout << "Input your date of birth [1...31]" << endl;
	cin >> date;
	cout << "Input your month of birth [1...12]" << endl;
	cin >> month;
	cout << "Input your year of birth [1...9999]" << endl;
	cin >> year;
	
		//inputs processing
	if (date < 1 || date > 31) {
		cout << "Error! Date must be in range from 1 to 31" << endl;
		return 1;
	} else if (month < 1 || month > 12) {
		cout << "Error! Month must be in range from 1 to 12" << endl;
		return 1;
	} else if (year < 1 || year > 9999) {
		cout << "Error! Year must be in range from 1 to 9999 (program limit)" << endl;
		return 1;
	} else {}

	//related cases processing (with february leap year)
	if (((month == 2) || (month == 4) || (month == 6) || (month == 9) || (month == 11) ) && date == 31) {
		cout << "Error! This month cannot be 31 days" << endl;
		return 1;
	} else if (month == 2 && date == 30) {
		cout << "Error! This month cannot be 30 days" << endl;
		return 1;
	} else if (month == 2 && date == 29) {
		if ((year % 4 != 0) || (year % 100 == 0 && year % 100 != 0)) {
			cout << "Error! This is not leap year and february cannot be 29 days" << endl;
			return 1;
		} else {}
	} else {}

	//logic
	//Date processing
	while (date > 0) {
		buff = date % 10;
		dateSum = dateSum + buff;
		date = date / 10;
	}
	buff = dateSum % 10;
	dateSum = dateSum / 10;
	dateSum = dateSum + buff;

	//Month processing
	while (month > 0) {
		buff = month % 10;
		monthSum = monthSum + buff;
		month = month / 10;
	}

	//Year processing
	while (year > 0) {
		buff = year % 10;
		yearSum = yearSum + buff;
		year = year / 10;
	}
	buff = yearSum % 10;
	yearSum = yearSum / 10;
	yearSum = yearSum + buff; 
	
	//Summary
	numberOfFateSum = dateSum + monthSum + yearSum;
	while (numberOfFateSum > 0) {
		buff = numberOfFateSum % 10;
		numberOfFate = numberOfFate + buff;
		numberOfFateSum = numberOfFateSum / 10;
	}

	//output
	cout << "Your number of fate is " << numberOfFate;
	return 0;
}