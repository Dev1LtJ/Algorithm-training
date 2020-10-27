// ввод данных (+)
// не уменьшаются BYN (+)
// только 1 валюта - добавить EURO, RUR (+)
// внести деньги (+)

#include <iostream>
#define RESET   "\033[0m"
#define BLUE    "\033[34m"      /* Blue */
#define GREEN   "\033[32m"      /* Green */
#define RED     "\033[31m"      /* Red */
#define YELLOW  "\033[33m"      /* Yellow */
#define CYAN    "\033[36m"      /* Cyan */
#define MAGENTA "\033[35m"      /* Magenta */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */

using namespace std;

#define BYN_USD 2.62;
#define BYN_EUR 3.07;
#define BYN_RUR 0.0346;

void printMenu();

void printExchangeBYNtoAnyCurrencyMenu(char str[]);
double exchangeBYNtoAnyCurrency(double byn, char str[], double byn_anyCurrency);

double putMoney(double byn);
void checkBalance(double byn);

double putBalanceOnCardOrPhone(double byn);
void printputBalanceOnCardOrPhoneMenu();

void checkActualCourses();

int main() {

	char user = '0';
	double byn = 0.0;
	char strUSD[] = "USD", strEUR[] = "EUR", strRUR[] = "RUR";
	double byn_usd = BYN_USD;
	double byn_eur = BYN_EUR;
	double byn_rur = BYN_RUR;

	while (true) {
		printMenu();
		cout << endl << "What do you want to do? ";
		cin >> user;
		cin.ignore(32767, '\n');
		if (user == '1') {
			byn = putMoney(byn);
		} else if (user == '2') {
			checkBalance(byn);
		} else if (user == '3') {
			checkActualCourses();
		} else if (user == '4') {
			byn = exchangeBYNtoAnyCurrency(byn, strUSD, byn_usd);
		} else if (user == '5') {
			byn = exchangeBYNtoAnyCurrency(byn, strEUR, byn_eur);
		} else if (user == '6') {
			byn = exchangeBYNtoAnyCurrency(byn, strRUR, byn_rur);
		} else if (user == '7') {
			byn = putBalanceOnCardOrPhone(byn);
		} else if (user == '8') {
			cout << BOLDBLUE << "Goodbye! Thank you for using our service. See you soon..." << RESET;
			break;
		} else {
			cout << endl << RED << "Error! You entered a wrong symbol! Try again." << RESET;
		}
	}

	return 0;
}

void printMenu() {

	cout << endl << BOLDBLUE << "Currency Exchange: " << RESET << endl << endl;
	cout << GREEN << "1. Put Money." << RESET << endl;
	cout << YELLOW << "2. Show Balance." << RESET << endl;
	cout << "3. See actual courses." << RESET << endl;
	cout << "4. Exchange" << BOLDCYAN << " BYN" << RESET << " to " << BOLDMAGENTA << "USD." << RESET << endl;
	cout << "5. Exchange" << BOLDCYAN << " BYN" << RESET << " to " << BOLDYELLOW << "EUR." << RESET << endl;
	cout << "6. Exchange" << BOLDCYAN << " BYN" << RESET << " to " << BOLDGREEN << "RUR." << RESET << endl;
	cout << "7. Put your balance on the " << YELLOW << "Phone" << RESET << " or " << BLUE << "Card." << RESET << endl;
	cout << RED << "8. Exit." << RESET << endl;
}


//balance adding
double putMoney(double byn) {

	double money = 0.0;

	cout << "Put your money: " << GREEN;
	cin >> money;
	while (money <= 0) {
		cout << RED << "Error! Try again." << RESET << endl;
		cin >> money;
	}
	cout << RESET << "Succesful! Your balance has been increased by " << GREEN << money << RESET << " BYN." << endl;
	money = byn + money;

	return money;
}

//balance checking
void checkBalance (double byn) {
	cout << YELLOW << "Your balance is " << RESET << GREEN << byn << RESET << YELLOW << " BYN." << RESET << endl;
}


