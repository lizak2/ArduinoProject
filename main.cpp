#include "Calculator.hpp"
#include "InputHandler.hpp"

#include <exception>
#include <iostream>

// placeholder for arduino's loop()
void loop()
{
    try {
        InputHandler inputHandler;
        inputHandler.start();
    } catch (const std::exception& e) {
        std::cout << "Program exited an exception: " << e.what() << std::endl;
        return;
    } catch (...)  {
        std::cout << "Program exited an error" << std::endl;
    }

    std::cout << "Program exited with success!" << std::endl;
    return;
}

int main()
{
    loop();
}