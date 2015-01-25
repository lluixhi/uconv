#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib/strings.h"
#include "lib/data/link.h"

#define LINEMAXLEN 40
#define EXPBUFLEN 20

/*
 * Adds link into the tree.
 */
void addLink(Link* link) {
    int i;
    printf("%s\n%s\n%s\n", link->type, link->name1, link->name2);
    for(i = 0; link->expression[i]; i++)
        printf("%s ", link->expression[i]);
    printf("\n\n");
    return;
}

int
loadConf(char* fileContents) {
    // Link pieces.
    Link* link;
    char* typeLabel;
    char* unit1;
    char* unit2;
    char** exprbuffer;

    // Temporary Pieces.
    char* expression;
    int label = 0;
    int i, j;

    for(i = 0; i < (int) strlen(fileContents); i++) {
        /*
         * Check if the line starts with '#', if so, it's a comment.
         */
        if(fileContents[i] == '#') {
            while(fileContents[i] != '\n')
                i++;
        }

        /*
         * Check if the line starts with '\n', if so, it's the end of a
         * block, and we commit the link.
         */
        else if(fileContents[i] == '\n') {
            link = malloc(sizeof(Link));
            link->type = typeLabel;
            link->name1 = unit1;
            link->name2 = unit2;
            link->expression = exprbuffer;
            addLink(link);
        }

        /*
         * Check if the line starts with a '@', if so, it's a type label
         * we keep type labels until a new one is declared.
         */
        else if(fileContents[i] == '@') {
            typeLabel = malloc(sizeof(char) * LINEMAXLEN);
            for(j = 0; fileContents[i] != '\n'; j++) {
                i++;
                typeLabel[j] = fileContents[i];
            }
            j--;
            typeLabel[j] = 0;
        }

        /*
         * Finally, we catch everything else, which are normal input lines.
         */

        else{
            if(label == 0) {
                unit1 = malloc(sizeof(char) * LINEMAXLEN);
                for(j = 0; fileContents[i] != '\n'; j++) {
                    unit1[j] = fileContents[i];
                    i++;
                }
                unit1[j] = 0;
                label++;
            } else if(label == 1) {
                unit2 = malloc(sizeof(char) * LINEMAXLEN);
                for(j = 0; fileContents[i] != '\n'; j++) {
                    unit2[j] = fileContents[i];
                    i++;
                }
                unit2[j] = 0;
                label++;
            } else {
                expression = malloc(sizeof(char) * LINEMAXLEN);
                for(j = 0; fileContents[i] != '\n'; j++) {
                    expression[j] = fileContents[i];
                    i++;
                }
                // Subtle bug in whitespace split? Last character in string cannot be 0.
                // This is bad. REALLY BAD.
                expression[j] = ' ';
                label = 0;
                exprbuffer = calloc(EXPBUFLEN, sizeof(char*));
                whitespaceSplit(expression, exprbuffer, EXPBUFLEN);
            }
        }
    }
    return 1;
}
