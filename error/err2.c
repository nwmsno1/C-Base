#include <stdio.h>
#include <stdlib.h>

main()
{
        int dividend=20;
        int divisor=1;
        int quotient;

        if(divisor==0)
        {
                fprintf(stderr, "exit with divisor=0...\n");
                exit(-1);
        }
        quotient=dividend/divisor;
        fprintf(stderr, "the value of quotient is: %d\n", quotient);

        exit(0);
}
