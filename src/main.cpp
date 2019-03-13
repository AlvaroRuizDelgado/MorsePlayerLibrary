#include <iostream>
#include <fstream>
#include <sstream>
#include "morse.hpp"

#include "portaudio.h"
#include "sine.h"

int main(void) {
    
    Morse morse;

    std::string example ("Captain, we have new orders for you.");
    morse.textToMorse(&example);
    std::cout << "\n";

    // std::cout << "Input word to translate:\n";
    // std::string request;
    // std::cin >> request;
    // morse.textToMorse(&request);

    return EXIT_SUCCESS;
}