#include "Predicate.h"

bool Predicate::isClear(char operation)
{
    return operation == 'c' || operation == 'C';
}

bool Predicate::isQuit(char operation)
{
    return operation == 'q' || operation == 'Q';
}
