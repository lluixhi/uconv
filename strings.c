#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Returns index of first char which is not whitespace after startindex. If it's all whitespace, return -1
int impCharInd(const char input[], const unsigned long startIndex) {
    unsigned long i;
    for(i = startIndex; i != strlen(input); ++i) {
        if(!input[i])
            break;
        if(!isspace(input[i]))
            return i;
    }
    return -1;
}

// Convert User char[] to char*[] based on whitespace
void whitespaceSplit(const char input[], char** exprbuffer, const unsigned long exprBuffLen) {
    // Loop counter, substring length, and counter for exprbuffer.
    int i, j = 0;
    unsigned long k = 0;
    for(i = impCharInd(input, 0); i != (int) strlen(input); ++i){
        if(input[i] && !isspace(input[i]))
            j++;
        else if(j) {
            char *substr = malloc((j + 1) * sizeof(char));
            strncpy(substr, input + i - j, j);
            substr[j] = 0;
            exprbuffer[k] = substr;
            k++;
            if((i = impCharInd(input, i)) == -1 || k == exprBuffLen)
                break;
            j = 1;
        } else break;
    }
}
