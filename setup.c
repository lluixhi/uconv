#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib/strings.h"
#include "lib/data/btree.h"

#define LINEMAXLEN 64
#define EXPBUFLEN 32

int
loadConf(char* fileContents)
{
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
                else if(fileContents[i] == '\n' || fileContents[i] == 0) {
                        link = malloc(sizeof(Link));
                        link->type = typeLabel;
                        link->name1 = unit1;
                        link->name2 = unit2;
                        link->expression = exprbuffer;
                        link->creationFlag = 0;
                        insertLink(link);
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

                else {
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
                                label = 0;
                                exprbuffer = calloc(EXPBUFLEN, sizeof(char*));
                                spacetokenize(expression, exprbuffer, EXPBUFLEN);
                        }
                }
        }
        return EXIT_SUCCESS;
}

int
saveConf(char* filePath)
{
        return EXIT_SUCCESS;
}
