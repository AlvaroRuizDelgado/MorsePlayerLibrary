#include <iostream>
#include <fstream>
#include <sstream>
#include "morse.hpp"

// #include </usr/local/include/portaudio.h>
// #include "portaudio.h"

int main(void) {
    
    Morse morse;

    std::string example ("Will proceed to process 1 file.");
    morse.textToMorse(&example);

    // PaError err = Pa_Initialize();

    // std::cout << "Input word to translate:\n";
    // std::string request;
    // std::cin >> request;
    // morse.textToMorse(&request);

    return EXIT_SUCCESS;
}