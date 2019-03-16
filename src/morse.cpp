#include "morse.hpp"

void Morse::textToMorse(std::string *text) {
    int i = 0;
    for (char& c : *text) {
        if ('a' <= c && c <= 'z') {     // Alternative: store capital letters in dictionary --> more often out of cache.
            c = c^0x20;
        }
        i = charToMorse(&c);
        std::cout << c; // << ": " << morse_[i] << "\n";
        fflush(stdout);
        playMorse(&morse_[i]);
    }
}

int Morse::charToMorse(char *c) {
    int i = (int) (*c - '0');
    if (0 <= i && i < ALPHABET_SIZE) {
        return i;
    }
    return ALPHABET_SIZE-1;
}

void Morse::playDot() {
    playTone( dotDurationSec_ );
    playSilence( dotsBetweenBeeps );
}

void Morse::playDash() {
    playTone( dashDurationInDots * dotDurationSec_ );
    playSilence( dotsBetweenBeeps);
}

void Morse::playSilence(float durationInDots) {
    Pa_Sleep( durationInDots * dotDurationSec_ * 1000);
}

void Morse::playMorse(std::string *morse) {
    if ( !morse->compare(morse_[ALPHABET_SIZE-1]) ) {
        playSilence( dotsExtraBetweenWords );
    }
    else {
        for (char& c : *morse) {
            if ( c == '.' ) {
                playDot();
            }
            else if ( c == '-' ) {
                playDash();
            }
            else {
                std::cout << "Unexpected character in a morse symbol.";
            }
        }
    }
    playSilence( dotsExtraBetweenLetters );
}

int Morse::playTone(float durationSec) {

    ScopedPaHandler paInit;
    if( paInit.result() != paNoError ) goto error;

    if (sine_.open(Pa_GetDefaultOutputDevice()))
    {
        if (sine_.start())
        {
            // printf("Play for %f seconds.\n", DOT_SECONDS );
            Pa_Sleep( durationSec * 1000 );

            sine_.stop();
        }

        sine_.close();
    }

    // printf("Test finished.\n");
    return paNoError;

error:
    fprintf( stderr, "An error occured while using the portaudio stream\n" );
    fprintf( stderr, "Error number: %d\n", paInit.result() );
    fprintf( stderr, "Error message: %s\n", Pa_GetErrorText( paInit.result() ) );
    return 1;
}
