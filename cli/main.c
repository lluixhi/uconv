#include <stdio.h>
#include <stdlib.h>
#include "../strings.h"
#include "../conversion.h"

#define BUFSIZE 100

void printHelp();
char entry[BUFSIZE];

int main(const int argc, const char** argv ) {

    while(1) {
whileStart:
        printf(">> ");
        fgets(entry, BUFSIZE, stdin);
        if(impCharInd(entry, 0) == -1)
            goto whileStart;
        if(entry[impCharInd(entry, 0)] == 'q')
            break;
        if(entry[impCharInd(entry, 0)] == 'c')
            doConversion();
        if(entry[impCharInd(entry, 0)] == 'a')
            addConversion();
        if(entry[impCharInd(entry, 0)] == 'h' || entry[impCharInd(entry, 0)] == '?')
            printHelp();
    }
    return 0;
}

void printHelp() {
    printf("c(onv):\
            \tWrite c, then the conversion.\n\
            \t\tExample:\n\
            \t\t>> c 50m ft\n\
            \t\t164.04 ft\n\n");
    printf("a(dd):\
            \tWrite a, then the conversion to add it to the conversion dictionary.\n\
            \t\tExample:\n\
            \t\t >>a m ft 3.281\n\n");
    printf("h(elp):\
            \tPrints help.\n\n");
    printf("q(uit):\
            \tQuits.\n");
    return;
}
