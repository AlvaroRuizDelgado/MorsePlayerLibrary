#include "morse.hpp"

void Morse::textToMorse(std::string *text) {
    int i = 0;
    for (char& c : *text) {
        if ('a' <= c && c <= 'z') {     // Alternative: store capital letters in dictionary --> more often out of cache.
            c = c^0x20;
        }
        i = charToMorse(&c);
        std::cout << c << ": " << morse_[i] << "\n";
    }
}

int Morse::charToMorse(char *c) {
    int i = (int) (*c - '0');
    if (0 < i && i < ALPHABET_SIZE) {
        return i;
    }
    return ALPHABET_SIZE-1;
}