#include <stdlib.h>
#include "sstack.h"

void*
pop_SS(SStack* Corn)
{
        if(Corn->LSize) {
                Corn->LSize--;
                void* temp = Corn->Top[Corn->LSize];
                return temp;
        }
        return NULL;
}

int
push_SS(SStack* Corn, void* val)
{
        if(Corn->LSize != Corn->PSize) {
                Corn->Top[Corn->LSize] = val;
                Corn->LSize++;
                return EXIT_SUCCESS;
        }
        return EXIT_FAILURE;
}

SStack*
make_SS(int size)
{
        SStack* Popcorn = malloc(sizeof(SStack));
        Popcorn->Top = malloc(size * sizeof(void*));
        Popcorn->PSize = size;
        Popcorn->LSize = 0;
        return Popcorn;
}

void
break_SS(SStack* Popcorn)
{
        while(Popcorn->LSize) {
                pop_SS(Popcorn);
        }
        free(Popcorn->Top);
        free(Popcorn);
        return;
}
