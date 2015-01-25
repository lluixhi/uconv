#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../lib/strings.h"

#define BUFSIZE 100
#define EXPRESSIZE 10

int main(const int argc, const char** argv ) {
    char **expressionbuffer;
    char entry[BUFSIZE];

    while(1) {
        expressionbuffer = calloc(EXPRESSIZE, sizeof(char*));
whileStart:
        printf(">> ");
        fgets(entry, BUFSIZE, stdin);
        if(impCharInd(entry, &isspace, 0) == -1)
            goto whileStart;
        if(entry[impCharInd(entry, &isspace, 0)] == 'q') {
            free(expressionbuffer);
            break;
        }
        whitespaceSplit(entry, expressionbuffer, EXPRESSIZE);
        int i;
        for(i = 0; expressionbuffer[i]; i++)
            printf("%s\n", expressionbuffer[i]);
        free(expressionbuffer);
    }
    return 0;
}
