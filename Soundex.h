#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    static const char soundexTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '0', '0', '2', '0', '2'
    };
    c = (char)toupper(c);
    if (c >= 'A' && c <= 'Z') {
        return soundexTable[c - 'A'];
    }
    return '0';
}

void generateSoundex(const char *name, char *soundex) {
    int len = (int)strlen(name);
    int sIndex = 1;
    char prevCode = '0';

    soundex[0] = (char)toupper(name[0]);

    for (int i = 1; i < len; i++) {
        char code = getSoundexCode(name[i]);

        // If code is valid and different from the previous one
        if (code != '0' && code != prevCode) {
            soundex[sIndex++] = code;
        }

        // Update prevCode regardless of whether the code was added
        prevCode = code;

        // Stop if soundex string is full
        if (sIndex == 4) {
            break;
        }
    }

    // Fill remaining spaces with '0'
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
