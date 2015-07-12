#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "../lib/strings.h"

#define BUFSIZE 100
#define EXPRESSIZE 10

int
main(const int argc, const char** argv )
{
        unsigned int i;
        char **expressionbuffer;
        char entry[BUFSIZE];

        for(;;) {
                expressionbuffer = calloc(EXPRESSIZE, sizeof(char*));

                printf(">> ");
                fgets(entry, BUFSIZE, stdin);

                //printf("%s\n", strfun(entry, &isspace));

                spacetokenize(entry, expressionbuffer, EXPRESSIZE);
                for(i = 0; expressionbuffer[i]; i++) {
                        printf("%s\n", expressionbuffer[i]);
                        free(expressionbuffer[i]);
                }
                free(expressionbuffer);

                if(*strfun(entry, &isspace) == 'q')
                        break;
        }
        return 0;
}
