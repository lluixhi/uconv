typedef struct Link{
    char* type;
    char* name1;
    char* name2;
    char** expression;
    char exprLength;
    struct Link *Next1;
    struct Link *Next2;
} Link;
