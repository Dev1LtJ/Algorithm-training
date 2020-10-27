/* 2. 2->10. Переведите число из двоичной системы в десятичную. */

#include <iostream>
#include <cmath>
#define BOLDWHITE "\033[1m\033[37m"      /* Bold White */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define RESET "\033[0m"

using namespace std;

int main() {
	
	//initialization
	cout << endl << BOLDWHITE << "Translation 2 -> 10 program" << RESET << endl << endl;
	int binaryNumber = 0, digitQuantity = 0, digit = 0, decimalNumber = 0, digitCounter = 0, decimalNumberSumm = 0, binaryCheck = 0;

	//input
	cout << "Input " << BOLDBLUE << "binary" << RESET << " number: ";
	cin >> binaryNumber;
	binaryCheck = binaryNumber;

	//input processing
	while (binaryCheck > 0) {
		digit = binaryCheck % 10;
		if (digit !=0 && digit !=1) {
			cout << endl << BOLDRED << "Error! Your number contains digit differing from 0 or 1 !" << endl;
			return 1;
		}
		binaryCheck = binaryCheck / 10;
	}

	//Quantity of digits for cycle breaking
	if (binaryNumber != 0) {
		digitQuantity = log10(binaryNumber) + 1;
	} else {
		decimalNumber = pow(2, 0);
		cout << "Decimal number: " << decimalNumberSumm;
		return 0;
	}

	//logic
	while (true) {
		digit = binaryNumber % 10;
		if (digit == 0) {
			decimalNumber = 0;
		} else {
			decimalNumber = pow(2, digitCounter);
		}
		decimalNumberSumm = decimalNumberSumm + decimalNumber;
		digitCounter++;
		binaryNumber = binaryNumber / 10;
		if (digitCounter == digitQuantity) {
			break;
		}
	}

	//output
	cout << BOLDCYAN << "Decimal" << RESET << " number: " << decimalNumberSumm << endl;
	return 0;
}