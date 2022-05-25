#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

class Calculator
{
public:
    Calculator() = default;

    static int add(int a, int b)
    {
        return a+b;
    }

    static int subtract(int a, int b);
    static int multiply(int a, int b);
    static int divide(int a, int b);

    static int performOperation(int a, int b, char operation);

    template <typename Type>
    static Type altAdd(Type a, Type b);
};

template <typename T>
T Calculator::altAdd(T a, T b)
{
    return a+b;
}

#endif // CALCULATOR_HPP