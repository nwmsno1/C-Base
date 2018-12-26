#include <stdio.h>

const int Max=3;

int main(void)
{
        int var[]={10, 100, 1000};
        int i, *ptr[Max];

        for (i=0; i<Max; i++)
        {
                ptr[i]=&var[i];
                printf("address: var[%d]=%x\n", i, ptr[i]);
                printf("value: var[%d]=%d\n", i, *ptr[i]);

                /*ptr++;*/
        }

        return 0;
}
