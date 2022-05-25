#include "InputValidator.hpp"

bool InputValidator::isDigit(char input)
{
    return ((input-48) >= MIN_INPUT_VAL && 
            (input-48) <= MAX_INPUT_VAL);
}

bool InputValidator::isOperation(char input)
{
    return (input == '+' ||
            input == '-' ||
            input == '*' ||
            input == '/');
}

bool InputValidator::isEqualitySign(char input)
{
    return input == '=';
}

bool InputValidator::isValid(char input)
{
    return (isOperation(input) || 
            isDigit(input) ||
            isEqualitySign(input));
}