#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../lib/strings.h"
#include "../lib/data/link.h"
#include "../lib/file.h"

#include "../setup.h"
#include "../conversion.h"

#define BUFSIZE 100

void printHelp();
char entry[BUFSIZE];

int main() {
    /*
     * First, load the configuration file into RAM
     */
    FILE* confFile = fopen("config","r+"); // Todo -- support config file in users' directory.
    char* confFileContents = fileAsString(confFile);

    /*
     * Second, translate file into the linked list/tree format in RAM.
     */
    loadConf(confFileContents);
    free(confFileContents);

    /*
     * Third, enter the main loop.
     */
    while(1) {
whileStart:
        printf(">> ");
        if(fgets(entry, BUFSIZE, stdin)) {
            if(impCharInd(entry, &isspace, 0) == -1)
                goto whileStart;
            switch(entry[impCharInd(entry, &isspace, 0)]) {
                case 'q':
                    goto exitLoop;
                case 'c':
                    doConversion();
                    break;
                case 'a':
                    addConversion();
                    break;
                case 'h':
                    printHelp();
                    break;
                case '?':
                    printHelp();
                    break;
                default:
                    break;
            }
        }
    }
exitLoop:

    /*
     * Fourth, convert the linked list structure in RAM into a string.
     */

    /*
     * Fifth, write the string to the config file.
     */

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
            \t\t>> a m ft 3.281\n\n");
    printf("h(elp):\
            \tPrints help.\n\n");
    printf("q(uit):\
            \tQuits.\n");
    return;
}
