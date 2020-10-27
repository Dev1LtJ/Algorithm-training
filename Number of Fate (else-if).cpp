/* Число судьбы. Напишите программу, которая запрашивает дату рождения.
После этого она суммирует все цифры дня, месяца и года рождения, пока не получится одна цифра - это и есть число судьбы.
Введите свою дату рождения и проверьте в интернете, подходит ли оно вам.  */

#include <iostream>

using namespace std;

int main() {

	//initialize
	cout << "Program for calculating the number of fate" << endl;
	int date = 0, month = 0, year = 0;
	int dateNumber1 = 0, dateNumber2 = 0, monthNumber1 = 0, monthNumber2 = 0, yearNumber1 = 0, yearNumber2 = 0, yearNumber3 = 0, yearNumber4 = 0;
	int preNumberOfFate1 = 0, preNumberOfFate2 = 0, preNumberOfFate3 = 0, numberOfFate = 0;

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
	} else {

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
		} else {
			
			//data preprocessing
			//date
			dateNumber1 = date / 10;
			dateNumber2 = date % 10;
			//month
			monthNumber1 = month / 10;
			monthNumber2 = month % 10;
			//year
			yearNumber1 = year / 1000;
			yearNumber2 = (year - (yearNumber1 * 1000)) / 100;
			yearNumber3 = (year - (yearNumber1 * 1000) - (yearNumber2 * 100)) / 10;
			yearNumber4 = year % 10;
	
			//logic-output
			preNumberOfFate1 = dateNumber1 + dateNumber2 + monthNumber1 + monthNumber2 + yearNumber1 + yearNumber2 + yearNumber3 + yearNumber4;
			if (preNumberOfFate1 < 10) {
				cout << "Your number of fate is " << preNumberOfFate1;
				return 0;
			} else {
				preNumberOfFate2 = preNumberOfFate1 / 10;
				preNumberOfFate3 = preNumberOfFate1 % 10;
				numberOfFate = preNumberOfFate2 + preNumberOfFate3;
			}
			if (numberOfFate < 10) {
				cout << "Your number of fate is " << numberOfFate;
				return 0;
			} else {
				preNumberOfFate2 = numberOfFate / 10;
				preNumberOfFate3 = numberOfFate % 10;
				numberOfFate = preNumberOfFate2 + preNumberOfFate3;
				cout << "Your number of fate is " << numberOfFate;
				return 0;
			}
		}
	}
}