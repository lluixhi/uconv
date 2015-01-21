#include <string.h>
#include <stdlib.h>

#include "lib/strings.h"
#include "lib/data/link.h"

void addLink(Link* link) {

}

int loadConf(char* fileContents) {
    int i;
    Link* link;
    char typeLabel[40];

    for(i = 0; i < strlen(fileContents); i++) {
        /*
         * Check if the line starts with '\n', if so, it's the end of a
         * block, and we commit the link.
         */
        if(fileContents[i] == '\n') {
            link = malloc(sizeof(Link));
            addLink(link);
        }

        /*
         * Check if the line starts with a '@', if so, it's a type label
         * we keep type labels until a new one is declared.
         */
        else if(fileContents[i] == '@') {
            i++;
            // Stop filling the typeLabel when the line ends.
            // If the label is over 40 chars, that's dumb, so we truncate. (currently)
            while(fileContents[i] != '\n' && i % 40 != 0)
                typeLabel[i] = fileContents[i];
        }

        /*
         * Finally, we catch everything else, which are normal input lines.
         */

        else {
        
        }
    }
    return 0;
}
