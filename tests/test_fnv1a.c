#include <stdio.h>

#include "../lib/data/mkeyhmap.h"

int main(const int argc, const char** argv) {
        const char* test_string1 = "Le test";
        const char* test_string2 = "Le testink";
        const char* test_string3 = "testink";
        const char* test_string4 = "testonk";
        const char* test_string5 = "testank";
        printf("%u\n", fnv1a(test_string1));
        printf("%u\n", fnv1a(test_string2));
        printf("%u\n", fnv1a(test_string3));
        printf("%u\n", fnv1a(test_string4));
        printf("%u\n", fnv1a(test_string5));
        return 0;
}
