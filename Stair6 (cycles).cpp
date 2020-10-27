/* Лесенка:
-> 1) Печатаем все его цифры столбиком (с новой строки) (+)
-> 2) Печатаем сумму и произведение цифр числа (+)
-> 3) Печатаем самую большую и маленькую цифру (+)
-> 4) Содержит ли число две одинаковые цифры, стоящие подряд? (+)
-> 5) Является ли число возрастающей или убывающей последовательностью цифр? (+) */


#include <iostream>
#include <cmath>

using namespace std;

int main() {

	//initialization
	cout << "Program for breaking a number into digits" << endl << endl;
	int number = 0, numberDigit = 0, numberSum = 0, numberMult = 1, numberDigitMax = 0, numberDigitMin = 0, numberDigitBuff = 0, coherentCheckCon = 0, risingSequenceCounter = 0, decreasingSequenceCounter = 0, referenceSequenceCounter = 0, decreasingSequenceCounterBuff = 0, risingSequenceCounterBuff = 0, coherentCounter = 0, coherentSumm = 0, coherentSummDigit = 0, reverseNumber = 0;
	bool coherentCheck = false;

	//input
	cout << "Input a number: ";
	cin >> number;
	number = abs(number);

	//logic
	cout << "Reverse digits: " << endl;
	numberDigitMin = number;
	risingSequenceCounterBuff = number;
	while (number > 0) {
		numberDigit = number % 10;
		reverseNumber = reverseNumber * 10 + numberDigit;
		cout << numberDigit << endl;
		if (numberDigit > numberDigitMax) {
			numberDigitMax = numberDigit;
		}
		if (numberDigit < numberDigitMin) {
			numberDigitMin = numberDigit;
		}
		if (numberDigitBuff == numberDigit) {
			coherentCheck = true;
			coherentCheckCon = numberDigitBuff;
			coherentSumm = coherentSumm * 10 + numberDigit;
			coherentCounter++;
		} else {
			numberDigitBuff = numberDigit;
		}
		referenceSequenceCounter++;
		if (decreasingSequenceCounterBuff < numberDigit) {
			decreasingSequenceCounter++;
			decreasingSequenceCounterBuff = numberDigit;
		}
		if (risingSequenceCounterBuff > numberDigit) {
			risingSequenceCounter++;
			risingSequenceCounterBuff = numberDigit;
		}
		numberSum = numberSum + numberDigit;
		numberMult = numberMult * numberDigit;
		number = number / 10;
	}

	//output
	//reverse
	cout << endl << "Direct digits: " << endl;
	while (reverseNumber > 0) {
		numberDigit = reverseNumber % 10;
		cout << numberDigit << endl;
		reverseNumber = reverseNumber / 10;
	}

	cout << endl << "Summary of digits: " << numberSum << endl;
	cout << "Multiplication of digits: " << numberMult << endl;
	cout << "Highest digit: " << numberDigitMax << endl;
	cout << "Smallest digit: " << numberDigitMin << endl;

	//coherent check & output
	if (coherentCheck == true) {
		cout << endl << "Yes! There are " << coherentCounter << " group(s) of two coherent digits: " << endl;
		while (coherentSumm > 0) {
			coherentSummDigit = coherentSumm % 10;
			cout << "Digit group: " << coherentSummDigit << " & " << coherentSummDigit << "." << endl;
			coherentSumm = coherentSumm / 10;
		}
	} else {
		cout << endl << "No! There are no coherent digits." << endl << endl;
	}

	//rising or decreasing sequence check & output
	if (decreasingSequenceCounter == referenceSequenceCounter) {
		cout << "There is a decreasing sequence in this number." << endl;
	} else if (risingSequenceCounter == referenceSequenceCounter) {
		cout << "There is a rising sequence in this number." << endl;
	} else {
		cout << "There are no sequences in this number.";
	}

	return 0;
}