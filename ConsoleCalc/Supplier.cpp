#include "Supplier.h"
#include "Predicate.h"

#include <iostream>
using namespace std;

bool getDouble(double&);
bool getOperation(char&);

static int IGNORE = 1024;


bool Supplier::get(double& first, double& second, char& operation, bool getX)
{
    Predicate predicate;

    double x = 0, y = 0;
    bool a = false, b = false, c = false;
    char o;

    cout << "Please enter the operation to perform. Format: " << (getX ? "a+b | a-b | a*b | a/b" : "+b | -b | *b | /b, 'c' for clear result or 'q' for quit") << endl;

    a = getX ? getDouble(x) : true;
    if (a) {
        b = getOperation(o);
        if (b) {
            if (predicate.isClear(o) || predicate.isQuit(o)) {
                second = 0; operation = o;
                if (predicate.isClear(o)) first = 0;
                return true;
            }
            c = getDouble(y);
        }
    }

    if (a && b && c) {
        first = getX ? x : first;
        second = y;
        operation = o;
        return true;
    }
    return false;
}

bool getDouble(double& value)
{
    double n;
    cin >> n;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(IGNORE, '\n');
        return false;
    }
    value = n;
    return true;
}

bool getOperation(char& value)
{
    char o;
    cin >> o;
    if (!cin.fail()) {
        if (o == '*' || o == '/' || o == '+' || o == '-' || o == 'c' || o == 'C' || o == 'q' || o == 'Q') {
            value = o;
            return true;
        }
    }
    cin.clear();
    cin.ignore(IGNORE, '\n');
    return false;
}