// Put balance on the card or phone function
double putBalanceOnCardOrPhone(double byn) {
	
	unsigned long long cardNumber = 0;
	int counter = 0;
	char user = '0';
	double money = 0.0;

	printputBalanceOnCardOrPhoneMenu();
	cin >> user;
	cin.ignore(32767, '\n');

	if (user == '1') {
		while (true) {
			cout << "Enter your phone number in format XXXXXXXXXXXX (12 digits): ";
			cin >> cardNumber;

			while (cardNumber > 0) {
				cardNumber = cardNumber / 10;
				counter++;
			}

			if (counter != 12) {
				cout << RED << "Error! You entered a wrong phone number! Try again." << RESET << endl;
			} else {
				cout << "Succesful! Your phone balance has been increased by " << GREEN << byn << RESET << " BYN." << endl;
				money = 0.0;
				return money;
			}
		}
	} else if (user == '2') {
		while (true) {
			cout << "Enter your card number in format XXXXXXXXXXXXXXX (16 digits): ";
			cin >> cardNumber;

			while (cardNumber > 0) {
				cardNumber = cardNumber / 10;
				counter++;
			}

			if (counter != 16) {
				cout << RED << "Error! You entered a wrong card number! Try again." << RESET << endl;
			} else {
				cout << "Succesful! Your card balance has been increased by " << GREEN << byn << RESET << " BYN." << endl;
				money = 0.0;
				return money;
			}
		}
	} else if (user == '3') {
		return byn;
	} else {
		cout << RED << "Error! You entered a wrong symbol! Try again." << RESET << endl;
	}
}

// Put balance on the card or phone function menu
void printputBalanceOnCardOrPhoneMenu() {
	cout << "1. Put money on the " << YELLOW << "phone." << RESET << endl;
	cout << "2. Put money on the " << BLUE << "card." << RESET << endl;
	cout << RED << "3. Exit this menu." << RESET << endl;
}

// Checking actual courses fucntion
void checkActualCourses() {

	double byn_usd = BYN_USD;
	double byn_eur = BYN_EUR;
	double byn_rur = BYN_RUR;

	cout << "1. " BOLDCYAN << "BYN" << RESET << " to " << BOLDMAGENTA << "USD" << RESET << " course ratio: " << BOLDMAGENTA << byn_usd << RESET << "." << endl;
	cout << "1. " BOLDCYAN << "BYN" << RESET << " to " << BOLDYELLOW << "EUR" << RESET << " course ratio: " << BOLDYELLOW <<  byn_eur << RESET << "." << endl;
	cout << "1. " BOLDCYAN << "BYN" << RESET << " to " << BOLDGREEN << "RUR" << RESET << " course ratio: " << BOLDGREEN << byn_rur << RESET << "." << endl;
}


//BYN to RUR exchange function
double exchangeBYNtoAnyCurrency(double byn,  char str[], double byn_anyCurrency) {

	char user = 0;
	double anyCurrency = 0.0;
	double byn_temp = 0.0;
	double balance = 0.0;

	while (true) {

		printExchangeBYNtoAnyCurrencyMenu(str);
		cin >> user;
		cin.ignore(32767, '\n');

		if (user == '1') {
			if (byn == 0) {
				cout << RED << "Unseccesful! There are no enough money on the balance. Put more money and try again." << RESET;
				return byn;
			}	
			anyCurrency = byn / byn_anyCurrency;
			cout << "Succesful! You bought " << GREEN << anyCurrency << RESET << " " << str << "." << RESET << endl;
			balance = 0.0;
			return balance;
		} else if (user == '2') {
			cout << "Enter the amount of " << str << ": " << GREEN;
			cin >> anyCurrency;
			balance = byn - anyCurrency * byn_anyCurrency;
			if (balance < 0) {
				cout << RED << "Unseccesful! There are no enough money on the balance. Put more money and try again." << RESET;
				return byn;
			}
			cout << RESET << "Succesful! You bought " << GREEN << anyCurrency << RESET << " " << str << "." << RESET << endl;
			return balance;
		} else if (user == '3') {
			cout << "Enter the amount of BYN: " << GREEN;
			cin >> byn_temp;
			if (byn_temp > byn) {
				cout << RED << "Unseccesful! There are no enough money on the balance. Put more money and try again." << RESET;
				return byn;
			}
			anyCurrency = byn_temp / byn_anyCurrency;
			cout << RESET << "Succesful! You bought " << GREEN << anyCurrency << RESET << " " << str << "." << RESET << endl;
			balance = byn - byn_temp / byn_anyCurrency;
			return balance;
		} else if (user == '4') {
			return byn;
		} else {
			cout << RED << "Error! You entered a wrong symbol! Try again." << RESET << endl;
		}
	}	
}


//BYN to RUR exchange function menu
void printExchangeBYNtoAnyCurrencyMenu(char str[]) {
	cout << BLUE << endl << "How many " << str << " do you want to buy?" << RESET << endl;
	cout << "1. Buy for all BYN." << endl;
	cout << "2. Buy a certain amount of " << str << "." << endl;
	cout << "3. Buy for a certain amount of BYN." << endl;
	cout << RED << "4. Exit this menu." << RESET << endl;
}