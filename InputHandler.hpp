#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <cstdint>
#include <vector>

#include "InputValidator.hpp"

class InputHandler
{
public:
    void start();

    InputHandler()
    {
        firstNumberDigits_.reserve(4);
        secondNumberDigits_.reserve(4);
    }

    class DigitToNumberConverter
    {
        public:
        static int convertNumberDigitsToNumber(std::vector<int> numbersDigits);
    };

private:
    const static std::uint8_t MAX_NUMBERS_DIGITS = 4;

    bool programTerminationTriggered(char input);
    bool clearTriggered(char input);
    
    bool numbersAreEmpty();
    bool operationIsSet();
    void clearAllStoredValues();

    void setFirstNumber(int number);
    void setSecondNumber(int number);
    void setOperation(char operation);

    int firstNumber_ = 0;
    char operation_ = '\0';
    int secondNumber_ = 0;
    std::vector<int> firstNumberDigits_;
    std::vector<int> secondNumberDigits_;

    bool firstNumberFilled_ = false;
    bool secondNumberFilled_ = false;
};

#endif // INPUT_HANDLER_HPP