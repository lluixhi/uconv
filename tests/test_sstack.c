#include <stdlib.h>
#include <stdio.h>
#include "../lib/data/sstack.h"

int main()
{
        SStack* Test2 = make_SS(3);
        double number1 = 3.0, number2 = 4.0, number3 = 5.0;

        // Stack Stuff.
        push_SS(Test2, &number1);
        push_SS(Test2, &number2);
        push_SS(Test2, &number3);
        printf("%d\n", Test2->LSize);
        printf("%lf\n", *((double*) pop_SS(Test2)));
        printf("%lf\n", *((double*) pop_SS(Test2)));
        printf("%lf\n", *((double*) pop_SS(Test2)));

        break_SS(Test2);
        return 0;
}
