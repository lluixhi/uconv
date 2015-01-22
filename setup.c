#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib/strings.h"
#include "lib/data/link.h"

#define LINEMAXLEN 40
#define EXPBUFLEN 20

/*
 * Does the legwork in adding the link into the tree.
 */
void
addLink(Link* link) {

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

    for(i = 0; i < strlen(fileContents); i++) {
        /*
         * Check if the line starts with '\n', if so, it's the end of a
         * block, and we commit the link.
         */
        if(fileContents[i] == '\n') {
            link = malloc(sizeof(Link));
            link->type = typeLabel;
            link->name1 = unit1;
            link->name2 = unit2;
            link->expression = exprbuffer;
            addLink(link);
            i++;
        }

        /*
         * Check if the line starts with a '@', if so, it's a type label
         * we keep type labels until a new one is declared.
         */
        else if(fileContents[i] == '@') {
            typeLabel = malloc(sizeof(char) * LINEMAXLEN);
            i++;
            for(j = 0; fileContents[i] != '\n'; j++) {
                typeLabel[i] = fileContents[i];
                i++;
            }
            // One after '\n'
            i++;
        }

        /*
         * Finally, we catch everything else, which are normal input lines.
         */
        else {
            if(label == 0) {
                unit1 = malloc(sizeof(char) * LINEMAXLEN);
                label++;
            } else if(label == 1) {
                unit2 = malloc(sizeof(char) * LINEMAXLEN);
                label++;
            } else {
                expression = malloc(sizeof(char) * LINEMAXLEN);
            }

            for(j = 0; fileContents[i] != '\n'; j++) {
                if(label == 0) {
                    unit1[j] = fileContents[i];
                } else if(label == 1) {
                    unit2[j] = fileContents[i];
                } else {
                    expression[j] = fileContents[i];
                }
                i++;
            }
            // One after '\n'
            i++;

            if(label == 2) {
                whitespaceSplit(expression, exprbuffer, EXPBUFLEN);
                label = 0;
            }
        }
    }
    return 0;
}
