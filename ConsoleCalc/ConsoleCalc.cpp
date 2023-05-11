#include <iostream>
#include "CalcMain.h"

using namespace std;

int main()
{   cout << "*** Console calculator. (C) 2023 by Max Filatov" << endl;
    double result;
    CalcMain calcMain;
    calcMain.run(result);
    cout << "Last result: " << result << endl;
}

