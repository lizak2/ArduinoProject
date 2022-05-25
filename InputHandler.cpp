#include <cmath>
#include <cstdint>
#include <exception>
#include <iostream>

#include "Calculator.hpp"
#include "InputHandler.hpp"
#include "InterfaceWrapper.hpp"

void InputHandler::start()
{
    std::cout << "Welcome to dummy calculator!\n";
    std::cout << "Please provide a first number up to 4 digits!\n";
    std::cout << "Then provide an operation type: \"+\" or \"-\" or \"*\" or \"/\"\n";
    std::cout << "Please provide a second number up to 4 digits!\n";

    char input = '\0';
    while (true) 
    {
        std::cout << "FirstNumber: " << firstNumberDigits_[0]
                                     << firstNumberDigits_[1]
                                     << firstNumberDigits_[2]
                                     << firstNumberDigits_[3] << "\n"
                  << "Operation: "   << operation_ << "\n"
                  << "SecondNumber: " << secondNumberDigits_[0]
                                      << secondNumberDigits_[1]
                                      << secondNumberDigits_[2]
                                      << secondNumberDigits_[3] << "\n";
        
        input = InterfaceWrapper::getUserInput();

        if (programTerminationTriggered(input)) 
        {
            std::cout << "User terminated the program.\n";
            return;
        } 
        
        if (clearTriggered(input))  
        {
            clearAllStoredValues();
            std::cout << "All values have been cleaned.\n";
        }

        if (!InputValidator::isValid(input)) 
        {
            std::cout << "Please provide valid input.\n";
            continue;
        } 

        if (InputValidator::isEqualitySign(input) && !numbersAreEmpty() && operationIsSet())
        {
            firstNumber_ = DigitToNumberConverter::convertNumberDigitsToNumber(firstNumberDigits_);
            secondNumber_ = DigitToNumberConverter::convertNumberDigitsToNumber(secondNumberDigits_);

            int result = Calculator::performOperation(firstNumber_, secondNumber_, operation_);

            std::cout << "\n" << firstNumber_ << " " << operation_<< " " << secondNumber_ << " = " << result << "\n";
            return;
        }

        if (InputValidator::isOperation(input))
        {
            std::cout << "Setting operation to: " << input << "\n";
            setOperation(input);
        }

        if (InputValidator::isDigit(input) && !operationIsSet() && !firstNumberFilled_)
        {
            firstNumberDigits_.push_back(static_cast<int>(input-48));
        }

        if (firstNumberDigits_.size() == MAX_NUMBERS_DIGITS || operationIsSet())
        {
            firstNumberFilled_ = true;
        }

        if (firstNumberDigits_.size() == MAX_NUMBERS_DIGITS && !operationIsSet())
        {
            std::cout << "You provided four digits for first number, please set operation.\n";
        }

        if (InputValidator::isDigit(input) && operationIsSet() && !secondNumberFilled_) {
            secondNumberDigits_.push_back(static_cast<int>(input-48));
        }

        if (secondNumberDigits_.size() == MAX_NUMBERS_DIGITS)
        {
            secondNumberFilled_ = true;
        }

        if (secondNumberDigits_.size() == MAX_NUMBERS_DIGITS && operationIsSet())
        {
            std::cout << "You provided four digits for second number, please hit \"=\" sign.\n";
        }
    }
}

bool InputHandler::programTerminationTriggered(char input)
{
    return (input == 'Q' || input == 'q');
}

bool InputHandler::clearTriggered(char input)
{
    return (input == 'C' || input == 'c');
}


bool InputHandler::numbersAreEmpty()
{
    return (firstNumberDigits_.size() == 0 && 
            secondNumberDigits_.size() == 0);
}

bool InputHandler::operationIsSet()
{
    return InputValidator::isOperation(operation_);
}

void InputHandler::clearAllStoredValues()
{
    firstNumber_ = 0;
    operation_ = '\0';
    secondNumber_ = 0;
    firstNumberDigits_.clear();
    firstNumberDigits_.clear();
    firstNumberFilled_ = false;
    secondNumberFilled_ = false;
}

void InputHandler::setFirstNumber(int number)
{
    firstNumber_ = number;
}

void InputHandler::setSecondNumber(int number)
{
    secondNumber_ = number;
}

void InputHandler::setOperation(char operation)
{
    operation_ = operation;
}

int InputHandler::DigitToNumberConverter::convertNumberDigitsToNumber(std::vector<int> numbersDigits)
{
    int result = 0;
    for (int i = numbersDigits.size()-1, j = 0; i >= 0; --i, ++j) {
        int base = std::pow(10, j);
        result += numbersDigits[i]*base;
    }
    return result;
}