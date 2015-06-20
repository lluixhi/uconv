typedef struct SQueue {
        void** OP;
        int FPos;
        int BPos;
        // Private Things above.
        int PSize;                          // Total Possible Size
        int LSize;                          // Actual Size
} SQueue;

SQueue* make_SQ(int size);
void break_SQ(SQueue* queue);
void* pop_SQ(SQueue* queue);
int push_SQ(SQueue* queue, void* item);
