#include <stdio.h>
#include <stdlib.h>
#include "../strings.h"

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
        if(impCharInd(entry, 0) == -1)
            goto whileStart;
        if(entry[impCharInd(entry, 0)] == 'q') {
            free(expressionbuffer);
            break;
        }
        whitespaceSplit(entry, expressionbuffer, EXPRESSIZE);
        int i;
        for(i = 0; i < EXPRESSIZE; i++) {
            if(expressionbuffer[i]) {
                printf("%s\n", expressionbuffer[i]);
                free(expressionbuffer[i]);
            }
            else break;
        }
        free(expressionbuffer);
    }
    return 0;
}
