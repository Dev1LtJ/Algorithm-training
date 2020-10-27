 /* 1. ТАБЛИЦА УМНОЖЕНИЯ. Напечатайте квадратную таблицу умножения 10х10. */

#include <iostream>
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define CYAN    "\033[36m"      /* Cyan */
#define BOLDWHITE "\033[1m\033[37m"      /* Bold White */
#define RESET "\033[0m"

using namespace std;

int main() {

	//initialization
	cout << endl << BOLDWHITE << "Multiplication table" << RESET << endl << endl;
	int x = 1, y = 1, z = 1;

	//logic-output
	while (x < 11 && y < 11) {
		z = x * y;
		if (z < 10) {
			cout << YELLOW << x << RESET << " X " << CYAN << y << RESET << " = " << GREEN << z << RESET << "   |   ";
		} else if (z > 9 && x < 10) {
			cout << YELLOW << x << RESET << " X " << CYAN << y << RESET << " = " << GREEN << z << RESET << "  |   ";
		} else if (x == 10) {
			cout << YELLOW << x << RESET << " X " << CYAN << y << RESET << " = " << GREEN << z << RESET << " |   ";
		}
		y++;
		if (y > 10) {
			x++;
			y = 1;
			cout << endl;
		}
	}
	return 0;
}