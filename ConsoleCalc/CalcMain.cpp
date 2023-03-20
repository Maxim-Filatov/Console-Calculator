#include "CalcMain.h"
#include "Supplier.h"
#include "Predicate.h"
#include <iostream>
#include "Calculator.h"
using namespace std;

void CalcMain::run(double& result)
{
	Supplier supplier;
	Predicate predicate;
	Calculator calculator;

	double x, y;
	char o;
	bool isBreak = false;

	while (!isBreak)
	{
		result = 0.0; x = 0; y = 0; o = '.';
		if (supplier.get(x, y, o, true)) {
			if (calculator.calculate(x, y, o)) {
				result = x;
				cout << "* First result: " << result << endl;
			}
			else {
				if (predicate.isQuit(o)) {
					isBreak = true;
					break;
				}
				cout << "ERROR: Invalid operation type, please enter again" << endl;
				continue;
			};
		}
		else {
			cout << "ERROR: Invalid operation type or number(s), please enter again" << endl;
			continue;
		}

		while (!isBreak) {
			if (supplier.get(result, y, o, false)) {
				if (calculator.calculate(result, y, o)) {
					cout << "* Current result: " << result << endl;
				}
				else {
					if (predicate.isClear(o)) {
						break;
					}
					if (predicate.isQuit(o)) {
						isBreak = true;
						break;
					}
					cout << "ERROR: Invalid second number, please enter again" << endl;
					continue;
				};
			}
			else {
				cout << "ERROR: Invalid operation type, please enter again" << endl;
				continue;
			}
		}
	}
}

