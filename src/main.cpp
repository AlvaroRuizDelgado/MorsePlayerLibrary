#include <iostream>
#include <fstream>
#include <sstream>
#include "morse.hpp"

// #include </usr/local/include/portaudio.h>
#include "portaudio.h"
#include "sine.h"

int main(void) {
    
    Morse morse;

    // std::string example ("Will proceed to process 1 file.");
    std::string example ("Maite Alpaca");
    morse.textToMorse(&example);

    // morse.playDot();
    // morse.playDash();

    // std::cout << "Input word to translate:\n";
    // std::string request;
    // std::cin >> request;
    // morse.textToMorse(&request);

    return EXIT_SUCCESS;
}