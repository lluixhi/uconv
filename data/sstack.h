typedef struct SStack{
    void** Top;
    // Private things above.
    int PSize;
    int LSize;
} SStack;

SStack* make_SS(int size);
void break_SS(SStack* stack);
void* pop_SS(SStack* stack);
int push_SS(SStack* stack, void* item);
