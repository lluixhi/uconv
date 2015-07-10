#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Functional strstr/strchr
 */
char* strfun(const char *input, int chartype (int))
{
        unsigned long i, length = strlen(input);

        for(i = 0; i != length && chartype(input[i]); ++i);
        if(i == length)
                return NULL;
        return (char *)input + i;
}

/*
 * Tokenize based on function.
 */
char** tokenize(const char *input, char **buffer, int chartype (int), const unsigned long len)
{
        char *token, *splitter = strfun(input, chartype);
        unsigned long i, buffi;

        for(buffi = 0; buffi != len; ++buffi) {
                if(splitter) {
                        for(i = 0; splitter[i] && !chartype(splitter[i]); ++i);

                        token = malloc(i * sizeof(char) + 1);
                        strncpy(token, splitter, i);
                        buffer[buffi] = token;
                        splitter += i;
                } else break;
                splitter = strfun(splitter, chartype);
        }
        return buffer;
}

char** spacetokenize(const char *input, char **buffer, const unsigned long len)
{
        return tokenize(input, buffer, &isspace, len);
}

int isnewline(int character)
{
        if(character == '\n')
                return 1;
        return 0;
}
