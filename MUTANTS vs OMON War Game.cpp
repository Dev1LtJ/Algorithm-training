#include <iostream>
#include <cmath>
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define RESET "\033[0m"
#define BOLDGREEN "\033[1m\033[32m"      /* Bold Green */
#define BOLDWHITE "\033[1m\033[37m"      /* Bold White */

using namespace std;

int main() {



	//initialization (introducing the game)
	cout << GREEN << "MUTANTS vs OMON war game v.1" << RESET << endl << endl;
	int mutants = 0, growthPercent = 0, reductRate = 0, daysCounter = 0, mutantsToday = 0, rate = 0;
	double mutantsDouble = 0.0, growthPercentDouble = 0.0, reductRateDouble = 0.0;

	//input (game variables)
	cout << RED << "Input initial MUTANTS quantity: " << RESET;
	cin >> mutantsDouble;
	cout << YELLOW << "Input percents of growth of MUTANTS, %: " << RESET;
	cin >> growthPercentDouble;
	cout << BLUE << "Input quantity of MUTANTS, that OMON kills everyday: " << RESET;
	cin >> reductRateDouble;

	//input processing (integer values check)
	mutants = mutantsDouble;
	growthPercent = growthPercentDouble;
	reductRate = reductRateDouble;

	if ((mutantsDouble - mutants) !=0 || (growthPercentDouble - growthPercent) !=0 || (reductRateDouble - reductRate) !=0 ) {
		cout << endl << RED << "Error! According to the the game conditions integer values must be entered" << RESET << endl;
		return 1;
	}

	//input processing (incorrent inputs)
	if (mutants < 1) {
		cout << RED << "Error! MUTANTS quantity can't be less than 1" << RESET << endl;
		return 2;
	}
	if (growthPercent < 1) {
		cout << RED << "Error! According to the the game conditions MUTANTS must GROW with at least 1 % rate" << RESET << endl;
		return 3;
	}
	if (reductRate < 1) {
		cout << RED <<"Error! According to the game conditions OMON must kill at least 1 MUTANT PER DAY" << RESET << endl;
		return 4;
	}


	//input processing (rate calculation)
	rate = (mutants * growthPercent / 100) - reductRate;
	cout << endl << MAGENTA << "MUTANT population rate per FIRST day with this pre-input data in absolute values: " << RESET << rate << endl << endl;
	
	//input processing (estimating the chances)
	if (rate > 0) {
		cout << RED << "There is no way to win this war. Run!" << RESET << endl;
		return 0;
	} else if (rate == 0) {
		cout << BLUE << "Infinity war! (hello Marvel)" << RESET << endl;
		return 0;
	} else {
		cout << GREEN << "OK! We have chances to win! Let's Go! " << RESET << endl << endl;
	}

	//logic (war)
	mutantsToday = mutants;
	while (mutants > 0) {
		rate = (mutantsToday * growthPercent / 100) - reductRate;
		cout << "MUTANT population rate per " << CYAN << daysCounter << RESET << " day: " << MAGENTA << rate << RESET << endl;
		rate = abs(rate);
		mutants = mutantsToday - rate;
			if (mutants > 0) {
				cout << "MUTANT population after " << CYAN << daysCounter << RESET << " day: " << RED << mutants << RESET << endl;
			} else {
				mutants = 0;
				cout << "MUTANT population after " << CYAN << daysCounter << RESET << " day: " << RED << mutants << RESET << endl;
			}
		mutantsToday = mutants;
		daysCounter++;
	} 
	
	//output (result)
	cout << endl << BOLDWHITE << "Victory will be won in " << BOLDGREEN << daysCounter << RESET << " days" << endl;
	return 0;
}