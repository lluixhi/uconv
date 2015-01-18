#include <stdio.h>
#include <stdlib.h>

char*
fileAsString(FILE* file)
{
    unsigned long length;
    char* contents = NULL;

    if (file) {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);
        contents = malloc(length + 1);
        if (contents && length == fread(contents, 1, length, file)); // Todo, implement logging
        fclose(file);
        contents[length] = 0;
    }
    return contents;
}
