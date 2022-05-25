#include <iostream>

#include "InterfaceWrapper.hpp"

// placeholder for interface function providing input
// getKey() whateva
char interface_get_input()
{
    char input;
    std::cin >> input;
    return input;
}

char InterfaceWrapper::getUserInput()
{
    return interface_get_input();
}
