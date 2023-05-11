#include "ClearIn.h"
#include <iostream>

using namespace std;

static int IGNORE = 1024;

void ClearIn::clear() {
	cin.clear();
	cin.ignore(IGNORE, '\n');
}