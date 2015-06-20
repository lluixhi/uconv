#include <stdio.h>
#include <stdlib.h>

#include "../lib/file.h"

int main(const int argc, const char** argv )
{
        FILE* confFile = fopen("../cli/config","r+");
        char* confFileContents = fileAsString(confFile);

        printf("%s", confFileContents);
        free(confFileContents);
        return 0;
}
