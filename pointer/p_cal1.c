#include <stdio.h>

const int Max=3;

int main(void)
{
        int var[]={10, 100, 1000};
        int i, *ptr;

        ptr=var;
        for (i=0; i<Max; i++)
        {
                printf("address: var[%d]=%x\n", i, ptr);
                printf("value: var[%d]=%d\n%d\n", i, *ptr, var[i]);

                ptr++;
        }

        return 0;
}
