#include <stdlib.h>
#include "squeue.h"

void* pop_SQ(SQueue* Line) {
    if(Line->LSize) {
        void* temp = Line->OP[Line->FPos];
        if(Line->FPos == Line->PSize - 1) {
            Line->FPos = 0;
        } else {
            Line->FPos++;
        }
        Line->LSize--;
        return temp;
    }
    return NULL;
}

int push_SQ(SQueue* Line, void* val) {
    if(Line->LSize != Line->PSize) {
        Line->OP[Line->BPos] = val;
        if(Line->BPos == Line->PSize - 1) {
            Line->BPos = 0;
        } else {
            Line->BPos++;
        }
        Line->LSize++;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

SQueue* make_SQ(int size) {
    SQueue* Line = malloc(sizeof(SQueue));
    Line->OP = malloc(size * sizeof(void*));
    Line->FPos = 0;
    Line->BPos = 0;
    Line->PSize = size;
    Line->LSize = 0;
    return Line;
}

void break_SQ(SQueue* Line) {
    free(Line->OP);
    free(Line);
    return;
}
