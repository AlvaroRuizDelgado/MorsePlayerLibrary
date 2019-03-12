# Morse library

Morse library based on a double array for storing the morse dictionary. See [this other repository](https://github.com/AlvaroRuizDelgado/MorseConversionSpeedComparison) for further detail on speed considerations when choosing the data structure to hold this information.

## Details

It is still a work in progress, but the intention is to create a simple library that will play the morse sounds for an input string.

The Sine class is based on Port Audio's example "paex_sine.cpp" (by Ross Bencina and Phil Burk).

## Morse conversion table

![](International_Morse_Code.png)

## Compilation

We have to include portaudio's header and library, and also Apple's framework if you using a Mac.

In my system (substitute header and library path as appropriate):
```bash
g++ *.cpp -o test.exe -I/usr/local/include /usr/local/lib/libportaudio.a \
        -framework CoreServices -framework CoreFoundation -framework AudioUnit \
        -framework AudioToolbox -framework CoreAudio
./test.exe
```
