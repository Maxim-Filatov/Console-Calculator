#include "Calculator.h"
#include <iostream>

using namespace std;

bool Calculator::calculate(double& x, double& y, char& operation) {
	switch (operation)
	{
	case '+':
		x += y;
		return true;
	case '-':
		x -= y;
		return true;
	case '*':
		x *= y;
		return true;
	case '/':
		if (y == 0) {
			cout << "ERROR: Second number is zero, please enter again" << endl;
			return false;
		}
		x /= y;
		return true;
	default:
		return false;
	}

}

