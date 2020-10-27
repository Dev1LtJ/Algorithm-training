// КАЛЬКУЛЯТОР. Строка содержит арифметическое выражение, состоящее из целых чисел и знаков операций: +, -, *, /. Проверье корректность последовательности чисел и знаков и вычислите значение выражения.


#include <iostream>
#include <stack>

//colors
#define RESET   "\033[0m"
#define CYAN    "\033[36m"      /* Cyan */
#define YELLOW  "\033[33m"      /* Yellow */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
// (6+9-4)/(1+1*2)+1 = 5
// (8+2*5)/(1+3*2-4) = 6
using namespace std;

bool inputCheck (char exp[]);
void doRPN (char exp[], char expRPN[], stack <char> stackRPN);
int getPriority (char exp);
double doComputing (stack <double> compStack, char expRPN[]);
int checkRPN (char expRPN);
int checkOperation (char expRPN);
double doMathematic (stack <double> compStack, int symbol);

int main() {
	//init
	cout << endl << CYAN << "Calculator v.1" << RESET << endl;
	char exp[] = "(6+9-4)/(1+1*2)+1";
	char expRPN[128] = "";
	stack <char> stackRPN;
	stack <double> compStack;
	double result = 0.0;
	cout << endl << "Entered expression: ";
	cout << YELLOW << exp << RESET << endl;

	//Stage1 - check input
	cout << endl << "Check for correct expression: ";
	if (inputCheck (exp) == false){
		return 1;
	}
	//Stage2 - do RPN
	doRPN(exp, expRPN, stackRPN);
	cout << endl << "RPN expression: ";
	cout << GREEN << expRPN << RESET;

	//stage3 - computing
	result = doComputing (compStack, expRPN);
	cout << endl << "Result = " << result;

	//end
	return 0;
}

bool inputCheck (char exp[]) {

	for (int i = 0; exp[i] != '\0'; i++) {
		//check for correct symbols
		if ((exp[i] < '0' || exp[i] > '9') && exp[i] != '(' && exp[i] != ')' && exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/') {
			cout << endl << RED << "Error! Your expression is incorrect" << RESET << endl;
			return false;
		}	
		//check for correct expression
		if ((exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*' || exp[i] == '(')  && (exp[i + 1] == '-' || exp[i + 1] == '*' || exp[i + 1] == '/' || exp[i + 1] == ')')) {
			cout << endl << RED << "Error! Your expression is incorrect!";
			cout << endl << "Two arithmetic signs can't follow immediately after each other." << RESET << endl;
			return false;
		}
	}
	cout << endl << GREEN << "OK! Your expression is correct!" << RESET << endl;
	return true;
}

void doRPN (char exp[], char expRPN[], stack <char> stackRPN) {

	int RPNcntr = 0;
	int priority = 0, stackPriority = 0, low = 1, mid = 2, high = 3, veryHigh = 4;

	for (int i = 0; exp[i] != '\0'; i++) {
		//for digits
		if (exp[i] >= '0' && exp[i] <= '9') {
				expRPN[RPNcntr] = exp[i];
				RPNcntr++;
		//for symbols
		} else if (stackRPN.empty() == true) {
			stackRPN.push(exp[i]);
		} else if (stackRPN.empty() == false) {
			//get priority
			priority = getPriority (exp[i]);
			stackPriority = getPriority (stackRPN.top());
			//sort station
			if (priority == low) {
				stackRPN.push(exp[i]);
			} else if ((priority == high || priority == mid) && stackPriority == low) {
				stackRPN.push(exp[i]);
			} else if (priority == mid && stackPriority != low) {
				expRPN[RPNcntr] = stackRPN.top();
				RPNcntr++;
				stackRPN.pop();
				stackRPN.push(exp[i]);
			} else if (priority == high && stackPriority == high) {
				expRPN[RPNcntr] = stackRPN.top();
				RPNcntr++;
				stackRPN.pop();
				stackRPN.push(exp[i]);
			} else if (priority == high && stackPriority == mid) {
				stackRPN.push(exp[i]);
			} else if (priority == veryHigh) {
				for (int i = 0; stackRPN.top() != '('; i++) {
					expRPN[RPNcntr] = stackRPN.top();
					RPNcntr++;
					stackRPN.pop();
				}
				stackRPN.pop();
			}
		}
	}

	//clear stack
	while (!stackRPN.empty()) {
		expRPN[RPNcntr] = stackRPN.top();
		RPNcntr++;
		stackRPN.pop();
	}
	//do '\0'
	exp[RPNcntr + 1] = '\0';
}

int getPriority (char exp) {

	if (exp == '+' || exp == '-') {
		return 2; // mid
	} else if (exp == '*' || exp == '/') {
		return 3; // high
	} else if (exp == '(') {
		return 1; // low
	} else if (exp == ')') {
		return 4; // veryHigh
	}
}

double doComputing (stack <double> compStack, char expRPN[]) {

	int decisionMaker = 0, prioritySymbol = 1, priorityDigit = 2;
	int plus = 1, minus = 2, mult = 3, dev = 4;
	char tempArray[2] = "";
	double result = 0.0;

	for (int i = 0; expRPN[i] != '\0'; i++) {
		if (compStack.empty() == true) {
			tempArray[0] = expRPN[i];
			compStack.push(atof(tempArray));
		} else if (compStack.empty() == false) {
			decisionMaker = checkRPN (expRPN[i]);
			if (decisionMaker == priorityDigit) {
				tempArray[0] = expRPN[i];
				compStack.push(atof(tempArray));
			} else if (decisionMaker == prioritySymbol) {
				decisionMaker = checkOperation (expRPN[i]);
				if (decisionMaker == plus) {
					result = doMathematic(compStack, plus);
					cout << endl << "Result of plus: " << result;
					compStack.push (result);
				} else if (decisionMaker == minus) {
					result = doMathematic(compStack, minus);
					cout << endl << "Result of minus: " << result;
					compStack.push (result);
				} else if (decisionMaker == mult) {
					result = doMathematic(compStack, mult);
					cout << endl << "Result of mult: " << result;
					compStack.push (result);
				} else if (decisionMaker == dev) {
					result = doMathematic(compStack, dev);
					cout << endl << "Result of dev: " << result;
					compStack.push (result);
				}
			}
		}
	}

	return compStack.top();
}

int checkRPN (char expRPN) {

	if (expRPN == '+' || expRPN == '-' || expRPN == '/' || expRPN == '*') {
		return 1;
	}
	return 2;
}

int checkOperation (char expRPN) {

	if (expRPN == '+') {
		return 1;
	} else if (expRPN == '-') {
		return 2;
	} else if (expRPN == '*') {
		return 3;
	} else if (expRPN == '/') {
		return 4;
	}
}

double doMathematic (stack <double> compStack, int symbol) {

	double digit1 = 0.0, digit2 = 0.0, result = 0.0;

	digit2 = compStack.top();
	cout << endl << endl << "top (digit2): " << digit2;
	compStack.pop();
	digit1 = compStack.top();
	cout << endl <<  "top (digit1): " << digit1;
	compStack.pop();
	

	if (symbol == 1) {
		result = digit2 + digit1;
	} else if (symbol == 2) {
		result = digit1 - digit2;
	} else if (symbol == 3) {
		result = digit1 * digit2;
	} else if (symbol == 4) {
		result = digit1 / digit2;
	}		

	return result;
}