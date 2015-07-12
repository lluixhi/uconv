#include "mkeyhmap.h"

unsigned int fnv1a(const char* string) {
        unsigned int hash;
        for(hash = 0; *string; ++string) {
                hash ^= *string;
                hash += (hash << 1) + (hash << 4) + (hash << 7) + (hash << 8) + (hash << 24);
        }
        return hash;
}

void insertLink(Link* link) {
        return;
}
