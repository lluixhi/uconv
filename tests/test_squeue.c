#include <stdlib.h>
#include <stdio.h>
#include "../lib/data/squeue.h"

int
main(const int argc, const char **argv)
{
        SQueue* Test2 = make_SQ(3);
        double number1 = 3.0, number2 = 4.0, number3 = 5.0, number4 = 6.0;

        // Basic Stack-Tier Stuff.
        push_SQ(Test2, &number1);
        push_SQ(Test2, &number2);
        push_SQ(Test2, &number3);
        printf("%d\n", Test2->LSize);
        printf("%lf\n", *((double*) pop_SQ(Test2)));
        printf("%lf\n", *((double*) pop_SQ(Test2)));
        printf("%lf\n", *((double*) pop_SQ(Test2)));

        // Now the real test. (Tests front and back pointer switcharoos)
        push_SQ(Test2, &number4);
        printf("%lf\n", *((double*) pop_SQ(Test2)));

        break_SQ(Test2);
        return 0;
}
