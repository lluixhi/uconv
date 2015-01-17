#include <stdio.h>
#include <stdlib.h>

char*
fileAsString(const char* filepath)
{
    unsigned long length;
    char* contents = NULL;
    FILE* file = fopen(filepath, "r");

    if (file) {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);
        contents = malloc(length + 1);
        if (contents && length == fread(contents, 1, length, file))
            printf("Successful\n");
        fclose(file);
        contents[length] = 0;
    }
    return contents;
}
