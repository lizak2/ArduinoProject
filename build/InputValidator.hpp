#ifndef INPUT_VALIDATOR_HPP
#define INPUT_VALIDATOR_HPP

#include <cstdint>

class InputValidator
{
public:
    static bool isDigit(char input);
    static bool isOperation(char input);
    static bool isEqualitySign(char input);
    static bool isValid(char input);

private:
    const static std::uint8_t MIN_INPUT_VAL = 0;
    const static std::uint8_t MAX_INPUT_VAL = 9;
};

#endif // INPUT_VALIDATOR_HPP
