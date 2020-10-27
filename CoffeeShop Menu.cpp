#include <iostream>
#include <cstdlib>

#define PIN 7788
#define LATTE_PRICE 2.5
#define CAPPUCINO_PRICE 3
#define ESPRESSO_PRICE 2

#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define CYAN    "\033[36m"      /* Cyan */
#define MAGENTA "\033[35m"      /* Magenta */
#define RED     "\033[31m"      /* Red */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */

using namespace std;

void printMenu(double byn);
void printServiceMenu();
double putMoney(double byn, double &billAcceptor, int cup);
double getCoffee(const double price, double byn, int &cup);
void checkInputValue(int value, int upperLimit);
void blockProgram();
void viewProceeds(double billAcceptor);
void viewCupNumber(int cup);
double pickProceeds(double billAcceptor);
void serviceMenu(int cup, double &billAcceptor);
void checkCinFail();
bool checkPin();

int main() {

	int user = 0, cup = 7;
	double byn = 0.0, billAcceptor = 100.0;

	cout << "Coffe shop Soft. v 1.0" << endl << "Powered by Yako and Dev1LtJ" << endl << endl; 

	while (true) {
		printMenu(byn);
		cout << "Select the required menu item: ";
		cin >> user;
		checkInputValue(user, 5);
		if (user == 1) {
			byn = putMoney(byn, billAcceptor, cup);
		} else if (user == 2) {
			byn = getCoffee(LATTE_PRICE, byn, cup);
		} else if (user == 3) {
			byn = getCoffee(ESPRESSO_PRICE, byn, cup);
		} else if (user == 4) {
			byn = getCoffee(CAPPUCINO_PRICE, byn, cup);
		} else if (user == 5) {
			if (checkPin()) {
				byn = 0.0;
				serviceMenu(cup, billAcceptor);
			}
			
		}
	}
	return 0;

}

bool checkPin() {
	int pinCounter = 0, inputPin;
	cout << endl << "To access the service menu, enter the pin code " << RED "(you have 3 attempts)." << RESET << endl;
	while(true) {
		cout << "If you want to return to the previous menu press '" << RED << "5"<< RESET << "'." << endl;
		cout << "Enter PIN (" << RED << 3 - pinCounter << RESET << " attempts left): " << GREEN;
		cin >> inputPin;
		checkCinFail();
		if (inputPin == 5 ) {
			return false;
		}else if (PIN == inputPin) {
			return true;
		} else {
			cout << endl << RED << "Wrong PIN!" << RESET << endl;	
		}
		pinCounter++;
		if (pinCounter == 3) {
			blockProgram();
		}
	}
}

void serviceMenu(int cup,double &billAcceptor) {
	int user;
	while (true) {
		printServiceMenu();
		cout << "Select the required menu item: ";
		cin >> user;
		checkInputValue(user, 4);
		if (user == 1) {
			viewProceeds(billAcceptor);
		} else if (user == 2) {
			viewCupNumber(cup);
		} else if (user == 3) {
			billAcceptor = pickProceeds(billAcceptor);
		} else if (user == 4) {
			break;
		}
	}
}

double putMoney(double byn, double &billAcceptor, int cup) {

	if (cup < 1) {
		cout << RED << "Sorry! There are no cups in the storage and you will not get Coffee. Call a serviceman, please." << RESET << endl;
		return byn;
	}

	while (true) {
		cout << endl << "Put the bill into the bill acceptor [0...100 BYN]: " << GREEN;
		double money = 0.0;
		cin >> money;
		if (money > 100) {
			cout << RED << "Sorry! You can't put more than 100 BYN at once." << RESET << endl;
		} else if (cin.fail() || money < 0) {
            cin.clear(); 
            cin.ignore(32767,'\n');
			cout << RED << "Error! You entered a wrong bill! Try again." << RESET << endl;
		} else {
			cout << GREEN "Bill accepted" << RESET << endl;
			byn = byn + money;
			billAcceptor = billAcceptor +  money;
			return byn;
		}
	}
}

double getCoffee(const double price, double byn, int &cup) {

	if (byn < price) {
		cout << RED << "Sorry! There are not enough money on balance. Put more money and try again." << RESET << endl;
		return byn;
	}

	if (cup < 1) {
		cout << RED << "Sorry! There are no cups in the storage and you will not get Coffee. Call a serviceman, please." << RESET << endl;
		return byn;
	}

	cout << YELLOW << "Take your Coffee. Bon appetit!" << RESET << endl;
	byn = byn - price;
	cup--;
	return byn;
}

void viewProceeds(double billAcceptor) {
	cout << "The amount of money in the bill acceptor: " << GREEN << billAcceptor << RESET << " BYN" << endl;
}

void viewCupNumber(int cup) {
	cout << "Cups left: " << CYAN << cup << RESET << endl;
}

double pickProceeds(double billAcceptor) {
	if (billAcceptor == 0) {
		cout << RED << "Sorry! Bill acceptor is empty!" << RESET << endl;
	} else {
		cout << GREEN << "Succesfull! Bill acceptor is reset! Take money." << RESET << endl;
		billAcceptor = 0.0;
		
	}
	return billAcceptor;
}

void blockProgram() {
	int n;
	while (true) {
		cout << RED << "Program was blocked" << RESET;
		//system("pause");
		cin >> n;
		checkCinFail();
	}
}

void checkInputValue(int value, int upperLimit) {
	if (value <= 0 || value > upperLimit) {
            //check for data type
            checkCinFail();
            cout << RED << "Error! You entered a wrong symbol/number! Try again." << RESET << endl;
        }
}

void checkCinFail() {
	if (cin.fail()) {
        cin.clear(); 
        cin.ignore(32767,'\n'); 
    }
}

void printMenu(double byn) {
	cout << endl << "----- " << BOLDBLUE << "CoffeShop" << RESET << " -----" << endl;
	cout << "---------------------" << endl;
	cout << "Balance: " << GREEN << byn << RESET << " BYN" << endl;
	cout << "---------------------" << endl;
	cout << "| " << GREEN << "1. Put money" << RESET << "      |" << endl;
	cout << "| " << YELLOW << "2. Latte - 2.5" << RESET << "      |" << endl;
	cout << "| " << CYAN << "3. Espresso - 3" << RESET << " |" << endl;
	cout << "| " << MAGENTA << "4. Cappuccino - 2" << RESET << " |" << endl;
	cout << "---------------------" << endl;
	cout << "| " << RED << "5. Service" << RESET << "        |" << endl;
	cout << "---------------------" << endl;
}

void printServiceMenu() {
	cout << endl << RESET << "-------------- " << BOLDBLUE << "Service Menu" << RESET << " -------------" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "| " << YELLOW << "1. View Balance Amount" << RESET << "                |" << endl;
	cout << "| " << CYAN << "2. View the number of cups remaining" << RESET << "  |" << endl;
	cout << "| " << MAGENTA << "3. Pick up the proceeds" << RESET << "               |" << endl;
	cout << "| " << RED << "4. Exit" << RESET << "                               |" << endl;
	cout << "-----------------------------------------" << endl;
}