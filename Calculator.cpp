#include <stdexcept>

#include "Calculator.hpp"

int Calculator::subtract(int a, int b)
{
    return a-b;
}

int Calculator::multiply(int a, int b)
{
    return a*b;
}

int Calculator::divide(int a, int b)
{
    return a/b;
}

int Calculator::performOperation(int a, int b, char operation)
{
    switch (operation)
    {
        case '+' :
            return add(a, b);
        case '-' :
            return subtract(a, b);
        case '*' :
            return multiply(a, b);
        case '/' :
            return divide(a, b);
        default:
            throw std::runtime_error("INVALID_OPERATION_TYPE");
    }
}