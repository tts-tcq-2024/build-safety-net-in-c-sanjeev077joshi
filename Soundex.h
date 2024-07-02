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

    soundex[0] = (char)toupper(name[0]);
    int sIndex = 1;
    char prevCode = '0';

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex[sIndex++] = code;
            prevCode = code;
        }
    }

    for (; sIndex < 4; sIndex++) {
        soundex[sIndex] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
