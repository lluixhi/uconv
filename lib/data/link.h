typedef struct Link{
    char* name1;
    char* name2;
    char** expression;
    char exprLength;
    struct Link *Next;
} Link;
