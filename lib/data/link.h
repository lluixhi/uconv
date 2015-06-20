typedef struct Link {
        char* type;
        char* name1;
        char* name2;
        char** expression;
        int creationFlag;
        struct Link *Left;
        struct Link *Right;
} Link;
