#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Returns index of first char which is not a char matching FP after startindex.
 * If it's all whitespace, return -1
 */
int
impCharInd(const char input[], int charType (int), const unsigned long startIndex)
{
    unsigned long i;
    for(i = startIndex; i != strlen(input); ++i) {
        if(!input[i])
            break;
        if(!charType(input[i]))
            return i;
    }
    return -1;
}

/*
 * Convert User char[] to char*[] based on whitespace
 */
void
charTypeSplit(const char input[], char** exprbuffer, int charType (int), const unsigned long exprBuffLen)
{
    // Loop counter, substring length, and counter for exprbuffer.
    int i, j = 0;
    unsigned long k = 0;
    for(i = impCharInd(input, charType, 0); i != (int) strlen(input); ++i){
        if(input[i] && !charType(input[i]))
            j++;
        else if(j) {
            char *substr = malloc((j + 1) * sizeof(char));
            strncpy(substr, input + i - j, j);
            substr[j] = 0;
            exprbuffer[k] = substr;
            k++;
            if((i = impCharInd(input, charType, i)) == -1 || k == exprBuffLen)
                break;
            j = 1;
        } else break;
    }
    return;
}

void
whitespaceSplit(const char input[], char** exprbuffer, const unsigned long exprBuffLen) {
    charTypeSplit(input, exprbuffer, &isspace, exprBuffLen);
    return;
}

int isNewLine(int character) {
    if(character == '\n')
        return 1;
    return 0;
}
