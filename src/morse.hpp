#pragma once
#ifndef MORSEH
#define MORSEH

#include <iostream>
#include "sine.h"

// #define DOT_SECONDS (0.3)

class Morse
{
public:
    Morse() : dotDurationSec_(0.06) {};
    int charToMorse(char *character);
    void textToMorse(std::string *text);
    int playTone(float durationSec);
    void playDot();
    void playDash();
    void playSilence(float durationInDots);
    void playMorse(std::string *morse);

private:
    Sine sine_;
    float dotDurationSec_;
    static const int dashDurationInDots {3};
    static const int dotsBetweenBeeps {1};          // Always added after a beep.
    static const int dotsExtraBetweenLetters {2};   // Always added after a letter -> 3 in total
    static const int dotsExtraBetweenWords {4};     // 7 in total, counting the previous ones
    static const int ALPHABET_SIZE {44};    // 37 without dummy characters
    char alphabet_[ALPHABET_SIZE] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                                   ':', ';', '>', '=', '<', '?', '@',   // dummy characters
                                   'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                                   'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                                   'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
    std::string morse_[ALPHABET_SIZE] {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",
                                       " ", " ", " ", " ", " ", " ", " ", // dummy characters
                                       ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                                       "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                                       "..-", "...-", ".--", "-..-", "-.--", "--..", " "};
};

#endif